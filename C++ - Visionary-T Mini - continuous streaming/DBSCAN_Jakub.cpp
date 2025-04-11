//Aiut - Jakub Klepacz - Version 1.0 - 17.03.2025
//Aiut - Jakub Klepacz - Version 1.1 - 20.03.2025

#include "DBSCAN_Jakub.h"

// Euclidean distance
float distance(const visionary::PointXYZ& a, const visionary::PointXYZ& b) {
	// Calculating the Euclidean distance between two points
	return std::sqrt((a.x - b.x) * (a.x - b.x) +
		(a.y - b.y) * (a.y - b.y) +
		(a.z - b.z) * (a.z - b.z));
}

// K-means algoritm - algoritm no. 1
void kMeansClustering(std::vector<visionary::PointXYZ>& points, int k, std::vector<int>& labels) {
	std::vector<visionary::PointXYZ> centroids(k); // Centers of clusters
	labels.resize(points.size(), -1);

	// Initializing centroids with random points from the vector
	for (int i = 0; i < k; ++i) {
		centroids[i] = points[std::rand() % points.size()];
	}

	bool changed = true;
	while (changed) {
		changed = false;

		// Assigning each point to the nearest centroid
		for (size_t i = 0; i < points.size(); ++i) {
			float minDist = std::numeric_limits<float>::max();
			int bestCluster = -1;

			for (int j = 0; j < k; ++j) {
				float dist = distance(points[i], centroids[j]);
				if (dist < minDist) {
					minDist = dist;
					bestCluster = j;
				}
			}

			if (labels[i] != bestCluster) {
				labels[i] = bestCluster; // Update cluster assignment
				changed = true;
			}
		}

		// Centroid update
		std::vector<visionary::PointXYZ> newCentroids(k, { 0.0f, 0.0f, 0.0f });
		std::vector<int> count(k, 0);

		for (size_t i = 0; i < points.size(); ++i) {
			int cluster = labels[i];
			newCentroids[cluster].x += points[i].x;
			newCentroids[cluster].y += points[i].y;
			newCentroids[cluster].z += points[i].z;
			count[cluster]++;
		}

		for (int j = 0; j < k; ++j) {
			if (count[j] > 0) {
				centroids[j].x = newCentroids[j].x / count[j];
				centroids[j].y = newCentroids[j].y / count[j];
				centroids[j].z = newCentroids[j].z / count[j];
			}
		}
	}
}

// DBSCAN algoritm - algoritm no. 2
void DBSCAN(const std::vector<visionary::PointXYZ>& points, float eps, int min_samples, 
	std::vector<int>& labels, std::vector<visionary::PointXYZ>& centroids,int pixel_cm,
	cv::Mat& image_out, const std::uint32_t height, const std::uint32_t width) {
	int cluster_id = 0;
	labels.resize(points.size(), -1); // -1 means unassigned points

	for (size_t i = 0; i < points.size(); ++i) {
		if (labels[i] != -1) continue; // Point already assigned to a cluster or marked as noise

		// Find the neighborhood of a point
		std::vector<size_t> neighbors;
		for (size_t j = 0; j < points.size(); ++j) {
			if (distance(points[i], points[j]) <= eps) {
				neighbors.push_back(j);
			}
		}

		if (neighbors.size() < static_cast<size_t>(min_samples)) {
			labels[i] = -2; // Mark as noise
			continue;
		}

		// Initialize new cluster
		cluster_id++;
		labels[i] = cluster_id;

		// Expand cluster
		for (size_t n = 0; n < neighbors.size(); ++n) {
			size_t neighbor_idx = neighbors[n];
			if (labels[neighbor_idx] == -2) {
				labels[neighbor_idx] = cluster_id; // Noise point becomes part of cluster
			}
			if (labels[neighbor_idx] != -1) continue;

			labels[neighbor_idx] = cluster_id;

			// Find the neighbors of this point
			std::vector<size_t> neighbors_of_neighbor;
			for (size_t k = 0; k < points.size(); ++k) {
				if (distance(points[neighbor_idx], points[k]) <= eps) {
					neighbors_of_neighbor.push_back(k);
				}
			}

			if (neighbors_of_neighbor.size() >= static_cast<size_t>(min_samples)) {
				neighbors.insert(neighbors.end(), neighbors_of_neighbor.begin(), neighbors_of_neighbor.end());
			}
		}
	}

	// Clusters centroids
	centroids.resize(cluster_id);

	// Checking the consistency of the points and labels sizes
	if (points.size() != labels.size()) {
		std::cerr << "\033[1;31m" << "ERROR: Points and labels size mismatch" << "\033[0m" << std::endl;
		return;
	}

	if (cluster_id == 0) {
		std::cerr << "\033[33m" << "Warning: Clusters not found" << "\033[0m" << std::endl;
		return;
	}

	for (int c = 1; c <= cluster_id; ++c) {
		float sum_x = 0, sum_y = 0, sum_z = 0;
		int count = 0;

		for (size_t i = 0; i < points.size(); ++i) {
			if (labels[i] == c) {
				sum_x += points[i].x;
				sum_y += points[i].y;
				sum_z += points[i].z;
				++count;
			}
		}

		if (count > 0) {
			centroids[c - 1] = { sum_x / count, sum_y / count, sum_z / count };
			std::cout << "Cluster " << c << " centroid: ("
				<< centroids[c - 1].x << ", "
				<< centroids[c - 1].y << ", "
				<< centroids[c - 1].z << ")" << std::endl;
		}
		else {
			std::cerr << "\033[33m" << "Warning: Cluster " << c << " has no points assigned!" << "\033[0m" << std::endl;
		}
	}

	cv::Mat image(height, width, CV_8UC3, cv::Scalar(255, 255, 255)); // White background

	// Maximum target dimensions
	const int MAX_WIDTH = 512;
	const int MAX_HEIGHT = 424;

	// Finding minimum and maximum values for x and y
	float x_min = std::numeric_limits<float>::max();
	float x_max = std::numeric_limits<float>::lowest();
	float y_min = std::numeric_limits<float>::max();
	float y_max = std::numeric_limits<float>::lowest();

	for (const auto& point : points) {
		x_min = std::min(x_min, point.x);
		x_max = std::max(x_max, point.x);
		y_min = std::min(y_min, point.y);
		y_max = std::max(y_max, point.y);
	}

	// Random and unique colors of clusters
	std::vector<cv::Scalar> clusterColors(cluster_id);
	for (int c = 0; c < cluster_id; ++c) {
		int blue = (161 * c) % 256;   // B (od 0 do 255)
		int green = (107 * c) % 256;  // G (od 0 do 255)
		int red = (33 * c) % 256;   // R (od 0 do 255)
		clusterColors[c] = cv::Scalar(blue, green, red); // Dynamically generated color
	}

	// All points of clusters to the PNG
	for (size_t i = 0; i < points.size(); ++i) {
		// The point belongs to the cluster
		if (labels[i] >= 1) {
			// Cluster index (color vector matching)
			int clusterIndex = labels[i] - 1; 

			float scaledX = width - (((points[i].x - x_min) / (x_max - x_min)) * width);
			float scaledY = height - (((points[i].y - y_min) / (y_max - y_min)) * height);

			// Making sure the scaled coordinates are within the image boundaries
			int x = static_cast<int>(scaledX);
			int y = static_cast<int>(scaledY);

			cv::circle(image, cv::Point(x, y), 1, clusterColors[clusterIndex], -1); // Color of the cluster
		}
	}

	// Centroids in the same colors
	for (int c = 1; c <= cluster_id; ++c) {
			float scaledX = width - (((centroids[c-1].x - x_min) / (x_max - x_min)) * width);
			float scaledY = height - (((centroids[c-1].y - y_min) / (y_max - y_min)) * height);

			// Making sure the scaled coordinates are within the image boundaries
			int x = static_cast<int>(scaledX);
			int y = static_cast<int>(scaledY);

			// Brighten the color of the centroid
			cv::Scalar baseColor = clusterColors[c - 1];
			cv::Scalar brighterColor(
				std::min(baseColor[0] + 50, 255.0), // Blue
				std::min(baseColor[1] + 50, 255.0), // Green
				std::min(baseColor[2] + 50, 255.0)  // Red
			);

			cv::circle(image, cv::Point(x, y), 1, brighterColor, -1); // Centroid in the cluster color
	}

	// Displaying in continuous_streaming
	cv::resize(image, image_out, cv::Size(MAX_WIDTH, MAX_HEIGHT), 0, 0, cv::INTER_LINEAR);
}
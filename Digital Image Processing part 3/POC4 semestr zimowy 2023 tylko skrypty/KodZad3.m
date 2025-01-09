circles = {im2bw(imread('C:\Users\Krzysztof\Desktop\circle1.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\circle2.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\circle3.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\circle4.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\circle5.png'))};
squares = {im2bw(imread('C:\Users\Krzysztof\Desktop\square1.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\square2.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\square3.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\square4.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\square5.png'))};
triangles = {im2bw(imread('C:\Users\Krzysztof\Desktop\triangle1.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\triangle2.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\triangle3.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\triangle4.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\triangle5.png'))};
ladowarka = {im2bw(imread('C:\Users\Krzysztof\Desktop\obudowax.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\obudowa2.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\obudowa3.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\obudowa4.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\obudowa5.png'))};
moneta = {im2bw(imread('C:\Users\Krzysztof\Desktop\zakretkax.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\zakretka2.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\zakretka3.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\zakretka4.png')), ...
 im2bw(imread('C:\Users\Krzysztof\Desktop\zakretka5.png'))};
 
visualise_stats({circles, squares, triangles, ladowarka, moneta});

function visualise_stats(imgs)
 figure; 
 for i = 1:length(imgs)
 shapeShapeSeries = imgs{i};
    for j = 1:length(shapeShapeSeries)
     [K(j), C(j), M(j)] = imgStats(shapeShapeSeries{j});
    end
 subplot(2, 2, 1); hold on; scatter3(K, C, M);
 grid on
 subplot(2, 2, 2); hold on; scatter3(K, C, M);
 grid on
 subplot(2, 2, 3); hold on; scatter3(K, C, M);
 grid on
 subplot(2, 2, 4); hold on; scatter3(K, C, M);
 grid on
 end
 hold off;
 subplot(2, 2, 1);
 xlabel('K'); ylabel('Mz'); zlabel('M'); legend('Location', 'northeastoutside');
 legend('Koło', 'Prostokąt', 'Trójkąt', 'Obudowa', 'Zakretka');
 subplot(2, 2, 2); view(180, 0);
 xlabel('K'); ylabel('Mz'); zlabel('M'); legend('Location', 'northeastoutside');
 legend('Koło', 'Prostokąt', 'Trójkąt', 'Obudowa', 'Zakretka');
 subplot(2, 2, 3); view(-90, 0);
 xlabel('K'); ylabel('Mz'); zlabel('M'); legend('Location', 'northeastoutside');
 legend('Koło', 'Prostokąt', 'Trójkąt', 'Obudowa', 'Zakretka');
 subplot(2, 2, 4); view(45, 45);
 xlabel('K'); ylabel('Mz'); zlabel('M'); legend('Location', 'northeastoutside');
 legend('Koło', 'Prostokąt', 'Trójkąt', 'Obudowa', 'Zakretka');
end
function [K, Mz, M] = imgStats(img)
 S = bwarea(img);
 L = regionprops(img, 'Perimeter');
 L = L.Perimeter;
 K = 4 * pi * S / L^2;
 Mz = 2 * sqrt(S * pi) / L;
 M = L / (2 * sqrt(pi * S)) - 1;
end
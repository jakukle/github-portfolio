#include "Consumer.h"

Consumer::Consumer(Producer* producer) : producer(producer), average(0)
{}

void Consumer::ThreadRoutine()
{
	while (isRunning())
	{
		vector<double> data = producer->GetData();
		double avg = accumulate(data.begin(), data.end(), 0.0) / data.size();

		averageMutex.lock();
		average = avg;
		averageMutex.unlock();

		this_thread::sleep_for(chrono::milliseconds(100));
	}
}
double Consumer::GetAverage()
{
	averageMutex.lock();
	double average = this->average;
	averageMutex.unlock();

	return average;

}
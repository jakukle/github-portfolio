#include "Producer.h"

void Producer::ThreadRoutine()
{
	while (isRunning())
	{
		double randomElement = rand() % 100;

		dataMutex.lock();
		data.push_back(randomElement);
		dataMutex.unlock();

		this_thread::sleep_for(chrono::milliseconds(100));
	}
}
vector<double> Producer::GetData()
{
	vector<double> outData;
	dataMutex.lock();
	outData = data;
	dataMutex.unlock();

	return outData;

}

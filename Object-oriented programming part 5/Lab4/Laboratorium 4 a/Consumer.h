#pragma once
#include "IThread.h"
#include "Producer.h"
#include <numeric>
class Consumer : public IThread
{
private:
	Producer* producer;
	double average;
	mutex averageMutex;

	void ThreadRoutine() override;
public:
	Consumer(Producer* producer);
	double GetAverage();
};


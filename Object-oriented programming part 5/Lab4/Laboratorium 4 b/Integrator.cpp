#include "Integrator.h"

Integrator::Integrator() : status2( IDLE ), step(0.0){}

Integrator::~Integrator() {}

void Integrator::SetStatus(Status stan)
{
    statusMutex.lock();
	status2 = stan;
	statusMutex.unlock();
}
void Integrator::Count(const vector<double>& v, const double krok)
{
	dataMutex.lock();
	step = krok;
	dataMutex.unlock();

	dataMutex.lock();
	data = v;
	dataMutex.unlock();

	statusMutex.lock();
	status2 = WORKING;
	statusMutex.unlock();
}

Integrator::Status Integrator::GetStatus()
{
	return status2;
}
long double Integrator::GetResult()
{
	return result;
}
void Integrator::ThreadRoutine()
{
while (isRunning())
{
	if (status2 == WORKING)
	{
		dataMutex.lock();
		resultMutex.lock();
		for (int i = 0; i < data.size(); i++)
		{
			result += data[i] * step;
		}
		resultMutex.unlock();
		dataMutex.unlock();

		statusMutex.lock();
		status2 = IDLE;
		statusMutex.unlock();
	}
	this_thread::yield();
} 
}
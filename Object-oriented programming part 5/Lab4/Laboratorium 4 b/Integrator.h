#pragma once
#include "IThread.h"
#include <vector>
#include <mutex>

using namespace std;

class Integrator : public IThread
{
public:
	Integrator();
	virtual ~Integrator();
	void Count(const vector<double>&, const double);
	enum Status { IDLE, WORKING };
	Status status2;
	Status GetStatus();
	long double GetResult();
private:
	vector<double> data;
	double step;
	mutex dataMutex;
	mutex statusMutex;
	mutex resultMutex;
	void SetStatus(Status);
	void ThreadRoutine();
	long double result=0.0;
};

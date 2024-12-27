#pragma once
#include <mutex>
#include<vector>
#include "IThread.h"
using namespace std;
class Producer : public IThread
{
private:
	vector<double>data;
	mutex dataMutex;
	void ThreadRoutine() override;
public:
	vector<double> GetData();
};


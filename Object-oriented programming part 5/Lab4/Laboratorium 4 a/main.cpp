#pragma once
#include <iostream>
#include "Producer.h"
#include "Consumer.h"

int main()
{
	const size_t numberOfConsumers = 4;
	Producer* producer = new Producer();
	producer->Start();

	vector<Consumer*> consumers;

	for (size_t i = 0; i < numberOfConsumers; i++)
	{
		consumers.push_back(new Consumer(producer));
		consumers.back()->Start();
	}

	while (true) 
	{
		char key = getchar();
		if (key == 112) // to jest p, bo escape nie dziala ( czyli 27 )
		break;
		
		else if (key == '\n')
		{
			cout << endl;
			cout << "Producer data size: " << producer->GetData().size() << endl;
			for (size_t i = 0;  i < numberOfConsumers; i++)
				cout << "Consumer [" << i << "] average: " << consumers[i]->GetAverage() << endl;
			cout << endl;
		}
	}

	for (auto consumer : consumers)
	{
		consumer->Stop();
		delete consumer;
	}
	producer->Stop();
	delete producer;
}
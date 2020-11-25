#pragma once
#include <queue>
#include "Job.h"
using std::priority_queue;
class JobQueue
{
public:
	JobQueue(Job new_job)
	{
		this->jobqueue.push(new_job);
	}

private:
	priority_queue<Job> jobqueue;


};
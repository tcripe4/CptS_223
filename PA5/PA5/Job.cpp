#pragma once
#include "Job.h"

Job::Job(int Jobid, string jobdescription, int procs, int ticks)
{
	this->JobID = Jobid;

	this->JobDescription = jobdescription;

	this->n_procs = procs;

	this->n_ticks = ticks;
}

int Job::get_jobID()
{
	return this->JobID;
}

string Job::get_description()
{
	return this->JobDescription;
}

int Job::get_procs()
{
	return this->n_procs;
}

int Job::get_ticks()
{
	return this->n_ticks;
}
#pragma once
using namespace std;
#include <string>
#include <iostream>

class Job
{
public:
	Job(int Jobid = 0, string jobdesctiption = "", int procs = 0, int ticks = 0);

	int get_jobID();

	string get_description();

	int get_procs();

	int get_ticks();

private:
	int JobID;

	string JobDescription;

	int n_procs;

	int n_ticks;
};
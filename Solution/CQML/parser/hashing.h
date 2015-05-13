#pragma once
#include <string>

using namespace std;

struct PerfectHashData
{
	string * keys;
	int * T1;
	int * T2;
	int * g;
	int m;
	int n;
	int maxT;
};

PerfectHashData * makePerfectHash(string * strs, int cnt);

void MakeAllHashes();
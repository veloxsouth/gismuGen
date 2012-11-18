#pragma once
#include <random>

using namespace std;

class randFunctor
{
public:
	randFunctor(void);
	~randFunctor(void);
	int operator()(int var);
protected:
	mt19937 m_gen;
};


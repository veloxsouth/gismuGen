#include "randFunctor.h"
#include <ctime>

randFunctor::randFunctor(void)
	:m_gen(time(NULL))
{
}


randFunctor::~randFunctor(void)
{
}


int randFunctor::operator()(int var)
{
	uniform_int_distribution<int> dist(0, var -1);
	return dist(m_gen);
}
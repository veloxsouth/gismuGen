#include "randFunctor.h"
#include <ctime>

randFunctor::randFunctor(mt19937& gen)
	:m_gen(gen)
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
#ifndef GISMUENUMERATOR_H
#define GISMUENUMERATOR_H

#include "initialconsonantclustertable.h"
#include "consonantclustertable.h"
#include "gismu.h"
#include <random>
#include <vector>

using namespace std;

class GismuEnumerator
{
    public:
        GismuEnumerator();
        virtual ~GismuEnumerator();
        Gismu* getRandomGismu();
        string toString();
        vector<Gismu*> getList();
    protected:
        vector<Gismu*> m_allGismu;
        mt19937 m_gen;
    private:
};

#endif // GISMUENUMERATOR_H

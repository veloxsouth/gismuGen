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
        GismuEnumerator(InitialConsonantClusterTable& initConTable, ConsonantClusterTable& conClusterTable, ConsonantTable& conTable);
        virtual ~GismuEnumerator();
        string toString();
		vector<Gismu*>& getList() { return m_allGismu;};
    protected:
        vector<Gismu*> m_allGismu;
    private:
};

#endif // GISMUENUMERATOR_H

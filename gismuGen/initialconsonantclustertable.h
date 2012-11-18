#ifndef INITIALCONSONANTCLUSTERTABLE_H
#define INITIALCONSONANTCLUSTERTABLE_H
#include <vector>
#include <string>
#include <random>
#include "consonanttable.h"

using namespace std;

class InitialConsonantClusterTable
{
    public:
        InitialConsonantClusterTable();
        virtual ~InitialConsonantClusterTable();
        string getRandom();
        vector<string> getList();
        bool isValid(string var);
    protected:
        uniform_int_distribution<int>* m_intDist;
        mt19937 m_gen;
        vector<string> m_initConClusters;
        ConsonantTable m_conTable;
    private:
};

#endif // INITIALCONSONANTCLUSTERTABLE_H

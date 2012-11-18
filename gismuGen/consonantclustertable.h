#ifndef CONSONANTCLUSTERTABLE_H
#define CONSONANTCLUSTERTABLE_H
#include "consonanttable.h"
#include <vector>
#include <string>
#include <random>

using namespace std;

class ConsonantClusterTable
{
    public:
        ConsonantClusterTable();
        virtual ~ConsonantClusterTable();
        vector<string> getList();
        string getRandom();
        bool isValid(string var);
        int getWeededClusterCount(){return m_weededClusterCount;};
        int getWeededClusterDoubleCount(){return m_weededClusterDoubleCount;};
        int getWeededClusterVUCount(){return m_weededClusterVUCount;};
        int getWeededClusterExceptionCount(){return m_weededClusterExceptionCount;};
    protected:
        int m_weededClusterCount;
        int m_weededClusterDoubleCount;
        int m_weededClusterVUCount;
        int m_weededClusterExceptionCount;
        mt19937 m_gen;
        uniform_int_distribution<int>* m_intDist;
        vector<string> m_clusters;
        ConsonantTable m_conTable;
    private:
};

#endif // CONSONANTCLUSTERTABLE_H

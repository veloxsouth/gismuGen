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
        ConsonantClusterTable(ConsonantTable& conTable);
        virtual ~ConsonantClusterTable();
        const vector<string>& getList();
        bool isValid(string var);
    protected:
        vector<string> m_clusters;
    private:
};

#endif // CONSONANTCLUSTERTABLE_H

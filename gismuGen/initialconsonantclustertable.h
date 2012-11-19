#ifndef INITIALCONSONANTCLUSTERTABLE_H
#define INITIALCONSONANTCLUSTERTABLE_H
#include <vector>
#include <string>
#include <random>

using namespace std;

class InitialConsonantClusterTable
{
    public:
        InitialConsonantClusterTable();
        virtual ~InitialConsonantClusterTable();
        const vector<string>& getList();
        bool isValid(string var);
    protected:
        vector<string> m_initConClusters;
    private:
};

#endif // INITIALCONSONANTCLUSTERTABLE_H

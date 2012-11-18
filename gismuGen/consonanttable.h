#ifndef CONSONANTTABLE_H
#define CONSONANTTABLE_H
#include <vector>
#include <random>

using namespace std;

enum ConsonantClusterVoicing
{
    voiced,
    unvoiced,
    exempt,
};

class ConsonantTable
{
    public:
        ConsonantTable();
        virtual ~ConsonantTable();
        char getRandom();
        vector<char> getList();
        bool isValid(char var);
        static ConsonantClusterVoicing isVoiced(char c);
    protected:
        vector<char> m_consonants;
        mt19937 m_gen;
        uniform_int_distribution<int>* m_intDist;
    private:
};

#endif // CONSONANTTABLE_H

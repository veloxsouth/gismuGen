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
        const vector<char>& getList();
        static ConsonantClusterVoicing isVoiced(char c);
    protected:
        vector<char> m_consonants;
    private:
};

#endif // CONSONANTTABLE_H

#ifndef COLLISIONTABLE_H
#define COLLISIONTABLE_H

#include <map>
#include <vector>

using namespace std;

class CollisionTable
{
    public:
        CollisionTable();
        virtual ~CollisionTable();
        bool areLettersColliding(char proposed, char existing);
        vector<char> getCollisions(char proposed);
    protected:
        multimap<char, char> m_table;
    private:
};

#endif // COLLISIONTABLE_H

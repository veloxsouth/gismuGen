#include "collisiontable.h"

CollisionTable::CollisionTable()
{
    //ctor
    m_table.insert(pair<char, char>('b', 'p'));
    m_table.insert(pair<char, char>('b', 'v'));

    m_table.insert(pair<char, char>('c', 'j'));
    m_table.insert(pair<char, char>('c', 's'));

    m_table.insert(pair<char, char>('d', 't'));

    m_table.insert(pair<char, char>('f', 'p'));
    m_table.insert(pair<char, char>('f', 'v'));

    m_table.insert(pair<char, char>('g', 'k'));
    m_table.insert(pair<char, char>('g', 'x'));

    m_table.insert(pair<char, char>('j', 'c'));
    m_table.insert(pair<char, char>('j', 'z'));

    m_table.insert(pair<char, char>('k', 'g'));
    m_table.insert(pair<char, char>('k', 'x'));

    m_table.insert(pair<char, char>('l', 'r'));

    m_table.insert(pair<char, char>('m', 'n'));
    m_table.insert(pair<char, char>('n', 'm'));

    m_table.insert(pair<char, char>('p', 'b'));
    m_table.insert(pair<char, char>('p', 'f'));

    m_table.insert(pair<char, char>('r', 'l'));

    m_table.insert(pair<char, char>('s', 'c'));
    m_table.insert(pair<char, char>('s', 'z'));

    m_table.insert(pair<char, char>('t', 'd'));

    m_table.insert(pair<char, char>('v', 'b'));
    m_table.insert(pair<char, char>('v', 'f'));

    m_table.insert(pair<char, char>('x', 'g'));
    m_table.insert(pair<char, char>('x', 'k'));

    m_table.insert(pair<char, char>('z', 'j'));
    m_table.insert(pair<char, char>('z', 's'));
}

CollisionTable::~CollisionTable()
{
    //dtor
}

bool CollisionTable::areLettersColliding(char proposed, char existing)
{
    vector<char> collisions = getCollisions(proposed);
    vector<char>::iterator iter;
    for (iter = collisions.begin(); iter != collisions.end(); iter++)
    {
        if (*iter == existing)
        {
            return true;
        }
    }
    return false;
}

vector<char> CollisionTable::getCollisions(char proposed)
{
    vector<char> retVec;
    pair<multimap<char, char>::iterator, multimap<char, char>::iterator> lookup = m_table.equal_range(proposed);
    multimap<char, char>::iterator iter;
    for (iter = lookup.first; iter != lookup.second; iter++)
    {
        retVec.push_back((*iter).second);
    }

    //empty vec if no entry in table.
    return retVec;
}

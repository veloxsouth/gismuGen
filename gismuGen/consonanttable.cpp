#include "consonanttable.h"

ConsonantTable::ConsonantTable()
{
    //ctor
    m_consonants.push_back('b');
    m_consonants.push_back('c');
    m_consonants.push_back('d');
    m_consonants.push_back('f');
    m_consonants.push_back('g');
    m_consonants.push_back('j');
    m_consonants.push_back('k');
    m_consonants.push_back('l');
    m_consonants.push_back('m');
    m_consonants.push_back('n');
    m_consonants.push_back('p');
    m_consonants.push_back('r');
    m_consonants.push_back('s');
    m_consonants.push_back('t');
    m_consonants.push_back('v');
    m_consonants.push_back('x');
    m_consonants.push_back('z');
}

ConsonantTable::~ConsonantTable()
{
    //dtor
}

const vector<char>& ConsonantTable::getList()
{
    return m_consonants;
}

ConsonantClusterVoicing ConsonantTable::isVoiced(char c)
{
    if (c == 'b' ||
        c == 'd' ||
        c == 'g' ||
        c == 'v' ||
        c == 'j' ||
        c == 'z')
    {
        return voiced;
    }
    else if (c == 'p'||
        c == 't' ||
        c == 'k' ||
        c == 'f' ||
        c == 'c' ||
        c == 's' ||
        c == 'x')
    {
        return unvoiced;
    }
    else
    {
        return exempt;
    }
}

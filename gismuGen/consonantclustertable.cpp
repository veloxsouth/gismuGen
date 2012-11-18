#include "consonantclustertable.h"

ConsonantClusterTable::ConsonantClusterTable()
{
    //ctor
    //enumerate all valid clusters into m_clusters
    int i, j;
    m_weededClusterCount = 0;
    m_weededClusterDoubleCount = 0;
    m_weededClusterExceptionCount = 0;
    m_weededClusterVUCount = 0;
    vector<char> conList = m_conTable.getList();
    int size = (signed) conList.size();
    char a, b;
    string tempString;
    ConsonantClusterVoicing isFirstCharVoiced;
    ConsonantClusterVoicing isSecondCharVoiced;
    for (i = 0; i < size; i++)
    {
        a = conList[i];
        for (j = 0; j < size; j++)
        {
            b = conList[j];

            //only save tempString to m_clusters if it follows the rules

            //no double consonants
            if (a == b)
            {
                m_weededClusterCount++;
                m_weededClusterDoubleCount++;
                continue;
            }

            //can not be voiced and unvoiced together
            isFirstCharVoiced = m_conTable.isVoiced(a);
            isSecondCharVoiced = m_conTable.isVoiced(b);
            if ((isFirstCharVoiced == voiced && isSecondCharVoiced == unvoiced) ||
                (isFirstCharVoiced == unvoiced && isSecondCharVoiced == voiced))
            {
                m_weededClusterVUCount++;
                m_weededClusterCount++;
                continue;
            }

            //cjsz set rule, and forbidden pair rule not counting voiced unvoiced pairs
            tempString.clear();
            tempString += a;
            tempString += b;
            if (!tempString.compare("cs") ||
                !tempString.compare("jz") ||
                !tempString.compare("sc") ||
                !tempString.compare("zj") ||

                !tempString.compare("cx") ||
                !tempString.compare("kx") ||
                !tempString.compare("xc") ||
                !tempString.compare("xk") ||
                !tempString.compare("mz"))
            {
                m_weededClusterExceptionCount++;
                m_weededClusterCount++;
                continue;
            }

            m_clusters.push_back(tempString);
        }
    }
    m_intDist = new uniform_int_distribution<int>(0, m_clusters.size() - 1);
}

ConsonantClusterTable::~ConsonantClusterTable()
{
    //dtor
    delete m_intDist;
}


string ConsonantClusterTable::getRandom()
{
    return m_clusters[(*m_intDist)(m_gen)];
}

vector<string> ConsonantClusterTable::getList()
{
    return m_clusters;
}

bool ConsonantClusterTable::isValid(string var)
{
    vector<string>::iterator iter;
    for (iter = m_clusters.begin(); iter != m_clusters.end(); iter++)
    {
        if (var.compare(*iter) == 0)
            return true;
    }
    return false;
}

#include "consonantclustertable.h"

ConsonantClusterTable::ConsonantClusterTable(ConsonantTable& conTable)
{
    //ctor
    //enumerate all valid clusters into m_clusters
    int i, j;
    vector<char> conList = conTable.getList();
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
                continue;
            }

            //can not be voiced and unvoiced together
            isFirstCharVoiced = conTable.isVoiced(a);
            isSecondCharVoiced = conTable.isVoiced(b);
            if ((isFirstCharVoiced == voiced && isSecondCharVoiced == unvoiced) ||
                (isFirstCharVoiced == unvoiced && isSecondCharVoiced == voiced))
            {
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
                continue;
            }

            m_clusters.push_back(tempString);
        }
    }
}

ConsonantClusterTable::~ConsonantClusterTable()
{
    //dtor
}

const vector<string>& ConsonantClusterTable::getList()
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

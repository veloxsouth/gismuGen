#include "gismuenumerator.h"
#include "collisiontable.h"

GismuEnumerator::GismuEnumerator()
{
    //ctor
    CollisionTable colTable;
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    ConsonantClusterTable conClusterTable;
    ConsonantTable conTable;
    InitialConsonantClusterTable initConTable;

    vector<string> clusterList = conClusterTable.getList();
    vector<char> conList = conTable.getList();
    vector<string> initClusterList = initConTable.getList();

    //CCVCV
    vector<string>::iterator clusterIter;
    vector<char>::iterator conIter;
    vector<string>::iterator initClusterIter;
    int i, j;
    string tempString;
    for (initClusterIter = initClusterList.begin(); initClusterIter != initClusterList.end(); initClusterIter++)
    {
        for (i = 0; i < 5; i++)
        {
            for (conIter = conList.begin(); conIter != conList.end(); conIter++)
            {
                for (j = 0; j < 5; j++)
                {
                    tempString.clear();
                    tempString += *initClusterIter;
                    tempString += vowels[i];
                    tempString += *conIter;
                    tempString += vowels[j];
                    m_allGismu.push_back(new Gismu(tempString, colTable));
                }
            }
        }
    }

    //CVCCV
    for (conIter = conList.begin(); conIter != conList.end(); conIter++)
    {
        for (i = 0; i < 5; i++)
        {
            for (clusterIter = clusterList.begin(); clusterIter != clusterList.end(); clusterIter++)
            {
                for (j = 0; j < 5; j++)
                {
                    tempString.clear();
                    tempString += *conIter;
                    tempString += vowels[i];
                    tempString += *clusterIter;
                    tempString += vowels[j];
                    m_allGismu.push_back(new Gismu(tempString, colTable));
                }
            }
        }
    }
}

GismuEnumerator::~GismuEnumerator()
{
    //dtor
    vector<Gismu*>::iterator iter;
    for (iter = m_allGismu.begin(); iter != m_allGismu.end(); iter++)
    {
        delete *iter;
    }
}

string GismuEnumerator::toString()
{
    string retString;
    vector<Gismu*>::iterator iter;
    for (iter = m_allGismu.begin(); iter != m_allGismu.end(); iter++)
    {
        retString += (*iter)->getName();
        retString += '\n';
    }
    return retString;
}

Gismu* GismuEnumerator::getRandomGismu()
{
    uniform_int_distribution<int> intDist(0, m_allGismu.size() - 1);
    return m_allGismu[intDist(m_gen)];
}

vector<Gismu*> GismuEnumerator::getList()
{
    return m_allGismu;
}

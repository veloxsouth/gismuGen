#include "initialconsonantclustertable.h"

InitialConsonantClusterTable::InitialConsonantClusterTable()
{
    //ctor
    //1-4
    m_initConClusters.push_back(string("bl"));
    m_initConClusters.push_back(string("br"));
    m_initConClusters.push_back(string("cf"));
    m_initConClusters.push_back(string("ck"));

    //5-8
    m_initConClusters.push_back(string("cl"));
    m_initConClusters.push_back(string("cm"));
    m_initConClusters.push_back(string("cn"));
    m_initConClusters.push_back(string("cp"));

    //9-12
    m_initConClusters.push_back(string("cr"));
    m_initConClusters.push_back(string("ct"));
    m_initConClusters.push_back(string("dj"));
    m_initConClusters.push_back(string("dr"));

    //13-16
    m_initConClusters.push_back(string("dz"));
    m_initConClusters.push_back(string("fl"));
    m_initConClusters.push_back(string("fr"));
    m_initConClusters.push_back(string("gl"));

    //17-20
    m_initConClusters.push_back(string("gr"));
    m_initConClusters.push_back(string("jb"));
    m_initConClusters.push_back(string("jd"));
    m_initConClusters.push_back(string("jg"));

    //21-24
    m_initConClusters.push_back(string("jm"));
    m_initConClusters.push_back(string("jv"));
    m_initConClusters.push_back(string("kl"));
    m_initConClusters.push_back(string("kr"));

    //25-28
    m_initConClusters.push_back(string("ml"));
    m_initConClusters.push_back(string("mr"));
    m_initConClusters.push_back(string("pl"));
    m_initConClusters.push_back(string("pr"));

    //29-32
    m_initConClusters.push_back(string("sf"));
    m_initConClusters.push_back(string("sk"));
    m_initConClusters.push_back(string("sl"));
    m_initConClusters.push_back(string("sm"));

    //33-36
    m_initConClusters.push_back(string("sn"));
    m_initConClusters.push_back(string("sp"));
    m_initConClusters.push_back(string("sr"));
    m_initConClusters.push_back(string("st"));

    //37-40
    m_initConClusters.push_back(string("tc"));
    m_initConClusters.push_back(string("tr"));
    m_initConClusters.push_back(string("ts"));
    m_initConClusters.push_back(string("vl"));

    //41-44
    m_initConClusters.push_back(string("vr"));
    m_initConClusters.push_back(string("xl"));
    m_initConClusters.push_back(string("xr"));
    m_initConClusters.push_back(string("zb"));

    //45-48
    m_initConClusters.push_back(string("zd"));
    m_initConClusters.push_back(string("zg"));
    m_initConClusters.push_back(string("zm"));
    m_initConClusters.push_back(string("zv"));
}

InitialConsonantClusterTable::~InitialConsonantClusterTable()
{
    //dtor
}

const vector<string>& InitialConsonantClusterTable::getList()
{
    return m_initConClusters;
}

bool InitialConsonantClusterTable::isValid(string var)
{
    vector<string>::iterator iter;
    for (iter = m_initConClusters.begin(); iter != m_initConClusters.end(); iter++)
    {
        if (var.compare(*iter) == 0)
            return true;
    }
    return false;
}

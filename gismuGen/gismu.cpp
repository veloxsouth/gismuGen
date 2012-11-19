#include "gismu.h"
#include <iostream>

Gismu::Gismu(string name, CollisionTable& colTable, InitialConsonantClusterTable& initConClusterTable, ConsonantClusterTable& conClusterTable)
    :m_colTable(colTable), m_name(name), m_isRetired(false)
{
    //ctor
    //cout << "Generating Gismu: " << m_name << endl;
    calcCollisions(initConClusterTable, conClusterTable);
}

Gismu::~Gismu()
{
    //dtor
}

bool Gismu::isColliding(Gismu& gismu)
{
    list<string>::iterator iter;
    if (!gismu.getName().compare(m_name))
        return true;
    for (iter = m_collisions.begin(); iter != m_collisions.end(); iter++)
    {
        if (!gismu.getName().compare(*iter))
            return true;
    }
    return false;
}

void Gismu::addToBlacklist()
{
    m_isRetired = true;
}

void Gismu::calcCollisions(InitialConsonantClusterTable& initConClusterTable, ConsonantClusterTable& conClusterTable)
{
    int i, j;
    vector<char> lerfuCollisions;
    string tempName;

    //stop short since no two gismu can differ only by their last vowel
    for (i = 0; i < (signed) m_name.length() - 1; i++)
    {
        //returns empty vector on vowels
        lerfuCollisions = m_colTable.getCollisions(m_name.at(i));

        for (j = 0; j < (signed) lerfuCollisions.size(); j++)
        {
            tempName = m_name;
            tempName.replace(i, 1, 1, lerfuCollisions[j]);
            if (Gismu::isValid(tempName, initConClusterTable, conClusterTable))
            {
                m_collisions.push_back(tempName);
                //cout << "collision calculated: " << tempName << endl;
            }
        }
    }

    //the only exception to this rule is broda-brodu
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    if (m_name.substr(0, 4).compare("brod"))
    {
        for (i = 0; i < 5; i++)
        {
            if (vowels[i] != m_name.at(4))
            {
                tempName = m_name;
                tempName.replace(4, 1, 1, vowels[i]);
                if (Gismu::isValid(tempName, initConClusterTable, conClusterTable))
                {
                    m_collisions.push_back(tempName);
                    //cout << "collision calculated: " << tempName << endl;
                }
            }
        }
    }
}

bool Gismu::isValid(string var, InitialConsonantClusterTable& initConClusterTable, ConsonantClusterTable& conClusterTable)
{
    //must be of the form ccvc or cvc/cv
    //where cc is a permissible initial consonant pair
    //where v is a vowel
    //where c/c is a permissible consonant pair

    //guard clause
    if (var.size() != 5)
        return false;

    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    //ccvcv
    char vowel;
    bool consonantsPass = false;
    bool firstVowelPass = false;
    bool secondVowelPass = false;
    if (initConClusterTable.isValid(var.substr(0, 2)))
    {
        consonantsPass = true;
        vowel = var.at(2);
    }

    if (conClusterTable.isValid(var.substr(2, 2)))
    {
        consonantsPass = true;
        vowel = var.at(1);
    }

    int i;
    for (i = 0; i < 5; i++)
    {
        if (vowel == vowels[i])
        {
            firstVowelPass = true;
            break;
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (var.at(4) == vowels[i])
        {
            secondVowelPass = true;
            break;
        }
    }

    return (consonantsPass && firstVowelPass && secondVowelPass);
}

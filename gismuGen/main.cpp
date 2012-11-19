#include <iostream>
#include "collisiontable.h"
#include "gismu.h"
#include "consonantclustertable.h"
#include "initialconsonantclustertable.h"
#include "gismuenumerator.h"
#include <algorithm>
#include <map>
#include "randFunctor.h"
#include <ctime>

using namespace std;

int test ();
unsigned int sim(GismuEnumerator& gismuEnum, randFunctor& myRand);

int main()
{
	mt19937 gen;
	randFunctor myRand(gen);
	time_t enumerationTime = time(NULL);
	cout << "Enumerating All Possible Gismu. This may take a while." << endl;
	ConsonantTable conTable;
	ConsonantClusterTable conClusterTable(conTable);
	InitialConsonantClusterTable initConClusterTable;
    GismuEnumerator gismuEnum(initConClusterTable, conClusterTable, conTable);
	enumerationTime = time(NULL) - enumerationTime;
	cout << enumerationTime << " seconds elapsed to generate enumeration." << endl;
    int i;
    int accum = 0;
    int temp;
	time_t iterStart = time(NULL);
	time_t iterCurrent;
    for (i = 0; i < 10000; i++)
    {
        cout << "Iteration: " << i + 1 << endl;
        temp = sim(gismuEnum, myRand);
        cout << "Dictionary Size: " << temp << endl;
        accum += temp;
        cout << "Running Avg: " << accum / (i + 1) << endl;
		iterCurrent = time(NULL);
		cout << "Avg iterations per second: ";
		if (iterCurrent != iterStart)
			cout << (double) (i + 1) / (double) (iterCurrent - iterStart) << endl;
		else
			cout << "undefined";
    }

    return 0;
}

int test (CollisionTable& colTable, InitialConsonantClusterTable initConClusterTable, ConsonantClusterTable conClusterTable)
{
    cout << "Letter collisions" << endl;
    cout << "not colliding :" << endl;
    cout << colTable.areLettersColliding('b', 'c') << endl;
    cout << colTable.areLettersColliding('c', 'x') << endl;
    cout << "colliding :" << endl;
    cout << colTable.areLettersColliding('b', 'p') << endl;
    cout << colTable.areLettersColliding('b', 'v') << endl;
    cout << colTable.areLettersColliding('g', 'x') << endl;

    Gismu gismu("gismu", colTable, initConClusterTable, conClusterTable);
    Gismu gicmu("gicmu", colTable, initConClusterTable, conClusterTable);
    Gismu zukte("zukte", colTable, initConClusterTable, conClusterTable);
    Gismu xicmu("xicmu", colTable, initConClusterTable, conClusterTable);
    Gismu broda("broda", colTable, initConClusterTable, conClusterTable);

    cout << "gismu collisions" << endl;
    cout << "not colliding :" << endl;
    cout << gismu.isColliding(zukte) << endl;
    cout << gismu.isColliding(xicmu) << endl;
    cout << "colliding :" << endl;
    cout << gismu.isColliding(gicmu) << endl;

    ConsonantTable conTable;
    vector<char> tempCharVec = conTable.getList();
    cout << "Consonants:" << endl;
    cout << "count: " << tempCharVec.size() << endl;
    int i;
    for (i = 0; i < (signed) tempCharVec.size(); i++)
    {
        cout << tempCharVec[i] << endl;
    }
    cout << endl;

    cout << "Consonant Clusters:" << endl;
    vector<string> tempVec = conClusterTable.getList();
    cout << "count: " << tempVec.size() << endl;

    for (i = 0; i < (signed) tempVec.size(); i++)
    {
        cout << tempVec[i] << endl;
    }
    cout << endl;

    InitialConsonantClusterTable initConTable;
    cout << "Initial Consonant Clusters:" << endl;
    tempVec = initConTable.getList();
    cout << "count: " << tempVec.size() << endl;
    for (i = 0; i < (signed) tempVec.size(); i++)
    {
        cout << tempVec[i] << endl;
    }
    cout << endl;

    list<string> collisions = gismu.getCollisions();
    list<string>::iterator iter;
    cout << gismu.getName() << ": " << endl;
    for (iter = collisions.begin(); iter != collisions.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << endl;

    collisions = zukte.getCollisions();
    cout << zukte.getName() << ": " << endl;
    for (iter = collisions.begin(); iter != collisions.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << endl;

    collisions = broda.getCollisions();
    cout << broda.getName() << ": " << endl;
    for (iter = collisions.begin(); iter != collisions.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << endl;

    return 0;
}

unsigned int sim(GismuEnumerator& gismuEnum, randFunctor& myRand)
{
    vector<Gismu*> gismuToAdd = gismuEnum.getList();
    map<string, Gismu*> gismuAccess;
    map<string, Gismu*> gismuAdded;
    //fill gismuToAdd into the lookup system
    vector<Gismu*>::iterator iter;
    for (iter = gismuToAdd.begin(); iter != gismuToAdd.end(); iter++)
    {
        gismuAccess.insert(pair<string, Gismu*>((*iter)->getName(), *iter));
    }

    //shuffle the list randomly to simulate words randomly being introduced into the dictionary
    random_shuffle(gismuToAdd.begin(), gismuToAdd.end(), myRand);

    int count = 0;
    //introduce words into dictionary, retiring collision-words before considering them
    for (iter = gismuToAdd.begin(); iter != gismuToAdd.end(); iter++)
    {
        if (!(*iter)->isRetired())
        {
            //if it isn't a retired word, consider it for adding to the dictionary

            //no need to check that it is not going to collide with any other words.
            //all additions to dictionary will retire collision words ahead of time

            gismuAdded.insert(pair<string, Gismu*>((*iter)->getName(), *iter));
            //cout << (*iter)->getName() << endl;
            count++;
            //retire all collision words associated with this word
            list<string> collisions = (*iter)->getCollisions();
            list<string>::iterator collisionIter;
            string collision;
            Gismu* gismuCollision;
            map<string, Gismu*>::iterator accessIter;
            pair<string, Gismu*> accessPair;
            for (collisionIter = collisions.begin(); collisionIter != collisions.end(); collisionIter++)
            {
                collision = *collisionIter;
                accessIter = gismuAccess.find(collision);
                accessPair = *accessIter;

                gismuCollision = accessPair.second;
                gismuCollision->addToBlacklist();
            }
        }
    }

	//return all gismu back to original state
    for (iter = gismuToAdd.begin(); iter != gismuToAdd.end(); iter++)
    {
		(*iter)->reset();
    }

    return count;
}
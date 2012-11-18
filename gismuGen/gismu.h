#ifndef GISMU_H
#define GISMU_H

#include <string>
#include <list>
#include "collisiontable.h"

using namespace std;

class Gismu
{
    public:
        Gismu(string name, CollisionTable& colTable);
        virtual ~Gismu();
        bool isColliding(Gismu& gismu);
        list<string> getCollisions(){return m_collisions;};
        void addToBlacklist();
        bool isRetired(){return m_isRetired;};
        string getName() {return m_name;};
        static bool isValid(string var);
		void reset(){m_isRetired = false;};
    protected:
        CollisionTable& m_colTable;
        string m_name;
        bool m_isRetired;
        list<string> m_collisions;
        void calcCollisions();
    private:
};

#endif // GISMU_H

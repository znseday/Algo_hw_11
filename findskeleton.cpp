#include <iostream>
#include <fstream>
#include <algorithm>

#include "findskeleton.h"

using namespace std;

std::ostream & operator<<(std::ostream &s, const Edge &e)
{
    s << "{" << e.v1 << "; " << e.v2 << "}";
    return s;
}

std::ostream & operator<<(std::ostream &s, const WeightEdge &we)
{
    s << "{" << static_cast<const Edge &>(we) << "; " << we.w << "}";
    return s;
}

bool operator<(const WeightEdge &we1, const WeightEdge &we2) // для сортировки
{
    return we1.w < we2.w;
}


bool FindSkeleton::LoadFromFile(const std::string &fn)
{
    ifstream f(fn);
    if (!f)
        return false;

    size_t ECount;
    f >> N >> ECount;

    Parents.reserve(N);
    for (size_t i = 0; i < N; ++i)
        Parents.emplace_back(i);

    Graph.reserve(ECount);

    int x, y; double w;

    for (size_t i = 0; i < ECount; ++i)
    {
        f >> x >> y >> w;
        Graph.emplace_back(x, y, w);
    }

    MY_DEBUG_ONLY(
        cout << "Src Graph:" << endl;
        for (const auto &we : Graph)
            cout << we << endl;
        cout << endl;
    )

    return true;
}
//---------------------------------------------------------

int FindSkeleton::Find(int i)
{
    if (Parents[i] == i)
        return i;
    else
        return Find(Parents[i]);
}
//---------------------------------------------------------

void FindSkeleton::Union(int x, int y)
{
    Parents[x] = Parents[y];
}
//---------------------------------------------------------

vector<Edge> FindSkeleton::FindKruskal()
{
    vector<Edge> res;

    sort(Graph.begin(), Graph.end());

    MY_DEBUG_ONLY(
        cout << "Sorted:" << endl;
        for (const auto &we : Graph)
            cout << we << endl;
        cout << endl;
    )

    int x, y;

    for (const auto &e : Graph)
    {
        x = Find(e.v1);
        y = Find(e.v2);
        if ( x != y)
        {
            res.emplace_back(e.v1, e.v2);
            Union(x, y);
        }
    }

    return res;
}
//---------------------------------------------------------

#ifndef FINDSKELETON_H
#define FINDSKELETON_H

#include <iostream>
#include <string>
#include <vector>

extern bool IsDebugOutput;

#define MY_DEBUG_ONLY(x) { if(IsDebugOutput) {x}  }

struct Edge // Согласно заданию
{
    int v1; int v2;
    Edge(int x, int y) : v1(x), v2(y) {}
};

struct WeightEdge : Edge // добавляем вес
{
    double w;
    WeightEdge(int x, int y, double _w) : Edge (x, y), w(_w) {}
};

std::ostream & operator<<(std::ostream &s, const Edge &e);
std::ostream & operator<<(std::ostream &s, const WeightEdge &we);
bool operator<(const WeightEdge &we1, const WeightEdge &we2); // для сортировки

class FindSkeleton
{
protected:

    std::vector<WeightEdge> Graph;
    size_t N = 0;

    std::vector<int> Parents;

    int Find(int i);
    void Union(int x, int y);

public:
    FindSkeleton() = default;

    bool LoadFromFile(const std::string &fn);

    ~FindSkeleton() = default;

    std::vector<Edge> FindKruskal();

};

#endif // FINDSKELETON_H

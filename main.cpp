#include <iostream>

using namespace std;

// Реализовать алгоритм нахождения минимального остовного дерева

// Реализовать алгоритм Краскала

// Задание:

// Реализовать алгоритм Краскала. Структура Union-Find собственной реализации.
// Если понадобится использование стека/очереди обязательно применение собственных структур данных из предыдущих занятий.
// Можно использовать стандартный массив [] встроенный в язык.

// Выходные данные: Результат должен быть представлен в виде массива Edge[] edges где Edge - класс,
// содержащий пару вершин, которые соединяет это ребро Edge { int v1; int v2; }

#include "findskeleton.h"

bool IsDebugOutput = true;

int main()
{
    FindSkeleton findSkeleton;

    if (!findSkeleton.LoadFromFile("test.txt"))
    {
        cerr << "file not found or can not be read" << endl;
        exit(0);
    }

    auto res = findSkeleton.FindKruskal();

    cout << "Skeleton:" << endl;
    for (const auto & e : res)
        cout << e << endl;
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

//--------------- MAX HEAPIFY ----------------//
void buildMaxHeap(vector<int>& a, int size, int root)
{
    int maxIndex = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l < size && a[l] > a[maxIndex])
        maxIndex = l;

    if (r < size && a[r] > a[maxIndex])
        maxIndex = r;

    if (maxIndex != root)
    {
        swap(a[root], a[maxIndex]);
        buildMaxHeap(a, size, maxIndex);
    }
}

//--------------- MAX HEAP SORT ----------------//
void heapSortMax(vector<int>& a)
{
    int size = a.size();

    for (int i = size / 2 - 1; i >= 0; --i)
        buildMaxHeap(a, size, i);

    for (int last = size - 1; last >= 1; --last)
    {
        swap(a[0], a[last]);
        buildMaxHeap(a, last, 0);
    }
}

//--------------- MIN HEAPIFY ----------------//
void buildMinHeap(vector<int>& a, int size, int root)
{
    int minIndex = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l < size && a[l] < a[minIndex])
        minIndex = l;

    if (r < size && a[r] < a[minIndex])
        minIndex = r;

    if (minIndex != root)
    {
        swap(a[root], a[minIndex]);
        buildMinHeap(a, size, minIndex);
    }
}

//--------------- MIN HEAP SORT ----------------//
void heapSortMin(vector<int>& a)
{
    int size = a.size();

    for (int i = size / 2 - 1; i >= 0; --i)
        buildMinHeap(a, size, i);

    for (int last = size - 1; last >= 1; --last)
    {
        swap(a[0], a[last]);
        buildMinHeap(a, last, 0);
    }

    reverse(a.begin(), a.end());
}

//--------------- MAIN FUNCTION ----------------//
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    srand(time(0));

    for (int i = 0; i < n; ++i)
    {
        data[i] = rand() % 100000;
    }

    vector<int> maxData = data;
    vector<int> minData = data;

    //--------------- MAX HEAP SORT TIME ----------------//
    auto maxStart = high_resolution_clock::now();

    heapSortMax(maxData);

    auto maxEnd = high_resolution_clock::now();

    //--------------- MIN HEAP SORT TIME ----------------//
    auto minStart = high_resolution_clock::now();

    heapSortMin(minData);

    auto minEnd = high_resolution_clock::now();

    //--------------- CALCULATE TIME ----------------//
    auto maxNano = duration_cast<nanoseconds>(maxEnd - maxStart);
    auto maxMicro = duration_cast<microseconds>(maxEnd - maxStart);

    auto minNano = duration_cast<nanoseconds>(minEnd - minStart);
    auto minMicro = duration_cast<microseconds>(minEnd - minStart);

    //--------------- DISPLAY RESULT ----------------//
    cout << "\n========== MAX HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << maxNano.count() << " ns\n";
    cout << "Microseconds : " << maxMicro.count() << " us\n";

    cout << "\n========== MIN HEAP SORT ==========\n";
    cout << "Nanoseconds  : " << minNano.count() << " ns\n";
    cout << "Microseconds : " << minMicro.count() << " us\n";

    return 0;
}
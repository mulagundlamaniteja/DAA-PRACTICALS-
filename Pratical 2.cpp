#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search using while loop
int linearSearch(vector<int> &arr, int key)
{
    int i = 0;

    while (i < arr.size())
    {
        if (arr[i] == key)
            return i;

        i++;
    }

    return -1;
}

// Recursive Binary Search
int binarySearch(vector<int> &arr, int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);

    return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    const int SIZE = 100000;

    vector<int> arr;

    // Create sorted array using push_back()
    for (int i = 1; i <= SIZE; i++)
        arr.push_back(i);

    int key;

    cout << "Enter the element to search: ";
    cin >> key;

    int position;

    // Linear Search
    auto start = high_resolution_clock::now();

    position = linearSearch(arr, key);

    auto stop = high_resolution_clock::now();

    cout << "\n----- Linear Search -----\n";

    if (position == -1)
        cout << "Element Not Found\n";
    else
        cout << "Element Found at Index : " << position << endl;

    cout << "Execution Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    // Binary Search
    start = high_resolution_clock::now();

    position = binarySearch(arr, 0, arr.size() - 1, key);

    stop = high_resolution_clock::now();

    cout << "\n----- Binary Search -----\n";

    if (position == -1)
        cout << "Element Not Found\n";
    else
        cout << "Element Found at Index : " << position << endl;

    cout << "Execution Time : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds\n";

    return 0;
}

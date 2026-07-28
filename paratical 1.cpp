#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// ------------------------------
// Bubble Sort
// ------------------------------
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

// ------------------------------
// Selection Sort
// ------------------------------
template <typename T>
void selectionSort(vector<T>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}

// ------------------------------
// Insertion Sort
// ------------------------------
template <typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// ------------------------------
// Merge Sort
// ------------------------------
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {

    vector<T> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[left + k] = temp[k];
}

template <typename T>
void mergeSortHelper(vector<T>& arr, int left, int right) {

    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

template <typename T>
void mergeSort(vector<T>& arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// ------------------------------
// Quick Sort
// ------------------------------
template <typename T>
int partition(vector<T>& arr, int low, int high) {

    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T>
void quickSortHelper(vector<T>& arr, int low, int high) {

    if (low < high) {

        int p = partition(arr, low, high);

        quickSortHelper(arr, low, p - 1);
        quickSortHelper(arr, p + 1, high);
    }
}

template <typename T>
void quickSort(vector<T>& arr) {

    if (!arr.empty())
        quickSortHelper(arr, 0, arr.size() - 1);
}

// ------------------------------
// Benchmark Function
// ------------------------------
template <typename T>
void benchmark(string name,
               void (*sortFunction)(vector<T>&),
               vector<T> data) {

    auto start = high_resolution_clock::now();

    sortFunction(data);

    auto stop = high_resolution_clock::now();

    auto timeTaken = duration_cast<microseconds>(stop - start);

    cout << left << setw(18) << name
         << ": "
         << setw(8)
         << timeTaken.count()
         << " microseconds"
         << endl;
}

// ------------------------------
// Main
// ------------------------------
int main() {

    const int SIZE = 1000;

    vector<int> numbers(SIZE);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10000);

    for (int& x : numbers)
        x = dist(gen);

    cout << "=========================================\n";
    cout << "      SORTING ALGORITHM COMPARISON\n";
    cout << "=========================================\n";
    cout << "Array Size : " << SIZE << endl;
    cout << "-----------------------------------------\n\n";

    benchmark<int>("Bubble Sort", bubbleSort<int>, numbers);
    benchmark<int>("Selection Sort", selectionSort<int>, numbers);
    benchmark<int>("Insertion Sort", insertionSort<int>, numbers);
    benchmark<int>("Merge Sort", mergeSort<int>, numbers);
    benchmark<int>("Quick Sort", quickSort<int>, numbers);

    cout << "\n=========================================\n";

    return 0;
}

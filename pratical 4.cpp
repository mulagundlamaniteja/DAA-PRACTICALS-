#include <iostream>  // Used for input and output
#include <chrono>   // Used to measure execution time

using namespace std;
using namespace std::chrono;

// Function to calculate factorial using iteration
unsigned long long factorialIterative(int n)
{
    unsigned long long result = 1;  // Stores factorial result
    int i = 1;  // Initialize counter

    // Repeat until i becomes greater than n
    while (i <= n)
    {
        result = result * i;  // Multiply result by current number
        i++;  // Increment counter
    }

    return result;  // Return factorial result
}

// Function to calculate factorial using recursion
unsigned long long factorialRecursive(int n)
{
    // Base condition to stop recursion
    if (n == 0 || n == 1)
        return 1;

    // Recursive call: multiply n by factorial of n-1
    return n * factorialRecursive(n - 1);
}

int main()
{
    int n;  // Stores the input number

    cout << "Enter a non-negative integer : ";

    // Read input and check whether it is valid
    if (!(cin >> n) || n < 0)
    {
        cout << "Invalid input! Please enter a non-negative integer." << endl;
        return 1;  // Terminate program for invalid input
    }

    // Measure Iterative Implementation
    auto startIter = high_resolution_clock::now();  // Start timer

    unsigned long long resIter = factorialIterative(n);  // Calculate factorial

    auto endIter = high_resolution_clock::now();  // Stop timer

    // Calculate iterative execution time in nanoseconds
    duration<double, nano> durationIter = endIter - startIter;

    // Measure Recursive Implementation
    auto startRec = high_resolution_clock::now();  // Start timer

    unsigned long long resRec = factorialRecursive(n);  // Calculate factorial

    auto endRec = high_resolution_clock::now();  // Stop timer

    // Calculate recursive execution time in nanoseconds
    duration<double, nano> durationRec = endRec - startRec;

    // Output Results
    cout << "\n--- Results for " << n << "! ---" << endl;

    cout << "Iterative Result : " << resIter << endl;  // Display iterative result
    cout << "Iterative Time   : " << durationIter.count() << " ns" << endl;

    cout << "-------------------------------" << endl;

    cout << "Recursive Result : " << resRec << endl;  // Display recursive result
    cout << "Recursive Time   : " << durationRec.count() << " ns" << endl;

    return 0;  // End program successfully
}

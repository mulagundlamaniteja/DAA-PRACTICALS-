#include <iostream>  // Used for input and output
#include <climits>   // Used for INT_MAX
using namespace std;

int n = 4;  // Total number of cities

// Cost matrix representing travel cost between cities
int cost[10][10] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[10] = {0};  // Keeps track of visited cities
int minCost = INT_MAX;  // Stores minimum travelling cost

// Recursive function to find minimum travelling cost
void tsp(int city, int count, int totalCost, int start)
{
    // Check whether all cities are visited
    // and whether there is a path back to starting city
    if (count == n && cost[city][start] != 0)
    {
        // Add the cost of returning to starting city
        int finalCost = totalCost + cost[city][start];

        // Update minimum cost if a smaller cost is found
        if (finalCost < minCost)
            minCost = finalCost;

        return;  // End current recursive call
    }

    // Check all available cities
    for (int i = 0; i < n; i++)
    {
        // Check whether city is not visited
        // and a direct path exists to that city
        if (!visited[i] && cost[city][i] != 0)
        {
            visited[i] = 1;  // Mark city as visited

            // Recursively visit the next city
            tsp(i, count + 1,
                totalCost + cost[city][i], start);

            visited[i] = 0;  // Backtrack: mark city as unvisited
        }
    }
}

int main()
{
    visited[0] = 1;  // Mark starting city (city 0) as visited

    // Start TSP from city 0
    // count = 1, totalCost = 0, start = 0
    tsp(0, 1, 0, 0);

    // Display the cost matrix
    cout << "Cost Matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << cost[i][j] << " ";

        cout << endl;  // Move to next row
    }

    // Check whether a valid tour exists
    if (minCost == INT_MAX)
        cout << "No possible tour exists.";
    else
        // Display minimum travelling cost
        cout << "Minimum travelling cost: " << minCost << endl;

    return 0;  // End program successfully
}
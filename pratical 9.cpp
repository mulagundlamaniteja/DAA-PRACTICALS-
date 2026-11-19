#include <iostream>  // Used for input and output
using namespace std;

int main()
{
    int n;  // Stores number of vertices

    cout << "Enter number of vertices: ";
    cin >> n;  // Read number of vertices

    int cost[10][10];  // Stores the cost/weight of edges

    cout << "Enter cost matrix:\n";

    // Read the cost matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int selected[10] = {0};  // Initially, all vertices are not selected
    selected[0] = 1;  // Start from vertex 0

    int edges = 0, total = 0;  // Count edges and calculate total cost

    cout << "Edges in Minimum Spanning Tree:\n";

    // Repeat until we get n-1 edges
    while (edges < n - 1)
    {
        int min = 9999;  // Initialize minimum cost
        int x = 0, y = 0;  // Store selected edge vertices

        // Check all vertices
        for (int i = 0; i < n; i++)
        {
            // Check only selected vertices
            if (selected[i])
            {
                // Check all adjacent vertices
                for (int j = 0; j < n; j++)
                {
                    // Find the minimum cost edge connecting
                    // a selected vertex to an unselected vertex
                    if (!selected[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];  // Update minimum cost
                        x = i;  // Store starting vertex
                        y = j;  // Store ending vertex
                    }
                }
            }
        }

        // Display the selected edge and its cost
        cout << x << " - " << y << " = " << min << endl;

        total += min;  // Add edge cost to total MST cost
        selected[y] = 1;  // Mark the new vertex as selected
        edges++;  // Increase edge count
    }

    // Display the minimum spanning tree cost
    cout << "Minimum cost = " << total;

    return 0;  // End the program
}

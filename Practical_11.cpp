#include <iostream>  // Used for input and output
using namespace std;

int main()
{
    int n = 4;  // Number of vertices in the graph

    // Cost matrix representing distances between vertices
    // 999 represents infinity (no direct connection)
    int dist[4][4] = {
        {0,   5,  999, 10},
        {999, 0,   3, 999},
        {999, 999, 0,   1},
        {999, 999, 999, 0}
    };

    // Select each vertex as an intermediate vertex
    for (int k = 0; k < n; k++)
    {
        // Select source vertex
        for (int i = 0; i < n; i++)
        {
            // Select destination vertex
            for (int j = 0; j < n; j++)
            {
                // Check whether the path through vertex k is shorter
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    // Update with the shorter distance
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Display the final shortest distance matrix
    cout << "Shortest distance matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Display INF if no path exists
            if (dist[i][j] == 999)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";  // Display shortest distance
        }
        cout << endl;  // Move to next row
    }

    return 0;  // End program successfully
}
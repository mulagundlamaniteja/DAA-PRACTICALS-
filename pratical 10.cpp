#include <iostream>   // Used for input and output
#include <algorithm> // Used for sorting edges

using namespace std;

// Structure to store edge details
struct Edge
{
    int u, v, w;  // u = source, v = destination, w = weight
};

// Function to sort edges in ascending order of weight
bool compare(Edge a, Edge b)
{
    return a.w < b.w;  // Smaller weight comes first
}

int parent[10];  // Stores parent of each vertex

// Find function to identify the parent of a vertex
int find(int x)
{
    if (parent[x] == x)
        return x;  // Return vertex if it is its own parent

    return find(parent[x]);  // Recursively find the parent
}

int main()
{
    int n, e;  // n = number of vertices, e = number of edges

    cout << "Enter number of vertices: ";
    cin >> n;  // Read number of vertices

    cout << "Enter number of edges: ";
    cin >> e;  // Read number of edges

    Edge edges[20];  // Array to store all edges

    cout << "Enter edges (u v weight):\n";

    // Read source, destination and weight of each edge
    for (int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    // Initially, every vertex is its own parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort all edges in ascending order of weight
    sort(edges, edges + e, compare);

    int total = 0, count = 0;  // Total MST cost and selected edge count

    cout << "Edges in Minimum Spanning Tree:\n";

    // Process edges until MST contains n-1 edges
    for (int i = 0; i < e && count < n - 1; i++)
    {
        // Find the parent of both vertices
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        // Check whether both vertices belong to different sets
        if (a != b)
        {
            // Print the selected edge and its weight
            cout << edges[i].u << " - "
                 << edges[i].v << " = "
                 << edges[i].w << endl;

            total += edges[i].w;  // Add edge weight to total cost

            parent[a] = b;  // Join both sets

            count++;  // Increase selected edge count
        }
    }

    // Display the total minimum spanning tree cost
    cout << "Minimum cost = " << total;

    return 0;  // End the program
}

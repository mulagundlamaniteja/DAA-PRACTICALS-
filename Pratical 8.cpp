#include <iostream>  // For input and output
#include <vector>    // For storing graph connections
#include <queue>     // For BFS queue
#include <chrono>    // For measuring execution time

using namespace std;
using namespace std::chrono;

// Class to represent a graph
class NetworkGraph {
    int totalNodes;  // Stores total number of vertices
    vector<vector<int>> adjacencyMatrix;  // Stores adjacent vertices (adjacency list)

public:

    // Constructor to initialize the graph
    NetworkGraph(int nodeCount) {
        totalNodes = nodeCount;
        adjacencyMatrix.resize(totalNodes);  // Create list for each vertex
    }

    // Function to connect two vertices
    void connectNodes(int sourceNode, int targetNode) {
        adjacencyMatrix[sourceNode].push_back(targetNode);
        adjacencyMatrix[targetNode].push_back(sourceNode);  // Remove this line for directed graph
    }

    // Recursive function to perform DFS
    void performDFSRecursive(int currentNode, vector<bool> &isVisited) {

        isVisited[currentNode] = true;  // Mark current vertex as visited
        cout << currentNode << " ";     // Print current vertex

        // Visit all adjacent vertices
        for (int adjacentNode : adjacencyMatrix[currentNode]) {

            // Check whether adjacent vertex is visited
            if (!isVisited[adjacentNode])
                performDFSRecursive(adjacentNode, isVisited);  // Recursive DFS call
        }
    }

    // Function to start DFS traversal
    void depthFirstSearch(int initialNode) {

        vector<bool> isVisited(totalNodes, false);  // Initially all vertices are unvisited

        performDFSRecursive(initialNode, isVisited);  // Start recursive DFS
    }

    // Function to perform BFS traversal
    void breadthFirstSearch(int initialNode) {

        vector<bool> isVisited(totalNodes, false);  // Initially all vertices are unvisited
        queue<int> processingQueue;  // Create a queue for BFS

        isVisited[initialNode] = true;  // Mark starting vertex as visited
        processingQueue.push(initialNode);  // Insert starting vertex into queue

        // Continue until the queue becomes empty
        while (!processingQueue.empty()) {

            int currentElement = processingQueue.front();  // Get front element
            processingQueue.pop();  // Remove front element from queue

            cout << currentElement << " ";  // Print current vertex

            // Visit all adjacent vertices
            for (int adjacentNode : adjacencyMatrix[currentElement]) {

                // Check whether adjacent vertex is unvisited
                if (!isVisited[adjacentNode]) {

                    isVisited[adjacentNode] = true;  // Mark as visited
                    processingQueue.push(adjacentNode);  // Insert into queue
                }
            }
        }
    }
};

// Main function
int main() {

    int nodeQuantity, connectionQuantity;  // Number of vertices and edges

    cout << "Enter number of vertices: ";
    cin >> nodeQuantity;  // Read number of vertices

    NetworkGraph myGraph(nodeQuantity);  // Create graph object

    cout << "Enter number of edges: ";
    cin >> connectionQuantity;  // Read number of edges

    cout << "Enter edges (u v):\n";

    // Read and connect all edges
    for (int index = 0; index < connectionQuantity; index++) {

        int firstEndpoint, secondEndpoint;
        cin >> firstEndpoint >> secondEndpoint;

        myGraph.connectNodes(firstEndpoint, secondEndpoint);  // Connect two vertices
    }

    int originNode;

    cout << "Enter starting vertex: ";
    cin >> originNode;  // Read starting vertex

    // DFS Time Analysis
    auto dfsStartTime = high_resolution_clock::now();  // Start DFS timer

    cout << "\nDFS Traversal: ";
    myGraph.depthFirstSearch(originNode);  // Perform DFS

    auto dfsEndTime = high_resolution_clock::now();  // Stop DFS timer

    // Calculate DFS execution time in nanoseconds
    auto totalDfsDuration =
        duration_cast<nanoseconds>(dfsEndTime - dfsStartTime);

    // BFS Time Analysis
    auto bfsStartTime = high_resolution_clock::now();  // Start BFS timer

    cout << "\n\nBFS Traversal: ";
    myGraph.breadthFirstSearch(originNode);  // Perform BFS

    auto bfsEndTime = high_resolution_clock::now();  // Stop BFS timer

    // Calculate BFS execution time in nanoseconds
    auto totalBfsDuration =
        duration_cast<nanoseconds>(bfsEndTime - bfsStartTime);

    // Display execution time of both algorithms
    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << totalDfsDuration.count() << " ns";
    cout << "\nBFS: " << totalBfsDuration.count() << " ns";

    return 0;  // End program
}

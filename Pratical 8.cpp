#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

class NetworkGraph {
    int totalNodes;
    vector<vector<int>> adjacencyMatrix;

public:
    NetworkGraph(int nodeCount) {
        totalNodes = nodeCount;
        adjacencyMatrix.resize(totalNodes);
    }

    void connectNodes(int sourceNode, int targetNode) {
        adjacencyMatrix[sourceNode].push_back(targetNode);
        adjacencyMatrix[targetNode].push_back(sourceNode);   // Remove this line for directed graph
    }

    void performDFSRecursive(int currentNode, vector<bool> &isVisited) {
        isVisited[currentNode] = true;
        cout << currentNode << " ";

        for (int adjacentNode : adjacencyMatrix[currentNode]) {
            if (!isVisited[adjacentNode])
                performDFSRecursive(adjacentNode, isVisited);
        }
    }

    void depthFirstSearch(int initialNode) {
        vector<bool> isVisited(totalNodes, false);
        performDFSRecursive(initialNode, isVisited);
    }

    void breadthFirstSearch(int initialNode) {
        vector<bool> isVisited(totalNodes, false);
        queue<int> processingQueue;

        isVisited[initialNode] = true;
        processingQueue.push(initialNode);

        while (!processingQueue.empty()) {
            int currentElement = processingQueue.front();
            processingQueue.pop();

            cout << currentElement << " ";

            for (int adjacentNode : adjacencyMatrix[currentElement]) {
                if (!isVisited[adjacentNode]) {
                    isVisited[adjacentNode] = true;
                    processingQueue.push(adjacentNode);
                }
            }
        }
    }
};

int main() {
    int nodeQuantity, connectionQuantity;

    cout << "Enter number of vertices: ";
    cin >> nodeQuantity;

    NetworkGraph myGraph(nodeQuantity);

    cout << "Enter number of edges: ";
    cin >> connectionQuantity;

    cout << "Enter edges (u v):\n";
    for (int index = 0; index < connectionQuantity; index++) {
        int firstEndpoint, secondEndpoint;
        cin >> firstEndpoint >> secondEndpoint;
        myGraph.connectNodes(firstEndpoint, secondEndpoint);
    }

    int originNode;
    cout << "Enter starting vertex: ";
    cin >> originNode;
s
    // DFS Time Analysis
    auto dfsStartTime = high_resolution_clock::now();
    cout << "\nDFS Traversal: ";
    myGraph.depthFirstSearch(originNode);
    auto dfsEndTime = high_resolution_clock::now();

    auto totalDfsDuration = duration_cast<nanoseconds>(dfsEndTime - dfsStartTime);

    // BFS Time Analysis
    auto bfsStartTime = high_resolution_clock::now();
    cout << "\n\nBFS Traversal: ";
    myGraph.breadthFirstSearch(originNode);
    auto bfsEndTime = high_resolution_clock::now();

    auto totalBfsDuration = duration_cast<nanoseconds>(bfsEndTime - bfsStartTime);

    cout << "\n\nExecution Time:";
    cout << "\nDFS: " << totalDfsDuration.count() << " ns";
    cout << "\nBFS: " << totalBfsDuration.count() << " ns";

    return 0;
}
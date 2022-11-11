#include <bits/stdc++.h>
using namespace std;

constexpr size_t maxNode = 100;
constexpr long long INF = 1e18;

// finds a path in parent and returns the maximum flow through that path
long long bfs(long long* graph, size_t source, size_t destination, size_t numberOfNodes, long* parent) {

    memset(parent, -1, sizeof(long)*maxNode);
    parent[source] = -2; // just marking as visited

    queue<pair<size_t, long long>> nextNode;
    nextNode.emplace(source, INF);

    while(!nextNode.empty()) {
        size_t from = nextNode.front().first;
        long long capacity = nextNode.front().second;
        nextNode.pop();
        for(size_t to = 0; to < numberOfNodes; to++) {
            if(graph[from*maxNode + to] && parent[to] == -1) {
                parent[to] = from;
                long long newCapacity = min(capacity, graph[from*maxNode + to]);
                if(to == destination)
                    return newCapacity;

                nextNode.emplace(to, newCapacity);
            }
        }
    }

    return 0;
}

long long edmondKarp(long long* graph, size_t source, size_t destination, size_t numberOfNodes) {
    long long flow = 0LL;
    long parent[maxNode];
    while(long long capacity = bfs(graph, source, destination, numberOfNodes, parent)) {
        flow += capacity;
        for(size_t to = destination; to != source; to = parent[to]) {
            size_t from = parent[to];
            graph[from*maxNode + to] -= capacity; // forward edge
            graph[to*maxNode + from] += capacity; // backward edge
        }
    }

    return flow;
}

int main() {

    for(size_t networkNumber = 1; true; networkNumber++) {
        size_t numberOfNodes;
        cin >> numberOfNodes;

        if(!numberOfNodes)
            break;

        // mapping the matrix into a 1D array
        // network[i][j] = network[i*maxNode + j]
        long long network[maxNode*maxNode];

        // Reset the network
        memset(network, 0, sizeof(network));

        size_t source, destination, numberOfConnections;
        cin >> source >> destination >> numberOfConnections;

        while(numberOfConnections--) {
            size_t node1, node2;
            long long bandwidth;
            cin >> node1 >> node2 >> bandwidth;

            node1--; node2--; // transform into a zero-indexed graph

            // network[node1][node2] = bandwidth
            network[node1*maxNode + node2] += bandwidth;
            // network[node2][node1] = bandwidth
            network[node2*maxNode + node1] += bandwidth;
        }

        cout << "Network " << networkNumber << '\n';
        cout << "The bandwidth is " << edmondKarp(network, --source, --destination, numberOfNodes) << ".\n\n";

    }
    return 0;
}
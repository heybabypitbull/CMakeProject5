#include "Graph.h"

Graph::Graph(int V) : V(V), adj(V), disc(V, -1), low(V, -1), parent(V, -1), time(0) {}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::articulationDFS(int u) {
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            parent[v] = u;
            children++;
            articulationDFS(v);

            low[u] = std::min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                articulationPoints.insert(u);
            if (parent[u] != -1 && low[v] >= disc[u])
                articulationPoints.insert(u);
        }
        else if (v != parent[u]) {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

void Graph::findArticulationPoints() {
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            articulationDFS(i);
        }
    }
}

void Graph::printArticulationPoints(std::ofstream& outputFile) {
    outputFile << "Articulation points: ";
    for (int ap : articulationPoints) {
        outputFile << ap << " ";
    }
    outputFile << std::endl;
}
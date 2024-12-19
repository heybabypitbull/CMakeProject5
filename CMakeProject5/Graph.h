#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> disc, low, parent;
    std::set<int> articulationPoints;
    int time;

    void articulationDFS(int u);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void findArticulationPoints();
    void printArticulationPoints(std::ofstream& outputFile);
};
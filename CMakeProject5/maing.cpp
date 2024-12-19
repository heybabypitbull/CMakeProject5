#include "Graph.h"

int main() {
    setlocale(LC_ALL, "RU");
    std::ifstream inputFile("C:/Users/stank/Desktop/input1.txt");
    std::ofstream outputFile("C:/Users/stank/Desktop/output1.txt");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка открытия файлов." << std::endl;
        return 1;
    }
    int V;
    inputFile >> V;
    inputFile.ignore();
    Graph g(V);
    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        int u, v;
        ss >> u >> v;
        g.addEdge(u, v);
    }

    g.findArticulationPoints();
    g.printArticulationPoints(outputFile);

    inputFile.close();
    outputFile.close();
    return 0;
}
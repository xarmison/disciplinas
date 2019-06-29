#include <iostream>
#include <list>
using namespace std;

struct Vertex {
    int label;
    bool visited;
};

struct Graph {
    int nVertices;
    list<int> *adjList;
};


// Adiciona a aresta (u, v) no grafo
void addEdge(Graph *graph, int u, int v) {
    graph->adjList[u].push_back(v);
    //graph->adjList[v].push_back(u);
}

void depthFirstSearch(Graph *graph, int v, bool *visited) {
    visited[v] = true; 
    cout << v << " "; 
  
    list<int>::iterator i; 
    for (i = graph->adjList[v].begin(); i != graph->adjList[v].end(); ++i)
        if (!visited[*i]) 
            depthFirstSearch(graph, *i, visited);
}

void printGraph(Graph *graph) {
    for(int v = 0; v < graph->nVertices; v++) {
        cout << v << ": ";

        list<int>::iterator i; 
        for (i = graph->adjList[v].begin(); i != graph->adjList[v].end(); i++) {
            cout << *i << " ";
        } 
        
        cout << endl;
    }    
}


int main(int argc, char **argv) {
    // Instância um grafo
    Graph graph;
    graph.nVertices = 6;
    graph.adjList = new list<int>[6];

    // Adiciona as arestas
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 2);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 0);
    addEdge(&graph, 5, 1);

    bool *visited = new bool[graph.nVertices]; 
    for (int i = 0; i < graph.nVertices; i++) {
        visited[i] = false; 
    }

    cout << "Grafo\n";
    printGraph(&graph);

    cout << "\nBusca em profundidade a partir de 3: ";
    depthFirstSearch(&graph, 3, visited);
    cout << endl;

    return 0;
}
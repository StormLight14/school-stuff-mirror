#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

template <typename Type>
class Graph;

template <typename Type>
ostream& operator<<(ostream &out, const Graph<Type> &g);

template <typename Type>
class Graph {
private:
    vector<Type> vertices;
    vector<vector<Type>> edges;

public:
    Graph();
    void addVertex(Type vertex);
    void addEdge(Type source, Type target);
    int getVertexPos(Type item);
    int getNumVertices() const;
    bool isEdge(Type source, Type target);
    friend ostream& operator<< <>(ostream &out, const Graph<Type> &g);
    vector<Type> getPath(Type source, Type target);
};

/*********************************************
* Constructs an empty graph
*
*********************************************/
template<typename Type>
Graph<Type>::Graph() {}

/*********************************************
* Adds a Vertex to the Graphs. Note that the vertex may not be an int value
*********************************************/
template <typename Type>
void Graph<Type>::addVertex(Type vertex) {
    vertices.push_back(vertex);
    vector<Type> list;
    edges.push_back(list);
}

/*********************************************
* Returns the current number of vertices
*
*********************************************/
template<typename Type>
int Graph<Type>::getNumVertices() const {
    return vertices.size();
}

/*********************************************
* Returns the position in the vertices list where the given vertex is located, -1 if not found.
*
*********************************************/
template <typename Type>
int Graph<Type>::getVertexPos(Type item) {
    for (unsigned int i = 0; i < vertices.size(); i++) {
        if (item == vertices[i]) {
            return i;
        }
    }
    return -1;
}

/*********************************************
* Adds an edge going in the direction of source going to target
*
*********************************************/
template <typename Type>
void Graph<Type>::addEdge(Type source, Type target) {
    int srcPos = getVertexPos(source);
    if (srcPos < 0) {
        throw runtime_error("Vertex not found.");
    }
    edges[srcPos].push_back(target);
}

template <typename Type>
bool Graph<Type>::isEdge(Type source, Type target) {
    int srcPos = getVertexPos(source);
    if (srcPos < 0) {
        throw runtime_error("Vertex not found.");
    }
    for (unsigned int i = 0; i < edges[srcPos].size(); i++) {
        if (edges[srcPos][i] == target) {
            return true;
        }
    }
    return false;
}

/*********************************************
* Returns a display of the graph in the format
* vertex: edge edge
* Note: This is not a traversal, just output
*********************************************/
template <typename Type>
ostream& operator<<(ostream &out, const Graph<Type> &g) {
    for (unsigned int i = 0; i < g.vertices.size(); i++) {
        out << g.vertices[i] << ": ";
        for (unsigned int e = 0; e < g.edges[i].size(); e++) {
            out << g.edges[i][e] << " ";
        }
        out << endl;
    }
    return out;
}

template <typename Type>
vector<Type> Graph<Type>::getPath(Type source, Type target) {
    vector<Type> solution;
    if (getVertexPos(source) == -1 || getVertexPos(target) == -1) {
        return solution; // Return empty solution if source or target is not found
    }

    unordered_map<Type, Type> parent;
    unordered_map<Type, bool> visited;
    queue<Type> q;

    q.push(source);
    visited[source] = true;
    parent[source] = source;

    while (!q.empty()) {
        Type current = q.front();
        q.pop();

        if (current == target) {
            break;
        }

        for (const Type& neighbor : edges[getVertexPos(current)]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (visited[target]) {
        for (Type at = target; at != source; at = parent[at]) {
            solution.push_back(at);
        }
        solution.push_back(source);
        reverse(solution.begin(), solution.end());
    }

    return solution;
}

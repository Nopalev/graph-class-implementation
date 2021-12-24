#include<bits/stdc++.h>
using namespace std;

class unweighted_graph{
    private:
    long vertex, edge;
    vector<vector<long>> adjList;
    bool isDirected;
    void depth_first_search(long vertex, vector<bool> &visited, vector<long> &v);
    void breadth_first_search(long vertex, vector<bool> &visited, vector<long> &v);

    public:
    unweighted_graph(long vertex, bool isDirected);
    void addEdge(long vertex1, long vertex2);
    long edgeCount();
    void dfs(long vertex, vector<long> &v);
    void bfs(long vertex, vector<long> &v);
};

unweighted_graph::unweighted_graph(long vertex, bool isDirected){
    this->vertex = vertex;
    this->edge = 0;
    this->isDirected = isDirected;
    for(long i = 0; i < vertex; i++){
        adjList.push_back({});
    }
}

void unweighted_graph::addEdge(long vertex1, long vertex2){
    adjList[vertex1].push_back(vertex2);
    if(!isDirected) adjList[vertex2].push_back(vertex1);
    edge++;
}

long unweighted_graph::edgeCount(){
    return edge;
}

void unweighted_graph::dfs(long vertex, vector<long> &v){
    vector<bool> visited(this->vertex, false);
    v.clear();
    depth_first_search(vertex, visited, v);
}

void unweighted_graph::depth_first_search(long vertex, vector<bool> &visited, vector<long> &v){
    visited[vertex] = true;

    v.push_back(vertex);

    for(auto it : adjList[vertex]){
        if(!visited[it]) depth_first_search(it, visited, v);
    }
}

void unweighted_graph::bfs(long vertex, vector<long> &v){
    vector<bool> visited(this->vertex, false);
    v.clear();
    breadth_first_search(vertex, visited, v);
}

void unweighted_graph::breadth_first_search(long vertex, vector<bool> &visited, vector<long> &v){
    queue<long> q;
    q.push(vertex);
    visited[vertex] = true;

    v.push_back(vertex);

    while(!q.empty()){
        long temp = q.front();
        q.pop();
        for(auto it : adjList[temp])if(!visited[it]){
            q.push(it);
            visited[it] = true;
            v.push_back(it);
        }
    }
}
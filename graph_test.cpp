#include<bits/stdc++.h>
#include "unweighted_graph.h"
using namespace std;

int main(){
    vector<long> transversal;
    unweighted_graph graph = unweighted_graph(5, false);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(3, 0);
    graph.addEdge(0, 4);
    graph.addEdge(2, 4);
    graph.dfs(2, transversal);
    for(auto it : transversal) cout << it << "\n";
    graph.bfs(2, transversal);
    for(auto it : transversal) cout << it << "\n";
    return 0;
}
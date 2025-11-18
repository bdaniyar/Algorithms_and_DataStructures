#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_list(int start, const vector<vector<int>>& graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int u: graph[v]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}


void bfs_matrix(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int v = q.front();
        q.pop();
        cout << v << " ";  // если нужно только вершины
        for(int u = 0; u < n; u++) {
            if(graph[v][u] == 1 && !visited[u]) { // есть ребро и не посещена
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {0,3},
        {0,3},   
        {1,2}  
    };

    bfs_list(0,graph);
}
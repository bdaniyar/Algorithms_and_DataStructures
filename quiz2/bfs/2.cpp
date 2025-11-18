#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph){
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

void bfs2(int start, const vector<vector<int>>& graph){
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

void bfs3(int start, vector<vector<int>>& graph){
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
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 1e4 + 5;

int n, u , v, farNode = 0, longestPath = 0;
vector<int> adj[N];
bool vis[N];

void DFS(int src, int length) {
    vis[src] = true;
    if (longestPath < length){
        longestPath = length;
        farNode = src;
    }
    for (int u : adj[src]){
        if (!vis[u]){
            DFS(u, length + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1;i < n; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    memset(vis, 0, sizeof vis);
    DFS(farNode, 0);
    printf("%d", longestPath);
}
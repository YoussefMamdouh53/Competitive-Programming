#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 2e2 + 5, M = 1e6 + 5;
int n, m, u, v;
vector<int> adjList[N];
int color[N];

bool BFS(int a) {
    color[a] = 1;
    queue<int> q;
    q.push(a);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adjList[u]){
            if (color[v] == 0){
                color[v] = color[u] == 1 ? 2 : 1;
                q.push(v);
            }
            else if (color[v] == color[u]){
                return true;
            }
        }
    }
    return false;
}

void init() {
    for (int i = 0;i < N; i++){
        adjList[i].clear();
        color[i] = 0;
    }
}
int main() {
    while (scanf("%d", &n), n){
        init();
        scanf("%d", &m);
        for (int i = 1; i <= m; i++){
            scanf("%d %d", &u, &v);
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        puts(BFS(0) ? "NOT BICOLORABLE." : "BICOLORABLE.");
    }
}
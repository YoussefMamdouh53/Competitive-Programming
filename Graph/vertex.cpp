#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int N = 105;
vector<int> edges[N];
int n, u, v, q;
bool visited[N];

// void BFS(int start) {
//     memset(visited, false, sizeof visited);
//     queue<int> q;
//     q.push(start);
//     while (!q.empty()){
//         int u = q.front();
//         q.pop();
//         for (int v : edges[u])
//             if (!visited[v]){
//                 q.push(v);
//                 visited[v] = true;
//             }

//     }
// }

void DFS(int start) {
    if (start != u) visited[start] = true;
    for (int v : edges[start]){
        if (!visited[v]) {
            DFS(v);
        }
        if (v == u) visited[u] = true;
    }
}

int main() {
    while (cin >> n, n){
        while (cin >> u, u) {
            while (cin >> v, v) {
                edges[u].push_back(v);
            }
        }
        cin >> q;
        while (q--) {
            cin >> u;
            DFS(u);
            int cnt = 0;
            for (int i = 1;i<=n;i++){
                if (!visited[i]) cnt++;
            }
            cout << cnt;
            for (int i = 1;i<=n;i++){
                if (!visited[i]) 
                    cout << " " << i;
            }
            cout << endl;
            memset(visited, false, sizeof visited);
        }
        for (int i = 1;i<N;i++) edges[i].clear();
    }
}
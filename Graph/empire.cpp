#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t, n, u , v, d, k;

const int N = 1e5 + 5;
vector<int> adj[N];
int dis[N];

void BFS() {
    queue<int> q;
    q.push(u);
    while (q.empty() && k--){
        int a = q.front();
        q.pop();
        dis[a]++;

    }
}

void reset() {
    for (int i = 1;i<N;i++) {
        dis[i] = 0;
        adj[i].clear();
    }
}

int main() {
    cin >> t;
    while (t--){
        reset();
        cin >> n;
        for (int i = 1;i<= n;i++){
            cin >> u >> v;
            if (v > u) swap(u, v);
            adj[u].push_back(v);
            //adj[v].push_back(u);
        }
        for (int i = 1;i<=n;i++){
            sort(adj[i].begin(), adj[i].end());
        }
        cin >> d;
        for (int i = 1;i<=d;i++){
            cin >> u >> k;
            BFS();
        }
        for (int i = 1; i<=n;i++){
            cout << dis[i] << " ";
        }
        cout << endl;
    }
}
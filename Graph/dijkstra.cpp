#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const int V = 30;
const int INF = 0x3f3f3f3f;

map<char, int> mp;
vector<pair<int,int>> adjList[N];

int dijkstra(int src, int target) {
    vector<int> dist(V, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto v : adjList[u]){
            if (dist[v.second] > dist[u] + v.first) {
                dist[v.second] = dist[u] + v.first; 
                pq.push({-dist[v.second], v.second});
            }
        }
    }
    return dist[target];
}

int main() {
    int n, e, c, id = 0;
    char u, v;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> c;
        if (mp.count(u) < 1)
        {
            mp[u] = id++;
        }
        if (mp.count(v) < 1)
        {
            mp[v] = id++;
        }
        adjList[mp[u]].push_back({c, mp[v]});
        adjList[mp[v]].push_back({c, mp[u]});
    }
    cout << dijkstra(mp['A'], mp['B']);
}

/*

20 23
A Z 75
A T 118
Z O 71
O S 151
A S 140
T L 111
L M 70
M D 75
D C 120
C R 146
R S 80
C P 138
P R 97
P B 101
S F 99
F B 211
B G 90
B U 85
U H 98
H E 86
U V 14
V I 92
I N 87

*/
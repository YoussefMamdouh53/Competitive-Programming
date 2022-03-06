#include <bits/stdc++.h>

using namespace std;

const int N = 25;

map<char, int> mp;
map<int, char> lookup;
vector<pair<int, int>> adjList[N];
bool vis[N];

void uniform_cost_search(int u, int dest)
{
    priority_queue<pair<int,vector<int>>> pq;
    vector<int> p;
    p.push_back(u);
    pq.push({0,p});
    while (!pq.empty())
    {
        pair<int,vector<int>> path = pq.top();
        pq.pop();
        vis[path.second.back()] = true;

        if (path.second.back() == dest)
        {
            for (auto x : path.second)
            {
                cout << lookup[x] << ' ';
            }
            cout << " - Cost = " << -path.first << endl;
        }

        for (pair<int, int> x : adjList[path.second.back()])
        {
            if (vis[x.second])
                continue;
            // Add new node
            path.second.push_back(x.second);
            // sum cost of new node
            path.first -= x.first;
            pq.push(path);
            // undo last action for new action
            path.second.pop_back();
            path.first += x.first;
        }
    }
}

int main()
{
    int n, e, c, id = 0;
    char u, v;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> c;
        if (mp.count(u) < 1)
        {
            mp[u] = id++;
            lookup[id - 1] = u;
        }
        if (mp.count(v) < 1)
        {
            mp[v] = id++;
            lookup[id - 1] = v;
        }
        adjList[mp[u]].push_back({c, mp[v]});
        adjList[mp[v]].push_back({c, mp[u]});
    }
    uniform_cost_search(mp['A'], mp['B']);
}

/*
INPUT:

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
U V 142
V I 92
I N 87

*/

/*
OUTPUT:

A S R P B  - Cost = 418
A S F B  - Cost = 450

*/
// ACCEPTED 70ms 8.6MB

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 5e4 + 5;
int t, n, u, v, c, farNode = 0;
long longestPath = 0;

vector<pair<int, int>> adj[N];
bool vis[N];

void DFS(int src, long length)
{
    vis[src] = true;
    if (longestPath < length)
    {
        longestPath = length;
        farNode = src;
    }
    for (auto u : adj[src])
    {
        if (!vis[u.first])
        {
            DFS(u.first, length + u.second);
        }
    }
}

void init()
{
    for (int i = 1; i < N; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
        farNode = 0;
        longestPath = 0;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        init();
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        DFS(1, 0);
        memset(vis, false, sizeof vis);
        DFS(farNode, 0);
        printf("%ld\n", longestPath);
    }
}
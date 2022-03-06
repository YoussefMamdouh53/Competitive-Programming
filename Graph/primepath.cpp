#include <iostream>
#include <list>
#include <bitset>
#include <queue>
#include <cstring>

using namespace std;
const int N = 10000, INF = 0x3f3f3f3f;
int t, u, v, dist[N];

list<int> adj[N];
bitset<N> not_prime;

void sieve()
{
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i * i <= 10000; i++)
    {
        if (!not_prime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                not_prime[j] = true;
            }
        }
    }
}

bool one_change(int a, int b)
{
    int cnt = 0;
    while (a > 0 && b > 0)
    {
        if (a % 10 != b % 10)
            cnt++;
        a /= 10;
        b /= 10;
    }
    return cnt == 1;
}

void init()
{
    for (int i = 1000; i < 10000; i++)
    {
        if (!not_prime[i])
        {
            for (int j = i + 1; j < 10000; j++)
            {
                if (!not_prime[j] && one_change(i, j))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    }
}

void BFS(int src, int dst)
{
    memset(dist, INF, sizeof dist);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == INF)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
            }
            if (v == dst){
                printf("%d\n", dist[dst]);
                return;
            }
        }
    }
    puts("Impossible");
}

int main()
{
    scanf("%d", &t);
    sieve();
    init();
    while (t--)
    {
        scanf("%d %d", &u, &v);
        BFS(u, v);
    }
}
// ACCEPTED 10ms

#include <iostream>
#include <cstring>
#include <queue>
#include <list>

using namespace std;

const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;
int t, n;
char u[3], v[3];
list<pair<int, int>> adj[8][8];
int visited[8][8];

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isvalid(int x, int y)
{
    return x < 8 && x > -1 && y < 8 && y > -1;
}

void init()
{
    visited[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> k = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int x = k.first + dx[i];
            int y = k.second + dy[i];
            if (isvalid(x, y) && visited[x][y] != VISITED)
            {
                if (visited[x][y] != IN_PROGRESS)
                    q.push({x, y});
                visited[x][y] = IN_PROGRESS;
                adj[k.first][k.second].push_back({x, y});
                adj[x][y].push_back({k.first, k.second});
            }
        }
        visited[k.first][k.second] = VISITED;
    }
}

int solve(int a, int b, int x, int y)
{
    if (a == x && b == y)
        return 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = 0;
    while (!q.empty())
    {
        pair<int, int> k = q.front();
        q.pop();
        for (auto i : adj[k.first][k.second])
        {
            if (visited[i.first][i.second] == 0)
            {
                q.push(i);
                visited[i.first][i.second] = visited[k.first][k.second] + 1;
            }
            if (i.first == x && i.second == y) return visited[i.first][i.second];
        }
    }
    return -1;
}

int main()
{
    init();
    scanf("%d", &n);
    for (t = 1; t <= n; t++)
    {
        memset(visited, NOT_VISITED, sizeof visited);
        scanf("%s %s", u, v);
        printf("%d\n", solve(u[0] - 'a', u[1] - '1', v[0] - 'a', v[1] - '1'));
    }
}
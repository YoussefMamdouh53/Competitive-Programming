//ACCEPTED 40ms 5.3MB
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 190, INF = 0x3f3f3f3f;

int t, n, m, dist[N][N];
char a[N][N];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isvalid(int x,int y){
    return (x < n && y < m && x > -1 && y > -1);
}

void fill()
{
    memset(dist, INF, sizeof dist);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '1')
            {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0;i<4;i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (isvalid(x,y) && dist[x][y] == INF){
                dist[x][y] = dist[p.first][p.second] + 1;
                q.push({x,y});
            }
        }
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%s", a[i]);
        fill();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
    }
}
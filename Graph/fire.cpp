// ACCEPTED 218ms

#include <iostream>
#include <queue>

using namespace std;

const int N = 2e3 + 5;

int a[N][N], n, m, k, mx = -1;
queue<pair<int,int>> q;
pair<int, int> ans;

bool isvalid(int x, int y) {
    return x > 0 && x <= n && y <= m && y > 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    while (k--){
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        q.push({x, y});
    }
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    ans = q.front();
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        for (int i = 0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (isvalid(nx,ny) && a[nx][ny] == 0) {
                a[nx][ny] = a[p.first][p.second] + 1;
                q.push({nx,ny});
                if (a[nx][ny] > mx){
                    ans = {nx,ny};
                    mx = a[nx][ny];
                }
            }
        }
    }
    printf("%d %d\n", ans.first, ans.second);
}
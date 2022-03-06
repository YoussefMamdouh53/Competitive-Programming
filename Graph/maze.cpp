#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 25, NOT_VISITED = 0, VISITED = 1, BLOCK = 2;

int grid[N][N];

char c;
int n, m, t;
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
pair<int,int> e;

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m;
}

bool dfs(int x, int y){
    if (x == e.first && y == e.second) return true;
    grid[x][y] = VISITED;
    for (int i = 0;i<4;i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if (isvalid(a,b) && grid[a][b] != BLOCK) {
            if (grid[a][b] == NOT_VISITED){
                if (dfs(a,b)) return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> t;
    while (t--){
        cin >> n >> m;
        queue<pair<int,int>> q;
        for (int i = 0; i <n;i++){
            for (int j = 0;j<m;j++){
                cin >> c;
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && c == '.') {
                    q.push({i,j});
                }
                if (c=='#') grid[i][j] = BLOCK;
            }
        } 
        if (q.size() == 2) {
            e = q.front();
            q.pop();
            grid[q.front().first][q.front().second] = 1;
            if (dfs(q.front().first, q.front().second))
                puts("valid");
            else 
                puts("invalid");
            
        }
        else {
            puts("invalid");
        }
        memset(grid, NOT_VISITED, sizeof grid);
    }
}
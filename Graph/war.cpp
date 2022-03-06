#include <iostream>
#include <cstring>

using namespace std;

const int N = 30;
char grid[N][N];
bool vis[N][N];
int t = 1, n;

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {1,0,-1,1,-1,-1,0,1};

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < n;
}
void DFS(int i, int j) {
    vis[i][j] = true;
    for (int k = 0;k<8;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if (!vis[x][y] && grid[x][y] == '1'){
            DFS(x,y);
        }
    }
}
int main() {
    while (cin >> n){
        for (int i = 0;i < n; i++){
            cin >> grid[i];
        }
        int wars = 0;
        for (int i = 0;i<n;i++){
            for (int j = 0;j<n;j++){
                if (grid[i][j] == '1' && !vis[i][j]) {
                    DFS(i, j);
                    wars++;
                }
            }
        }
        cout << "Image number " << t++ << " contains " << wars << " war eagles." << endl;
        memset(vis, 0, sizeof vis);
    }
}
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int grid[100][100];
// int cnt = 0;
typedef long long ll;

ll grid_traveler(int x, int y) {
    if (x == 1 && y == 1) return 1;
    if (x == 0 || y == 0 || g[x-1][y-1] == 1) return 0;
    if (grid[x][y] > 0 ) return grid[x][y];
    return grid[x][y] = grid_traveler(x-1,y) + grid_traveler(x,y-1);
}

int main() {
    //memset(grid, -1, sizeof grid);
    int n = 2, m = 2;
    cout << grid_traveler(n, m) << endl << endl;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
           printf("%-8d ", grid[i][j]);
        }
        cout << endl;
    }
    // cerr << "Recurisve calls count: " << cnt << endl;
}

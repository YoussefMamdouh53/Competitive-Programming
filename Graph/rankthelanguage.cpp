#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e4;

char grid[N][N];
int vis[N][N];

int n, m, t;
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};

bool isvalid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m;
}

void dfs(int x, int y) {
    vis[x][y] = t;
    for (int i = 0;i<4;i++){
        int a = x + dx[i];
        int b = y + dy[i];
        if (isvalid(a,b) && vis[a][b] != t && grid[a][b] == grid[x][y]){
            dfs(a,b);
        }
    }
}

int main() {
    int k = 1;
    scanf("%d", &t);
    while (t){
        map<char,int> mp;
        scanf("%d %d", &n, &m);
        for (int i = 0;i<n;i++){
            scanf("%s", grid[i]);
        }
        for (int i = 0;i<n;i++){
            for (int j = 0; j < m;j++){
                if (vis[i][j] != t){
                    dfs(i,j);
                    mp[grid[i][j]]++;
                }
            }
        }
        printf("World #%d\n", k++);
        vector<pair<int,char>> v;
        for (auto i : mp) {
            v.push_back({-i.second,i.first});
        }
        sort(v.begin(),v.end());
        for (auto i : v){
            printf("%c: %d\n", i.second, -i.first);
        }
        t--;
    }
}
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e3 + 5;
int dp[N][N];

// void debug(int x = N,int y = N) {
//     for (int i = 1;i<=x;i++){
//         for (int j = 1;j<=y;j++){
//             printf("%-5d", dp[i][j]);
//         }
//         cout << endl;
//     }
// }

int lcs(string &a, string &b) {
    memset(dp, 0, sizeof dp);
    int sz_a = a.size();
    int sz_b = b.size();
    if (sz_a == 0 || sz_b == 0) return 0;
    for (int i = 1;i<=sz_a;i++){
        for (int j = 1; j<=sz_b;j++){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    } 

    return dp[sz_a][sz_b];
}

// int lcs2(string a, string b) {
//     memset(dp, 0, sizeof dp);
//     int sz_a = a.size();
//     int sz_b = b.size();
//     int best = 0;
//     for (int i = 1;i<=sz_a;i++){
//         for (int j = 1; j<=sz_b;j++){
//             if (a[i-1] == b[j-1]) {
//                 dp[i][j] = dp[i-1][j-1] + 1;
//                 best = max(best, dp[i][j]);
//             }
//         }
//     } 
//     return best;
// }

int main() {
    string a,b;
    while (getline(cin , a) && getline(cin, b)) {
        cout << lcs(a,b) << endl;
    }
}
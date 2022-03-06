#include <iostream>
 
using namespace std;
 
int t, n, p, bar[25], sum = 0;
bool yes = false;
 
void solve(int idx) {
    if (idx >= p) {
        if (sum == n) {
            yes = true;
        }
        return;
    }
    printf("%d ", sum);
    if (sum + bar[idx] <= n){
        sum += bar[idx];
        solve(idx + 1);
        sum -= bar[idx];
    }
    solve(idx + 1);
}
 
int main() {
    scanf("%d", &t);
    while (t--){
        sum = 0;
        yes = false;
        scanf("%d %d", &n, &p);
        for (int i = 0; i < p; i++) scanf("%d", &bar[i]);
        solve(0);
        puts(yes ? "YES" : "NO");
    }
}
// ECPC PROBLEM E
// BINARY SEARCH APPROACH
// COMPLIXITY: T*LOG(N)


#include <iostream>
#include <cmath>

using namespace std;

const int N = 5e8 + 5;
int t;

pair<int,int> getCordinate(long n) {  //O(log(n))
    int x = ceil((-1 + sqrt(1 + 8 * n)) / 2);
    int y = n - ((x-1) * (x) / 2);
    return {x, y};
}

int main() {
    cin >> t;
    long u, r , x;
    while (t--) {
        cin >> u >> r >> x;
        long long upper = N, lower = 0;
        bool found = false;
        while (upper >= lower) {
            long long mid = (upper + lower) / 2;
            long long eq = u + mid * (2 * r);
            if (eq > x) upper = mid - 1;
            else if (eq < x) lower = mid + 1;
            else {
                found = true;
                pair<int,int> ans = getCordinate(mid + 1);
                cout << ans.first << " " << ans.second << endl;
                break;
            }
        }
        if (!found) puts("-1");
    }
}

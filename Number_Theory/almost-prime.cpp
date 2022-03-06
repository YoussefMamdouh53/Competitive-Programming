#include <iostream>
#include <set>

using namespace std;
int PrimeFactorsCnt(int n){
    set<int> s;
    for (int i = 2; i*i<=n;i++){
        while (n%i==0){
            s.insert(i);
            n/=i;
        }
    }
    if (n>1) s.insert(n);
    return s.size();
}
int main() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 1;i<=n;i++){
        cnt += PrimeFactorsCnt(i) == 2;
    }
    cout << cnt << endl;
}
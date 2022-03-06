#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10e6+5;
const long long M = 10e12+5;
bool prime[N];
vector<long long> almost_prime;

void sieve()
{
    fill(prime, prime + N, true);
    for (int i = 2; i < N; i++)
    {
        if (prime[i])
        {
            long long x = (long long)i * i;
            while(x < M){
                almost_prime.push_back(x);
                x *= i;
            }
            for (long long j = (long long)i * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
    sort(almost_prime.begin(), almost_prime.end());
}


int main() {
    //freopen("input.in","r" , stdin);
    sieve();
    int t;
    cin >> t;
    long long a, b;
    while (t--){
        cin >> a >> b;
        cout << (upper_bound(almost_prime.begin(), almost_prime.end(), b) - lower_bound(almost_prime.begin(), almost_prime.end(), a)) << endl;
    }
}
#include <iostream>
#include <set>

using namespace std;

const int N = 1e+6 + 5;
bool primes[N];
set<long long> tprime;

bool isTPrime(long long n)
{
    return tprime.count(n) == 1;
}
int main()
{
    fill(primes, primes + N, true);
    primes[0] = primes[1] = 0;
    for (long long p = 2; p * p <= N; p++)
    {
        if (primes[p])
        {
            for (long i = p * p; i <= N; i += p)
                primes[i] = false;
        }
    }
    for (long long p = 2; p < N; p++)
        if (primes[p])
            tprime.insert(p * p);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << (isTPrime(n) ? "YES" : "NO") << endl;
    }
    return 0;
}
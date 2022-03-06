// Sieve of Eratosthenes Algorithm
// Find prime number between 1 to N in O(N) complexity

#include <iostream>

using namespace std;

const int N = 1e3 + 5;

bool prime[N];

void sieve(bool *a, int n)
{
    fill(a, a + n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    sieve(prime, N);
    for (int i = 1; i < N; i++)
    {
        cout << i << " is " << (prime[i] ? "Prime" : "Not") << endl;
    }
}
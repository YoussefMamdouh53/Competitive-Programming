#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n <= 2)
        return true;
    if (!(n & 1))
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, c;
    while (cin >> n)
    {
        cin >> c;
        vector<int> primes;
        for (int i = 1; i <= n; i++)
        {
            if (isPrime(i))
                primes.push_back(i);
        }
        cout << n << " " << c << ":";
        if (primes.size() & 1)
            c = 2 * c - 1;
        else
            c = 2 * c;
        //cerr << i << " " << j << endl;
        if (c > primes.size())
            c = primes.size();

        for (int i = primes.size() /2 - c/2, j=0; j<c;j++,i++)
            cout << " " << primes[i];
        cout << endl << endl;
    }
}
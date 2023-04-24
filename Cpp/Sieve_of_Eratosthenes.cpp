#include <bits/stdc++.h>
using namespace std;

//

vector<bool> Prime(3 * 1e6, true);

void Sieve()
{
    Prime[1] = false;
    for (long long i = 2; i * i <= Prime.size(); i++)
    {
        if (Prime[i] != true) // not prime
            continue;
        for (long long j = i * i; j < Prime.size(); j += i)
        {
            Prime[j] = false;
        }
    }
}

void solve()
{
    Sieve();
    long long num;
    cin >> num;
    // 0 1 Format , 0 means not prime , 1 means prime
    for (long long i = 2; i <= num; i++)
    {
        cout << i << " -> " << Prime[i] << "\n";
    }
    cout << "\n";

    // word format
    for (long long i = 2; i <= num; i++)
    {
        if (Prime[i])
        {
            cout << " " << i << " is a Prime number.\n";
        }
        else if (Prime[i] == 0)
        {
            cout << " " << i << " is not a Prime number.\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

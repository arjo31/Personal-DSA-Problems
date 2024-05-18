#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//TC : O(n*log(logn))

void sieveOfEratosthenes(int n)
{
    vector<bool>prime(n+1, true);
    for (int p = 2; p*p<=n; p++)
    {
        if (prime[p])
        {
            for (int k = p*p; k<=n; k+=p)
            {
                prime[k] = false;
            }
        }
    }

    cout<<"The prime numbers upto "<<n<<" are : "<<endl;
    for (int i = 2; i<=n; i++)
    {
        if (prime[i]) cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cout<<"Enter the number n till you want to see the primes = ";
    cin>>n;
    sieveOfEratosthenes(n);
    return 0;
}
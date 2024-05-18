#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

#define ll long long int

ll getHash(string key)
{
    ll value = 0;
    ll p = 31;
    ll pPower = 1;

    for (char ch : key)
    {
        value = (value + (ch - 'a' + 1)*pPower) % MOD;
        pPower = (pPower * p)%MOD;
    }
    return value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool flag = 1;

    while (flag)
    {
        string key;
        cin>>key;

        if (key==".") flag = false;
        else cout<<"Key = "<<key<<" Hash = "<<getHash(key)<<endl;
    }

    return 0;
}
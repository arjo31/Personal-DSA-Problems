#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node
{
    int number;
    int index;
};

bool comp(struct node a, struct node b)
{
    return (a.number <= b.number);
}

int main()
{
    ll n,x;
    cin>>n>>x;
    struct node a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].number;
        a[i].index = i+1;
    }

    sort(a, a+n, comp);
    for (ll i = 0; i < n-2; i++)
    {
        ll j = i+1, k = n-1;
        while (j < k)
        {
            if ((a[i].number + a[j].number + a[k].number) == x)
            {
                cout<<a[i].index<<" "<<a[j].index<<" "<<a[k].index<<endl;
                return 0;
            }
            else if ((a[i].number + a[j].number + a[k].number) > x)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
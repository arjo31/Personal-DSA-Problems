#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// int solve(vector<int>&price, int x)
// {
//     int n = price.size();
//     int low = 0, high = n - 1;
//     int ind = -1;
//     while (low <= high)
//     {
//         int mid = low + (high - low)/2;
//         if (price[mid] <= x)
//         {
//             ind = mid;
//             low = mid + 1;
//         }
//         else
//         {
//             high = mid - 1;
//         }
//     }
//     if (ind==-1) return -1;
//     int ans = price[ind];
//     price.erase(price.begin() + ind);
//     return ans;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    multiset<int>price;
    int n,m;
    cin>>n>>m;
    for (int i = 0 ; i < n; i++)
    {
        int x;
        cin>>x;
        price.insert(x);
    }

    while (m--)
    {
        int q;
        cin>>q;
        auto ind = price.upper_bound(q);
        if (ind==price.begin()) cout<<-1<<endl;
        else
        {
            cout<<*(--ind)<<endl;
            price.erase(ind);
        }
    }
    return 0;
}
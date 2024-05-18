#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

//We want to find the minimum cost to make all of the elements equal.
//Summation(x-A) = min. It happens when A = median

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    long long int count = 0;
    int median = arr[n/2];
    for (auto it : arr)
    {
        count+=abs(it - median);
    }
    cout<<count<<endl;
    return 0;
}
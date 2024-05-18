#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MOD = 1e9 + 7;

ll numOfSubarrays(vector<ll> &arr, int k, ll mid)
{
    ll count = 1;
    ll sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return LONG_LONG_MAX;
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            count++;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll low = *max_element(arr.begin(), arr.end());
    ll high = accumulate(arr.begin(), arr.end(), 0LL);

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (numOfSubarrays(arr, k, mid) <= (ll)k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
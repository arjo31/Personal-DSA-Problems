#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    stack<int> st;
    st.push(1);
    vector<int> ans(n + 1);
    ans[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
            st.push(i);
        if (arr[i] > arr[st.top()])
        {
            ans[i] = st.top();
            st.push(i);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
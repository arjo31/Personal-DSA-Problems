#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int>st;
    vector<int>arr = {17,18,5,4,6,1};
    st.push(arr[0]);
    for (int i = 1 ; i < arr.size(); i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }

        while (!st.empty() && st.top() < arr[i])
        {
            cout<<"NGE of "<<st.top()<< " = "<<arr[i]<<endl;
            st.pop();
        }

        st.push(arr[i]);
    }

    while (!st.empty())
    {
        cout<<"NGE of "<<st.top()<< " = "<<-1<<endl;
        st.pop();
    }

    return 0;
}
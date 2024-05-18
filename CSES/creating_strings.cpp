#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n==1) return 1;
    return n*factorial(n-1);
}

int main()
{
    string s;
    cin>>s;
    vector<int>mpp(26,0);
    for (char c : s)
    {
        mpp[c - 'a']++;
    }
    sort(mpp.begin(), mpp.end(), greater<int>());
    int n = s.size();
    int i = 0;
    int prod = 1;
    while (mpp[i]!=0)
    {
        prod*=factorial(mpp[i]);
        i++;
    }
    cout<<factorial(n)/prod<<endl;
    int l = factorial(n)/prod;
    sort(s.begin(),s.end());
    for (int i = 0; i < l; i++)
    {
        cout<<s<<endl;
        next_permutation(s.begin(),s.end());
    }
    return 0;
}
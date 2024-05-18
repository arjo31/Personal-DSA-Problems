#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int _xor = 0;
    for (int i = 1; i < n; i++)
    {
        int ele;
        cin>>ele;
        _xor = _xor^ele^i;
    }
    _xor = _xor^n;
    cout<<_xor<<endl;
    return 0;
}
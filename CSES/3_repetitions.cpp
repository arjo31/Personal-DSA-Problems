#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int count = 1;
    int _max = INT_MIN;
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i]==s[i+1])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        _max = fmax(count,_max);
    }
    if (s.size()==1)
    {
        cout<<1<<endl;
        return 0;
    }
    cout<<_max<<endl;
    return 0;
}
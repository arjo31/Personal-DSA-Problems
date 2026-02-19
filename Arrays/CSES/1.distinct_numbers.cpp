/*You are given a list of n integers, and your task is to calculate the number of distinct values in the list.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        s.insert(j);
    }
    cout << s.size() << endl;
    return 0;
}
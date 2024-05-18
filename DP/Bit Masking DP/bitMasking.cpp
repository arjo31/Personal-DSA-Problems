#include <bits/stdc++.h>
using namespace std;

void add(int &subset, int x)
{
    subset = (subset ^ (1 << (x - 1)));
}

void remove(int &subset, int x)
{
    subset = (subset ^ (1 << (x - 1)));
}

void display(int n)
{
    for (int bitNo = 0; bitNo <= 9; bitNo++)
    {
        if (bitNo && (1 << bitNo))
        {
            cout << bitNo + 1 << " ";
        }
    }
    cout << endl;
}

int main()
{
    int Set = 15;
    display(Set);
    remove(Set, 2);

    return 0;
}
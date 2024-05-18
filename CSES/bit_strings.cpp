#include<bits/stdc++.h>
using namespace std;

/*Your task is to calculate the number of bit strings of length 
n.

For example, if 
=
3
n=3, the correct answer is 
8
8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

Input
The only input line has an integer 
n.

Output
Print the result modulo 
1
0
9
+
7
10 
9
 +7.
 
Example
Input:
3
Output:
8*/

int main()
{
    long long int n;
    cin>>n;
    long long int ans = 1;
    for (int i = 1; i<=n; i++)
    {
        ans = ans*2;
        ans = ans%(int(1e9+7));
    }
    cout<<ans<<endl;
    return 0;
}
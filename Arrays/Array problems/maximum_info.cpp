/*There is a computer network consisting of n servers or nodes, numbered from 1 to n, and each node has a security value, security_val[i]. A hacker must choose a starting node, start jumping through the network compromising servers along the way until the end. From node x, the hacker can jump to node (x + k). Initially, the hacker has access to 0 servers and 0 security value. The security value at each compromised node is added to the hacker's security value sum, and values may be negative.

The task is to choose the starting node optimally such that the hacker compromises servers with maximum possible security value sum.*/

#include <bits/stdc++.h>
using namespace std;

// O(n^2)
long long int maxSecurityValue(vector<int> &security_val, int k)
{
    int n = security_val.size();
    long long int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        long long int sum = 0;
        while (j < n)
        {
            sum += security_val[j];
            j = j + k;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}

// O(n)
long long int maxSecurityValue(vector<int> &security_val, int k)
{
    int n = security_val.size();
    long long int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        security_val[i] = ((i + k) < n) ? security_val[i] + security_val[i + k] : security_val[i];
        ans = max(ans, (long long)security_val[i]);
    }
    return ans;
}
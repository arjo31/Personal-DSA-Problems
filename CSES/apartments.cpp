#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    //n - no of applicants
    //m - no of rooms
    //k - max allowed diff
    vector<int>a(n),b(m);
    for (int i = 0; i < n; i++) cin>>a[i]; //Desired apartment size of each applicant
    //if for any x in v : accept condition : size <= x - k && size >= x + k
    for (int i = 0; i < m; i++) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());
    int i = 0,j=0;
    int count = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <=k)
        {
            i++;
            j++;
            count++;
        }
        else
        {
            if (a[i] - b[j] > k)
            {
                j++;
            }   
            else
            {
                i++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
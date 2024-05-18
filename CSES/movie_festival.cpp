#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct timings
{
    int start;
    int end;
};

bool comp(struct timings a, timings b)
{
    return (a.end < b.end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    struct timings time[n];
    for (int i = 0; i < n; i++)
    {
        int s,e;
        cin>>s>>e;
        time[i].start = s;
        time[i].end = e;
    }
    sort(time, time + n, comp);
    int prev = time[0].end;
    int maxMovies = 1;
    for (int i = 1; i < n; i++)
    {
        if (time[i].start>=prev)
        {
            maxMovies++;
            prev = time[i].end;
        }
    }
    cout<<maxMovies<<endl;
    return 0;
}
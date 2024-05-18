#include <bits/stdc++.h>
using namespace std;

/*There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.*/

struct answer
{
    int start;
    int end;
    int pos;
};

bool comparator(struct answer m1, answer m2)
{
    if (m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if (m1.pos < m2.pos) return true;
    return false;
}

void solve(vector<int> start, vector<int>end, int n)
{
    struct answer ans[n];
    for (int i = 0; i < n ; i++)
    {
        ans[i].start = start[i];
        ans[i].end = end[i];
        ans[i].pos = i+1;
    }

    vector<int> a;
    sort(ans , ans + n,comparator); //sort by finishing times

    int limit = ans[0].end;
    a.push_back(ans[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (limit < ans[i].start)
        {
            limit = ans[i].end;
            a.push_back(ans[i].pos);
        }
    }
    sort(a.begin(), a.end());
    cout<<"The maximum meetings that can be accomodated in one room : "<<endl;
    for (auto it : a)
    {
        cout<<it<<" ";
    }
}
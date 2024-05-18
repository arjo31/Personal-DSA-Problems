#include <bits/stdc++.h>
using namespace std;

/*Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated with that Job.*/

struct Jobs
{
    int job_id;
    int profit;
    int deadline;
};

bool comp(struct Jobs j1, Jobs j2)
{
    if (j1.profit > j2.profit) return true;
    return false;
}

void JobSequencing(vector<int> ids,vector<int> profits, vector<int>deadlines, int n)
{
    struct Jobs j[n];
    for (int i = 0 ; i < n; i++)
    {
        j[i].job_id = ids[i];
        j[i].profit = profits[i];
        j[i].deadline = deadlines[i];
    }
    sort(j, j+n, comp);
    cout<<"Job_id   "<<"Deadlines   "<<"Profit "<<endl;
    for (int i = 0 ; i < n; i++)
    {
        cout<<"   "<<j[i].job_id<<"         "<<j[i].deadline<<"        "<<j[i].profit<<endl;
    }
    int max_deadline = *max_element(deadlines.begin(),deadlines.end());
    int max_profit = 0;
    vector<int> jobs(max_deadline,-1);
    int count = 0;
    for (int i = 0 ; i < n; i++)
    {
        for (int k = j[i].deadline-1; k>=0 ; k--)
        {
            if (jobs[k]==-1)
            {
                jobs[k] = ids[i];
                max_profit+=j[i].profit;
                count++;
                break;
            }
        }
    }
    cout<<"The jobs are = ";
    for (int i = 0; i < max_deadline; i++)
    {
        if (jobs[i]!=-1)
        {
            cout<<jobs[i]<<" ";
        }
        else{
            continue;
        }
    }
    cout<<endl;
    cout<<"Maximum Profit = "<<max_profit<<endl;
}

int main()
{
    vector<int> j = {6,3,7,2,5,8,1,7};
    vector<int> dead = {2,6,6,5,4,2,4,2};
    vector<int> pro = {80,70,65,60,25,22,20,10};
    int n = j.size();
    JobSequencing(j,pro,dead,n);
}
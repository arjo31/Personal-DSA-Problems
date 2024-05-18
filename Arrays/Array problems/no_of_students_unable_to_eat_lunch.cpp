/*The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
This continues until none of the queue students want to take the top sandwich and are thus unable to eat.

You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.*/

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    stack<int> st;
    deque<int> d;
    int n = students.size();
    int count0 = 0;
    int count1 = 0;
    int count00 = 0;
    int count11 = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i] == 0)
            count0++;
        else
            count1++;
        d.push_back(students[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (sandwiches[i] == 0)
            count00++;
        else
            count11++;
        st.push(sandwiches[i]);
    }
    while (!d.empty())
    {
        if (st.top() == d.front())
        {
            if (st.top() == 1)
            {
                count1--;
                count11--;
            }
            else
            {
                count0--;
                count00--;
            }
            st.pop();
            d.pop_front();
        }
        else
        {
            int x = d.front();
            d.pop_front();
            d.push_back(x);
        }

        if (count0 == 0 && count00 != 0)
        {
            if (st.top() == 1)
                continue;
            else
                return d.size();
        }
        else if (count1 == 0 && count11 != 0)
        {
            if (st.top() == 0)
                continue;
            else
                return d.size();
        }
    }
    return 0;
}

// In O(1) space
int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    vector<int> counts(2, 0);
    for (int student : students)
        counts[student]++;

    int remaining = sandwiches.size();
    for (int sandwich : sandwiches)
    {
        if (counts[sandwich] == 0)
            break;
        if (remaining == 0)
            break;
        counts[sandwich]--;
        remaining--;
    }

    return remaining;
}
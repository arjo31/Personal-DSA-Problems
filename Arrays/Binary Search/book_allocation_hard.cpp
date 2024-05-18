/*Given an array arr of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1*/

#include <bits/stdc++.h>
using namespace std;

int noOfStudents(vector<int>&pages, int pageLimit)
{
    int n = pages.size();
    int noOfStud = 1;
    int prev = pages[0];
    for (int i = 1; i < n; i++)
    {
        if (pages[i] + prev > pageLimit)
        {
            noOfStud++;
            prev = pages[i];
        }
        else
        {
            prev+=pages[i];
        }
    }
    return noOfStud;
}

int allocateMinPages(vector<int>&pages, int m)
{
    int n = pages.size(); //Number of books
    if (n<m) return -1;
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    while (low<=high)
    {
        int mid = low + (high - low)/2;
        if (noOfStudents(pages,mid) > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
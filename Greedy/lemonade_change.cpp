/*In the problem ” Lemonade Change” there is a queue of customers. They want to buy lemonade from us which costs 5 rupees. The customers can give us 5 rupees, 10 rupees, or 20 rupees. We want to return the correct amount of change to the customers. Initially, we don’t have any change. We need to answer if we can successfully return the correct amount of change to each customer or not.*/
#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int> &bill) {
	int n = bill.size();
	int five = 0;
	int ten = 0;
	for (int i = 0; i < n; i++)
	{
		if (bill[i]==5)
		{
			five++;
		}
		else if (bill[i]==10)
		{
			if (five>=1)
			{
				five--;
			}
			else{
				return false;
			}
			ten++;
		}
		else if (bill[i]==20)
		{
			if (ten>=1 && five>=1)
			{
				ten--;
				five--;
			}
			else if (five>2)
			{
				five = five - 3;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
	// Write your code here.
}

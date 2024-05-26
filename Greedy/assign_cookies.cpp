/*Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.*/

#include <bits/stdc++.h>
using namespace std;

int assignCookie(vector<int> &greed, vector<int> &size)
{
	int n = greed.size();
	int m = size.size();
	sort(greed.begin(), greed.end(), greater<int>());
	sort(size.begin(), size.end(), greater<int>());
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < n && j < m)
	{
		if (size[j] >= greed[i])
		{
			count++;
			i++;
			j++;
		}
		else if (size[j] < greed[i])
		{
			i++;
		}
	}
	return count;
}
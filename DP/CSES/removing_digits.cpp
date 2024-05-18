#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1,1e9);
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    for (char c : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(c-'0')]+1);
    }
  }
  cout << dp[n] << endl;
}

/*Greedy solution : 
int sol = 0;
while (n > 0)
{
    int biggestDigit = 0;
    int temp = n;
    while (temp > 0)
    {
        if (biggestDigit < temp%10) biggestDigit = temp%10;
        temp = temp/10;
    }
    sol++;
    x-=biggestDigit;
}
cout<<sol<<endl;
*/
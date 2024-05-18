/*Given a string, your task is to determine the longest palindromic substring of the string. For example, the longest palindrome in aybabtu is bab.*/

#include <bits/stdc++.h>
using namespace std;

// Method 0 - Basic Recursion
string longestPalindrome(string s)
{
    if (s == string(s.rbegin(), s.rend()))
    {
        return s;
    }

    string left = longestPalindrome(s.substr(1));
    string right = longestPalindrome(s.substr(0, s.size() - 1));

    if (left.length() > right.length())
    {
        return left;
    }
    else
    {
        return right;
    }
}

// Method 1 - Brute Force : O(n^3)
string longestPalindrome(string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    int max_len = 1;
    string max_str = s.substr(0, 1);

    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = i + max_len; j <= s.length(); ++j)
        {
            if (j - i > max_len && isPalindrome(s.substr(i, j - i)))
            {
                max_len = j - i;
                max_str = s.substr(i, j - i);
            }
        }
    }

    return max_str;
}

bool isPalindrome(const string &str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

// Method 2 - Expand around center - O(n^2)
string longestPalindrome(string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    auto expand_from_center = [&](int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    };

    string max_str = s.substr(0, 1);

    for (int i = 0; i < s.length() - 1; i++)
    {
        string odd = expand_from_center(i, i);
        string even = expand_from_center(i, i + 1);

        if (odd.length() > max_str.length())
        {
            max_str = odd;
        }
        if (even.length() > max_str.length())
        {
            max_str = even;
        }
    }

    return max_str;
}

// Method 3 - Dynamic Programming - O(n^2) and O(n^2) space
string longestPalindrome(string s)
{
    if (s.length() <= 1)
    {
        return s;
    }

    int max_len = 1;
    int start = 0;
    int end = 0;
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

    for (int i = 0; i < s.length(); ++i)
    {
        dp[i][i] = true;
        for (int j = 0; j < i; ++j)
        {
            if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1]))
            {
                dp[j][i] = true;
                if (i - j + 1 > max_len)
                {
                    max_len = i - j + 1;
                    start = j;
                    end = i;
                }
            }
        }
    }

    return s.substr(start, end - start + 1);
}

// Method 4 - Manacher's Algorithm - O(n)
struct manacher
{
    vector<int> p;

    void run_manacher(string s)
    {
        // cout<<s<<endl;
        int n = s.length();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
                p[i] = max(0, min(r - i, p[l + r - i]));
            while (((i + p[i]) < n) && ((i - p[i]) >= 0) && (s[i + p[i]] == s[i - p[i]]))
            {
                p[i]++;
            }
            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
        // for (auto it : p) cout<<it<<" ";
        // cout<<endl;
    }

    void build(string s)
    {
        string t = "";
        for (char c : s)
        {
            t += string("#") + c;
        }
        run_manacher(t + "#");
    }
};

string longestPalindrome(string s)
{
    struct manacher m;
    m.build(s);
    vector<int> p = m.p;
    int maxPalindrome = INT_MIN;
    int center = 0;
    bool odd = true;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] > maxPalindrome)
        {
            maxPalindrome = p[i];
            center = i;
            if (center % 2 == 0)
                odd = false;
            else
                odd = true;
        }
    }
    maxPalindrome -= 1;
    int actualCenter = (center - 1 - (!odd)) / 2;
    int l = (2 * actualCenter - maxPalindrome + 1 + (!odd)) / 2;
    return s.substr(l, maxPalindrome);
}

#include <bits/stdc++.h>
using namespace std;

class BitManipulation
{
public:
    int getBit(int num, int i) // 1 indexing
    {
        i--;
        num = num >> i;
        return num & 1;
    }

    int setBit(int num, int i) // 1 indexing
    {
        i--;
        int set_bit = 1 << i;
        return num | set_bit;
    }

    int clearBit(int num, int i) // 1 indexing
    {
        i--;
        int clear_bit = ~(1 << i);
        return num & clear_bit;
    }

    bool isKthBitSet(int num, int k) // 1 indexing
    {
        k--;
        int res = 1 << k;
        return num & res;
    }

    string oddEven(int N)
    {
        if (N & 1)
        {
            return "odd";
        }
        return "even";
    }

    bool isPowerOfTwoMethod1(int n)
    {
        if (n & 1)
        {
            return false;
        }
        int length = floor(log2(n));
        int set_bit = 1 << length;
        if ((n & set_bit) == n)
        {
            return true;
        }
        return false;
    }

    bool isPowerOfTwoMethod2(int n)
    {
        if (n & 1)
        {
            return false;
        }
        if ((n & (n - 1)) == 0)
        {
            return true;
        }
        return false;
    }

    int countSetBits(int N) // STL : __builtin_popcount(N)
    {
        int count = 0;
        while (N)
        {
            N = N & (N - 1);
            count++;
        }
        return count;
    }

    int flipBits(int A, int B)
    {
        int res = A ^ B;
        return countSetBits(res);
    }

    int missingNumber(int n, vector<int> &arr)
    {
        int _xor = 0;
        for (int i = 0; i < n; i++)
        {
            _xor = _xor ^ arr[i];
        }
        return _xor;
    }

    vector<string> subsequences(string str)
    {
        int n = str.size();
        string ans;
        vector<string> a;
        for (int i = 0; i < (1 << n); i++)
        {
            ans = "";
            for (int j = 0; j < n; j++)
            {
                int res = 1 << j;
                res = i & res;
                if (res != 0)
                    ans += str[j];
            }
            a.push_back(ans);
        }
        return a;
    }

    // xor from 1 to n
    int findXOR(int n)
    {
        int mod = n % 4;
        if (mod == 0)
            return n;

        else if (mod == 1)
            return 1;

        else if (mod == 2)
            return n + 1;

        else if (mod == 3)
            return 0;
    }

    // Function to return the XOR of elements
    // from the range [l, r]
    int findXOR(int l, int r)
    {
        return (findXOR(l - 1) ^ findXOR(r));
    }

    bool isPowerOfFour(int n)
    {
        return !(n & (n - 1)) && (n & 0x55555555);
    }
};
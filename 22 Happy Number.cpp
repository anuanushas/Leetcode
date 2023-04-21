#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> mp;
        while (n != 1)
        {
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                sum = sum + digit * digit;
                n = n / 10;
            }
            if (mp.find(sum) != mp.end())
            {
                return false;
            }

            mp.insert(sum);
            n = sum;
        }
        return true;
    }
};
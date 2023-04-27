
#include <bits/stdc++.h>
using namespace std;
// Approach 1:TC :SC:O(1)

class Solution
{
public:
    int bulbSwitch(int n)
    {
        return sqrt(n);
    }
};

// Approach 2: TC:O(N) SC:O(1)

class Solution
{
public:
    int bulbSwitch(int n)
    {
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i += 2)
        {
            sum = sum + i;
            if (n < sum)
            {
                break;
            }
            cnt++;
        }
        return cnt;
    }
};

// Approach 2: TC:O(N^2) SC:O(N)

class Solution
{
public:
    int bulbSwitch(int n)
    {
        vector<bool> bulbs(n + 1, false);
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j += i)
            {
                bulbs[j] = !bulbs[j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (bulbs[i])
                count++;
        }

        return count;
    }
};
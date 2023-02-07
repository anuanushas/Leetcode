#include <bits/stdc++.h>
using namespace std;
// Approach 1 : using hash map  // TC: O(N) SC: O(N)
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto x : nums)
        {
            mp[x]++;
        }
        for (auto x : mp)
        {
            if (x.second > 1)
            {
                return true;
            }
        }
        return false;
    }
};



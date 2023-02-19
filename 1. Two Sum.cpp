#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    { // 3 2 4    target=6
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) // i=2
        {
            if (mp.find(target - nums[i]) == mp.end()) // 6-4=2
                mp[nums[i]] = i;                       //
            else
                return {mp[target - nums[i]], i}; //
        }

        return {-1, -1}; // tc: O(n)   sc:O(n)
    }
};
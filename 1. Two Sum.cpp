#include <bits/stdc++.h>
using namespace std;

// Approach 1 :-

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    { // 3 2 4    target=6
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) // i=2
        {
            if (mp.find(target - nums[i]) == mp.end()) // 6-4=2
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }

        return {-1, -1}; // tc: O(n)   sc:O(n)
    }
};

// Approach 2 :-

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) // 2     7    11      15
        {                                     // i j
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) // i=0 j=2
            {
                if (i != j) // 2!=15
                {
                    sum = nums[i] + nums[j]; //  sum=2+11 =13
                    if (sum == target)       //
                    {
                        ans.push_back(i); // 2
                        // ans.push_back(j);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};



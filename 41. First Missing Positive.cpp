#include <bits/stdc++.h>
using namespace std;

// Approach 1 :TC : O(N log N)  SC: O(1)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ans)
                ans++;
        }
        return ans;
    }
};

// Approach: TC :O(N)  Sc : O(1)

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};
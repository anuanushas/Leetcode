#include <bits/stdc++.h>
using namespace std;

// Approach 1: TC:O(N^2)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Approach 2:TC : O(Log (m * n))

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = (row * col) - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int element = matrix[mid / col][mid % col];

            if (element == target)
            {
                return true;
            }
            else if (element > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};
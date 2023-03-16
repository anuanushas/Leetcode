
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative approach  TC : SC : O(N)
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            auto leftNode = q.front();
            q.pop();
            auto rightNode = q.front();
            q.pop();
            if (!leftNode && !rightNode)
            {
                continue;
            }
            if (!leftNode || !rightNode)
            {
                return false;
            }
            if (leftNode->val != rightNode->val)
            {
                return false;
            }
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        return true;
    }
};

// Recursive approach    TC : O(N)   SC: O(H)

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2)
        {
            return true;
        }
        if (!t1 || !t2)
        {
            return false;
        }
        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};
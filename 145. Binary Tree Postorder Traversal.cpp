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

// Approach 1 : TC : O(N)   SC : O(2N)   : Iterative Approach

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        if (!root)
        {
            return vec;
        }
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s1.pop();
            s2.push(curr);
            if (curr->left)
            {
                s1.push(curr->left);
            }
            if (curr->right)
            {
                s1.push(curr->right);
            }
        }
        while (!s2.empty())
        {
            vec.push_back(s2.top()->val);
            s2.pop();
        }
        return vec;
    }
};

// Approach 2 : TC : O(N)   SC : O(N)   : Recursive Approach

class Solution
{
public:
    void traversal(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
            return;
        traversal(root->left, vec);
        traversal(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        traversal(root, vec);
        return vec;
    }
};

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

// Approach 1 : TC : O(N)   SC : O(N)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
    void traversal(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
    }
};

// Approach 2 : TC : O(N)   SC : O(N)

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> st;
        if (root != NULL)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            vec.push_back(curr->val);
            if (curr->right != NULL)
            {
                st.push(curr->right);
            }
            if (curr->left != NULL)
            {
                st.push(curr->left);
            }
        }
        return vec;
    }
};

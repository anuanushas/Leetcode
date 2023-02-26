
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

// Approach 1 :- TC : O(N) SC : O(N)

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            vec.push_back(curr->val);
            curr = curr->right;
        }
        return vec;
    }
};

// Approach 2 :- TC : O(N) SC : O(N)

class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &vec)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vec;
        inorder(root, vec);
        return vec;
    }
};
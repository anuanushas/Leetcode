#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach 1: TC : O(N) SC: O(N)

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;

        unordered_set<ListNode *> st;
        while (head)
        {
            if (st.find(head) != st.end())
                return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};

// Approach 2 : TC :O(N)  SC : O (1)

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
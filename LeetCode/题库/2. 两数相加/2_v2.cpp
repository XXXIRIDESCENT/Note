#include <vector>
using namespace std;

// 解法同 2.cpp，仅优化结构
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    int Sum(int a, int b, int& carry)
    {
        int sum = a + b + carry;
        if (sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        return sum;
    }
    
    ListNode* AddNode(ListNode *p, int num)
    {
        ListNode *node = new ListNode(num);
        if (p)
        {
            p->next = node;
        }
        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = nullptr;
        ListNode *head = nullptr;
        int carry = 0;
        while (l1 && l2)
        {
            p = AddNode(p, Sum(l1->val, l2->val, carry));
            l1 = l1->next;
            l2 = l2->next;
            if (!head)
            {
                head = p;
            }
        }

        while (l1)
        {
            p = AddNode(p, Sum(l1->val, 0, carry));
            l1 = l1->next;
        }

        while (l2)
        {
            p = AddNode(p, Sum(l2->val, 0, carry));
            l2 = l2->next;
        }

        if (carry)
        {
            p = AddNode(p, 1);
        }
        
        return head;
    }
};
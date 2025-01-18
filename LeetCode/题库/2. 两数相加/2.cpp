#include <vector>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = nullptr;
        ListNode *head = nullptr;
        int carry = 0;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            if (p)
            {
                p->next = node;
            }
            else
            {
                head = node;
            }
            p = node;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int sum = l1->val + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            p->next = node;
            p = node;
            l1 = l1->next;
        }

        while (l2)
        {
            int sum = l2->val + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            ListNode *node = new ListNode(sum);
            p->next = node;
            p = node;
            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *node = new ListNode(1);
            p->next = node;
        }
        
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *vir = new ListNode(), *f1, *b1, *tail2;
        vir->next = list1;
        list1 = vir;
        int cnt = 0;
        while (list1) {
            if (cnt == a)  f1 = list1;
            if (cnt == b + 2)  b1 = list1;
            ++cnt;  
            list1 = list1->next;
        }
        list1 = list2;
        while (list1) {
            if (list1->next == nullptr)  tail2 = list1;
            list1 = list1->next;
        }
        f1->next = list2;
        tail2->next = b1;
        return vir->next;
    }
};

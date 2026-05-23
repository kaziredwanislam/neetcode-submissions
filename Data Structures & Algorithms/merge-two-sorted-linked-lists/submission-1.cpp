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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        ListNode* node1=list1;
        ListNode* node2=list2;
        ListNode* curNode;
        ListNode* newHead;
        if(node1->val<=node2->val) {
            curNode=node1;
            newHead=curNode;
            node1=node1->next;
        }
        else {
            curNode=node2;
            newHead=curNode;
            node2=node2->next;
        }

        while(node1!=nullptr && node2!=nullptr) {
            if(node1->val<=node2->val) {
                curNode->next=node1;
                curNode=curNode->next;
                node1=node1->next;
            }
            else {
                curNode->next=node2;
                curNode=curNode->next;
                node2=node2->next;
            }
        }

        if(node1!=nullptr) {
            curNode->next=node1;
        }

        if(node2!=nullptr) {
            curNode->next=node2;
        }
        return newHead;
    }
};

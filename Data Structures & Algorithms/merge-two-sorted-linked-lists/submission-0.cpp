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
        if(list1==nullptr &&list2==nullptr)return nullptr;
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        ListNode* curNode1=list1;
        ListNode* curNode2=list2;
        ListNode* newNode;
        if(curNode1->val<=curNode2->val)
        {
            newNode=curNode1;
            curNode1=curNode1->next;
        }
        else
        {
            newNode=curNode2;
            curNode2=curNode2->next;
        }
        ListNode*headNode=newNode;
        while(curNode1!=nullptr && curNode2!=nullptr)
        {
            if(curNode1->val<=curNode2->val)
            {
                newNode->next=curNode1;
                curNode1=curNode1->next;
            }
            else
            {
                newNode->next=curNode2;
                curNode2=curNode2->next;
            }
            newNode=newNode->next;
        }
        while(curNode1!=nullptr)
        {
            newNode->next=curNode1;
            curNode1=curNode1->next;
            newNode=newNode->next;
        }

        while(curNode2!=nullptr)
        {
            newNode->next=curNode2;
            curNode2=curNode2->next;
            newNode=newNode->next;
        }

        return headNode;
    }
};

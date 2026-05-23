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
    void reorderList(ListNode* head) {
        if(head==NULL|| head->next==NULL)return;

        vector<ListNode*>nodes;
        ListNode*curNode=head;
        while(curNode!=NULL) {
            nodes.push_back(curNode);
            curNode=curNode->next;
        }

        int i=0;
        int j=nodes.size()-1;
        while(i<j) {
            nodes[i]->next=nodes[j];
            i++;
            if(i>=j)break;
            nodes[j]->next=nodes[i];
            j--;
        }
        nodes[i]->next=nullptr;
    }
};

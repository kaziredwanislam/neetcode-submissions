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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        vector<ListNode*>curNodes;
        ListNode* newHead=nullptr;
       
        for(int i=0;i<lists.size();i++)curNodes.push_back(lists[i]);

         ListNode* curNode=new ListNode(100000);
        int curInd=-1;
        while(true) {
            ListNode* nextNode=new ListNode(100000);
            int curInd=-1;
            for(int i=0;i<curNodes.size();i++) {
                if(curNodes[i]!=nullptr && curNodes[i]->val <nextNode->val) {
                    nextNode=curNodes[i];
                    curInd=i;
                }
            }

            if(curInd==-1)break;

            if(newHead==nullptr) {
                newHead=nextNode;
                curNode=nextNode;
                //curNode->next=nullptr;
            }
            else {
                curNode->next=nextNode;
                curNode=curNode->next;
                //curNode->next=nullptr;
            }
            
            lists[curInd]=lists[curInd]->next;
            //if(lists[curInd]!=nullptr)
            //cout<<curInd<<" "<<lists[curInd]->val<<endl;
            curNodes[curInd]=lists[curInd];
        }

        return newHead;
    }
};

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
class HashMap {
    vector<vector<ListNode*>>nodes;
    int size;
public:
    HashMap(int index) {
        for(int i=0;i<index;i++) {
            vector<ListNode*>r;
            nodes.push_back(r);
        }
        size=index;
    }

    void insert(ListNode* node) {
        int index=node->val%size;
        if(index<0)index*=-1;
        if(!isPresent(node)) {
            nodes[index].push_back(node);
        }
    }

    bool isPresent(ListNode* node) {
        int index=node->val%size;
        if(index<0)index*=-1;
        for(int i=0;i<nodes[index].size();i++) {
            if(nodes[index][i]==node)return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        HashMap hashMap(10);
        ListNode* curNode=head;
        while(curNode!=NULL) {
            if(hashMap.isPresent(curNode))return true;
            hashMap.insert(curNode);
            curNode=curNode->next;
        }

        return false;
    }
};

class Solution {
public:
    void removeGroup(vector<int>&hand,int groupSize)
    {
        int val=hand[0];
        for(int i=0;i<groupSize;i++)
        {
            auto it=find(hand.begin(),hand.end(),val);
            if(it!=hand.end())
            {
                hand.erase(it);
            }
            val++;
        }
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        sort(hand.begin(),hand.end());
        int totGroup=hand.size()/groupSize;
        for(int i=0;i<totGroup;i++)
        {
            removeGroup(hand,groupSize);
        }
        if(hand.size()==0)return true;
        return false;
    }
};

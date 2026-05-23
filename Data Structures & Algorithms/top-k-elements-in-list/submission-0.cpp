class Element{
    public:
        int num;
        int freq=0;
};

 bool compareByFreqDesc(const Element& a,const Element& b)
    {
        return a.freq>b.freq;
    }

class Solution {
public:
    bool isPresent(vector<int>&numList,int num)
    {
        for(int i=0;i<numList.size();i++)
        {
            if(numList[i]==num)return true;
        }
        return false;
    }
    
    void incrementFreq(vector<Element>&elementList,int num)
    {
        for(int i=0;i<elementList.size();i++)
        {
            if(elementList[i].num==num)
            {
                elementList[i].freq++;
            }
        }
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>numList;
        vector<Element>elementList;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(!isPresent(numList,nums[i]))
            {
                numList.push_back(nums[i]);
                Element e;
                e.num=nums[i];
                elementList.push_back(e);
            }
            incrementFreq(elementList,nums[i]);
        }

        sort(elementList.begin(),elementList.end(),compareByFreqDesc);
        for(int i=0;i<k;i++)
        {
            res.push_back(elementList[i].num);
        }
        return res;
    }
};

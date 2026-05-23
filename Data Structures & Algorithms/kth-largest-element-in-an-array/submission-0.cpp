class Heap{
    vector<int>element;
    public:


        void insert(int num)
        {
            int hasEntered=0;
            for(int i=0;i<element.size();i++)
            {
                if(num>element[i])
                {
                    element.push_back(0);
                    for(int j=element.size()-2;j>=i;j--)
                    {
                        element[j+1]=element[j];
                    }
                    element[i]=num;
                    hasEntered=1;
                    break;
                }
            }
            if(hasEntered==0)element.push_back(num);
        }

        int getE(int index)
        {
            for(int i=0;i<element.size();i++)cout<<element[i]<<" ";
            cout<<endl;
            return element[index-1];
        }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        Heap curHeap;
        for(int n:nums)
        {
            curHeap.insert(n);
        }
        return curHeap.getE(k);
    }
};

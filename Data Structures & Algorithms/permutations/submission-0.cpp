class Element
{
    public:
    vector<int>permutation;
    vector<int>rem;
};

class Solution {
public:
    void showV(vector<int>v)
    {
        for(int num:v)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    void findAllPermutations(vector<vector<int>>& allPermutations,vector<int>nums)
    {
        stack<Element>estack;
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            Element e;
            e.permutation.push_back(nums[i]);
            vector<int>rem=nums;
            rem.erase(rem.begin()+i);
            
            e.rem=rem;
            estack.push(e);
        }
        while(! estack.empty())
        {
            Element cur_e=estack.top();
            estack.pop();
            //showV(cur_e.permutation);
            //showV(cur_e.rem);
            if(cur_e.permutation.size()==nums.size())
            {
                allPermutations.push_back(cur_e.permutation);
            }
            else
            {
                for(int i=0;i<cur_e.rem.size();i++)
                {
                    Element new_e=cur_e;
                    new_e.permutation.push_back(cur_e.rem[i]);
                    new_e.rem.erase(new_e.rem.begin()+i);
                    estack.push(new_e);
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>allPermutations;
        int length=nums.size();
        findAllPermutations(allPermutations,nums);
        return allPermutations;
    }
};

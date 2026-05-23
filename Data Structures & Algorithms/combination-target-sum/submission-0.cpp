class Solution {
public:
    int Sum(vector<int>comb)
    {
        int sum=0;
        for(int num:comb)
        {
            sum+=num;
        }
        return sum;
    }

    void copy(vector<int>&source,vector<int>&target)
    {
        for(int num:source)
        {
            target.push_back(num);
        }
    }

    void showVector(vector<int>s)
    {
        for(int num:s)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    void findAllValidCombinations(vector<int>&nums,set<vector<int>>&allvalidCombinations,int target)
    {
        stack<vector<int>>cstack;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>s;
            s.push_back(nums[i]);
            //showSet(s);
            cstack.push(s);
        }

        while(cstack.size()>0)
        {
            vector<int>comb=cstack.top();
            cstack.pop();
            //showVector(comb);
            //cout<<"Sum: "<<Sum(comb)<<endl;
            if(Sum(comb)==target)
            {
                allvalidCombinations.insert(comb);
                continue;
            }
            if(Sum(comb)>target)
            {
                continue;
            }

            for(int i=0;i<nums.size();i++)
            {
                vector<int>s;
                copy(comb,s);
                if(comb[comb.size()-1]<=nums[i])
                {
                    s.push_back(nums[i]);
                    //showVector(s);
                    cstack.push(s);
                }

            }
            //exit(0);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        set<vector<int>>allValidCombinations;
        vector<vector<int>>result;
        findAllValidCombinations(nums,allValidCombinations,target);
        for(vector<int>s:allValidCombinations)
        {

            result.push_back(s);
            showVector(s);
        }
        return result;
    }
};
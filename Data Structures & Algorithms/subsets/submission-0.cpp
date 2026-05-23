class Solution {
public:
    void remove(vector<int>&v,vector<int>&nv,int index)
    {
        for(int i=0;i<v.size();i++)
        {
            if(i!=index)nv.push_back(v[i]);
        }
    }

    void showVector(vector<int>v)
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

    void findAllSubsets(set<vector<int>>&allSubsets)
    {
        stack<vector<int>>vstack;
        for(vector<int> v:allSubsets)
        {
            vstack.push(v);
        }
        while (!vstack.empty()){
            vector<int>v=vstack.top();
            vstack.pop();
            allSubsets.insert(v);
            for(int i=0;i<v.size();i++)
            {
                vector<int>nv;
                remove(v,nv,i);
                //showVector(nv);
                if(nv.size()>0)vstack.push(nv);
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>allSubsets;
        allSubsets.insert(nums);
        findAllSubsets(allSubsets);
        vector<vector<int>>result;
        for(vector<int>v: allSubsets)
        {
            result.push_back(v);
        }
        vector<int>emptyV;
        result.push_back(emptyV);
        return result;
    }
};

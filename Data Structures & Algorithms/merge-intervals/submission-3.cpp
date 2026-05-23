class Solution {
public:
    bool isOverlap(vector<int>v1,vector<int>v2) {
        //cout<<v1[0]<<" "<<v1[1]<<"   "<<v2[0]<<" "<<v2[1]<<endl;
        if(v1[0]>=v2[0] && v1[0]<=v2[1])return true;
        if(v2[0]>=v1[0] && v2[0]<=v1[1])return true;
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
            [](const std::vector<int>&a,const std::vector<int>&b) 
            {return a[0]<b[0];}
        );

        /*for(int i=0;i<intervals.size();i++) {
            for(int j=0;j<intervals[0].size();j++) {
                cout<<intervals[i][j]<<" ";
            }
            cout<<endl;
        }*/

        vector<int>curV=intervals[0];
        vector<vector<int>>mergedV;
        mergedV.push_back(curV);

        for(int i=1;i<intervals.size();i++) {
            if(isOverlap(curV,intervals[i])) {
                vector<int>newV={min(curV[0],intervals[i][0]),max(curV[1],intervals[i][1])};
                mergedV[mergedV.size()-1]=newV;
                curV=newV;
            }
            else {
                mergedV.push_back(intervals[i]);
                curV=intervals[i];
            }
        }
        return mergedV;
    }
};

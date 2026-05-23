class Solution {
public:
    bool isOverlap(vector<int>v1,vector<int>v2) {
        //cout<<v1[0]<<" "<<v1[1]<<"   "<<v2[0]<<" "<<v2[1]<<endl;
        if(v1[0]==v2[0] && v1[1]<=v2[1])return true;
        if(v1[0]==v2[0] && v2[1]<=v1[1])return true;
        if(v1[0]>v2[0] && v1[0]<v2[1])return true;
        if(v2[0]>v1[0] && v2[0]<v1[1])return true;
        return false;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
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
        int removalNum=0;

        for(int i=1;i<intervals.size();i++) {
            if(isOverlap(curV,intervals[i])) {
                removalNum++;
                if(curV[1]>intervals[i][1]) {
                    curV=intervals[i];
                }
                
            }
            else {
               
                curV=intervals[i];
            }
        }
        return removalNum;
    }
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

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

    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()==0)return true;
        vector<vector<int>>intervalsList;
        for(int i=0;i<intervals.size();i++) {
            Interval inter=intervals[i];
            vector<int>v={inter.start,inter.end};
            intervalsList.push_back(v);
        }

        sort(intervalsList.begin(),intervalsList.end(),
            [](const std::vector<int>&a,const std::vector<int>&b) 
            {return a[0]<b[0];}
        );

        vector<int>curV=intervalsList[0];
        for(int i=1;i<intervalsList.size();i++) {
            if(isOverlap(curV,intervalsList[i])) {
                return false;
            }
            else {
                if(intervalsList[i][1]>curV[1])
                curV=intervalsList[i];
            }
        }
        return true;
    }
};

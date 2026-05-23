class Solution {
public:
    bool isEqual(vector<int>v1,vector<int>v2) {
         if(v1.size()!=v2.size())return false;
         for(int i=0;i<v1.size();i++) {
            if(v1[i]!=v2[i])return false;
         }
         return true;
    }

    vector<int>findmergeList(vector<int>v1,vector<int>v2) {
        vector <int> merged={max(v1[0],v2[0]),max(v1[1],v2[1]),max(v1[2],v2[2])};
        return merged;
    }

    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>>i1List;
        vector<vector<int>>i2List;
        vector<vector<int>>i3List;
        vector<vector<int>>i4List;

        for(int i=0;i<triplets.size();i++) {
            vector<int >triplet=triplets[i];
            if(triplet[0]==target[0] && triplet[1]==target[1] && triplet[2]==target[2])return true;
            if(triplet[0]==target[0])i1List.push_back(triplet);
            if(triplet[1]==target[1])i2List.push_back(triplet);
            if(triplet[2]==target[2])i3List.push_back(triplet);
        }

        for(int i=0;i<i1List.size();i++) {
            for(int j=0;j<i2List.size();j++) {
                if(i2List[j][0]<=target[0]) {
                    vector<int> merged=findmergeList(i1List[i],i2List[j]);
                    if(isEqual(merged,target))return true;
                    if(merged[0]==target[0] && merged[1]==target[1]) {
                        i4List.push_back(merged);
                    }
                }
                
            }
        }


        for(int i=0;i<i3List.size();i++) {
            for(int j=0;j<i4List.size();j++) {
                if(i4List[j][2]<=target[2]) {
                    vector<int> merged=findmergeList(i3List[i],i4List[j]);
                    if(isEqual(merged,target))return true;
                    if(merged[0]==target[0] && merged[1]==target[1] && merged[2]==target[2]) {
                        return true;
                    }
                }
                
            }
        }
        return false;
    }
};

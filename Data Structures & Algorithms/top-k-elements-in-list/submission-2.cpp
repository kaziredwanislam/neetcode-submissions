class ValFreq{
public:
    int value;
    int freq;
    ValFreq() {

    }
    ValFreq(int v,int f) {
        value=v;
        freq=f;
    }

    bool operator < (const ValFreq& other) const{
        return freq<other.freq;
    }
    
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<ValFreq>valfreqs;
        vector<bool>hastaken(nums.size(),false);
        for(int i=0;i<nums.size();i++) {
            if(hastaken[i])continue;
            int n=nums[i];
            int freq=1;
            hastaken[i]=true;
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j]==n){
                    freq++;
                    hastaken[j]=true;
                }
            }
            ValFreq ob(n,freq);
            valfreqs.push_back(ob);
        }

        sort(valfreqs.begin(),valfreqs.end());
        if(valfreqs.size()==1)return vector<int>{valfreqs[0].value};
        //return vector<int> {valfreqs[valfreqs.size()-1].value,valfreqs[valfreqs.size()-2].value};
        vector<int>ans;
        int size=valfreqs.size();
        for(int i=0;i<k;i++) {
            ans.push_back(valfreqs[size-i-1].value);
        }
        return ans;
    
    }
}; 

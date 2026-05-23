class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i=0;i<s.length();i++) {
            int index=s[i]-97;
            freq1[index]++;
        }

        for(int i=0;i<t.length();i++) {
            int index=t[i]-97;
            freq2[index]++;
        }


        for(int i=0;i<26;i++) {
            if(freq1[i]!=freq2[i]){
                //cout<<i<<" "<<freq1[i]<<" "<<freq2[i]<<endl;
                return false;
            }
        }
        return true;
    }
};

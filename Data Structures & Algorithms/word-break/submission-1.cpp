class Solution {
public:
    bool findSyllable(string s,vector<string>&wordDict,vector<int>&memo) {
        if(s.length()==0)return true;
        for(string subs:wordDict) {
            if(subs.length()<=s.length()) {
                int start_pos=s.length()-subs.length();
                if(memo[start_pos]==0)continue;
                string csubs=s.substr(start_pos);
                if(csubs==subs) {
                    string newString=s.substr(0,start_pos);
                    bool isSyllable=findSyllable(newString,wordDict,memo);
                    memo[start_pos]=isSyllable;
                    if(isSyllable)return true;
                }
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>memo(s.length()+1,-1);
        return findSyllable(s,wordDict,memo);
    }
};

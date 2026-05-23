class Solution {
    bool hasFound=false;
public:
    void split(string & s,vector<string>& wordDict,vector<bool>&memo,int startIndex,int curIndex) {
        if(startIndex>=s.length())hasFound=true;
        if(!hasFound && curIndex<s.length() && memo[curIndex]==false) {
            string curS(s.begin()+startIndex,s.begin()+curIndex+1);
            for(int i=0;i<wordDict.size();i++) {
                if(!hasFound) {
                    if(wordDict[i]==curS ){
                        memo[curIndex]=true;
                        split(s,wordDict,memo,curIndex+1,curIndex+1);
                    }
                }
                
            }
            if(!hasFound && memo[curIndex+1]==false)split(s,wordDict,memo,startIndex,curIndex+1);
        } 
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>memo(s.length(),false);
        split(s,wordDict,memo,0,0);
        return hasFound;
    }
};

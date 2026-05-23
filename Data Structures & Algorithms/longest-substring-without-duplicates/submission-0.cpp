class HashSet {
    vector<vector<char>>charList;
    int index;
    public:
    HashSet(int ind) {
        index=ind;
        for(int i=0;i<index;i++) {
            vector<char>v;
            charList.push_back(v);
        }
    }

    void insert(char ch) {
        int ascii_val=ch;
        if(!isPresent(ch)) {
            int ind=ascii_val%index;
            charList[ind].push_back(ch);
        }
    }

    bool isPresent(char ch) {
        int ascii_val=ch;
        int ind=ascii_val%index;
        for(int i=0;i<charList[ind].size();i++) {
            if(charList[ind][i]==ch)return true;
        }
        return false;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;
        int maxsubLen=0;
        for(int i=0;i<s.length();i++) {
            HashSet hashSet(10);
            int cursubLen=0;
            for(int j=i;j<s.length();j++) {
                if(hashSet.isPresent(s[j]))break;
                hashSet.insert(s[j]);
                cursubLen++;
            }
            if(cursubLen>maxsubLen)maxsubLen=cursubLen;
        }
        return maxsubLen;
    }
};

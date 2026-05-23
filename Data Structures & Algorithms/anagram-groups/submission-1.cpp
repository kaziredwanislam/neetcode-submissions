class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int>s_freq(26,0);
        vector<int>t_freq(26,0);

        for(int i=0;i<s.length();i++) {
            s_freq[s[i]-'a']++;
            t_freq[t[i]-'a']++;
        }

        for(int i=0;i<26;i++) {
            if(s_freq[i]!=t_freq[i])return false;
        }
        return true;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int>hastaken(strs.size(),0);
        vector<vector<string>>gAnagrams;

        for(int i=0;i<strs.size();i++) {
            if(hastaken[i]==1)continue;
            vector<string>anagrams;
            anagrams.push_back(strs[i]);
            hastaken[i]=1;
            for(int j=i+1;j<strs.size();j++) {
                if(hastaken[j]==1)continue;
                if(isAnagram(strs[i],strs[j])) {
                    anagrams.push_back(strs[j]);
                    hastaken[j]=1;
                }
            }
            gAnagrams.push_back(anagrams);
        }    

        return gAnagrams;
    }
};

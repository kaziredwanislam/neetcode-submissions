class Solution {
public:
    bool isSameAnagram(vector<int>w1,vector<int>w2)
    {
        for(int i=0;i<w1.size();i++)
        {
            if(w1[i]!=w2[i])return false;
        }
        return true;
    }

    void initiateVector(vector<int>&v)
    {
        for(int i=0;i<26;i++)v.push_back(0);
    }

    int getIndex(char c)
    {
        int index=c-97;
        return index;
    }    

    void getAsciiValofWord(string w,vector<int>&v)
    {
        //initiateVector(&v);
        for(int i=0;i<w.length();i++)
        {
            int index=getIndex(w[i]);
            v[index]++;
        }
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>vv;
        if(strs.size()==0)return vv;
        for(int i=0;i<strs.size();i++)
        {
            string curWord=strs[i];
            vector<int>curWordV(26,0);
            getAsciiValofWord(curWord,curWordV);
            bool hasFoundSameAnagram=false;
            for(int j=0;j<vv.size();j++)
            {
                string comparingWord=vv[j][0];
                vector<int>comparingWordV(26,0);
                getAsciiValofWord(comparingWord,comparingWordV);
                if(isSameAnagram(comparingWordV,curWordV))
                {
                    hasFoundSameAnagram=true;
                    vv[j].push_back(curWord);
                    break;
                }
            }
            if(hasFoundSameAnagram==false)
            {
                vector<string>newAnagram;
                newAnagram.push_back(curWord);
                vv.push_back(newAnagram);
            }
        }
        return vv;
    }
};

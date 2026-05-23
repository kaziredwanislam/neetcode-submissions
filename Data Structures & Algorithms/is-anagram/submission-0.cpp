class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>s_vec(26);
        vector<int>t_vec(26);
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            s_vec[index]++;
        }
        for(int j=0;j<t.size();j++)
        {
            int index2=t[j]-'a';
            t_vec[index2]++;
        }
        for(int i=0;i<s_vec.size();i++)
        {
            if(s_vec[i]!=t_vec[i])return false;
        }
        return true;
    }
};

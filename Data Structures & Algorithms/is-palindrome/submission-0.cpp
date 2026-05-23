class Solution {
public:
    bool isPalindrome(string s) {
        string modifiedS="";
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>=48 &&s[i]<=57)||(s[i]>=97 && s[i]<=122))
            {
                modifiedS+=s[i];
            }
            if((s[i]>=65 && s[i]<=90))
            {
                modifiedS+=s[i]+32;
            }
        }

        int j=modifiedS.size()-1;
        for(int i=0;i<j;i++)
        {
            if(modifiedS[i]!=modifiedS[j]){
                    //cout<<s[i]<<" "<<s[j]<<endl;
                    return false;
            }
            j--;
        }
        return true;
    }
};
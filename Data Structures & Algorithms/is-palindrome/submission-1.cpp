class Solution {
public:
    bool isAlphanumeric(char ch) {
        if(ch>=48 && ch<=57)return true;
        if(ch>=65 && ch<=90)return true;
        if(ch>=97 && ch<=122)return true;

        return false;
    } 

    bool checkPalindrome(string s) {
        int fIndex=0;
        int lIndex=s.length()-1;

        while(fIndex<lIndex) {
            if(s[fIndex]!=s[lIndex])return false;
            fIndex++;
            lIndex--;
        }
        return true;
    }
    
    bool isPalindrome(string s) {
       string newstr;
       for(int i=0;i<s.length();i++) {
        if(isAlphanumeric(s[i])) {
            if(s[i]>=65 && s[i]<=90)s[i]+=32;
            newstr+=s[i];
        }
       } 
        //cout<<newstr<<endl;
       return checkPalindrome(newstr);
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right) {
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        if(s.length()==1)return s;
        int maxLen=1;
        string maxPalindrome="";
        maxPalindrome+=s[0];
        cout<<maxPalindrome<<endl;
        for(int i=0;i<s.length();i++) {
            for(int j=s.length()-1;j>i;j--) {
                int len=j-i+1;
                if(len<=maxLen)break;
                string str=s.substr(i,len);
                if(isPalindrome(str)){
                    maxLen=len;
                    maxPalindrome=str;
                    break;
                }
            }
        }

        return maxPalindrome;
    }
};

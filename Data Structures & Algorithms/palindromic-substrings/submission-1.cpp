class Solution {
public:
    int findOddPalindrome(string s,int index) {
        int left=index-1;
        int right=index+1;
        int len=s.length();
        int totPalindrome=1;

        while(left>=0 && right<len) {
            if(s[left]==s[right]) {
                totPalindrome++;
                left--;
                right++;
            }
            else break;
        }
        return totPalindrome;
    }

    int findEvenPalindrome(string s,int index) {
        int left=index;
        int right=index+1;
        int len=s.length();
        int totPalindrome=0;

        while(left>=0 && right<len) {
            if(s[left]==s[right]) {
                totPalindrome++;
                left--;
                right++;
            }
            else break;
        }
        return totPalindrome;
    }

    int countSubstrings(string s) {
       int totalPalindrome=0;
       for(int i=0;i<s.length();i++) {
            totalPalindrome+=findOddPalindrome(s,i)+findEvenPalindrome(s,i);
       }   
       return totalPalindrome;
    }
};

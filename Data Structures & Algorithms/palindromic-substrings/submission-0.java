class Solution {
    boolean isValidIndex(String s, int pos)
    {
        if(pos<0 || pos>=s.length())return false;
        return true;
    }

    int oddLengthPalindrome(String s,int pos)
    {
        int pos1=pos-1;
        int pos2=pos+1;
        int maxPalindromeLen=1;
        int totPalindrome=0;
        while(isValidIndex(s,pos1)&&isValidIndex(s,pos2))
        {
            if(s.charAt(pos1)==s.charAt(pos2))
            {
                maxPalindromeLen+=2;
                pos1--;
                pos2++;
                totPalindrome++;
            }
            else break;
        }
        return totPalindrome;
    }

    int evenLengthPalindrome(String s,int pos)
    {
        int pos1=pos;
        int pos2=pos+1;
        int maxPalindromeLen=0;
        int totPalindrome=0;
        while(isValidIndex(s,pos1)&&isValidIndex(s,pos2))
        {
            if(s.charAt(pos1)==s.charAt(pos2))
            {
                pos1--;
                pos2++;
                maxPalindromeLen+=2;
                totPalindrome++;
            }
            else break;
        }
        return totPalindrome;
    }

    public int countSubstrings(String s) {
        int totalPalindrome=s.length();
        for(int i=0;i<s.length();i++)
        {
            totalPalindrome+=oddLengthPalindrome(s,i)+evenLengthPalindrome(s,i);
        }   
        return totalPalindrome; 
    }
}

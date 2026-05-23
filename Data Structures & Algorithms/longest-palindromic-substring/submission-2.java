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
        while(isValidIndex(s,pos1)&&isValidIndex(s,pos2))
        {
            if(s.charAt(pos1)==s.charAt(pos2))
            {
                maxPalindromeLen+=2;
                pos1--;
                pos2++;
            }
            else break;
        }
        return maxPalindromeLen;
    }

    int evenLengthPalindrome(String s,int pos)
    {
        int pos1=pos;
        int pos2=pos+1;
        int maxPalindromeLen=0;
        while(isValidIndex(s,pos1)&&isValidIndex(s,pos2))
        {
            if(s.charAt(pos1)==s.charAt(pos2))
            {
                pos1--;
                pos2++;
                maxPalindromeLen+=2;
            }
            else break;
        }
        return maxPalindromeLen;
    }

    public int maxVal(int []ara)
    {
        int maxVal=ara[0];
        for(int i=1;i<ara.length;i++)
        {
            if(ara[i]>=maxVal)maxVal=ara[i];
        }
        return maxVal;
    }

    public String longestPalindrome(String s) {
        if(s.length()==1)return s;
        int maxPalindromeLen=1;
        String maxPalindrome=s.substring(0,1);
        for(int i=0;i<s.length()-1;i++)
        {
            int len1=evenLengthPalindrome(s,i);
            int len2=oddLengthPalindrome(s,i);
            if(len1<len2){
                if(len2>maxPalindromeLen)
                {
                    maxPalindromeLen=len2;
                    int startingIndex=i-len2/2;
                    int endingIndex=startingIndex+len2;
                    maxPalindrome=s.substring(startingIndex,endingIndex);
                    //System.out.println(maxPalindrome+" "+i+" odd");
                }
            }
            else 
            {
                if(len1>maxPalindromeLen)
                {
                    maxPalindromeLen=len1;
                    int startingIndex=i-len1/2+1;
                    int endingIndex=startingIndex+len1;
                    maxPalindrome=s.substring(startingIndex,endingIndex);
                    //System.out.println(maxPalindrome+" "+i+" "+len1);
                }
            }
        }
        return maxPalindrome;
    }
}

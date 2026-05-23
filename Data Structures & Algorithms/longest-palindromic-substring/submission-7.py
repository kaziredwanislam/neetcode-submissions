class Solution:
    def longestPalindrome(self, s: str) -> str:
        def checkOddPalindrome(pos):
            l=pos-1
            r=pos+1
            p_size=1
            while l>=0 and r<len(s):
                if s[l]==s[r]:
                    p_size+=2
                    l-=1
                    r+=1
                else: break
            return p_size
        
        def checkEvenPalindrome(pos):
            l=pos
            r=pos+1
            p_size=0
            while l>=0 and r<len(s):
                if s[l]==s[r]:
                    p_size+=2
                    l-=1
                    r+=1
                else: break
            return p_size

        lp=s[0]
        lp_size=1
        for i in range(len(s)):
            odd_palindrome_size=checkOddPalindrome(i)
            even_palindrome_size=checkEvenPalindrome(i)
            #print(i,s[i])
            if odd_palindrome_size>lp_size:
                lp_size=odd_palindrome_size
                start=i-lp_size//2
                #print(i,lp_size,start)
                lp=s[start:start+lp_size]
            if even_palindrome_size>lp_size:
                lp_size=even_palindrome_size
                start=i-lp_size//2+1
                lp=s[start:start+lp_size]
        
        return lp
            
class Solution:
    def countSubstrings(self, s: str) -> int:
        def checkOddPalindrome(pos):
            l=pos-1
            r=pos+1
            p_size=1
            while l>=0 and r<len(s):
                if s[l]==s[r]:
                    p_size+=1
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
                    p_size+=1
                    l-=1
                    r+=1
                else: break
            return p_size

        tot_palindrome=0
        for i in range(len(s)):
            odd_palindrome_size=checkOddPalindrome(i)
            even_palindrome_size=checkEvenPalindrome(i)
            tot_palindrome+=odd_palindrome_size+even_palindrome_size
        
        return tot_palindrome
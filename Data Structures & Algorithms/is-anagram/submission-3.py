class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        letter_s=[0 for _ in range(26)]
        letter_t=[0 for _ in range(26)]

        for ch in s:
            index=ord(ch)-ord('a')
            letter_s[index]+=1
        
        for ch in t:
            index=ord(ch)-ord('a')
            letter_t[index]+=1
        
        return letter_s==letter_t
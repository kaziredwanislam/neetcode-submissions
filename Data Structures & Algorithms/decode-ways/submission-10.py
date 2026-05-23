class Solution:
    def numDecodings(self, s: str):
        if s[0]=='0':
            return 0
        total_ways=0
        
        def count_ways(pos):
            nonlocal total_ways
            if pos==len(s):
                total_ways+=1
                return
            if s[pos]=='0':
                return
            count_ways(pos+1)
            if pos+1<len(s):
                two_digit=int(s[pos:pos+2])
                if 10<=two_digit<=26:
                    count_ways(pos+2)
        
        count_ways(0)
        return total_ways
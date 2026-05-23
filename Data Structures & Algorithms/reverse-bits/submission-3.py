class Solution:
    def reverseBits(self, n: int) -> int:
        rev_num=0
        for i in range(32):
            if 1 & n>>i==1:
                rev_index=31-i
                rev_num+=pow(2,rev_index)
        
        return rev_num
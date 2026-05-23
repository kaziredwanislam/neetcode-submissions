class Solution:
    def hammingWeight(self, n: int) -> int:
        count_one=0
        for i in range(32):
            #print(n>>i)
            if (1 & n>>i)==1:
                count_one+=1
        return count_one

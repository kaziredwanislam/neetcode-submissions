class Solution:
    def countBits(self, n: int) -> List[int]:
            def hammingWeight( n: int) -> int:
                count_one=0
                for i in range(32):
                    if (1 & n>>i)==1:
                        count_one+=1
                return count_one

            res=[]
            for i in range(n+1):
                res.append(hammingWeight(i))

            return res
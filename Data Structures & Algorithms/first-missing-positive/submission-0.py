class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        num_hash={}
        tot_positive=0
        for num in nums:
            if num>0:
                num_hash[num]=1
                tot_positive+=1
        
        for num in range(1,tot_positive+2):
            if num not in num_hash:
                return num

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        circular_nums=nums+nums
        n=len(nums)
        max_sum=max(nums)
        for i in range(n):
            cur_sum=0
            for j in range(i,i+n):
                cur_sum+=circular_nums[j]
                if cur_sum>max_sum:
                    max_sum=cur_sum
                if cur_sum<0:
                    break
            
        
        return max_sum
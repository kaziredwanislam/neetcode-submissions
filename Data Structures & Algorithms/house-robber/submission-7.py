class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return nums[0]
        if n==2:
            return max(nums[1],nums[0])
        
        amount=[0 for _ in range(n)]
        amount[-1]=nums[-1]
        amount[-2]=nums[-2]

        for i in range(n-3,-1,-1):
            amount[i]=max(nums[i]+amount[i+2],amount[i+1])

        return amount[0] 
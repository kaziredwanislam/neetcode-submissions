class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[-1]
            
        def rob_in_line(nums: List[int]) -> int:
            n=len(nums)
            if n==1:
                return nums[0]
            if n==2:
                return max(nums[1],nums[0])
            
            amount=[0 for _ in range(n)]
            amount[-1]=nums[-1]
            amount[-2]=max(nums[-2],nums[-1])

            for i in range(n-3,-1,-1):
                amount[i]=max(nums[i]+amount[i+2],amount[i+1])

            return amount[0] 
        #print(nums[0:len(nums)])
        return max(rob_in_line(nums[0:len(nums)-1]),rob_in_line(nums[1:len(nums)]))
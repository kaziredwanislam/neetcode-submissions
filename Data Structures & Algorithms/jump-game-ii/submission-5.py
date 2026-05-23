class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return 0
        req=[1000000000 for _ in range(n)]
        for i in range(n-2,-1,-1):
            if nums[i]+i>=n-1:
                req[i]=1
                #print(i,"Here",req[i])
            elif nums[i]!=0:
                min_jump=min(req[i+1:nums[i]+i+1])
                req[i]=min_jump+1
                #print(i," ",req[i])
        #print(req)
        return req[0]
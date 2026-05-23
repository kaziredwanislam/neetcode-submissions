class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        if n==1:
            return True
        checkmarks=[False]*n

        def isPossible(start,end):
            for i in range(start,end+1):
                if checkmarks[i]==True:
                    return True
            return False
        
        for i in range(n-2,-1,-1):
            if i+nums[i]>=n-1:
                checkmarks[i]=True

            else:
                max_jump_index=min(n-1,i+nums[i])
                if(isPossible(i,max_jump_index)):
                    checkmarks[i]=True
        
        return checkmarks[0]

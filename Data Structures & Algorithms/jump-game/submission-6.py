class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n=len(nums)
        can_reach=[False for _ in range(n)]
        can_reach[n-1]=True
        for i in range(n-1,-1,-1):
            max_pos=i+nums[i]
            #print(max_pos,n)
            if max_pos>=n-1:
                can_reach[i]=True
            
            else:
                for j in range(i+1,max_pos+1):
                    if can_reach[j]==True:
                        can_reach[i]=True
                        break
                
        #print(can_reach)
        return can_reach[0]
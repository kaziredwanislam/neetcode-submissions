class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefixes=[]
        suffixes=()
        res=[0]*len(nums)

        prefix=1
        prefixes.append(1)
        for i in range(1,len(nums)):
            prefix=prefix*nums[i-1]
            prefixes.append(prefix)

        suffix=1
        suffixes=[1]*len(nums)
        for i in range(len(nums)-2,-1,-1):
            suffix=suffix*nums[i+1]
            suffixes[i]=suffix
        
        for i in range(len(nums)):
            res[i]=prefixes[i]*suffixes[i]
        
        return res

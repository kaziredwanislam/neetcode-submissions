class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        for i in range(1,n):
            pos = i
            while pos>0:
                if nums[pos]<nums[pos-1]:
                    nums[pos],nums[pos-1] = nums[pos-1],nums[pos]
                    pos-=1
                else:
                    break
        
        
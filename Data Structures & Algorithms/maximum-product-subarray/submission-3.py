class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        
        max_product=min_product=nums[0]
        for i in range(1,len(nums)):
            prev_min=min_product
            prev_max=max_product
            min_product=min(prev_min*nums[i],prev_max*nums[i],nums[i])
            max_product=max(prev_min*nums[i],prev_max*nums[i],nums[i])
            nums[i]=max(min_product,max_product)
            #print(nums[i],min_product,max_product)
        return max(nums)
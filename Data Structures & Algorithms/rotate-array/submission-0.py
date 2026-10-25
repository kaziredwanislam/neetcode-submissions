class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if k!=n :
            #right_move = (k%n)
            i = 0
            cur_index=0
            cur_val=nums[cur_index]
            next_indices = [0 for _ in range(n)]
            while i<n:
                next_index = (i+k)%n
                next_indices[i] = next_index
                i+=1
            
            #print(next_indices)
            new_order=[0 for _ in range(n)]
            for i in range(n):
                new_index=next_indices[i]
                new_order[new_index]=nums[i]
            
            #print(new_order)
            
            nums[:]=new_order




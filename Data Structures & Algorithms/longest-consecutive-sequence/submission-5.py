class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
            
        hash_set=set()
        
        for num in nums:
            hash_set.add(num)
        
        starts=[]

        for num in nums:
            if num-1 not in hash_set:
                starts.append(num)

        lcs=1
        for num in starts:
            cur_cs=1
            while num+1 in hash_set:
                cur_cs+=1
                num+=1
            lcs=max(cur_cs,lcs)

        return lcs            
from operator import itemgetter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq={}
        result=[]
        for i in range (len(nums)):
            if nums[i] in freq:
                freq[nums[i]]+=1
            else:
                freq[nums[i]]=1
        
        sorted_freq=dict(sorted(freq.items(),key=itemgetter(1),reverse=True))
        for key,val in sorted_freq.items():
            result.append(key)
        
        return result[:k]
class HashList:
    def __init__(self,n):
        self.li=[[] for _ in range(n)]
        self.n=n
    
    def insert(self,val):
        index=val%self.n
        if val not in self.li[index]:
            self.li[index].append(val)
    
    def isPresent(self,val):
        index=val%self.n
        if val in self.li[index]:
            return True
        return False

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        hash_list=HashList(10)
        for val in nums:
            if hash_list.isPresent(val)==True:
                return True
            hash_list.insert(val)
        
        return False
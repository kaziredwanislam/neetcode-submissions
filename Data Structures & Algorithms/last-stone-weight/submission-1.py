class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort(reverse=True)
        if(len(stones)==1):
            return stones[0]
        while(len(stones)>1):
            new_stones=stones[2:len(stones)]
            if(stones[0]<stones[1]):
                new_stones.append(stones[1]-stones[0])
            elif stones[0]>stones[1]:
                new_stones.append(stones[0]-stones[1])

            new_stones.sort(reverse=True)
            stones=new_stones
        
        if(len(stones)==0):
            return 0
        return stones[0]
class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        n=len(hand)
        if n%groupSize!=0:
            return False
        hand.sort()

        tot_iter=n//groupSize
        for i in range(tot_iter):
            cur_val=min(hand)
            hand.remove(cur_val)
            for j in range(1,groupSize):
                cur_val+=1
                if not cur_val in hand:
                    return False
                hand.remove(cur_val)
        
        return True
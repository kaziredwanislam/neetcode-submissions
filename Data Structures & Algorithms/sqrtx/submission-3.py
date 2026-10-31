class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x==1:
            return x
        
        left = 1
        right = x
        mid=1
        while left <= right:
            mid = (left+right)//2
            if mid*mid == x:
                return mid
            elif mid*mid < x:
                left = mid+1
            else:
                right = mid-1
        
        return left-1

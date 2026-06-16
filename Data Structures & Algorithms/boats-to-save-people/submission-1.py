class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        n=len(people)
        total_boat=0

        left=0
        right=n-1
        while left <= right:
            if people[left]+people[right]<=limit:
                left+=1
                right-=1
            else:
                right-=1
            total_boat+=1
        
        return total_boat
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        people = [0 for _ in range(n)]
        for t in trust:
            person = t[0]
            people[person-1] = 1
        
        try:
            judge1 = people.index(0)
        except ValueError:
            judge1 = -1
            return judge1
        
        people_trust = [0 for _ in range(n)]
        for t in trust:
            person_trust=t[1]
            people_trust[person_trust-1]+=1
        
        #print(people_trust)
        try:
            judge2 = people_trust.index(n-1)
        except ValueError:
            judge2 = -1
            return judge2
        
        #print(judge1, judge2)
        if judge1==judge2:
            return judge1+1
        else:
            return -1
        
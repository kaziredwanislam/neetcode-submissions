class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        if len(asteroids)==0:
            return asteroids

        hasExplotion=True
        while hasExplotion and asteroids:
            hasExplotion=False
            new_asteroids=[]
            new_asteroids.append(asteroids[0])
            for i in range(1,len(asteroids)):
                if len(new_asteroids)==0:
                    new_asteroids.append(asteroids[i])
                    continue
                if new_asteroids[-1]>0 and asteroids[i]<0:
                    if abs(new_asteroids[-1])<abs(asteroids[i]):
                        new_asteroids[-1]=asteroids[i]
                    elif abs(new_asteroids[-1])==abs(asteroids[i]):
                        new_asteroids.pop()
                    hasExplotion=True
                else:
                    new_asteroids.append(asteroids[i])
            
            asteroids=new_asteroids
        
        return asteroids
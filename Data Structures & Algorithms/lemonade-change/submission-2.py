class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        earning=0
        five_tk=0
        ten_tk=0
        twenty_tk=0
        for bill in bills:
            if bill>5:
                change=bill-5
                if change==5:
                    if five_tk==0:
                        return False
                    five_tk-=1
                if change==10:
                    if ten_tk==0:
                        return False
                    ten_tk-=1
                if change==15:
                    if five_tk>=1 and ten_tk>=1:
                        five_tk-=1
                        ten_tk-=1
                    elif five_tk>=3:
                        five_tk-=3
                    else: return False

            if bill==5:
                five_tk+=1
            if bill==10:
                ten_tk+=1
            if bill==20:
                twenty_tk+=1

        
        return True
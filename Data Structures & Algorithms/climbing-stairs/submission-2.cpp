class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int s1=2;
        int s2=1;
        n=n-2;
        int step;
        while(n>0) {
            step=s1+s2;
            s2=s1;
            s1=step;
            n--;
        }
        return step;
    }
};

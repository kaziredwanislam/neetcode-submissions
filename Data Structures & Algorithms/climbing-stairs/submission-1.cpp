class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int topmost_step1=1;
        int topmost_step2=2;
        int pres=n-2;
        int step=0;
        while(pres>0)
        {
            step=(topmost_step1+topmost_step2);
            topmost_step1=topmost_step2;
            topmost_step2=step;
            pres--;
            //cout<<pres<<" "<<topmost_step1<<" "<<topmost_step2<<" "<<step<<endl;
        }
        return step;
    }
};

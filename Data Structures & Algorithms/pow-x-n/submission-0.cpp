class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0;
        if(n==0)return 1;
        double res=1;
        double abs_n=n;
        if(n<0)abs_n=-n;
        for(int i=1;i<=abs_n;i++) {
            res*=x;
        }
        if (n<0) {
            res=1/res;
        }
        return res;
    }
};

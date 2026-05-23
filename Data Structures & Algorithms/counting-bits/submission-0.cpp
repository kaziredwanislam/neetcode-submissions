class Solution {
public:
    int retNearestTwosPower(int n)
    {
        int num=1;
        int testNum=num;
        while(testNum<=n)
        {
            num=testNum;
            testNum=2*testNum;
        }
        return num;
    }

    vector<int> countBits(int n) {
        vector<int>res(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int currentNum=i;
            int noOfOne=0;
            int testNum=currentNum;
            while(testNum>1)
            {
                int nearestTwosPower=retNearestTwosPower(testNum);
                testNum-=nearestTwosPower;
                noOfOne++;
            }
            if(testNum==1)noOfOne++;
            res[currentNum]=noOfOne;
        }
        return res;
    }
};

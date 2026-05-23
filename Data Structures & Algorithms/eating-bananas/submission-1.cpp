class Solution {
public:
    bool isMultiple(int a,int b)
    {
        int d=a/b;
        if(d*b==a)return true;
        return false;
    }

    int findTime(int val,int rate)
    {
        if(val<rate)return 1;
        if(isMultiple(val,rate))return val/rate;
        return val/rate+1;
    }

    int findTotalTime(vector<int>&piles,int rate)
    {
        int totalTime=0;
        for(int i=0;i<piles.size();i++)
        {
            totalTime+=findTime(piles[i],rate);
        }
        return totalTime;
    }

    pair<int,int> findUpperLowerBound(vector<int>&piles,int maxVal,int h)
    {
        int lb=maxVal/2;
        int ub=maxVal;
        int totalTime=findTotalTime(piles,lb);
        //cout<<lb<<" mm "<<ub<<" "<<totalTime<<endl;
        while(totalTime<=h)
        {
            ub=lb;
            lb=ub/2;
            totalTime=findTotalTime(piles,lb);
            //cout<<lb<<" "<<ub<<" nn "<<totalTime<<endl;
        }
        return make_pair(lb,ub);
    }

    int findMaximum(vector<int>&piles)
    {
        int maximum=piles[0];
        for(int i=1;i<piles.size();i++)
        {
            if(piles[i]>maximum)maximum=piles[i];
        }
        return maximum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()==1)
        {
            if(piles[0]<=h)return 1;
            int speed=piles[0]/h;
            speed+=piles[0]%h;
            return speed;
        }
        sort(piles.begin(),piles.end());
        int maximum=findMaximum(piles);
        int maxVal,minVal;
        pair<int,int> result=findUpperLowerBound(piles,maximum,h);
        minVal=result.first;
        maxVal=result.second;
        int res=maxVal;
        //cout<<maxVal<<"  "<<minVal<<" "<<res<<endl;
        for(int i=minVal;i<=maxVal;i++)
        {
            if(findTotalTime(piles,i)<=h)
            {
                //cout<<findTotalTime(piles,i)<<"  "<<i<<endl;
                res=i;
                break;
            }
        }
        return res;
    }
};
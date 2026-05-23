class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totsize=gas.size();
        for(int i=0;i<totsize;i++)
        {
            int startingPos=i;
            int j=startingPos;
            int stock=gas[j];
            //cout<<"y "<<j<<endl;
            if(stock<cost[j])continue;
            stock=stock-cost[j];
            j++;
            if(j>=totsize)j=0;
            while(j!=startingPos)
            {
                //cout<<"Yes"<<endl;
                stock+=gas[j];
                if(stock<cost[j])break;
                stock-=cost[j];
                j++;
                if(j>=totsize)j=0;
            }       
            if(j==startingPos)return startingPos;     
        }
        return -1;
    }
};

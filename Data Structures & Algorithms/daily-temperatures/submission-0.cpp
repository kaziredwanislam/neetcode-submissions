class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>res;
        for(int i=0;i<temperatures.size();i++)
        {
            int warmer=i;
            for(int j=i+1;j<temperatures.size();j++)
            {
                if(temperatures[j]>temperatures[i]){
                    warmer=j;
                    break;
                }
            }
            res.push_back(warmer-i);
        }
        return res;
    }
};

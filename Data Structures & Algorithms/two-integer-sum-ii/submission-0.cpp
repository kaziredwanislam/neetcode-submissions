class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>twoSum;
        for(int i=0;i<numbers.size()-1;i++)
        {
            for(int j=i+1;j<numbers.size();j++)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    twoSum.push_back(i+1);
                    twoSum.push_back(j+1);
                    return twoSum;
                }
                if(numbers[i]+numbers[j]>target)break;
            }
        }
        return twoSum;
    }
};

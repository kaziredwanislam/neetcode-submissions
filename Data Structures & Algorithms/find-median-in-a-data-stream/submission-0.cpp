class MedianFinder {
    vector<double>nums;
public:
    MedianFinder() {
        nums.clear();
    }

    int findIndex(int num) {
        int ind=0;
        for(ind=0;ind<nums.size();ind++) {
            if(nums[ind]>num)return ind;
        }
        return ind;
    }
    
    void addNum(int num) {
        int index=findIndex(num);
        nums.insert(nums.begin()+index,num);
    }
    
    double findMedian() {
        if(nums.size()%2==0) {
            double fNum=nums[nums.size()/2-1];
            double sNum=nums[nums.size()/2];
            return (fNum+sNum)/2;
        }

        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int totalOne=0;
        for(int i=0;i<32;i++)
        {
            int res=n&1;
            if(res==1)totalOne++;
            n=n>>1;
        }
        return totalOne;
    }
};

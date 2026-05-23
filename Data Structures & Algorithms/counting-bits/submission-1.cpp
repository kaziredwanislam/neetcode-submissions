class Solution {
public:
    int totalOneBits(int n) {
        
        int num=0;
        while(n>0) {
            int b=(int)log2(n);
            int val=(int)pow(2,b);
            num++;
            n=n-val;
        }  
        return num;  
    }

    vector<int> countBits(int n) {
        vector<int>bits;
        bits.push_back(0);
        for(int i=1;i<=n;i++) {
            bits.push_back(totalOneBits(i));
        }
        return bits;
    }
};

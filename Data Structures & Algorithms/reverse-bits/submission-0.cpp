class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      int newPos=31;
      int newNum=0;
      for(int i=31;i>=0;i--)
      {
        int bit=n&1;
        newNum+=(int)pow(2,i)*bit;
        n=n>>1;
      }  
      return newNum;
    }
};

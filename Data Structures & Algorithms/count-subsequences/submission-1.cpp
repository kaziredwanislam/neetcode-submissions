class Solution {
public:
    void findSubSeq(string longW,string shortW,int index1,int index2,int& totalSubSeq)
    {
        if(index2>=shortW.size())
        {
             totalSubSeq++;
        }
        else
        {
            for(int i=index1;i<longW.size();i++)
            {
                if(longW[i]==shortW[index2])
                {
                    findSubSeq(longW,shortW,i+1,index2+1,totalSubSeq);
                }
            }
        }
    }

    int numDistinct(string s, string t) {
        int len1=s.size();
        int len2=t.size();
        int totalSubSeq=0;
        if(len1<len2)return 0;
        if(len1==len2)
        {
            if(s==t)return 1;
            return 0;
        }
        findSubSeq(s,t,0,0,totalSubSeq);
        return totalSubSeq;
    }
};

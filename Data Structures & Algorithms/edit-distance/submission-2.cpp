class Solution {
public:
int min(int a,int b,int c)
{
    if(a<=b && a<=c)return a;
    if(b<=c && b<=a)return b;
    return c;
}

int min(int a,int b)
{
    if(a<=b)return a;
    return b;
}
    int minDistance(string word1, string word2) {
        if(word2.size()==0)return word1.size();
        if(word1.size()==0)return word2.size();
        int len1=word1.size();
        int len2=word2.size();
        int grid[len1+1][len2+1]={};

        for(int i=0;i<len2+1;i++)grid[0][i]=i;
        for(int i=0;i<len1+1;i++)grid[i][0]=i;

        for(int i=1;i<len1+1;i++)
        {
            for(int j=1;j<len2+1;j++)
            {
                if(word1[i-1]==word2[j-1])grid[i][j]=grid[i-1][j-1];
                else grid[i][j]=min(grid[i][j-1],grid[i-1][j],grid[i-1][j-1])+1;
            }
        }

        /*for(int i=0;i<len1+1;i++)
        {
            for(int j=0;j<len2+1;j++)cout<<grid[i][j]<<" ";
            cout<<endl;
        }*/
        return grid[len1][len2];
    }
};

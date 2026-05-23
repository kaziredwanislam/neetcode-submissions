class Solution {
public:
    void partitionSubstr(vector<int>&substringsNo,int startpos,int lastpos,int substr) {
        for(int i=startpos;i<=lastpos;i++) {
            substringsNo[i]=substr;
        }
    }

    vector<int> partitionLabels(string s) {
        vector<int>alphabets(26,-1);
        vector<int>substringsNo(s.length(),-1);
        int substr=0;
        for(int i=0;i<s.length();i++) {
            int charpos=s[i]-97;
            alphabets[charpos]=i;
        }

        for(int i=0;i<s.length();i++) {
            if(substringsNo[i]==-1) {
                substr++;
                int lastpos=alphabets[s[i]-97];
                partitionSubstr(substringsNo,i,lastpos,substr);
            }

            else {
                int lastpos=alphabets[s[i]-97];
                partitionSubstr(substringsNo,i,lastpos,substr);
            }
        }

        vector<int>substrings(substr,0);
        for(int i=0;i<substringsNo.size();i++) {
            int index=substringsNo[i]-1;
            substrings[index]+=1;
        }

        return substrings;
        //return alphabets;
    }
};

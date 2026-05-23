class Solution {
    int result=0;
public:
    void decode(string s,int index) {
        if(s[index]!='0') {
            result+=1;
            int i=index;
            while(i<s.length()-1) {
                if(s[i]=='2') {
                    if(s[i+1]=='1' ||s[i+1]=='2' || s[i+1]=='3' || s[i+1]=='4' || s[i+1]=='5' || s[i+1]=='6') {
                        decode(s,i+2);
                        //i+=1;
                    }
                    i+=1;
                }
                else if(s[i]=='1' && s[i+1]!='0') {
                    
                    decode(s,i+2);
                    i+=1;
                }
                else i+=1;
            }
        }
        
    }

    int numDecodings(string s) {
        if(s[0]=='0')return result;
        for(int i=0;i<s.length()-1;i++) {
            if(s[i]=='0' && s[i+1]=='0')return 0;
            if((s[i]!='1'&&s[i]!='2')&&(s[i+1]=='0'))return 0;
        }
        decode(s,0);
        return result;
       
    }
};

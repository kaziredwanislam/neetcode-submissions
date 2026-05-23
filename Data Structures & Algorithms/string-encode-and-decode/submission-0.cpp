class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string s:strs) {
            int len=s.length();
            string lenstr=to_string(len);
            if(len<10) {
                encoded+="00"+lenstr+s;
            }
            else if(len<100){
                encoded+="0"+lenstr+s;
            }
            else {
                encoded+=lenstr+s;
            }
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;
        int i=0;
        while(i<s.length()) {
            string lenstr=s.substr(i,3);
            int strlength=stoi(lenstr);
            int strstart=i+3;
            int strend=strstart+strlength;
            string str=s.substr(strstart,strlength);
            decoded.push_back(str);

            i=strend;
        }
        return decoded;
    }
};

class Element{
public:
    string s;
    vector<string>decodeList;
    int lastDoublePos=-1;
    int totalPairs=0;
};

class Solution {
public:
    bool isAllowedStringPair(string w)
    {
            if(w.length()!=2)return false;
            if(w[0]=='1')return true;
            if(w[0]=='2'&&(w[1]=='0'||w[1]=='1'||w[1]=='2'||w[1]=='3'||w[1]=='4'||w[1]=='5'||w[1]=='6'))
            {
                //cout<<"Hahahhah"<<w[0]<<" "<<w[1]<<endl;
                return true;
            }
            return false;
    }

    void bfs(Element &decodeList,int &totalDecodedWays,string s)
    {
        int maxPairs=s.length()/2;
        queue<Element>elementq;
        elementq.push(decodeList);
        while(elementq.size()>0)
        {
            Element curDList=elementq.front();
            elementq.pop();
            if(curDList.totalPairs<maxPairs)
            {
                int curPairPos=curDList.lastDoublePos+1;
                //cout<<curPairPos<<endl;
                for(int i=curPairPos;i<curDList.decodeList.size()-1;i++)
                {
                    if(curDList.decodeList[i].length()==1 && curDList.decodeList[i+1].length()==1)
                    {
                            Element element;
                            vector<string>dList;
                            for(int j=0;j<i;j++)
                            {
                                dList.push_back(curDList.decodeList[j]);
                            }
                            string w=curDList.decodeList[i]+curDList.decodeList[i+1];
                            //cout<<w<<endl;
                            if(!isAllowedStringPair(w))
                            {
                                //cout<<"Ye"<<endl;
                                continue;
                            }
                            dList.push_back(w);
                            for(int j=i+2;j<curDList.decodeList.size();j++)
                            {
                                //cout<<"iiiiiiiiii"<<endl;
                                dList.push_back(curDList.decodeList[j]);
                            }
                            //cout<<"yyy"<<endl;
                            element.s=s;
                            element.decodeList=dList;
                            element.lastDoublePos=i;
                            element.totalPairs=curDList.totalPairs+1;
                            elementq.push(element);
                            totalDecodedWays++;

                    }
                }
            }
        }
    }
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0' && s[i+1]=='0')return 0;
            if(s[i+1]=='0' && (s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'))return 0;
        }
        vector<string>dList;
        int totalPairs=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='0')
            {
                string w;
                w+=s[i];
                dList.push_back(w);
                //cout<<w<<endl;
            }
            else
            {
                dList[i-1]=dList[i-1]+'0';
                totalPairs++;
                //cout<<dList[i-1]<<endl;
            }
        }
        Element element;
        element.s=s;
        element.decodeList=dList;
        element.totalPairs=totalPairs;
        int totalDecodedWays=1;
        bfs(element,totalDecodedWays,s);
        return totalDecodedWays;
    }
};
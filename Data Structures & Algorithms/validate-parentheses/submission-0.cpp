class Solution {
public:
    bool isValid(string s) {
        stack<int>p;
        if(s[0]==')'|| s[0]=='}' || s[0]==']')return false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                p.push(s[i]);
            }
            else
            {
                if(p.empty())return false;
                char c=p.top();
                p.pop();
                if(s[i]==')' && c=='(')continue;
                if(s[i]=='}'&&c=='{')continue;
                if(s[i]==']' && c=='[')continue;
                return false;
            }
        }
        if(p.empty())return true;
        return false;
    }
};

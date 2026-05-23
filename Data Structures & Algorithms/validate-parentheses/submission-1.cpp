class Solution {
public:
    bool isValid(string s) {
        stack<char>brackets;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                brackets.push(s[i]);
            }
            else {
                if(brackets.size()==0)return false;
                if(s[i]==')' && brackets.top()!='(')return false;
                else if(s[i]=='}' && brackets.top()!='{')return false;
                else if(s[i]==']' && brackets.top()!='[')return false;

                brackets.pop();
            }
        }
        if(brackets.size()==0)return true;
        return false;
    }
};

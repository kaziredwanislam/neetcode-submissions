class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]!="*"&&tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="/")
            {
                //cout<<tokens[i]<<endl;
                int n=stoi(tokens[i]);
                nums.push(n);
                //cout<<n<<endl;
            }
            else
            {
                int num1=nums.top();
                nums.pop();
                int num2=nums.top();
                nums.pop();
                //cout<<"Yes"<<endl;
                if(tokens[i]=="+")nums.push(num1+num2);
                if(tokens[i]=="-")nums.push(num2-num1);
                if(tokens[i]=="*")nums.push(num2*num1);
                if(tokens[i]=="/")nums.push(num2/num1);
            }
        }
        return nums.top();
    }
};

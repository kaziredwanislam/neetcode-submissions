class Solution {
    vector<string>parenthesesList;
public:
    void rgp(string p,int left_p,int right_p,int n) {
        if(left_p==right_p && left_p==n) {
            parenthesesList.push_back(p);
            
        }

        if(right_p<=left_p) {
            if(left_p<n)rgp(p+'(',left_p+1,right_p,n);
            if(right_p<n)rgp(p+')',left_p,right_p+1,n);
        }
    }

    vector<string> generateParenthesis(int n) {
        string p="(";
        rgp(p,1,0,n);
        return parenthesesList;
    }
};

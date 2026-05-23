class Solution {
public:
    void showV(vector<int>v)
    {
        for(int n:v)
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>cintervals;
        int hasEntered=0;
        for(vector<int>v:intervals)
        {
            if(v[1]<newInterval[0])cintervals.push_back(v);
            if(v[0]<=newInterval[0] && v[1]>=newInterval[0] && v[1]<=newInterval[1]){
                newInterval[0]=v[0];
            }
            if(v[0]<=newInterval[0] && v[1]>newInterval[1])
            {
                newInterval[0]=v[0];
                newInterval[1]=v[1];
            }
            if(v[0]==newInterval[1])
            {
                
                //cout<<"V: "<<v[0]<<" "<<newInterval[1]<<endl;
                newInterval[1]=v[1];
                //showV(newInterval);
                //cintervals.push_back(newInterval);
                //hasEntered=1;
            }
            if(v[0]>newInterval[1] && hasEntered==1)
            {
                cintervals.push_back(v);
            }
            
            if(v[0]>newInterval[1]&&hasEntered==0)
            {
                cintervals.push_back(newInterval);
                cintervals.push_back(v);
                hasEntered=1;
            }



            if(v[0]<=newInterval[1] && v[1]>=newInterval[1])
            {
                newInterval[1]=v[1];
                //cout<<"mm: ";
                //showV(newInterval);
            }
        }
        if(hasEntered==0)cintervals.push_back(newInterval);
        return cintervals;
    }
};

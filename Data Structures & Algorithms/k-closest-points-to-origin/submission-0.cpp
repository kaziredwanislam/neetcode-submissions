class coordinate{
    public:
        int x;
        int y;
        int distance;
        void distancefromorigin()
        {
            distance=x*x+y*y;
        }
};


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            vector<coordinate>cvec;
            for(vector<int>v:points)
            {
                coordinate c;
                c.x=v[0];
                c.y=v[1];
                c.distancefromorigin();
                cvec.push_back(c);
            }
            for(int i=0;i<cvec.size();i++)
            {
                for(int j=i+1;j<cvec.size();j++)
                {
                    if(cvec[j].distance<cvec[i].distance)
                    {
                        coordinate temp=cvec[i];
                        cvec[i]=cvec[j];
                        cvec[j]=temp;
                    }
                }
            }

            vector<vector<int>>res;
            for(int i=0;i<k;i++)
            {
                vector<int>v;
                v.push_back(cvec[i].x);
                v.push_back(cvec[i].y);
                res.push_back(v);
            }
            return res;
    }
};

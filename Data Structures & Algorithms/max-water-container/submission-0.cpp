class Solution {
public:
    int min(int a,int b)
    {
        if(a<=b)return a;
        return b;
    }

    int maxElement(vector<int>&v)
    {
        int maxE=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i]>maxE)maxE=v[i];
        }
        return maxE;
    }

    int getMaxArea(vector<int>&heights,int index)
    {
        int firstBar=heights[index];
        int maxArea=0;
        for(int j=index+1;j<heights.size();j++)
        {
            int secondBar=heights[j];
            int area=min(firstBar,secondBar)*(j-index);
            if(area>maxArea)maxArea=area;
        }
        return maxArea;
    }

    int maxArea(vector<int>& heights) {
        vector<int>maxAreas;
        for(int i=0;i<heights.size()-1;i++)
        {
            int maxArea=getMaxArea(heights,i);
            maxAreas.push_back(maxArea);
        }
        return maxElement(maxAreas);
    }
};

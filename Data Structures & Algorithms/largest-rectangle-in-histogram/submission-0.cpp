class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        for(int i=0;i<heights.size();i++) {
            int area=heights[i];
            for(int j=i-1;j>=0;j--) {
                if(heights[j]<heights[i])break;
                area+=heights[i];
            }

            for(int k=i+1;k<heights.size();k++) {
                if(heights[k]<heights[i])break;
                area+=heights[i];
            }

            if(area>maxArea) maxArea=area;
        }
        return maxArea;
    }
};

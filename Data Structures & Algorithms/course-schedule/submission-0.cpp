class Solution {
public:
    bool hasCycle(vector<vector<int>>& courses,int src)
    {
       vector<int>visited;
        for(int i=0;i<courses.size();i++)
        {
            visited.push_back(0);
        }

        stack<int>cstack;
        cstack.push(src);
        visited[src]=1;
        while(!cstack.empty())
        {
            int curCourse=cstack.top();
            cstack.pop();
            for(int i=0;i<courses.size();i++)
            {
                if(courses[curCourse][i]==1)
                {
                    if(visited[i]==1)return true;
                    cstack.push(i);
                }
            }
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)return true;
        vector<vector<int>>courses;
        for(int i=0;i<numCourses;i++)
        {
            vector<int>course;
            for(int  j=0;j<numCourses;j++)
            {
                course.push_back(0);
            }
            courses.push_back(course);
        }

        for(vector<int>prerequisite:prerequisites)
        {
            courses[prerequisite[1]][prerequisite[0]]=1;
        }

        for(int i=0;i<numCourses;i++)
        {
            if(hasCycle(courses,i))return false;
        }
        return true;
    }
};


class Task {
public:
    char ch;
    int freq=0;
    int available_time=0;

    Task(char c,int f){ch=c;freq=f;}

    bool operator<(const Task& other )const {
        return freq<other.freq;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<Task>alph;
        for(int i=0;i<26;i++) {
            Task task(i+'A',0);
            alph.push_back(task);
        }

        for(int i=0;i<tasks.size();i++) {
            //cout<<"task: "<<tasks[i]-'A'<<endl;
            alph[tasks[i]-'A'].freq++;
        }

        priority_queue<Task>pqTask;
        for(int i=0;i<alph.size();i++) {
            if(alph[i].freq>0)pqTask.push(alph[i]);
        }

        queue<Task>waitingTask;
        int tot_tasks=tasks.size();
        int cur_time=0;
        while(tot_tasks>0) {
            cur_time++;
            //cout<<"cur_time: "<<cur_time<<endl;
            
            if(!waitingTask.empty()){
                Task task=waitingTask.front();
                if(task.available_time<=cur_time) {
                    waitingTask.pop();
                    pqTask.push(task);
                }
            }

            if(!pqTask.empty()) {
                Task task=pqTask.top();
                task.freq--;
                tot_tasks--;
                pqTask.pop();

                if(task.freq>0) {
                    task.available_time=cur_time+n+1;
                    waitingTask.push(task);
                }
            }
        }
        return cur_time;
    }
};
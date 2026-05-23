class HashSet {
vector<vector<int>>HashAra;
int index;
public:
    HashSet(int ind){
        index=ind;
        //cout<<"index:"<<index<<endl;
        for(int i=0;i<ind;i++)
        {
            vector<int>v;
            HashAra.push_back(v);
        }
        //cout<<"HashAra size: "<<HashAra.size()<<endl;
    }

    void insert(int e) {
        int elem=e;
        if(e<0)elem=-e;
        else elem=e;
        if(!isPresent(e)) {
            int ind=elem%(index);
            //cout<<ind<<" "<<index<<endl;
            HashAra[ind].push_back(e);
            //cout<<e<<" Pushed at index "<<ind<<endl;
        }
    }

    bool isPresent(int e) {
        int elem;
        if(e<0)elem=-e;
        else elem=e;
        int ind=elem%(index);
        for(int i=0;i<HashAra[ind].size();i++) {
            if(HashAra[ind][i]==e){
                //cout<<"Found: "<<e<<endl;
                return true;
            }
        }
        return false;
    }

    void showList() {
        int row=0;
        for(vector<int>v:HashAra) {
            //cout<<"Row: "<<row++<<" " <<v.size()<<endl;
            for(int n:v) {
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        HashSet hashSet(10);
        vector<int>cons_seq_startings;
        for(int i=0;i<nums.size();i++) {
            //cout<<"Inserting: "<<nums[i]<<endl;
            hashSet.insert(nums[i]);
        }
        hashSet.showList();
        //cout<<endl<<endl;
        for(int i=0;i<nums.size();i++) {
            int n=nums[i];
            //cout<<n<<" "<<hashSet.isPresent(nums[i]+1)<<endl;
            if(hashSet.isPresent(nums[i]+1)) {
                //cout<<"U"<<endl;
                //cout<<"push: "<<nums[i]<<endl;
                cons_seq_startings.push_back(nums[i]);
            }
        }

        if(cons_seq_startings.size()==0)return 1;
        int max_seq=1;
        for(int i=0;i<cons_seq_startings.size();i++) {
            int cur_num=cons_seq_startings[i];
            int cur_max_seq=1;
            while(true){
                cur_num++;
                if(hashSet.isPresent(cur_num)) {
                    cur_max_seq++;
                }
                else break;
            }
            if(max_seq<cur_max_seq){
                max_seq=cur_max_seq;
                //cout<<"cnum: "<<cur_num<<" "<<max_seq<<endl;
            }
        }
        return max_seq;
    }
};

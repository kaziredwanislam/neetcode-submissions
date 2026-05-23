class Car{
public:
    int pos;
    int speed;
};

bool compareByPosDesc(const Car& c1,const Car& c2) {
    return c1.pos>c2.pos;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int tot_car=position.size();
        vector<Car>cars;
        for(int i=0;i<position.size();i++) {
            Car ncar;
            ncar.pos=position[i];
            ncar.speed=speed[i];
            cars.push_back(ncar);
        }

        sort(cars.begin(),cars.end(),compareByPosDesc);

        //for(int i=0;i<cars.size();i++) {
           // cout<<"pos: "<<cars[i].pos<<"  speed: "<<cars[i].speed<<endl;
        //}
        float curmaxtime=(float)(target-cars[0].pos)/cars[0].speed;
        int carFleetNum=1;
        for(int i=1;i<cars.size();i++) {
            float curtime=(float)(target-cars[i].pos)/cars[i].speed;
            cout<<curtime<<endl;
            if(curtime>curmaxtime) {
                curmaxtime=curtime;
                carFleetNum++;
            }
        }

        return carFleetNum;
    }
};

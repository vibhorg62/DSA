class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int val=INT_MAX;
        int ind=0;
        int temp=0;
        for(int i=0;i<drones.size();i++){
            int a=drones[i][0];
            int b=drones[i][1];
            int r=drones[i][2];
            int dis=abs(a-target[0])+abs(b-target[1]);
            if(dis<=r){
                temp=val;
                val=min(val,dis);
                if(temp!=val) ind=i;
            }
        }
        if(val==INT_MAX) return -1;
        return ind;
    }
};
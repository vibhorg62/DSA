class Solution {
public:
    void solve(string &arr,int &day,int &month){
        string m ="";
        string d ="";
        int idx = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='-'){
                idx=i;
                break;
            }
            m+=arr[i];
        }
        for(int j=idx+1;j<arr.size();j++){
            d+=arr[j];
        }
        month = stoi(m);
        day = stoi(d);
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string arr = max(arriveAlice,arriveBob);
        string res = min(leaveAlice,leaveBob);
        int aday = 0,amonth = 0;
        int lday = 0,lmonth = 0;
        solve(arr,aday,amonth);
        solve(res,lday,lmonth);
        int ini = 0;
        int fini = 0;
        for(int i=0;i<amonth-1;i++){
            ini+=a[i];
        }
        ini+=aday;
        for(int i=0;i<lmonth-1;i++){
            fini+=a[i];
        }
        fini+=lday;
        return max(0,fini-ini+1);
    }
};
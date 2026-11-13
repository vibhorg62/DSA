class Solution {
public:
    bool repeatedStringMatch(string a, string b, int x, int y) {
        long long n = a.size();
        long long m = b.size();
        long long t_a = n*x;
        long long t_b = m*y;
        if(t_b > t_a) return false;
        long long check_len = min(t_b,n+m);
        for(int start = 0; start<n; start++){
            if(start+t_b > t_a) break;
            bool ok = true;
            for(long long k=0; k<check_len; k++){
                if(a[(start + k)%n]!=b[(k)%m]){
                    ok=false;
                    break;
                }
            }
            if(ok) return true;
        }
        return false;
    }
};
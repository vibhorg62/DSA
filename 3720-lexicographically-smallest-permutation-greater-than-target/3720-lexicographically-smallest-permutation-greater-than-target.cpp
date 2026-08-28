class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        map<char,int> mpp;
        string ans="";
        for(char c:s) mpp[c]++;
        for(int i=0;i<t.size();i++){
            if(mpp[t[i]]>0){
                ans+=t[i];
                mpp[t[i]]--;
            }
            else{
                for(char c=t[i]+1;c<='z';c++){
                    if(mpp[c]>0){
                        ans+=c;
                        mpp[c]--;

                        for(auto x:mpp)
                            ans+=string(x.second,x.first);

                        return ans;
                    }
                }
                break;
            }
        }
        for(int i=ans.size()-1;i>=0;i--){
            mpp[ans[i]]++;

            for(char c=t[i]+1;c<='z';c++){
                if(mpp[c]>0){
                    string res=ans.substr(0,i);
                    res+=c;
                    mpp[c]--;
                    for(auto x:mpp)
                        res+=string(x.second,x.first);

                    return res;
                }
            }
        }
        return "";
    }
};
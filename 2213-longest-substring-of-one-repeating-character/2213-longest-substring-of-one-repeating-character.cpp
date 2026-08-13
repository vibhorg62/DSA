class Solution {
public:
    struct Node{
        int maxlen;
        char leftchar,rightchar;
        int pref,suff;
    };
    vector<Node>seg;
    Node merge(Node a,Node b,int lenA,int lenB){
        Node c;
        c.leftchar=a.leftchar;
        c.rightchar=b.rightchar;

        c.pref=a.pref;
        c.suff=b.suff;

        c.maxlen=max(a.maxlen,b.maxlen);

        if(a.rightchar==b.leftchar){
            c.maxlen=max(c.maxlen,a.suff+b.pref);

            if(a.pref==lenA) c.pref=lenA+b.pref;
            if(b.suff==lenB) c.suff=lenB+a.suff;
        }

        return c;
    }

    void solve(int idx,int l,int r,string &s,int pos=-1,char ch='#'){
        if(l==r){
            if(pos==l) s[l]=ch;
            seg[idx]={1,s[l],s[l],1,1};
            return;
        }
        int m=(l+r)/2;
        if(pos==-1 || pos<=m) solve(idx*2,l,m,s,pos,ch);
        if(pos==-1 || pos>m) solve(idx*2+1,m+1,r,s,pos,ch);
        seg[idx]=merge(seg[idx*2],seg[idx*2+1],m-l+1,r-m);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        seg.resize(4*n);
        solve(1,0,n-1,s);
        vector<int>ans;
        for(int i=0;i<queryCharacters.size();i++){
            solve(1,0,n-1,s,queryIndices[i],queryCharacters[i]);
            ans.push_back(seg[1].maxlen);
        }
        return ans;
    }
};
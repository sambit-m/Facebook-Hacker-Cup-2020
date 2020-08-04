#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void build(vector<ull>& t, ull v, int l ,int r, vector<ull> arr,int m){
    if(l==r){
        t[v] = 1e18L+5;
    }else{
        int mid = (l+r)/2;
        build(t, 2*v,l,mid, arr,m);
        build(t, 2*v+1, mid+1, r, arr,m);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

ull qry(vector<ull>& t, ull v, int l ,int r, int tl ,int tr){
    if(tl>tr){
        return 1e18L+5;
    }
    if(l==tl && r==tr)
        return t[v];
    int mid = (l+r)/2;
    return min(qry(t, 2*v, l, mid, tl, min(mid, tr)),qry(t, 2*v+1, mid+1, r, max(tl, mid+1), tr));
}
void update(vector<ull>& t, ull v, int tl, int tr, int pos, ull new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(t,v*2, tl, tm, pos, new_val);
        else
            update(t,v*2+1, tm+1, tr, pos, new_val);
        t[v] = min(t[v*2], t[v*2+1]);
    }
}
int main() {
    string name = "d1";
    freopen((name +"_in"+".txt").c_str(), "r", stdin);
	freopen((name +"_out"+".txt").c_str(), "w", stdout);
    int t;
    cin>>t;
    int cn = 1;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<ull> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ull ts = 1;
        while(ts<n){
            ts*=2;
        }
       vector<ull> t(2*ts, 1e18L+5);
        update(t,1,0,n-1,0,0);
        ull ans=0;
        for(int i=1;i<n-1;i++){
            if(arr[i]!=0){
                ull c = qry(t,1,0,n-1,max(0,i-m), i-1);
                update(t,1,0,n-1,i,c+arr[i]);
            }
        }
        ans = qry(t,1,0,n-1,max(0,n-1-m),n-1);
        if(ans>=(ull)1e18L+5){
            cout<<"Case #"<<cn<<": "<<-1<<endl;
        }else
            cout<<"Case #"<<cn<<": "<<ans<<endl;
        cn++;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}

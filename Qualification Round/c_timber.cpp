#include<bits/stdc++.h>
using namespace std;
int main() {
    string name = "c";
    freopen((name +"_in"+".txt").c_str(), "r", stdin);
	freopen((name +"_out"+".txt").c_str(), "w", stdout);
    int t;
    cin>>t;
    int cn = 1;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++){
            int p,h;
            cin>>p>>h;
            arr[i] = make_pair(p,h);
        }
        sort(arr.begin(), arr.end());
        map<int,int> dp;
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[arr[i].first+arr[i].second] = max(dp[arr[i].first+arr[i].second], dp[arr[i].first]+arr[i].second);
            dp[arr[i].first] = max(dp[arr[i].first], dp[arr[i].first-arr[i].second]+arr[i].second);
            ans = max({ans, dp[arr[i].first+arr[i].second], dp[arr[i].first]});
        }
        cout<<"Case #"<<cn<<": "<<ans<<endl;
        cn++;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}

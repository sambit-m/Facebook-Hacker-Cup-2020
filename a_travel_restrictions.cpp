#include<bits/stdc++.h>
using namespace std;

int main() {
    string name = "a";
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    int t;
    cin>>t;
    int cn = 1;
    while(t--){
        int n;
        string inc,out;
        cin>>n;
        cin>>inc;
        cin>>out;
        vector<vector<int>> ans(n, vector<int>(n,0));
        for(int i=0;i<n;i++){
            ans[i][i]=1;
            for(int j=i+1;j<n;j++){
                 if(abs(i-j)==1){
                    if(out[i]=='Y' && inc[j]=='Y')
                       ans[i][j]=1;
                    else
                        ans[i][j]=0;
                }else{
                    if(j>1 && ans[i][j-1]){
                        if(out[j-1]=='Y' && inc[j]=='Y')
                            ans[i][j]=1;
                    }
                }
            }
            for(int j=i-1;j>=0;j--){
                if(abs(i-j)==1){
                    if(out[i]=='Y' && inc[j]=='Y')
                       ans[i][j]=1;
                    else
                        ans[i][j]=0;
                }else{
                    if(j<n-1 && ans[i][j+1]){
                        if(out[j+1]=='Y' && inc[j]=='Y')
                            ans[i][j]=1;
                    }
                }
            }
        }
        cout<<"Case #"<<cn<<": "<<endl;;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j])
                    cout<<'Y';
                else
                    cout<<'N';
            }
            cout<<endl;
        }
        cn++;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}

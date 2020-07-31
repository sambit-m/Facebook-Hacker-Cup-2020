#include<bits/stdc++.h>
using namespace std;
int main() {
    string name = "b";
    freopen((name +"_in"+".txt").c_str(), "r", stdin);
	freopen((name +"_out"+".txt").c_str(), "w", stdout);
    int t;
    cin>>t;
    int cn = 1;
    while(t--){
        int n;
        string c;
        cin>>n;
        cin>>c;
        int a=0,b=0;
        for(char ch:c){
            if(ch=='A')
                a++;
            else
                b++;
        }
        cout<<"Case #"<<cn<<": ";
        if(abs(a-b)==1)
            cout<<"Y"<<endl;
        else
            cout<<"N"<<endl;
        cn++;
    }
    fclose(stdout);
    fclose(stdin);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define f first
#define s second
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
#define inf 9223372036854775807
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
                 
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        int n,q;
        cin>>n>>q;
        vector<ll> v;
        int a[n+3][31];
        int pref[n+3][31];
        for(int i=0;i<n;i++){
            for(int j=0;j<31;j++){
                a[i][j] = 0;  
                pref[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            int c = 0;
            ll ans = -1;
            ll mul = 1;
            while(x!=0){
                if((x&1)==1){
                    ans = c;
                }
                mul*=2;
                x/=2;
                c++;
            }
            v.pb(ans);
            if(ans==-1) continue;
            a[i][ans] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<31;j++){
                pref[i][j] = pref[i-1][j] + a[i-1][j];
            }
        }
        cout<<"Case "<<tt<<":"<<endl;
        while(q--){
            int x,y;
            cin>>x>>y;
            ll mul = 1;
            ll sum = 0;
            for(int i=0;i<31;i++){
                if(pref[y][i] - pref[x-1][i]>0){
                    sum+=mul;
                }
                mul*=2;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

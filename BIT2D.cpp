#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
long long n,a[1001][1001],bit[1001][1001];
void update(int x,int y,long long val) {
    while(x<=n){
        int y1 = y;
        while(y1<=n) {
            bit[x][y1] += val;
             y1 += (y1&-y1);
        }
        x += (x&-x);
    }
}
long long get(int x,int y) {
    long long ans = 0;
    while(x > 0) {
            int y1 = y;
        while(y1 > 0) {
            ans += bit[x][y1];
            y1 -= (y1&-y1);
        }
        x -= (x&-x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        cin>>a[i][j];
        update(i,j,a[i][j]);
    }
    int q;
    cin>>q;
    while(q--) {
        int sit;
        cin>>sit;
        if(sit==1) {
            long long u,v,va;
            cin>>u>>v>>va;
            update(u,v,va);
        } else {
            int x,y,u,v;
            cin>>x>>y>>u>>v;
            cout<<1LL * (get(u,v) - get(x-1,v) - get(u,y-1) + get(x-1,y-1))<<'\n';
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6+7;
int n,m,bit[N],bitr[N],lef[N],rig[N],b[N];
pair<int,int> a[N];
map<string,int> MM;
priority_queue<pair<int,pair<int,int>>> dt;
void update(int x,int val)
{
    while(x<=n)
    {
        bit[x] = max(bit[x],val);
        x += (x&-x);
    }
}
void update2(int x,int val)
{
    while(x<=n)
    {
        bit[x] = min(bit[x],val);
        x += (x&-x);
    }
}
int get(int x)
{
    int ans = 0;
    while(x > 0)
    {
        ans = max(ans,bit[x]);
        x -= (x&-x);
    }
    return ans;
}
int get2(int x)
{
    int ans = m;
    while(x > 0)
    {
        ans = min(ans,bit[x]);
        x -= (x&-x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].fi;
        a[i].se = i;
        b[i] = a[i].fi;
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++)
    {
        lef[a[i].se] = get(a[i].se-1);
        update(a[i].se,a[i].fi);
    }

    for(int i=1;i<=n;i++) bit[i] = m;

    for(int i=n;i>0;i--)
    {
        rig[a[i].se] = get2(a[i].se-1);
        update2(a[i].se,a[i].fi);
    }

    for(int i=1;i<=n;i++) {
            dt.push({b[i] - lef[i],{lef[i],b[i]}});
            dt.push({rig[i] - b[i],{b[i],rig[i]}});
            MM[to_string(lef[i]) + '_' + to_string(rig[i])] = 1;
            while(!dt.empty() && MM[to_string(dt.top().se.fi) + '_' + to_string(dt.top().se.se)]==1) dt.pop();
            cout<<dt.top().fi<<" ";
    }

    return 0;
}

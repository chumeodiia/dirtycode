#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,m,a[N],b[N],nextt[N],pr[N],c[N],ok[N],valuee;
int get(int val)
{
    int l = 1;
    int r = n;
    int ans = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid] <= val)
        {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}
void dq(int x,int pos)
{
    if(x==0) {
        pr[pos] = 0;
        return;
    }

    if(nextt[x]==x) {
        if(x > 0) nextt[x] = x-1;
        valuee = x-1;
        pr[pos] = x;
        return;
    }
    dq(nextt[x],pos);
    nextt[x] = valuee;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
            cin>>a[i];
            nextt[i] = i;
    }

    sort(a+1,a+1+n);

    for(int i=1;i<=m;i++) {
        cin>>b[i];
        int pos = get(b[i]);
        c[i] = pos;
    }

    for(int i=1;i<=m;i++) {
            valuee = 0;
       dq(c[i],i);
    }

    for(int i=1;i<=m;i++) {
       if(pr[i] <= 0) cout<<-1<<'\n'; else cout<<a[pr[i]]<<'\n';
    }
    return 0;
}

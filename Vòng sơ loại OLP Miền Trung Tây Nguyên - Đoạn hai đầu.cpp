#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6+7;
int n,a[N],mari[N],miri[N],bit[N];
long long res = 0;
pair<int,int> male[N],mile[N];
stack<int> dtma,dtmi;
void update(int x)
{
    while(x <= n)
    {
        bit[x]++;
        x += (x&-x);
    }
}
long long get(int x)
{
    long long ans = 0;
    while(x > 0)
    {
        ans += bit[x];
        x -= (x&-x);
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        while(dtma.size() > 0 && a[dtma.top()] < a[i]) dtma.pop();
        if(dtma.size() > 0) male[i].fi = dtma.top();
        dtma.push(i);

         while(dtmi.size() > 0 && a[dtmi.top()] > a[i]) dtmi.pop();
        if(dtmi.size() > 0) mile[i].fi = dtmi.top();
        dtmi.push(i);

        male[i].se = mile[i].se = i;
    }

    sort(male+1,male+1+n);
    sort(mile+1,mile+1+n);

    while(!dtma.empty()) dtma.pop();
    while(!dtmi.empty()) dtmi.pop();

    for(int i=n;i>0;i--)
    {
        while(dtma.size() > 0 && a[dtma.top()] < a[i]) dtma.pop();
        if(dtma.size() > 0) mari[i] = dtma.top(); else mari[i] = n+1;
        dtma.push(i);

         while(dtmi.size() > 0 && a[dtmi.top()] > a[i]) dtmi.pop();
        if(dtmi.size() > 0) miri[i] = dtmi.top(); else miri[i] = n+1;
        dtmi.push(i);
    }
    int j = 1;
    for(int i=1;i<=n;i++)
    {
        int u = i;
        int v = miri[i]-1;

        while(j<=n && male[j].fi < u) {
            update(male[j].se);
            j++;
        }
        res += get(v) - get(u-1);
    }

    for(int i=1;i<=n;i++) bit[i] = 0;
    j = 1;

    for(int i=1;i<=n;i++)
    {
        int u = i;
        int v = mari[i] - 1;

        while(j <= n && mile[j].fi < u)
        {
            update(mile[j].se);
            j++;
        }

        res += get(v) - get(u-1);
    }
    cout<<res-n;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,a[N],q,lef[N];
stack<int> dt;
vector<int> st[N];
void build(int id, int l,int r)
{
    if(l > r) return;

    if(l==r) {
        st[id].push_back(lef[l]);
        return;
    }

    int mid = (l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    //merge_sort

    int i = 0;
    int j = 0;

    st[id*2].push_back(1e9+7);
    st[id*2+1].push_back(1e9+7);

    while(i <= st[id*2].size() && j <= st[id*2+1].size())
    {
        if(i==st[id*2].size()-1 && j==st[id*2+1].size()-1) break;

        if(st[id*2][i] < st[id*2+1][j])
        {
            st[id].push_back(st[id*2][i]);
            i++;
        } else if(st[id*2][i] >= st[id*2+1][j])
        {
            st[id].push_back(st[id*2+1][j]);
            j++;
        }
    }

    st[id*2].pop_back();
    st[id*2+1].pop_back();
}
long long get_fenwick(int id,int l,int r,int u,int v,int k)
{
    if(l > v || r < u) return 0;

    if(l >= u && r <= v)
    {
        int l = 0, r = st[id].size()-1;
        int ans = -1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(st[id][mid] < k) ans = mid, l = mid + 1; else r = mid - 1;
        }

        return ans + 1;
    }

    int mid = (l+r)/2;

    return get_fenwick(id*2,l,mid,u,v,k) + get_fenwick(id*2+1,mid+1,r,u,v,k);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        while(dt.size() > 0 && a[dt.top()] <= a[i]) dt.pop();
        if(dt.size() > 0) lef[i] = dt.top();
        dt.push(i);
    }
    build(1,1,n);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<get_fenwick(1,1,n,l,r,l)<<'\n';
    }
    return 0;
}

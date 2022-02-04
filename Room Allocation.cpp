#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,f[N],pr[N];
struct hihi {
    int va;
    int la;
};
hihi st[N];
struct haha {
    int start;
    int endd;
    int poss;
};
bool quick(const haha x, const haha y) {
    return x.start < y.start;
}
bool qu(const haha x, const haha y) {
    return x.endd < y.endd;
}
haha a[N];
void doo()
{
    int i = 1;
    int j = 1;
    while(i<=n && j<=n)
    {
        while(a[i].start == a[j].start && j<=n) j++;
        sort(a+i,a+j,qu);
        i = j;
    }
}
void build(int id,int l,int r)
{
    if(l > r) return;
    if(l==r) {
        st[id].va = l;
        return;
    }
    int mid = (l+r)/2;

    build(id*2,l,mid);
    build(id*2+1,mid+1,r);

    if(f[st[id*2].va] <= f[st[id*2+1].va]) st[id].va = st[id*2].va; else st[id].va = st[id*2+1].va;
}
void lazy(int id) {
    int pos = st[id].la;
    if(pos != 0) {
        st[id*2].va = pos;
        st[id*2].la = pos;
        st[id*2+1].va = pos;
        st[id*2+1].la = pos;
    }
    st[id].la = 0;
}
void update(int id,int l,int r,int u,int v,int pos)
{
    if(l > v || r < u) return;
    if(l>=u && r<=v) {
        st[id].va = pos;
        st[id].la = pos;
        return;
    }
    int mid = (l+r)/2;
    lazy(id);

    update(id*2,l,mid,u,v,pos);
    update(id*2+1,mid+1,r,u,v,pos);

    if(f[st[id*2].va] <= f[st[id*2+1].va]) st[id].va = st[id*2].va; else st[id].va = st[id*2+1].va;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
            cin>>a[i].start>>a[i].endd;
            a[i].poss = i;
    }

    sort(a+1,a+1+n,quick);

    doo();
    for(int i=0;i<=n;i++) f[i] = 1e9+7;
    build(1,1,n);
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        int pos = st[1].va;
        if(f[pos] >= a[i].start) {
            cnt++;
            pr[a[i].poss] = cnt;
            f[cnt] = a[i].endd;
            update(1,1,n,cnt,cnt,cnt);
        } else {
            pr[a[i].poss] = pos;
            f[pos] = a[i].endd;
            update(1,1,n,pos,pos,pos);
        }
    }
    cout<<cnt<<'\n';
    for(int i=1;i<=n;i++) cout<<pr[i]<<" ";
    return 0;
}

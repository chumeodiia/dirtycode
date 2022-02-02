#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,a[N],m,pre=1,b[N];
void make_it_complicated(int x, int y)
{
    if(a[x] > a[y]) pre--;
    if(a[y] > a[x]) pre++;
    if(a[x-1] > a[x]) pre--;
    if(a[x-1] > a[y]) pre++;
    if(a[y] > a[y+1]) pre--;
    if(a[x] > a[y+1]) pre++;

    cout<<pre<<'\n';
    swap(a[x],a[y]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
            cin>>b[i];
            a[b[i]] = i;
    }
    for(int i=1;i<=n;i++) if(a[i-1] > a[i]) pre++;

    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        int x = b[u], y = b[v];

        if(x > y) swap(x,y);

        if(x+1==y) make_it_complicated(x,y); else {

        //clear result of pre variable
        if(a[x-1] > a[x]) pre--;
        if(a[x] > a[x+1]) pre--;
        if(a[y-1] > a[y]) pre--;
        if(a[y] > a[y+1]) pre--;
        //calculate result of this test
        if(a[x-1] > a[y]) pre++;
        if(a[y] > a[x+1]) pre++;
        if(a[y-1] > a[x]) pre++;
        if(a[x] > a[y+1]) pre++;
        swap(a[x],a[y]);
        cout<<pre<<'\n';
        }

        swap(b[u],b[v]);
    }
    return 0;
}

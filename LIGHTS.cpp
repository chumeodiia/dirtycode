#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,m,status[N],res = 1e9+7,x[N];
vector<int> a[N];
map<string,int> MM;
void doo(int x)
{
    if(status[x] == 1) status[x] = 0; else status[x] = 1;
    for(int i: a[x]) if(status[i]==1) status[i] = 0; else status[i] = 1;
}
void dq_1(int i)
{
    for(int j=0;j<2;j++)
    {
        x[i] = j;
        if(i==(n+1)/2)
        {
            //clear array
            for(int k=1;k<=n;k++) status[k] = 0;
            //checkbit
            int cnt = 0;
            for(int k=1;k<=(n+1)/2;k++)
            {
                if(x[k]==1) {
                        doo(k);
                        cnt++;
                }
            }
            //con bo YURAN
            string s = "";
            for(int k=1;k<=n;k++)
                if(status[k] == 1) s += '1'; else s += '0';
            //cout<<s<<" "<<cnt<<'\n';
            if(MM[s]==0) MM[s] = cnt; else MM[s] = min(MM[s],cnt);

        } else dq_1(i+1);
    }
}
void dq_2(int i)
{
    for(int j=0;j<2;j++)
    {
        x[i] = j;
        if(i==n)
        {
            //clear array
            for(int k=1;k<=n;k++) status[k] = 0;
            //checkbit
            int cnt = 0;
            for(int k=(n+1)/2 + 1;k <= n;k++)
                if(x[k]==1)
                {
                    doo(k);
                    cnt++;
                }

            string s = "", t = "";
            for(int k=1;k<=n;k++)
                if(status[k]==1) t+='0'; else t+='1';
            //cout<<t<<" "<<cnt<<'\n';
            //if(MM[s] > 0) res = min(res,cnt + MM[s]);
            if(MM[t] > 0) res = min(res,cnt + MM[t]);
        } else dq_2(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("LIGHTS.INP","r",stdin);
    freopen("LIGHTS.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dq_1(1);
    //cout<<"------------------------------------------------------ \n";
    dq_2((n+1)/2 + 1);

    cout<<res;
    return 0;
}

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6+7;
const int MOD = 1e9+7;
long long n,a[N],m,d[N],f[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    bool ok = false;
    for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i] != a[i-1] && i > 1) ok = true;
    }

    if(ok==true || (ok==false && m==1)) f[0] = 1;

    int j = 1;
    int cnt = 0;

    for(int i=1;i<=n;i++)
    {
        while(cnt < m && j<=n)
        {
            if(d[a[j]]==0) cnt++;
            d[a[j]]++;
            j++;
        }

        if(cnt==m) f[j-1] += f[i-1] % MOD;

        if(d[a[i]]==1) cnt--;
        d[a[i]]--;

        if(i > 1)
        {
            f[i] = (f[i] + f[i-1])%MOD;
            f[i] %= MOD;
        }
    }

    cout<<f[n]%MOD;
    return 0;
}

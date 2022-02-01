#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,a[N],k,res;
int get(int l,int r,int val)
{
    int ans = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid] <= val)
        {
            ans = a[mid];
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+1+n);

    int i = 1;
    int j = n-1;

    while(i<j)
    {
        if(a[i] + a[j] + a[j+1] <= k)
        {
            int val = get(j+1,n,k-a[i]-a[j]);
            if(val != -1) res = max(res, a[i] + a[j] + val);
            i++;
        } else j--;
    }

    cout<<res;
    return 0;
}

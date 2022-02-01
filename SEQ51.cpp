#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n,a[N],res;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int i = 1;
    int j = 1;
    while(i<=n && j<=n)
    {
       if(a[j] >= (j-i+1)) {
            res = max(res,j-i+1);
            j++;
        } else i++;

    }

    cout<<res;
    return 0;
}

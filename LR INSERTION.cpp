#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+7;
int n, lef[N], rig[N];
string s;
void printt(int x)
{
    if(x == -1) return;
    cout<<x<<" ";
    printt(rig[x]);
}
int main()
{
    cin>>n>>s;

    int pre = 0;
    lef[pre] = -1;
    rig[pre] = -1;
    for(int i=0;i<n;i++)
    {
        int val = i + 1;
        if(s[i]=='L') {
                rig[lef[pre]] = val;
                lef[val] = lef[pre];
                lef[pre] = val;
                rig[val] = pre;
        } else {
                lef[rig[pre]] = val;
                rig[val] = rig[pre];
                rig[pre] = val;
                lef[val] = pre;
        }
        pre = val;
    }
    for(int i=0;i<=n;i++) if(lef[i]==-1) printt(i);
    return 0;
}

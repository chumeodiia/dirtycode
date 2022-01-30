#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6+7;
const int MAX = 2e6;
long long n,bit_left_to_right[N], bit_right_to_left[N],lef[N],rig[N],numbegin = 0,bit[N];
pair<long long,long long> a[N];
void updatefromlefttoright(long long x)
{
    while(x > 0)
    {
        bit_left_to_right[x]++;
        x -= (x&-x);
    }
}
long long getfromlefttoright(long long x)
{
    long long ans = 0;
    while(x <= MAX)
    {
        ans += bit_left_to_right[x];
        x += (x&-x);
    }
    return ans;
}
//----------------------------------------------------------//
void updatefromrighttoleft(long long x)
{
    while(x <= MAX)
    {
        bit_right_to_left[x]++;
        x += (x&-x);
    }
}
long long getfromrighttoleft(long long x)
{
    long long ans = 0;
    while(x > 0) {
        ans += bit_right_to_left[x];
        x -= (x&-x);
    }
    return ans;
}
//----------------------------------------------------------//
void update(long long x)
{
     while(x > 0)
    {
        bit[x]++;
        x -= (x&-x);
    }
}
long long get(long long x)
{
    long long ans = 0;
    while(x <= MAX)
    {
        ans += bit[x];
        x += (x&-x);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].fi;
        numbegin += get(a[i].fi);
        update(a[i].fi);
        a[i].se = i;
    }

    sort(a+1,a+1+n);

    //make binaryindextree from left to right
    for(int i=1;i<=n;i++) {
        long long valuee = getfromlefttoright(a[i].se);
        updatefromlefttoright(a[i].se);
        lef[i] = lef[i-1] + valuee;
    }
    //make binaryindextree from right to left
    for(int i=n;i>0;i--)
    {
        long long value = getfromrighttoleft(a[i].se);
        updatefromrighttoleft(a[i].se);
        rig[i] = rig[i+1] + value;
    }
    long long res = 1e18, numofres = 0;

    for(int i=1;i<=n;i++) {
        if(lef[i-1] + rig[i+1] < res) {
            numofres = a[i].fi;
            res = lef[i-1] + rig[i+1];
        }
    }

    cout<<numofres<<" "<<numbegin - res;
    return 0;
}

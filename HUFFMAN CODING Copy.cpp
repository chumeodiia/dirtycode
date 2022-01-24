#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6+7;
typedef pair<int,int> ii;
string s,t;
long long n,cnt,d[N],result[N],res,dem;
vector<int> a[N];
priority_queue<ii, vector<ii>, greater<ii> > dt;
void solve()
{
	while(dt.size() > 1)
	{
		long long num_1 = dt.top().fi, v1 = dt.top().se; dt.pop();
		long long num_2 = dt.top().fi, v2 = dt.top().se; dt.pop();

		dem++;
		a[dem].push_back(v1);
		a[dem].push_back(v2);

		dt.push({num_1 + num_2,dem});
	}
}
void DFS(int u,int count)
{
	if(a[u].size()==0) result[t[u]] = count;

	for(int k=0;k < a[u].size();k++) DFS(a[u][k],count+1);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	cin>>n>>s;
	n = s.length()-1;

	for(int i=0;i<=n;i++)
	{
		if(d[s[i]]==0) t += s[i];
		d[s[i]]++;
	}
	// all element in array is same as one
	if(t.length()==1)
	{
		cout<<s.length();
		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	// solving problem
	for(int i=0;i<=t.length()-1;i++) dt.push({d[t[i]],i});

	dem = t.length()-1;
	solve();

	DFS(dt.top().se,0);

	for(int i=0;i<=n;i++) res += result[s[i]];

    cout<<"conbooyuran";
	return 0;
}

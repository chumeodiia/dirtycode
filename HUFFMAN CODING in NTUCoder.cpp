#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e6+7;
typedef pair<long long,long long> ii;
string s,t;
long long n,cnt,d[N],result[N],res,ok[N],dem;
vector<long long> a[N];
priority_queue<ii, vector<ii>, greater<ii> > dt;
map<int,string> MM;
void solve()
{
	while(dt.size() > 1)
	{
		long long num_1 = dt.top().fi, v1 = dt.top().se; dt.pop();
		long long num_2 = dt.top().fi, v2 = dt.top().se; dt.pop();
		
		int sum = num_1 + num_2;
		
		dem++;
		a[dem].push_back(v1);
		a[dem].push_back(v2);
		
		dt.push({sum,dem});
	}
}
void DFS(int u,int count)
{
	//ok[u] = 1;
	//cout<<u<<" ";
	if(a[u].size()==0) 
	{
		//cout<<t[u]<<" "<<count<<'\n';
		
		result[t[u]] = count;
		//return
	}
	for(int k=0;k < a[u].size();k++)
	{
		int v = a[u][k];
		//if(ok[v]==1) continue;
		DFS(v,count+1);
	}
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
	
	if(t.length()==1) 
	{
		cout<<s.length();
		return 0;
	}
	for(int i=0;i<=t.length()-1;i++) 
	{
		/*string r = "";
		r += t[i];
		MM[d[t[i]]] = r;*/
		dt.push({d[t[i]],i});
	}
	dem = t.length()-1;
	solve();
	
	int v = dt.top().se;
	//for(int i=0;i<a[2].size();i++) cout<< a[2][i].fi <<" ";
	DFS(v,0);
	
	for(int i=0;i<=n;i++)
	{
		res += result[s[i]];
	}
	
	cout<<res;
	return 0;
}

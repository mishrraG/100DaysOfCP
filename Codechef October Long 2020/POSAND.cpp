#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define umii			unordered_map<int,int>
#define all(v)			v.begin(),v.end()
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define sortall(x)		sort(all(x))
#define deb(x)			cout << #x << "="<< x << '\n'
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

int power(int , unsigned int);
bool isPowerOfTwo(int n)
{
	if (n == 0)
		return false;

	return (ceil(log2(n)) == floor(log2(n)));
}
void solve(int n) {
	if (n == 1) {
		cout << "1\n";
		return;
	}
	else if (isPowerOfTwo(n))
	{
		cout << "-1\n";
		return;
	}
	else if (n == 3)
	{
		cout << "2 3 1\n";
		return;
	}
	vi ans;
	ans.pb(2);
	ans.pb(3);
	ans.pb(1);
	int i = 4;
	while (i <= n)
	{
		if (isPowerOfTwo(i))
		{
			ans.pb(i + 1);
			i++;
			continue;
		}
		if (isPowerOfTwo(i - 1))
		{
			ans.pb(i - 1);
			i++;
			continue;
		}
		ans.pb(i);
		i++;
	}
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(t) {
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}
int power(int x, unsigned int y)
{
	int res = 1;
	x = x % mod;
	if (x == 0) return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		y = y >> 1;
		x = (x * x) % mod;
	}
	return res;
}
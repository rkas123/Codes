#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define int long long
#define pll pair<long long,long long>

#define in(x) long long x;cin>>x
#define pb push_back
#define F first
#define S second
#define endl "\n"

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
#define deb(x) cout<<#x<<" "<<x<<endl;

const long long mod = 1e9 + 7;
const int MAX = INT_MAX;
const long long inf = 1e18 + 5;
const double pi = 3.14159265358979323846;

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

using namespace std;
void print_bool(bool zeman_modnar)
{
	if (zeman_modnar)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key   ==> number of elements whose value is less than the given element
//find_by_order ==> kth element in the set (counting from 0

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	in(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<vector<int>> dp(n, vector<int>(n, inf));

	for (int j = 0; j < n; j++)
	{
		dp[j][j] = 1;
		for (int i = j - 1; i >= 0; i--)
		{
			for (int k = i; k < j; k++)
			{
				if (v[i] == v[j])
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] - 1);
				else
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
	return 0;
}

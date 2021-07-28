#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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

const long long mod = 4294967296;
const int MAX = INT_MAX;
const long long inf = 3e18 + 5;
const double pi = 3.14159265358979323846;

long long dirX[] = {1, 1, 2, 2, -1, -1, -2, -2};
long long dirY[] = {2, -2, 1, -1, 2, -2, 1, -1};

using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key   ==> number of elements whose value is less than the given element
//find_by_order ==> kth element in the set (counting from 0)

bool isValid(int x, int y)
{
	if (x < 0 || y < 0 || x >= 8 || y >= 8)
		return false;
	return true;
}

int getHash(int x, int y)
{
	return 8 * x + y;
}


vector<vector<int>> matrix_mult(vector<vector<int>> &A, vector<vector<int>>&B)
{
	int n = A.size();
	vector<vector<int>> ans(n, vector<int>(n, inf));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (A[i][k] != inf && B[k][j] != inf)
					ans[i][j] = min(ans[i][j], A[i][k] + B[k][j]);
				if (B[i][k] != inf && A[k][j] != inf)
					ans[i][j] = min(ans[i][j], B[i][k] + A[k][j]);
			}
		}
	}
	return ans;
}

vector<vector<int>> identity_matrix(int n)
{
	vector<vector<int>> ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		ans[i][i] = 1;
	return ans;
}

vector<vector<int>> matrix_expo(vector<vector<int>> &A, int n)
{
	int r = A.size();
	if (n == 0)
	{
		return identity_matrix(r);
	}
	if (n == 1)
	{
		return A;
	}
	vector<vector<int>> res = matrix_expo(A, n / 2);
	res = matrix_mult(res, res);
	if (n & 1)
		res = matrix_mult(res, A);
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	in(n); in(m); in(k);

	vector<vector<int>> A(n, vector<int>(n, inf));
	for (int i = 0; i < m; i++)
	{
		in(u); in(v); in(c);
		u--; v--;
		A[u][v] = c;
	}


	vector<vector<int>> res = matrix_expo(A, k);

	int ans = inf;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			ans = min(ans, res[i][j]);
	}
	if (ans == inf)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;

	return 0;
}

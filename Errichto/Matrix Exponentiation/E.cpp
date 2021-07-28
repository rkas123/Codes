#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int unsigned int
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
const long long inf = 1e18 + 5;
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
	int r1 = A.size();
	int c1 = A[0].size();
	int r2 = B.size();
	int c2 = B[0].size();

	if (c1 != r2)
	{
		cout << "Not possbile" << endl;
		return {{0}};
	}

	vector<vector<int>> ans(r1, vector<int>(c2, 0));

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			for (int k = 0; k < r1; k++)
			{
				ans[i][j] += (A[i][k] * B[k][j]);
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

	vector<vector<int>> A(65, vector<int>(65, 0));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				int x = i + dirX[k];
				int y = j + dirY[k];
				if (isValid(x, y))
				{
					A[getHash(i, j)][getHash(x, y)] = 1;
				}
			}
		}
	}
	for (int i = 0; i <= 64; i++)
		A[64][i] = 1;

	vector<vector<int>> initial(65, vector<int>(1, 0));
	initial[0][0] = 1;
	in(n);
	n++;
	vector<vector<int>> res = matrix_expo(A, n);
	res = matrix_mult(res, initial);
	int ans = 0;

	cout << res[64][0] % mod << endl;


	return 0;
}

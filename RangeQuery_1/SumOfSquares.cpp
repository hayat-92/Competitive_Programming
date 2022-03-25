// #include<iostream>
// using namespace std;
// struct tree_attrs
// {
// 	int sum_of_squares;
// 	int sum;
// };
// struct lazy_attrs
// {
// 	int setter = 0;
// 	int incermentor = 0;
// };
// void build_tree(int* arr, tree_attrs* tree, int start, int end, int treenode)
// {
// 	if (start == end)
// 	{
// 		tree[treenode].sum_of_squares = arr[start]*arr[start];
// 		tree[treenode].sum = arr[start];
// 		return;
// 	}
// 	int mid = (start + end) / 2;
// 	build_tree(arr, tree, start, mid, 2 * treenode);
// 	build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
// 	tree[treenode].sum = tree[2 * treenode].sum + tree[2 * treenode + 1].sum;
// 	tree[treenode].sum_of_squares = tree[2 * treenode].sum_of_squares + tree[2 * treenode + 1].sum_of_squares;
// }
// void lazy_update_setter(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int x)
// {
// 	if (start > end)
// 	{
// 		return;
// 	}
// 	if (lazy[current_position].setter != 0)
// 	{
// 		tree[current_position].sum = (right-left + 1) * (lazy[current_position].setter);
// 		tree[current_position].sum_of_squares = (right-left + 1) * (lazy[current_position].setter * lazy[current_position].setter);
// 		if (start != end)
// 		{
// 			lazy[2 * current_position].setter = lazy[current_position].setter;
// 			lazy[2 * current_position+1].setter = lazy[current_position].setter;
// 		}
// 		lazy[current_position].setter = 0;
// 	}

// 	//completely outside
// 	if (start > right || end < left)
// 	{
// 		return;
// 	}
// 	//complete overlap
// 	if (start >= left && end <= right)
// 	{
// 		tree[current_position].sum_of_squares = (right-left + 1) * (x * x);
// 		tree[current_position].sum = (right-left + 1) * x;
// 		if (start != end)
// 		{
// 			lazy[2 * current_position].setter = x;
// 			lazy[2 * current_position + 1].setter = x;
// 		}
// 		return;
// 	}
// 	//partial overlap
// 	int mid = (start + end) / 2;
// 	lazy_update_setter(tree, lazy, start, mid, left, right, 2 * current_position, x);
// 	lazy_update_setter(tree, lazy, mid+1, end, left, right, 2 * current_position+1, x);
// 	tree[current_position].sum = tree[2 * current_position].sum + tree[2 * current_position + 1].sum;
// 	tree[current_position].sum_of_squares = tree[2 * current_position].sum_of_squares + tree[2 * current_position + 1].sum_of_squares;
// 	return;
// }
// void lazy_update_incrementor(tree_attrs* tree, lazy_attrs* lazy, int start, int end, int left, int right, int current_position, int increment)
// {
// 	if (start > end)
// 	{
// 		return;
// 	}
// 	if (lazy[current_position].incermentor != 0)
// 	{
// 		tree[current_position].sum_of_squares += (right-left + 1) * (lazy[current_position].incermentor * lazy[current_position].incermentor) + 2 * lazy[current_position].incermentor * tree[current_position].sum;
// 		tree[current_position].sum += (right-left + 1) * lazy[current_position].incermentor;
// 		if (start != end)
// 		{
// 			lazy[2 * current_position].incermentor += lazy[current_position].incermentor;
// 			lazy[2 * current_position + 1].incermentor += lazy[current_position].incermentor;
// 		}
// 		lazy[current_position].incermentor = 0;
// 	}
// 	if (lazy[current_position].setter != 0)
// 	{
// 		tree[current_position].sum = (right - left + 1) * (lazy[current_position].setter);
// 		tree[current_position].sum_of_squares = (right - left + 1) * (lazy[current_position].setter * lazy[current_position].setter);
// 		if (start != end)
// 		{
// 			lazy[2 * current_position].setter = lazy[current_position].setter;
// 			lazy[2 * current_position + 1].setter = lazy[current_position].setter;
// 		}
// 		lazy[current_position].setter = 0;
// 	}
// 	//completely outside
// 	if (start > right || end < left)
// 	{
// 		return;
// 	}
// 	//complete overlap
// 	if(start>=left&&end<=right)
// 	{
// 		tree[current_position].sum_of_squares += (right-left + 1) * (increment * increment) + 2 * increment * tree[current_position].sum;
// 		tree[current_position].sum += (right-left + 1) * increment;
// 		if (start != end)
// 		{
// 			lazy[2 * current_position].incermentor += increment;
// 			lazy[2 * current_position + 1].incermentor += increment;
// 		}
// 		return;
// 	}
// 	//partial overlap
// 	int mid = (start + end) / 2;
// 	lazy_update_incrementor(tree, lazy, start, mid, left, right, 2 * current_position, increment);
// 	lazy_update_incrementor(tree, lazy, mid+1, end, left, right, 2 * current_position+1, increment);
// 	tree[current_position].sum = tree[2 * current_position].sum + tree[2 * current_position + 1].sum;
// 	tree[current_position].sum_of_squares = tree[2 * current_position].sum_of_squares + tree[2 * current_position + 1].sum_of_squares;
// 	return;
// }

// tree_attrs query(tree_attrs* tree, lazy_attrs *lazy, int start, int end, int left, int right, int treenode)
// {
// 	if (start > end)
// 	{
// 		return { 0, 0 };
// 	}
// 	if (lazy[treenode].incermentor != 0)
// 	{
// 		tree[treenode].sum_of_squares += 2 * lazy[treenode].incermentor * tree[treenode].sum + lazy[treenode].incermentor * lazy[treenode].incermentor * (right - left + 1);
// 		tree[treenode].sum += (right - left + 1) * lazy[treenode].incermentor;
// 		if (start != end)
// 		{
// 			lazy[2 * treenode].incermentor += lazy[treenode].incermentor;
// 			lazy[2 * treenode + 1].incermentor += lazy[treenode].incermentor;
// 		}
// 		lazy[treenode].incermentor = 0;
// 	}
// 	if (lazy[treenode].setter != 0)
// 	{
// 		tree[treenode].sum = (right - left + 1) * lazy[treenode].setter;
// 		tree[treenode].sum_of_squares = (right - left + 1) * lazy[treenode].setter*lazy[treenode].setter;
// 		if (start != end)
// 		{
// 			lazy[2 * treenode].setter = lazy[treenode].setter;
// 			lazy[2 * treenode + 1].setter = lazy[treenode].setter;
// 		}
// 		lazy[treenode].setter = 0;
// 	}
// 	//completely outside
// 	if (start > right || end < left)
// 	{
// 		return { 0, 0 };
// 	}
// 	//fully inside
// 	if (start >= left && end <= right)
// 	{
// 		return tree[treenode];
// 	}
// 	//partial overlap
// 	int mid = (start + end) / 2;
// 	tree_attrs left_child = query(tree, lazy, start, mid, left, right, 2 * treenode);
// 	tree_attrs right_child = query(tree, lazy, mid+1, end, left, right, 2 * treenode+1);
// 	tree_attrs ans;
// 	ans.sum = left_child.sum + right_child.sum;
// 	ans.sum_of_squares = left_child.sum_of_squares + right_child.sum_of_squares;
// 	return ans;
// }

// int main()
// {
// 	int t;
// 	cin >> t;
// 	int case_number = 1;
// 	while (t--)
// 	{
// 		// cout << "Case " << case_number << ":" << endl;
// 		int n, q;
// 		cin >> n >> q;
// 		int* arr = new int[n];
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> arr[i];
// 		}
// 		tree_attrs* tree = new tree_attrs[4 * n]();
// 		lazy_attrs* lazy = new lazy_attrs[4 * n]();
// 		build_tree(arr, tree, 0, n - 1, 1);
// 		while (q--)
// 		{
// 			int type_of_operation;
// 			cin >> type_of_operation;
// 			if (type_of_operation == 2)
// 			{
// 				int left, right;
// 				cin >> left >> right;
// 				cout << query(tree, lazy, 0, n-1, left - 1, right - 1, 1).sum_of_squares<<endl;
// 			}
// 			else if (type_of_operation == 1)
// 			{
// 				int left, right;
// 				cin >> left >> right;
// 				int increment;
// 				cin >> increment;
// 				lazy_update_incrementor(tree, lazy, 0, n-1, left-1, right-1, 1, increment);
// 			}
// 			else
// 			{
// 				int left, right;
// 				cin >> left >> right;
// 				int x;
// 				cin >> x;
// 				lazy_update_setter(tree, lazy, 0, n-1, left-1, right-1, 1, x);
// 			}
// 		}
// 		case_number++;
// 	}
// }




















#include<iostream>
#include<iomanip>
#include<algorithm>
#include<climits>
#include<unordered_map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define fastio() ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define int long long
#define SZ(x) (int)x.size()
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define trav(a) for(auto p:a)cout<<p<<" ";cout<<endl;


//tree - <ss,s>
int query(vector<pair<int, int>>&tree, vector<pair<int, int>>&lazy, int l, int r, int i, int s, int e) {

      if (lazy[i].second != 0) {
            int change = lazy[i].second;
            int t = lazy[i].first;
            if (t == 1) {
                  tree[i].first += 2 * lazy[i].second * tree[i].second + lazy[i].second * lazy[i].second * (r - l + 1);
                  tree[i].second += lazy[i].second * (r - l + 1);
                  if (l != r) {
                        if (lazy[2 * i].first == 1 || lazy[2 * i].second == 0) {
                              lazy[2 * i].second += change;
                              lazy[2 * i].first = t;
                        }
                        else {
                              lazy[2 * i].second += change;
                        }
                        if (lazy[2 * i + 1].first == 1 || lazy[2 * i + 1].second == 0) {
                              lazy[2 * i + 1].second += change;
                              lazy[2 * i + 1].first = t;
                        }
                        else {
                              lazy[2 * i + 1].second += change;
                        }

                  }
            }
            else {
                  tree[i].first = change * change * (r - l + 1);
                  tree[i].second = change * (r - l + 1);
                  if (l != r) {
                        lazy[2 * i].second = change;
                        lazy[2 * i].first = t;
                        lazy[2 * i + 1].second = change;
                        lazy[2 * i + 1].first = t;
                  }
            }

            lazy[i].second = 0;

      }
      if (l > e || r < s)return 0;

      if (l >= s && r <= e)return tree[i].first;

      int m = (l + r) / 2;

      int sum = query(tree, lazy, l, m, 2 * i, s, e) + query(tree, lazy, m + 1, r, 2 * i + 1, s, e);
      return sum;
}
//Lazy - <type, value>
void updateLazy(vector<pair<int, int>>&lazy, vector<pair<int, int>>&tree, int l, int r, int i, int s, int e, int type, int val) {
      if (lazy[i].second != 0) {
            int change = lazy[i].second;
            int t = lazy[i].first;
            if (t == 1) {
                  tree[i].first += 2 * lazy[i].second * tree[i].second + lazy[i].second * lazy[i].second * (r - l + 1);
                  tree[i].second += lazy[i].second * (r - l + 1);
                  if (l != r) {
                        if (lazy[2 * i].first == 1 || lazy[2 * i].second == 0) {
                              lazy[2 * i].second += change;
                              lazy[2 * i].first = t;
                        }
                        else {
                              lazy[2 * i].second += change;
                        }
                        if (lazy[2 * i + 1].first == 1 || lazy[2 * i + 1].second == 0) {
                              lazy[2 * i + 1].second += change;
                              lazy[2 * i + 1].first = t;
                        }
                        else {
                              lazy[2 * i + 1].second += change;
                        }

                  }
            }
            else {
                  tree[i].first = change * change * (r - l + 1);
                  tree[i].second = change * (r - l + 1);
                  if (l != r) {
                        lazy[2 * i].second = change;
                        lazy[2 * i].first = t;
                        lazy[2 * i + 1].second = change;
                        lazy[2 * i + 1].first = t;
                  }
            }

            lazy[i].second = 0;

      }
      // if (l > r)return;
      if (l > e || r < s) {
            return;
      }

      if (l >= s && r <= e) {
            if (type == 1) {
                  tree[i].first += 2 * val * tree[i].second + val * val * (r - l + 1);
                  tree[i].second += val * (r - l + 1);
                  if (l != r) {
                        if (lazy[2 * i].first == 1 || lazy[2 * i].second == 0) {
                              lazy[2 * i].second += val;
                              lazy[2 * i].first = type;
                        }
                        else {
                              lazy[2 * i].second += val;
                        }
                        if (lazy[2 * i + 1].first == 1 || lazy[2 * i + 1].second == 0) {
                              lazy[2 * i + 1].second += val;
                              lazy[2 * i + 1].first = type;
                        }
                        else {
                              lazy[2 * i + 1].second += val;
                        }

                  }
            }
            else {
                  tree[i].first = val * val * (r - l + 1);
                  tree[i].second = val * (r - l + 1);
                  if (l != r) {
                        lazy[2 * i].second = val;
                        lazy[2 * i].first = type;
                        lazy[2 * i + 1].second = val;
                        lazy[2 * i + 1].first = type;
                  }
            }

            return;
      }

      int m = (l + r) / 2;
      updateLazy(lazy, tree, l, m, 2 * i, s, e, type, val);
      updateLazy(lazy, tree, m + 1, r, 2 * i + 1, s, e, type, val);
      tree[i].first = tree[2 * i].first + tree[2 * i + 1].first;
      tree[i].second = tree[2 * i].second + tree[2 * i + 1].second;


}
void buildTree(vector<int>&a, vector<pair<int, int>>&tree, int l, int r, int i) {
      if (l > r)return;
      if (l == r) {
            tree[i].first = a[l] * a[l];
            tree[i].second = a[l];
            return;
      }
      int m = (l + r) / 2;
      buildTree(a, tree, l, m, 2 * i);
      buildTree(a, tree, m + 1, r, 2 * i + 1);

      tree[i].first = tree[2 * i].first + tree[2 * i + 1].first;
      tree[i].second = tree[2 * i].second + tree[2 * i + 1].second;
}



void SolveCase() {



      int n, k;
      cin >> n >> k;
      vector<int>a(n);
      for(auto &x : a)cin>>x;

      vector<pair<int, int>>tree(4 * n, {0, 0});
      buildTree(a, tree, 0, n - 1, 1);

      vector<pair<int, int>>lazy(4 * n, {2, 0});

      for (int i = 0; i < k; i++) {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 2) {

                  cout << query(tree, lazy, 0, n - 1, 1, x - 1, y - 1) << "\n";
            } else {
                  int val;
                  cin >> val;
                  updateLazy(lazy, tree, 0, n - 1, 1, x - 1, y - 1, t, val);

            }
      }





}

signed main()
{
      fastio()

      int tt = 1; cin >> tt;
      for (int t = 1; t <= tt; t++) {
            // cout << "Case #" << t << ": ";
            SolveCase();
      }
      // cerr << "Time : " << 1000 * ( (double) clock() ) / (double) CLOCKS_PER_SEC << "ms\n";
}
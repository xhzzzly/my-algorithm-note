#pragma ccc optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define For(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
using ll = long long;

constexpr int L = 1e5 + 7;
set<int> ori_set;

int a[L];

int fmex(int l, int r)
{
    set<int> check_set(ori_set.begin(), ori_set.end());
    for (int i = l; i <= r; ++i) {
        if (check_set.count(a[i]) == 1) {
            check_set.erase(a[i]);
        }
    }
    return *(check_set.begin());
}

void solve()
{
    int n;
    cin >> n;
    int minn = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < minn)
            minn = a[i];
    }
    int mex = fmex(1, n);
    if (mex < minn) {
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << i << endl;
        }
        return;
    }
    vector<pair<int, int>> v;
    int left = 1, right = 1;
    while (right <= n) {
        set<int> check_set(ori_set.begin(), ori_set.end());
        while (right <= n) {
            if (check_set.count(a[right]) == 1) {
                check_set.erase(a[right]);
            }
            if (*check_set.begin() == mex) {
                break;
            }
            ++right;
        }
        while (right < n && a[right + 1] > mex) {
            ++right;
        }
        if (right == n + 1) {
            v.clear();
            break;
        }
        v.push_back(make_pair(left, right));
        left = ++right;
    }

    if (v.size() > 1) {
        cout << v.size() << endl;
        for (auto i : v) {
            cout << i.first << ' ' << i.second << endl;
        }
    } else {
        cout << "-1" << endl;
    }
}

signed main()
{
    for (int i = 0; i <= L; ++i)
        ori_set.insert(i);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef SINGLE_CASE
    solve();
    return 0;
#endif
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
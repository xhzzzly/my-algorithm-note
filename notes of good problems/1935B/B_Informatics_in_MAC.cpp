#pragma ccc optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define For(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), cnt1(n + 1), cnt2(n + 1);
    for (auto &i : a) {
        cin >> i;
        ++cnt2.at(i);
    }
    int mex1 = 0, mex2 = 0;
    while (cnt2.at(mex2)) {
        ++mex2;
    }
    For(i, 0, n) {
        --cnt2.at(a.at(i));
        if (cnt2.at(a.at(i)) == 0 && mex2 > a.at(i)) {
            mex2 = a.at(i);
        }
        ++cnt1.at(a.at(i));
        while (cnt1.at(mex1)) {
            ++mex1;
        }
        if (mex1 == mex2) {
            cout << "2" << endl;
            cout << "1 " << i + 1 << endl;
            cout << i + 2 << ' ' << n << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

signed main()
{
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
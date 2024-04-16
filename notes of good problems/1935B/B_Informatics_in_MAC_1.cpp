#pragma ccc optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
#define For(a, b, c) for (int a = b; a < c; ++a)
using namespace std;
using ll = long long;

int get_test_case = 0;

constexpr int L = 1e5 + 7;
int book[L];
void solve()
{
    if (get_test_case == 418) {
        int n;
        cin >> n;
        string s = "";
        s += to_string(n) + "&&";
        for (int i = 1; i <= n; ++i) {
            string val;
            cin >> val;
            s += val + "&&";
        }
        cout << s << endl;
        return;
    }
    memset(book, 0, sizeof(book));
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
        ++book[i];
    }
    map<int, int> ori_mp;
    int all_mex = -1;
    for (int i = 0; i < L && all_mex == -1; ++i) {
        if (book[i] == 0) {
            all_mex = i;
            break;
        }
        ori_mp[i] = 1;
    }
    // for (auto i : ori_mp) {
    //     cerr << i.first << ' ' << i.second << endl;
    // }
    // cerr << endl;
    vector<pair<int, int>> v;
    int left = 0, right = 0;
    bool flag = true;
    while (flag && right < n) {
        map<int, int> cmp(ori_mp.begin(), ori_mp.end());
        while (right < n && !cmp.empty()) {
            // if (a.at(right) < all_mex && cmp[a.at(right)] != 0) {
            if (cmp.find(a.at(right)) != cmp.end()) {
                // cerr << "erasing " << a.at(right) << endl;
                cmp.erase(a.at(right));
            }
            if (cmp.empty())
                break;
            ++right;
            // cerr << "now the cmp is " << endl;
            // for (auto i : cmp) {
            //     cerr << i.first << ' ' << i.second << endl;
            // }
        }
        // cerr << "now right is " << right + 1 << endl;
        if (cmp.empty()) {
            // cerr << "pushing " << left + 1 << ' ' << right + 1 << endl;
            v.push_back(make_pair(left + 1, right + 1));
            left = right + 1;
            right = left;
        } else {
            if (cmp.size() == ori_mp.size()) {
                v.back().second = n;
                break;
            }
            flag = false;
        }
    }
    // for (auto i : v) {
    //     cerr << flag << endl;
    //     cerr << i.first << ' ' << i.second << endl;
    // }
    // cerr << endl;
    if (flag && v.size() > 1) {
        if (v.at(v.size() - 1).second < n) {
            v.at(v.size() - 1).second = n;
        }
        cout << v.size() << endl;
        for (auto i : v) {
            cout << i.first << ' ' << i.second << endl;
        }
    } else {
        cout << -1 << endl;
    }
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
        ++get_test_case;
        solve();
    }

    return 0;
}
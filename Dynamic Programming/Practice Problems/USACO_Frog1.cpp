#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mxe max_element
#define mne min_element
#define vi vector <int>
#define pii pair<int, int>
#define pss pair<string, string>
#define psi pair<pss, int>
#define mii map <int, int>
#define umii unordered_map <int, int>
#define ust unordered_set <int>
#define umst unordered_multiset <int>
#define print_yes cout << "YES" << '\n'
#define print_no cout << "NO" << '\n'

int n, vis[100005], dp[100005], h[100005];

int slv(int idx) {
    if (idx == n) return 0;

    if (vis[idx]) return dp[idx];

    int res = INT_MAX;

    for (int j = 1; j <= 2; j++) {
        if (idx + j <= n) {
            int cost = abs(h[idx] - h[idx + j]);
            int now = cost + slv(idx + j);

            res = min(res, now);
        }
    }

    vis[idx] = -1;
    dp[idx] = res;

    return res;
}

int main() {
    optimize();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    cout << slv(1) << endl;
}

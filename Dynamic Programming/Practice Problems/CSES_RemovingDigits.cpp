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

int n, vis[10000005], dp[10000005];

int slv(int n) {
    if (n == 0) return 0;
    if (vis[n]) return dp[n];

    int tmp = n;
    int res = INT_MAX;
    while (tmp > 0) {
        int curr_dgt = tmp % 10;
        if (curr_dgt != 0) {
            res = min(res, 1 + slv(n - curr_dgt));
        }
        tmp /= 10;
    }
    vis[n] = -1;
    dp[n] = res;
    return res;
}

int main() {
    optimize();

    cin >> n;
    cout << slv(n) << endl;
}

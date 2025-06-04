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

int main() {
    optimize();

    int n;
    cin >> n;
    vector <int> dp(3);

    while (n--)
    {
        vector <int> cost(3);
        for (int i = 0; i < 3; i++) cin >> cost[i];
        vector <int> new_dp(3, 0);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    new_dp[j] = max(new_dp[j], dp[i] + cost[j]);
                }
            }
        }
        dp = new_dp;
    }
    cout << max({dp[0], dp[1], dp[2]}) << endl;
}

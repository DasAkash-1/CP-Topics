#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define vi vector <int>
#define vll vector <long long>
#define pii pair<int, int>
#define mii map <int, int>
#define mll map <long long, long long>
#define print_yes cout << "yes" << '\n'
#define print_no cout << "no" << '\n'

int lb (vll &v, ll tgt) {
    ll n = v.size();
    ll l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] < tgt) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

int ub (vll &v, ll tgt) {
    ll n = v.size();
    ll l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (v[mid] <= tgt) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

ll n, k;
vll v;
bool isOK (ll mid) {
    ll step = 0;
    for (int i = n / 2; i < n; i++) {
        step += max(0LL, mid - v[i]);
    }
    return step <= k;
}

int main(){
    optimize();

    //Sieve();

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    ll l = 0, r = 2e9, ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;

        if (isOK(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
}

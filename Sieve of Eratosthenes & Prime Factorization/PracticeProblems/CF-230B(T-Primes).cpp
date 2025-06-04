#include <bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
#define mxe max_element
#define mne min_element
#define vi vector <int>
#define vll vector <long long>
#define pii pair<int, int>
#define pss pair<string, string>
#define psi pair<pss, int>
#define mii map <int, int>
#define umii unordered_map <int, int>
#define ust unordered_set <int>
#define umst unordered_multiset <int>
#define print_yes cout << "YES" << '\n'
#define print_no cout << "NO" << '\n'

bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
int gcd(int a, int b) { return b ? gcd (b, a % b) : a; }
int lcm(int a, int b) { return abs(a * (b / gcd(a, b))); }

bool cmp (psi a, psi b) {
    if (a.first.first == b.first.first && a.first.second == b.first.second) return a.second > b.second;
    else if (a.first.second == b.first.second) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}
bool cmp2 (ll a, ll b) { return a > b; }

int n = 1000000;
vector<bool> is_prime(n +1, true);

void Sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (ll) i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
        }
    }
}
int main(){
    optimize();

    Sieve();

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll rt = sqrt(n);

        if (rt * rt == n && is_prime[rt]) print_yes;
        else print_no;
    }
}

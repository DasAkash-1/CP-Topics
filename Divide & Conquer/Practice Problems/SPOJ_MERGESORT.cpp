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

int a[100005], temp[100005];

void merge(int l, int r) {
    int mid = (l + r) / 2;
    int i = l, j = mid + 1, k = l; //k is the pointer on the temp/ new array which i want to keep all the sortyed val;ues

    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
        k++; //incrementing k to the next position after placing correct elementsa on their position
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++, i++;
    }
    while (j <= r) {
        temp[k] =a[j];
        k++, j++;
    }
    for (int i = l; i <= r; i++) a[i] = temp[i]; // now all element from (l, r) is sorted on the temp, so we are putting them back on the array (a)
}

void mergesort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;

    mergesort(l, mid);
    mergesort(mid + 1, r);

    merge(l, r);
}

int main() {
    optimize();

    int n = 0, e;

    while (cin >> e) {
        a[n] = e;
        n++;
    }
    mergesort(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

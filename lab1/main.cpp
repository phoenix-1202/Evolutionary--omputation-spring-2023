#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <chrono>

using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

int kth_naive(int k) {
    /// !! changes array while finding answer
    sort(b.begin(), b.end());
    return b[k];
}

int kth_standard(int k) {
    /// !! changes array while finding answer
    nth_element(c.begin(), c.begin() + k, c.end());
    return c[k];
}

int partition(int l, int r) {
    if (l != r) swap(a[l + rand() % (r - l)], a[r]);
    int x = a[r];
    int i = l - 1;
    for (int j = l; j <= r; j++) {
        if (a[j] <= x)
            swap(a[++i], a[j]);
    }
    return i;
}

int kth_hand_made(int k) {
    int l = 0, r = a.size() - 1;
    while (true) {
        int m = partition(l, r);
        if (m == k) return a[k];
        if (m < k)
            l = m + 1;
        else
            r = m - 1;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    a.resize(0);
    b.resize(0);
    c.resize(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace_back(x);
        b.emplace_back(x);
        c.emplace_back(x);
    }

    int k;
    cin >> k;
    k--;

    /// 1st case: naive sort from standard library
    auto start = chrono::system_clock::now();
    int res1 = kth_naive(k);
    auto end = chrono::system_clock::now();
    chrono::duration<double> work_time = end - start;
    cout << work_time.count() << ' ';

    /// 2nd case: implementation from standard library
    start = chrono::system_clock::now();
    int res2 = kth_standard(k);
    end = chrono::system_clock::now();
    work_time = end - start;
    cout << work_time.count() << ' ';

    /// 3rd case: hand-made implementation
    start = chrono::system_clock::now();
    int res = kth_hand_made(k);
    end = chrono::system_clock::now();
    work_time = end - start;
    cout << work_time.count() << '\n';

    if (!(res1 == res2 && res2 == res)) {
        throw runtime_error("Results are not equal");
    }
    
    //cout << res1 << " " << res2 << " " << res;
    return 0;
}
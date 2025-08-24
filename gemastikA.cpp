#include <bits/stdc++.h>
using namespace std;

#ifdef ENABLE_MONITORING
#include "monitoring.h"
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    // Baca input dulu (di luar pengukuran)
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];

#ifdef ENABLE_MONITORING
    start_monitoring(); // Mulai ukur SETELAH input selesai dibaca
#endif

    static bool seen[1001] = {false};
    for (int x : nums) if (1 <= x && x <= 1000) seen[x] = true;

    bool first = true;
    for (int i = 1; i <= 1000; ) {
        if (!seen[i]) { ++i; continue; }
        int l = i, r = i;
        while (r + 1 <= 1000 && seen[r + 1]) ++r;

        if (!first) cout << ",";
        first = false;

        if (l == r) cout << l;
        else cout << l << "-" << r;

        i = r + 1;
    }
    cout << "\n";

#ifdef ENABLE_MONITORING
    stop_monitoring();
    print_monitoring(); // ke stderr, tidak ganggu output
#endif

    return 0;
}

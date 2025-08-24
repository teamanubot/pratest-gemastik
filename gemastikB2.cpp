#include <bits/stdc++.h>
using namespace std;

#ifdef ENABLE_MONITORING
#include "monitoring.h"
#endif

static inline int idx(char c) { return c - 'A'; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    const int N = (int)s.size();

#ifdef ENABLE_MONITORING
    start_monitoring(); // MULAI ukur SETELAH input lengkap terbaca
#endif

    // Tabel 1
    string T1[4][4] = {
        {"AB","DC","CC","CB"},
        {"CA","DA","CD","DD"},
        {"BC","AA","BA","DB"},
        {"BD","AD","BB","AC"}
    };
    // Tabel 2
    string T2[4][4] = {
        {"CD","BB","AC","CC"},
        {"CB","DB","AD","DD"},
        {"DA","DC","BC","BD"},
        {"AA","BA","CA","AB"}
    };

    // Precompute mapping terenkripsi -> asli (16 pasangan)
    array<array<string,4>,4> enc_of; // hanya bantu debugging/cek
    unordered_map<string,string> decode;
    decode.reserve(32);

    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            string mid = T1[r][c];                       // tahap 1
            string fin = T2[idx(mid[0])][idx(mid[1])];   // tahap 2
            string orig;
            orig.push_back(char('A' + r));
            orig.push_back(char('A' + c));
            decode[fin] = orig; // peta balik untuk decoding
        }
    }

    // Decode tiap blok 2 karakter
    string out;
    out.reserve(N);
    for (int i = 0; i < N; i += 2) {
        string blk = s.substr(i, 2);
        auto it = decode.find(blk);
        // Asumsi input valid menurut skema; jika tidak, fallback jaga-jaga
        if (it != decode.end()) out += it->second;
        else out += "??";
    }

    cout << out << '\n';

#ifdef ENABLE_MONITORING
    stop_monitoring();
    print_monitoring(); // ke stderr, tidak ganggu output
#endif
    return 0;
}

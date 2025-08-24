#include <bits/stdc++.h>
using namespace std;

#include "monitoring.h"

// Konversi huruf A/B/C/D -> 0..3
inline int idx(char c) { return c - 'A'; }
// Konversi 0..3 -> huruf
inline char ch(int i) { return char('A' + i); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;         // baca input dulu (di luar pengukuran)

    start_monitoring();                // mulai ukur SETELAH input lengkap

    // Tabel 1 (baris, kolom) -> 2 huruf
    //   A    B    C    D
    // A AB | DC | CC | CB
    // B CA | DA | CD | DD
    // C BC | AA | BA | DB
    // D BD | AD | BB | AC
    static const char T1[4][4][2] = {
        {{'A','B'}, {'D','C'}, {'C','C'}, {'C','B'}},
        {{'C','A'}, {'D','A'}, {'C','D'}, {'D','D'}},
        {{'B','C'}, {'A','A'}, {'B','A'}, {'D','B'}},
        {{'B','D'}, {'A','D'}, {'B','B'}, {'A','C'}}
    };

    // Tabel 2
    //   A    B    C    D
    // A CD | BB | AC | CC
    // B CB | DB | AD | DD
    // C DA | DC | BC | BD
    // D AA | BA | CA | AB
    static const char T2[4][4][2] = {
        {{'C','D'}, {'B','B'}, {'A','C'}, {'C','C'}},
        {{'C','B'}, {'D','B'}, {'A','D'}, {'D','D'}},
        {{'D','A'}, {'D','C'}, {'B','C'}, {'B','D'}},
        {{'A','A'}, {'B','A'}, {'C','A'}, {'A','B'}}
    };

    string out;
    out.resize(s.size());

    for (size_t i = 0; i < s.size(); i += 2) {
        int r1 = idx(s[i]);
        int c1 = idx(s[i+1]);

        // Tahap 1
        char t1a = T1[r1][c1][0];
        char t1b = T1[r1][c1][1];

        // Tahap 2
        int r2 = idx(t1a);
        int c2 = idx(t1b);
        out[i]   = T2[r2][c2][0];
        out[i+1] = T2[r2][c2][1];
    }

    cout << out << "\n";

    stop_monitoring();
    print_monitoring(); // ke stderr, tidak mengganggu keluaran utama

    return 0;
}

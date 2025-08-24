# Panduan Build & Run (GemasTIK A / B1 / B2)

## 🔧 Kompilasi

> Gunakan C++17 dengan optimisasi. Opsi `-DENABLE_MONITORING` **opsional** (aktifkan jika memakai `monitoring.h` untuk ukur waktu & memori).

```bash
# Dengan monitoring (disarankan saat uji lokal)
g++ -O2 -std=c++17 gemastikA.cpp  -DENABLE_MONITORING -o gemastikA
g++ -O2 -std=c++17 gemastikB1.cpp -DENABLE_MONITORING -o gemastikB1
g++ -O2 -std=c++17 gemastikB2.cpp -DENABLE_MONITORING -o gemastikB2

# Tanpa monitoring (untuk submit ke judge)
g++ -O2 -std=c++17 gemastikA.cpp  -o gemastikA
g++ -O2 -std=c++17 gemastikB1.cpp -o gemastikB1
g++ -O2 -std=c++17 gemastikB2.cpp -o gemastikB2
```

## ▶️ Menjalankan

**Interaktif (ketik input manual):**

```bash
./gemastikA
./gemastikB1
./gemastikB2
```

**Dari file input (disarankan):**

```bash
# Hanya output ke layar
./gemastikA < input.txt

# Pisahkan jawaban & log monitoring (stdout vs stderr)
./gemastikA  < input.txt 1>out.txt 2>log.txt
./gemastikB1 < input.txt 1>out.txt 2>log.txt
./gemastikB2 < input.txt 1>out.txt 2>log.txt
# - out.txt : keluaran jawaban (cout)
# - log.txt : waktu & memori (cerr), jika monitoring diaktifkan
```

## 💡 Tips

* Pastikan `-O2` aktif untuk performa optimal.
* Simpan input contoh ke `input.txt` agar reproducible.
* Untuk membersihkan binary:

  ```bash
  rm -f gemastikA gemastikB1 gemastikB2
  ```

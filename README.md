# Tucil1_13524137
## penjelasan singkat program yang dibuat
objektif dari tucil ini adalah untuk membuat games queens linkedin, dengan deskripsi lengkap sbg berikut:

Queens adalah gim logika yang tersedia pada situs jejaring profesional LinkedIn. Tujuan dari gim ini 
adalah menempatkan queen pada sebuah papan persegi berwarna sehingga terdapat hanya satu queen pada 
tiap baris, kolom, dan daerah warna. Selain itu, satu queen tidak dapat ditempatkan bersebelahan dengan 
queen lainnya, termasuk secara diagonal. 

program dibuat dengan menggunakan algoritma brute force. dengan meminta masukan dari file txt, lalu masukkan koordinat tiap warna ke dalam map dengan key char dan value coordinat (x,y) lalu tiap tiap queen dalam queen_position diinisialisasi, tiap warna punya 1 queen, dan queen ditempatkan di petak awal dari koordinat masing2 warna. kemudian queen melalui proses brute force, dicoba kombinasi, jika dilihat posisi secara baris, kolom atau secara diagonal bersentuhan ada sepasang queen, maka akan dicoba semua kemungkinan petak koordinat dari region warna terakhir, jika masih belum ditemukannnya solusi yang valid, maka semua kemungkinan petak koordinat dari region warna lainnya yang akan dicoba, kombinasi dilakukan secara menyilang (uji koordinat antar warna diuji secara bersamaan). pengujian tiap-tiap kombinasi silang dilakukan hingga ditemukan solusi yang valid atau seluruh kombinasi habis (tidak ditemukan solusi).

## requirements
C++ compiler: minimal gcc (g++) versi 9.0 ke atas
Web browser: Google Chrome misalnya, untuk GUI

## cara menjalankan program
terminal\
```cd Tucil1_13524137/src```
```start index.html```

## author
Nama: Reysha Syafitri MR\
NIM : 13524137\
Kelas : K03


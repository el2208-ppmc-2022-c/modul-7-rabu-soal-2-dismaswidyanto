# Modul 7 Rabu Soal 2: Stacks and Queues

## Instruksi
Bacalah naskah soal yang tersedia pada *repository* ini dengan saksama. Kemudian kerjakan soal tersebut sesuai dengan ketentuan yang diberikan. Silakan mengerjakan pada *file* `soal-02.c`. Apabila sudah selesai, lakukan *commit* dan *push* ke branch `main` pada *repository* anda.

### Hint
Anda dapat mengerjakan dengan salah satu metode berikut:  
1. Melakukan `clone` *repository* ini ke komputer anda, mengubah *source code* secara *offline*, kemudian melakukan `commit` dan `push` ke *branch* `main`, atau
2. Mengunduh *repository* ini, mengubah *source code* secara *offline*, kemudian mengunggah *file* ke web GitHub dan melakukan `commit` ke *branch* `main`, atau
3. Mengubah *source code* secara langsung di web GitHub, kemudian melakukan `commit` ke *branch* `main`.  

## Perintah Kompilasi
Perhatikan bahwa *autograder* bekerja dengan sistem operasi Linux sehingga proses kompilasi juga disesuaikan dengan sistem operasi tersebut. *Compiler* yang digunakan dalam praktikum ini adalah `gcc`.

Proses kompilasi dilakukan dengan memanfaatkan `Makefile`. Secara sederhana `Makefile` merupakan file yang berisi kode kompilasi yang sudah diperpendek. Perintah kompilasi yang digunakan adalah

```sh
make soal-02
```

Perintah tersebut dapat langsung dijalankan pada terminal apabila anda tidak menggunakan *file eksternal* lainnya (sudah teruji pada `bash` Linux Ubuntu 20.04).

### Penjelasan Makefile
`Makefile` yang terdapat pada *repository* ini berarti:
1. Perintah `make soal-02` akan mengeksekusi perintah `gcc -o soal-02 soal-02.c` pada baris kedua yang berfungsi untuk melakukan kompilasi *file* `soal-02.c` dengan *compiler* `gcc` pada *file output* `main`.
2. Perintah `make clean` akan mengeksekusi perintah `rm soal-02` pada baris kedua yang berfungsi untuk menghapus file `soal-02` yang telah terkompilasi sebelumnya.

Apabila anda menggunakan *file eksternal* lainnya, silakan melakukan penyesuaian pada *file* `Makefile` pada bagian `make main` yakni dengan menambahkan perintah `gcc -o soal-02 soal-02.c (file eksternal) -lm`, ubah (file eksternal) dengan nama file yang anda gunakan.

## Perintah Run
Perhatikan bahwa *autograder* bekerja dengan sisten operasi Linux sehingga proses *run* juga disesuaikan dengan sistem operasi tersebut.

Perintah *run* yang digunakan adalah

```sh
./soal-02
```
Perintah tersebut sudah teruji pada `bash` Linux Ubuntu 20.04.

# Hotel Management System (C++ OOP Project)

Proyek ini adalah aplikasi sistem manajemen reservasi hotel. Aplikasi ini dibangun untuk mendemonstrasikan penerapan **Object-Oriented Programming (OOP)**, prinsip **SOLID**, dan **Design Patterns**.

---

## Fitur

### 1. Implementasi Design Patterns

Sistem ini memenuhi kriteria penilaian dengan menerapkan pola desain berikut:

- **Singleton Pattern** (Creational): Digunakan pada class `Hotel` untuk memastikan hanya ada satu instance controller pusat dalam aplikasi.
- **Factory Method Pattern** (Creational): Digunakan pada `RoomFactory` untuk mengenkapsulasi logika pembuatan objek kamar (`Deluxe`, `Superior`, `Suite`).
- **Decorator Pattern** (Structural): Digunakan untuk menambahkan fitur tambahan pada kamar (seperti _Breakfast_) secara dinamis tanpa mengubah class asli.
- **Strategy Pattern** (Behavioral): Digunakan pada modul `Payment` untuk memungkinkan fleksibilitas metode pembayaran (_Cash_ atau _Transfer_).

### 2. Kepatuhan Prinsip SOLID

- **Single Responsibility Principle (SRP):** Setiap modul (Hotel, Room, Customer, Reservation) memiliki tanggung jawab spesifik dan dipisah dalam file berbeda.
- **Open/Closed Principle (OCP):** Sistem terbuka untuk penambahan tipe kamar baru tanpa memodifikasi logika reservasi yang sudah ada.
- **Liskov Substitution Principle (LSP):** Subclass `DeluxeRoom` dapat menggantikan `Room` parent-nya tanpa merusak program.

### 3. Fungsionalitas Sistem

- **Manajemen Inventaris:** Menambah kamar baru dengan validasi ID unik.
- **Manajemen Tamu:** Registrasi tamu baru dan fitur **Edit Data** (Update nama/kontak).
- **Reservasi Cerdas:**
  - Validasi tanggal (Check-Out tidak boleh sebelum Check-In).
  - Pengecekan tabrakan jadwal (_Overlap Checking_) otomatis.
  - Perhitungan biaya otomatis (termasuk biaya tambahan dari Decorator).
- **Laporan & Dashboard:** Melihat statistik hunian, riwayat booking per tamu, dan pencarian ketersediaan kamar.

---

Proyek ini terdiri dari file-file berikut:

- **Core Logic:**

  - `main.cpp` : Entry point dan menu antarmuka pengguna (UI).
  - `Hotel.h/cpp` : Controller utama yang mengatur logika bisnis.
  - `DateUtils.h` : Helper statis untuk validasi tanggal.

- **Entities:**
  - `Room.h/cpp` : Definisi kamar, Factory, dan Decorator.
  - `Customer.h/cpp` : Definisi data tamu (termasuk Setter/Getter).
  - `Reservation.h/cpp` : Menghubungkan Tamu, Kamar, dan Pembayaran.
  - `Payment.h/cpp` : Logika strategi pembayaran.

---

## 🛠️ Cara Kompilasi & Menjalankan

Karena proyek ini menggunakan banyak file, Anda **harus** mengompilasi semua file `.cpp` secara bersamaan.

### Prasyarat

Pastikan Anda memiliki compiler C++ (seperti `g++`) terinstal.

### Perintah Terminal (Windows/Linux/Mac)

Buka terminal/CMD di folder proyek, lalu jalankan perintah berikut:

```bash
g++ main.cpp Hotel.cpp Reservation.cpp Customer.cpp Room.cpp Payment.cpp -o hotel_app
```

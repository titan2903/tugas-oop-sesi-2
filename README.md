# Tugas Inheritance and Polymorphism

## Sistem Pembayaran

Buat sistem pembayaran digital dengan:

- *Payment* sebagai parent class (id, amount, date, status)
- Child classes:

      - *CreditCardPayment*: cardNumber, expiryDate, cvv
      - *BankTransfer*: accountNumber, bankName, transferCode
      - *DigitalWallet*: walletId, provider, phoneNumber

- Implement method *processPayment()*, *validatePayment()* dan *refundPayment()*

## Langkah-langkah Menjalankan Kode

1. Kloning Kode dari GitHub:
   - Lakukan klon kode menggunakan command dibawah ini:

      ```bash
      git clone https://github.com/titan2903/tugas-oop-sesi-2.git
      ```

   - Buka kode yang sudah di klon menggunakan text editor seperti VSCode, Atom, Notepad++, atau sejenisnya.
2. Kompilasi Kode:
   - Buka terminal atau command prompt.
   - Navigasi ke direktori tempat Anda menyimpan file main.cpp.
   - Gunakan compiler C++ untuk mengkompilasi kode. Misalnya, jika Anda menggunakan GCC, jalankan perintah berikut:
  
      ```bash
      g++ main.cpp -o result
      ```

   - Perintah ini akan menghasilkan file executable bernama result (atau result.exe di Windows).
3. Jalankan Program:
   - Setelah kompilasi berhasil, jalankan program dengan perintah:

      ```bash
      ./result
      ```

   - Di Windows:

      ```bash
      result.exe
      ```
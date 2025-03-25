#include <iostream>
#include <string>
using namespace std;

// Parent class
class Payment {
protected:
    int id;
    double amount;
    string date;
    string status;

public:
    //  Payment constructor
    Payment(int id, double amount, string date, string status)
        : id(id), amount(amount), date(date), status(status) {}

    virtual void processPayment() {
        cout << "\nMemproses pembayaran sebesar: " << amount << endl;
    }

    virtual bool validatePayment() {
        cout << "\nMemvalidasi pembayaran..." << endl;
        return true;
    }

    virtual void refundPayment() {
        cout << "\nMengembalikan pembayaran sebesar: " << amount << endl;
    }

    virtual ~Payment() {}
};

// Child class: CreditCardPayment
class CreditCardPayment : public Payment {
private:
    string cardNumber;
    string expiryDate;
    string cvv;

public:
    // CreditCardPayment constructor
    CreditCardPayment(int id, double amount, string date, string status,
                      string cardNumber, string expiryDate, string cvv)
        : Payment(id, amount, date, status), cardNumber(cardNumber),
          expiryDate(expiryDate), cvv(cvv) {}

    void processPayment() override {
        cout << "\nMemproses pembayaran kartu kredit sebesar: " << amount << endl;
    }

    bool validatePayment() override {
        cout << "\nMemvalidasi detail kartu kredit..." << endl;
        return !cardNumber.empty() && !expiryDate.empty() && !cvv.empty();
    }

    void refundPayment() override {
        cout << "\nMengembalikan pembayaran kartu kredit sebesar: " << amount << endl;
    }
};

// Child class: BankTransfer
class BankTransfer : public Payment {
private:
    string accountNumber;
    string bankName;
    string transferCode;

public:
    // BankTransfer constructor
    BankTransfer(int id, double amount, string date, string status,
                 string accountNumber, string bankName, string transferCode)
        : Payment(id, amount, date, status), accountNumber(accountNumber),
          bankName(bankName), transferCode(transferCode) {}

    void processPayment() override {
        cout << "\nMemproses pembayaran transfer bank sebesar: " << amount << endl;
    }

    bool validatePayment() override {
        cout << "\nMemvalidasi detail transfer bank..." << endl;
        return !accountNumber.empty() && !bankName.empty() && !transferCode.empty();
    }

    void refundPayment() override {
        cout << "\nMengembalikan pembayaran transfer bank sebesar: " << amount << endl;
    }
};

// Child class: DigitalWallet
class DigitalWallet : public Payment {
private:
    string walletId;
    string provider;
    string phoneNumber;

public:
    DigitalWallet(int id, double amount, string date, string status,
                  string walletId, string provider, string phoneNumber)
        : Payment(id, amount, date, status), walletId(walletId),
          provider(provider), phoneNumber(phoneNumber) {}

    void processPayment() override {
        cout << "\nMemproses pembayaran dompet digital sebesar: " << amount << endl;
    }

    bool validatePayment() override {
        cout << "\nMemvalidasi detail dompet digital..." << endl;
        return !walletId.empty() && !provider.empty() && !phoneNumber.empty();
    }

    void refundPayment() override {
        cout << "\nMengembalikan pembayaran dompet digital sebesar: " << amount << endl;
    }
};

// Main function
int main() {
    Payment* payment1 = new CreditCardPayment(1, 100.0, "2025-03-01", "Pending", "1234567890123456", "12/25", "123");
    Payment* payment2 = new BankTransfer(2, 200.0, "2025-03-02", "Pending", "123456789", "Bank ABC", "TRF123");
    Payment* payment3 = new DigitalWallet(3, 50.0, "2025-03-03", "Pending", "WALLET12345", "ProviderX", "08123456789");

    payment1->processPayment();
    payment2->processPayment();
    payment3->processPayment();

    if (payment1->validatePayment()) {
        cout << "\nPembayaran kartu kredit valid" << endl;
    } else {
        cout << "\nPembayaran kartu kredit tidak valid" << endl;
    }

    if (payment2->validatePayment()) {
        cout << "\nPembayaran transfer bank valid" << endl;
    } else {
        cout << "\nPembayaran transfer bank tidak valid" << endl;
    }

    if (payment3->validatePayment()) {
        cout << "\nPembayaran dompet digital valid" << endl;
    } else {
        cout << "\nPembayaran dompet digital tidak valid" << endl;
    }

    payment1->refundPayment();
    payment2->refundPayment();
    payment3->refundPayment();

    delete payment1;
    delete payment2;
    delete payment3;

    return 0;
}
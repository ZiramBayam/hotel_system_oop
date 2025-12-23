#include "Payment.h"

using namespace std;

void CashPayment::pay(double amount) {
    cout << "   [PAYMENT] Menerima tunai: Rp " << (long)amount << endl;
}
string CashPayment::getMethodName() { return "Cash"; }

void TransferPayment::pay(double amount) {
    cout << "   [PAYMENT] Transfer bank sukses: Rp " << (long)amount << endl;
}
string TransferPayment::getMethodName() { return "Bank Transfer"; }

Payment::Payment(int id, double amount, IPaymentStrategy* strat) 
    : idPayment(id), totalAmount(amount), strategy(strat), status("Pending") {}

void Payment::process() {
    if (strategy) {
        strategy->pay(totalAmount);
        status = "Success";
    }
}

string Payment::getStatus() const { return status; }
double Payment::getAmount() const { return totalAmount; }
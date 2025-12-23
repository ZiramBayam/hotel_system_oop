#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>

class IPaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual std::string getMethodName() = 0;
    virtual ~IPaymentStrategy() {}
};

class CashPayment : public IPaymentStrategy {
public:
    void pay(double amount) override;
    std::string getMethodName() override;
};

class TransferPayment : public IPaymentStrategy {
public:
    void pay(double amount) override;
    std::string getMethodName() override;
};

class Payment {
private:
    int idPayment;
    double totalAmount;
    std::string status;
    IPaymentStrategy* strategy;

public:
    Payment(int id, double amount, IPaymentStrategy* strat);
    void process();
    std::string getStatus() const;
    double getAmount() const;
};

#endif
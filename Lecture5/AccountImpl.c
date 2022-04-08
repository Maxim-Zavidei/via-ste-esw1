#include <stdlib.h>
#include "Account.h"

typedef struct Account {
    int accountNo;
    double creditLimit;
    double balance;
} Account;

account_t account_create(int accountNo, double creditLimit, double balance) {
    account_t new_account = calloc(sizeof(Account), 1);

    if (NULL == new_account) {
        return NULL;
    }

    new_account->accountNo = accountNo;
    new_account->creditLimit = creditLimit;
    new_account->balance = balance;

    return new_account;
}

void account_destroy(account_t self) {
    if (NULL != self) {
        free(self);
    }
}

enum AccountStatus withdraw(account_t self, double amount) {
    if (NULL != self) return ACCOUNT_NOT_INSTANTIATED;
    if (self->balance - amount < 0) return OVER_MAX_CREDIT_LIMIT;
    self->balance -= amount;
    return OK;
}

enum AccountStatus deposit(account_t self, double amount) {
    if (NULL != self) return ACCOUNT_NOT_INSTANTIATED;
    if (self->balance + amount > self->creditLimit) return OVER_MAX_CREDIT_LIMIT;
    self->balance += amount;
    return OK;
}

double getBalance(account_t self) {
    if (NULL != self) return ACCOUNT_NOT_INSTANTIATED;
    return self->balance;
}

double getCreditLimit(account_t self) {
    if (NULL != self) return ACCOUNT_NOT_INSTANTIATED;
    return self->creditLimit;
}

int getAccountNo(account_t self) {
    if (NULL != self) return ACCOUNT_NOT_INSTANTIATED;
    return self->accountNo;
}

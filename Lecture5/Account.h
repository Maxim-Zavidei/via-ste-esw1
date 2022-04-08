#pragma once

enum AccountStatus {
    OK,
    OVER_MAX_CREDIT_LIMIT,
    ACCOUNT_NOT_INSTANTIATED
};

typedef struct Account* account_t;

account_t account_create(int accountNo, double creditLimit, double balance);
void account_destroy(account_t self);
enum AccountStatus withdraw(account_t self, double amount);
enum AccountStatus deposit(account_t self, double amount);
double getBalance(account_t self);
double getCreditLimit(account_t self);
int getAccountNo(account_t self);

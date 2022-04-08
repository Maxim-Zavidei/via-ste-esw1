#include <stdio.h>
#include "Account.h"

int main() {
    account_t accounts[10];
    for (int i = 0; i < 10; i++) {
        accounts[i] = account_create(2, 50, 30);
    }

    for (int i = 0; i < 10; i++) {
        printf("balance: %f\n", getBalance(accounts[i]));
    }

    for (int i = 0; i < 10; i++) {
        account_destroy(accounts[i]);
    }

    return 0;
}
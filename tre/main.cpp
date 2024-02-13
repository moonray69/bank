#include "bank.h"

int main() {

	bank monobank(4);

	bank_account account1;

	bank_account account2;

	bank_account account3;

	account1.input();
	account2.input();
	account3.input();

	monobank.add_bank_account(account1);
	monobank.add_bank_account(account2);
	monobank.add_bank_account(account3);

	monobank.print();

	monobank.withdraw(account3, 100);
	monobank.withdraw(account1, 200);

	monobank.checkins(account2, 300);
	monobank.checkins(account1, 50);

	monobank.print();

	return 0;
}
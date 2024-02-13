#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

class client {
private:
	string name;
	string surname;
	int age;

public:

	client() {
		name = "";
		surname = "";
		age = 0;

	}

	client(const string& name_, const string& surname_, int age_) {
		name = name_;
		surname = surname_;
		age = age_;
	}

	client(const client& other) {
		this->name = other.name;
		this->surname = other.surname;
		this->age = other.age;
	}

	void print()const {
		cout << "Information about the customer: " << endl;
		cout << name << " " << surname << " " << age << endl;
		cout << endl;
	}

	void input() {
		cout << "Enter your name: ";
		cin >> name;
		cout << "Enter your surname: ";
		cin >> surname;
		cout << "Enter your age: ";
		cin >> age;
		cout << endl;
	}

};


class bank_account {
private:
	string number_account;
	int amount_of_money;
	client Client;

public:

	bank_account(): Client() {
		number_account = "";
		amount_of_money = 0;
	}
	
	bank_account(const string& number_account_, int amount_of_money_, const string& name_, const string& surname_, int age_): Client(name_, surname_, age_) {
		number_account = number_account_;
		amount_of_money = amount_of_money_;
	}

	bank_account(const bank_account& other): Client(other.Client) {
		this->amount_of_money = other.amount_of_money;
		this->number_account = other.number_account;
	}

	void print()const {
		cout << "Bank information: " << endl;
		cout << amount_of_money << " " << number_account << endl;
		Client.print();
		cout << endl;
	}

	void withdrawals(int amount_of_money_) {
		if (amount_of_money - amount_of_money_ < 0) {
			cout << "don`t have enough money";
		}
		else {
			amount_of_money -= amount_of_money_;
			cout << "successful";
		}
		cout << endl;
	}

	void checkin(int amount_of_money_) {
		amount_of_money += amount_of_money_;
		cout << "money was successfully credited";
		cout << endl;
	}

	void input() {
		cout << "Enter number account: ";
		cin >> number_account;
		cout << "Balance: ";
		cin >> amount_of_money;
		Client.input();
		cout << endl;
	}

	bool operator==(const bank_account& ANOTHER)const {
		return this->number_account == ANOTHER.number_account;
	}

};

class bank {
private:
	bank_account* accounts;
	int size;
	int i;
public:

	bank() {
		accounts = 0;
		size = 0;
		i = 0;
	}

	bank(int size_) {
		size = size_;
		accounts = new bank_account[size_];
		i = 0;
	}

	bank(const bank& other) {
		this->size = other.size;
		this->accounts = new bank_account[this->size];
		for (int i = 0; i < size; i++) {
			this->accounts[i] = other.accounts[i];
		}
		this->i = other.i;
	}

	~bank() { delete[] accounts; }

	void add_bank_account(const bank_account& another) { 
		if (i >= size) {
			cout << "account does not accept so many accounts!";
		}
		else {
			accounts[i] = another;
			i++;
		}
	}

	void print()const {
		for (int j = 0; j < i; j++){
			accounts[j].print();
		}
	}

	void withdraw(const bank_account& account, int money) {
		for (int j = 0; j < i; j++){
			if (accounts[j] == account) {
				accounts[j].withdrawals(money);
				break;
			}
		}
	}

	void checkins(const bank_account& account, int money) {
		for (int j = 0; j < i; j++) {
			if (accounts[j] == account) {
				accounts[j].checkin(money);
				break;
			}
		}
	}
};





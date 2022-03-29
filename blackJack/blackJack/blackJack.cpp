#include<iostream>
#include <vector>
#include<algorithm>

class accountMaker {
public:
	std::string username;
	std::string password;
	int currentBalance = 500;
};

accountMaker account1;
accountMaker account2;
accountMaker account3;

std::vector<std::string> listOfAccountUsernames = {""};
std::vector<std::string> listOfAccountPasswords = { "" };
std::vector<int> listOfDepositedValues = {0};

int amountOfAccounts = 1;

void setUp();
void makeAccount();
int getAccountNumber(std::string a);
void sendValuesToObject(int i);
void login();
void beginBlackjack();

void setUp() {
	int a;
	std::cout << "1. Login to an account\n";
	std::cout << "2. Make an account\n";
    std::cin >> a;
	switch (a) {
	case 1:
		login();
		break;
	case 2:
		makeAccount();
		break;
	default:
		std::cout << "Pick a valid option\n";
	}
}

void makeAccount() {
	int accountNumber;
	std::cout << "Enter a username\n";
	std::string userName;
	std::cin >> userName;

	std::cout << "Enter a password\n";
	std::string password;
	std::cin >> password;

	listOfAccountUsernames.push_back(userName);
	listOfAccountPasswords.push_back(password);
	listOfDepositedValues.push_back(0);

	accountNumber = getAccountNumber(userName);
	sendValuesToObject(accountNumber);
	std::cout << accountNumber;
	std::cout << "New account created\n";
	login();
}

int getAccountNumber(std::string a) {
	for (int i = 0; i <= listOfAccountUsernames.size(); i++) {
		if (listOfAccountUsernames[i] == a) {
			return i;
		}
	}
}

void sendValuesToObject(int i) {
	int a = i;
	a--;
	switch (i) {
	case 1:
		account1.username = listOfAccountUsernames[a];
		account1.password = listOfAccountPasswords[a];
		account1.currentBalance = listOfDepositedValues[a];
		break;
	case 2:
		account2.username = listOfAccountUsernames[a];
		account2.password = listOfAccountPasswords[a];
		account2.currentBalance = listOfDepositedValues[a];
		break;
	case 3:
		account3.username = listOfAccountUsernames[a];
		account3.password = listOfAccountPasswords[a];
		account3.currentBalance = listOfDepositedValues[a];
		break;
	}
}

void login() {
	std::string username;
	std::string password;
	int accountNumber;
	for (int i = 0; i < 3; i++) {
		switch (i) {
		case 1:
			if (account1.username == username) {
				accountNumber = 1;
			}
			break;
		}
	}
	if (std::binary_search(listOfAccountUsernames.begin(), listOfAccountUsernames.end(), username)) {
		if (std::binary_search(listOfAccountPasswords.begin(), listOfAccountPasswords.end(), password)) {
			switch (accountNumber) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			}
		}
	}
}

void beginBlackjack() {
	std::cout << "You current balance is: " << account1.currentBalance;
	std::cout << "How much do you want to bid\n";
}

int main() {
	setUp();
	return 0;
}
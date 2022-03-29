#include <algorithm>
#include <iostream>
#include <vector>


class accountMaker {
public:
  std::string username;
  std::string password;
  int currentBalance = 500;
  bool loggedIn = false;
};

accountMaker account1;
accountMaker account2;
accountMaker account3;

std::vector<std::string> listOfAccountUsernames = {""};
std::vector<std::string> listOfAccountPasswords = {""};
std::vector<int> listOfDepositedValues = {0};

int amountOfAccounts = 1;

void setUp();
void makeAccount();
int getAccountNumber(std::string a);
void sendValuesToObject(int i);
void login(int theAccountNumber);
void beginBlackjack(int a);

void setUp() {
  int a;
  std::cout << "1. Login to an account\n";
  std::cout << "2. Make an account\n";
  std::cin >> a;
  switch (a) {
  case 1:
      int saveNumber;
      std::cout << "Select save file number\n";
      std::cin >> saveNumber;
    login(saveNumber);
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
  std::cout << "New account created\n";
  std::cout << "Using save" << accountNumber;
  switch (accountNumber) {
  case 1:
    account1.loggedIn = true;
    break;
  case 2:
    account2.loggedIn = true;
    break;
  case 3:
    account3.loggedIn = true;
  }
  beginBlackjack(accountNumber);
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

void login(int theAccountNumber) {
  std::string username;
  std::string password;

  int accountNumber = getAccountNumber(username);

  switch (theAccountNumber) {
  case 1:
    if (listOfAccountUsernames[accountNumber] == username) {
    }
  }
  /*if (std::binary_search(listOfAccountUsernames.begin(),
  listOfAccountUsernames.end(), username)) { if
  (std::binary_search(listOfAccountPasswords.begin(),
  listOfAccountPasswords.end(), password)) { std::cout << "Logged in\n"; for
  (int i = 0; i < 3; i++) { switch (i) { case 1: if (account1.username ==
  username) { accountNumber = 1; std::cout << "Using save 1\n";
                                  }
                                  break;
                          case 2:
                                  if (account2.username == username) {
                                          accountNumber = 2;
                                          std::cout << "Using save 2\n";
                                  }
                                  break;
                          case 3:
                                  if (account3.username == username) {
                                          accountNumber = 3;
                                          std::cout << "Using save 3\n";
                                  }
                                  break;
                          }
                  }
          }
          else {
                  std::cout << "Wrong username or password";
          }
  }
  */
}

void beginBlackjack(int a) {
  std::vector<bool> accountDeterminingVector;
  accountDeterminingVector.push_back(account1.loggedIn);
  accountDeterminingVector.push_back(account2.loggedIn);
  accountDeterminingVector.push_back(account3.loggedIn);
  std::cout << "You current balance is: " << account1.currentBalance;
  std::cout << "How much do you want to bid\n";
}

int main() {
  setUp();
  return 0;
}
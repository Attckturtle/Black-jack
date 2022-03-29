#include <algorithm>
#include <iostream>
#include <vector>


class accountMaker {
public:
  std::string username;
  std::string password;
  int currentBalance = 500;
  int currentBet = 0;
  bool loggedIn = false;
  int wins = 0;

  std::vector<int>chosenCards;
};

class dealerCreator {
public:
    std::vector<int>chosenCards;
    int wins = 0;
};

class deckOfCardsMaker {
public:
    std::vector<int>potentialCards;
    void createSelf() {
        for (int i = 1; i < 3; i++) {
            for (int b = 1; b < 10; b++) {
                potentialCards.push_back(b);
                std::cout << b;
            }
        }
    }
};

deckOfCardsMaker deck;

dealerCreator dealer;

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
void login();
void beginBlackjack(int a);
void account1BlackJackProcessing(int a);
void account2BlackJackProcessing(int a);
void account3BlackJackProcessing(int a);

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
  std::cout << "New account created\n";
  std::cout << "Using save " << accountNumber << std::endl;
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
      i++;
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
  std::cout << "Enter username";
  std::cin >> username;
  std::cout << "Enter password";
  std::cin >> password;

  int accountNumber = getAccountNumber(username);

  switch (accountNumber) {
  case 1:
    if (account1.username == username) {
        beginBlackjack(0);
    }
    break;
  case 2:
      if (account2.username == username) {
          beginBlackjack(1);
      }
      break;
  case 3:
      if (account3.username == username) {
          beginBlackjack(2);
      }
      break;
  }
}

void beginBlackjack(int a) {
  int biddingAmount;
  std::vector<bool> accountDeterminingVector;
  accountDeterminingVector.push_back(account1.loggedIn);
  accountDeterminingVector.push_back(account2.loggedIn);
  accountDeterminingVector.push_back(account3.loggedIn);
  std::cout << "Your current balance is: " << account1.currentBalance << std::endl;
  std::cout << "How much do you want to bid\n";
  std::cin >> biddingAmount;
  if (account1.loggedIn == true) {
      account1.currentBet = biddingAmount;
      std::cout << "$" << account1.currentBet << " deposited\n";
      account1BlackJackProcessing(biddingAmount);
  }
  else if (account2.loggedIn == true) {
      account2.currentBet = biddingAmount;
      std::cout << "$" << account2.currentBet << " deposited\n";
  }
  else if (account3.loggedIn == true) {
      account3.currentBet = biddingAmount;
      std::cout << "$" << account3.currentBet << " deposited\n";
  }
}

void account1BlackJackProcessing(int a){
 int indexOfRemoveNumberPlayer = rand() % (deck.potentialCards.size() - 1) + 0;
 int indexOfRemoveNumberDealer = rand() % (deck.potentialCards.size() - 1) + 0;
}

void account2BlackJackProcessing(int a) {

}

void account3BlackJackProcessing(int a) {

}

int main() {
    deck.createSelf();
    //for (auto i : deck.potentialCards) {
    //    std::cout << i << ' '; 
    //}
    setUp();
  return 0;
}
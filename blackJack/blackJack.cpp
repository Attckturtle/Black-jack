#include <iostream>
#include <vector>
#include <chrono>
#include <thread>


class accountMaker {
public:
  std::string username;
  std::string password;
  int currentBalance = 0;
  int totalCards = 0;
  int currentBet = 0;
  bool loggedIn = false;
  int wins = 0;
  std::vector<int>chosenCards;

  void setValues() {
      currentBalance = 500;
      totalCards = 0;
      currentBet = 0;
      loggedIn = false;
      wins = 0;
  }
};

class dealerCreator {
public:
    std::vector<int>chosenCards;
    int totalScore = 0;
    int wins = 0;
};

class deckOfCardsMaker {
public:
    std::vector<int>potentialCards;
    void createSelf() {
        for (int i = 0; i < 4; i++) {
            for (int b = 1; b < 10; b++) {
                potentialCards.push_back(b);
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
const int winningScore = 21;

bool dealerTrue;
bool playerTrue;

void setUp();
void makeAccount();
int getAccountNumber(std::string a);
void sendValuesToObject(int i);
void login();
void beginBlackjack(int a);
void account1BlackJackProcessing(int a);
void account2BlackJackProcessing(int a);
void account3BlackJackProcessing(int a);
void dealerProcessing(int a);
void seeWhoWon(int a);

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
    setUp();
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

  accountNumber = getAccountNumber(userName);
  sendValuesToObject(accountNumber);
  std::cout << "New account created\n";
  std::cout << "Using save " << accountNumber << "\n";
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
            break;
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
    break;
  case 2:
    account2.username = listOfAccountUsernames[a];
    account2.password = listOfAccountPasswords[a];
    break;
  case 3:
    account3.username = listOfAccountUsernames[a];
    account3.password = listOfAccountPasswords[a];
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
  std::cout << "Your current balance is: " << account1.currentBalance << "\n";
  std::cout << "How much do you want to bid?\n";
  std::cin >> biddingAmount;
  if (account1.loggedIn == true) {
      account1.currentBet = biddingAmount;
      std::cout << "$" << account1.currentBet << " deposited\n";
      account1BlackJackProcessing(biddingAmount);
  }
  else if (account2.loggedIn == true) {
      account2.currentBet = biddingAmount;
      std::cout << "$" << account2.currentBet << " deposited\n";
      account2BlackJackProcessing(biddingAmount);
  }
  else if (account3.loggedIn == true) {
      account3.currentBet = biddingAmount;
      std::cout << "$" << account3.currentBet << " deposited\n";
      account3BlackJackProcessing(biddingAmount);
  }
  dealerProcessing(biddingAmount);
}

//TODO: Gives 2 wins
void dealerProcessing(int a) {
    std::cout << "Dealer drew another card\n";
    int indexOfRemoveNumberDealer = rand() % (deck.potentialCards.size() - 1) + 0;
    dealer.totalScore += deck.potentialCards[indexOfRemoveNumberDealer];
    dealer.chosenCards.push_back(deck.potentialCards[indexOfRemoveNumberDealer]);

    int determineDealerMove = rand() % 5 + 1;
    if (dealer.totalScore < (winningScore - determineDealerMove)) {
        dealerProcessing(a);
    }
    else if (dealer.totalScore > (winningScore - determineDealerMove)) {
        dealerTrue = true;
        seeWhoWon(a);
    }
}

void account1BlackJackProcessing(int a){
 bool drawingAnotherCard = true;
 char letterAnswer;
 if (drawingAnotherCard) {
     int indexOfRemoveNumberPlayer = rand() % (deck.potentialCards.size() - 1) + 0;
     account1.totalCards += deck.potentialCards[indexOfRemoveNumberPlayer];
     account1.chosenCards.push_back(deck.potentialCards[indexOfRemoveNumberPlayer]);
     drawingAnotherCard = false;

     std::cout << "You currently have: \n";
     for (int i = 0; i < account1.chosenCards.size(); i++) {
         std::cout << account1.chosenCards[i] << "\n";
     }
     std::cout << "\n";
 }
 std::cout << "Draw another card? T/F\n";
 std::cin >> letterAnswer;
 letterAnswer = toupper(letterAnswer);

 switch (letterAnswer) {
 case 'T':
     drawingAnotherCard = true;
     account1BlackJackProcessing(a);
     break;
 case 'F':
     drawingAnotherCard = false;
     playerTrue = true;
     seeWhoWon(a);
     break;
     default:
     std::cout << "Pick a valid option\n";
     account1BlackJackProcessing(a);
 }
}

void account2BlackJackProcessing(int a) {
    std::cout << "You currently have: ";
    for (auto i : account2.chosenCards) {
        std::cout << i << ' ';
    }
    std::cout << "" << std::endl;
    int indexOfRemoveNumberPlayer = rand() % (deck.potentialCards.size() - 1) + 0;
    account2.totalCards += deck.potentialCards[indexOfRemoveNumberPlayer];
    account2.chosenCards.push_back(deck.potentialCards[indexOfRemoveNumberPlayer]);

    int indexOfRemoveNumberDealer = rand() % (deck.potentialCards.size() - 1) + 0;
    dealer.totalScore += deck.potentialCards[indexOfRemoveNumberPlayer];
    dealer.chosenCards.push_back(deck.potentialCards[indexOfRemoveNumberDealer]);
}

void account3BlackJackProcessing(int a) {
    std::cout << "You currently have: ";
    for (auto i : account3.chosenCards) {
        std::cout << i << ' ';
    }
    std::cout << "" << std::endl;
    int indexOfRemoveNumberPlayer = rand() % (deck.potentialCards.size() - 1) + 0;
    account3.totalCards += deck.potentialCards[indexOfRemoveNumberPlayer];
    account3.chosenCards.push_back(deck.potentialCards[indexOfRemoveNumberPlayer]);

    int indexOfRemoveNumberDealer = rand() % (deck.potentialCards.size() - 1) + 0;
    dealer.totalScore += deck.potentialCards[indexOfRemoveNumberPlayer];
    dealer.chosenCards.push_back(deck.potentialCards[indexOfRemoveNumberDealer]);
}

void seeWhoWon(int a) {
    bool dealerLessThan21 = false;
    bool playerLessThan21 = false;
    if (dealerTrue && playerTrue) {
        if (dealer.totalScore <= 21)
        {
            dealerLessThan21 = true;
        }

        if (account1.totalCards <= 21) {
            playerLessThan21 = true;
        }

        if (!dealerLessThan21 && playerLessThan21) {
            std::cout << "You win " << a << " dollars!\n";
            account1.currentBalance += a;
            std::cout << account1.currentBalance << " dollars remaining\n";
        }
        else if (dealerLessThan21 && !playerLessThan21) {
            std::cout << "Dealer wins you lost " << a << "dollars!\n";
            account1.totalCards -= a;
            std::cout << account1.currentBalance << " dollars remaining\n";
        }

        if (dealerLessThan21 && playerLessThan21) {
            if (dealer.totalScore < account1.totalCards) {
                std::cout << "You win " << a << "dollars!\n";
                account1.currentBalance += a;
                std::cout << account1.currentBalance << " dollars remaining\n";
            }
            else if (dealer.totalScore > account1.totalCards) {
                std::cout << "Dealer wins you lost " << a << "dollars!\n";
                account1.totalCards -= a;
                std::cout << account1.currentBalance << " dollars remaining\n";
            }
        }
    }
    else if (!dealerTrue && playerTrue) {
        dealerProcessing(a);
    }

    else if (dealerTrue && !playerTrue) {
        account1BlackJackProcessing(a);
    }
}

int main() {
    account1.setValues();
    account2.setValues();
    account3.setValues();
    deck.createSelf();
    setUp();
  return 8;
}
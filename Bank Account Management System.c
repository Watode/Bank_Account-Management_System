#include <stdio.h>

typedef struct {
  int account_number;
  char name[50];
  float balance;
} Account;

void create_account(Account *accounts, int *account_count);
void display_accounts(Account *accounts, int account_count);
void deposit(Account *accounts, int account_count);
void withdraw(Account *accounts, int account_count);

int main() {
  int account_count = 0;
  Account accounts[100];
  int choice;

  while (1) {
    printf("\n1. Create Account\n");
    printf("2. Display Accounts\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      create_account(accounts, &account_count);
      break;
    case 2:
      display_accounts(accounts, account_count);
      break;
    case 3:
      deposit(accounts, account_count);
      break;
    case 4:
      withdraw(accounts, account_count);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}

void create_account(Account *accounts, int *account_count) {
  printf("Enter account number: ");
  scanf("%d", &accounts[*account_count].account_number);
  getchar(); // consume newline
  printf("Enter account holder name: ");
  fgets(accounts[*account_count].name, 50, stdin);
  accounts[*account_count].balance = 0;
  (*account_count)++;
}

void display_accounts(Account *accounts, int account_count) {
  printf("\nAccount Number\t\tName\t\tBalance\n");
  for (int i = 0; i < account_count; i++) {
    printf("%d\t\t%s\t\t%.2f\n", accounts[i].account_number, accounts[i].name,
           accounts[i].balance);
  }
}

void deposit(Account *accounts, int account_count) {
  int account_number;
  float amount;

  printf("Enter account number: ");
  scanf("%d", &account_number);

  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Enter amount to deposit: ");
      scanf("%f", &amount);
      accounts[i].balance += amount;
      printf("Amount deposited successfully.\n");
      return;
    }
  }

  printf("Account not found.\n");
}

void withdraw(Account *accounts, int account_count) {
  int account_number;
  float amount;

  printf("Enter account number: ");
  scanf("%d", &account_number);

  for (int i = 0; i < account_count; i++) {
    if (accounts[i].account_number == account_number) {
      printf("Enter amount to withdraw: ");
      scanf("%f", &amount);
      if (accounts[i].balance >= amount) {
        accounts[i].balance -= amount;
        printf("Amount withdrawn successfully.\n");
      } else {
        printf("Insufficient balance.\n");
      }
      return;
    }
  }

  printf("Account not found.\n");
}
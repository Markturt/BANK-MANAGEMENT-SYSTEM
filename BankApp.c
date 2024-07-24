#include <stdio.h>
#include <cs50.h>
#include <time.h>
#include <stdlib.h>

typedef struct 
{
    int balance;
    char* name;
    char* acct_No;
    bool acct_deleted;
    char* password;
} customer;



customer customers[]={};


//Function Prototypes
void manage_acct(void);
void make_transactions(void);
void check_balance(void);
void create_acct(int customer_index);

int main(void)
{
    int option;

    printf("You are Welcome! \n");
    
    printf("\n Select from the options Below. \n\n");

    printf("1. Manage Account\n");
    printf("2. Handle Transactions\n");
    printf("3. Check Balance\n");

    scanf("%i",&option);

    switch (option)
    {
    case 1:
        manage_acct();   
        break;
    case 2:
        // Handle Transactions
        make_transactions();
        break;
    case 3:
        // Check Balance
        check_balance();
        break;
    default:
    printf("Invalid Option.\n");
        break;
    }
    
}



void manage_acct(void)
{
    int number_of_customers = 0;

    printf("1. Create new Account\n");
    printf("2. Delete Existing Account\n");
    printf("3. Modify Account Details.\n");

    int option;
    scanf("%i",&option);

    switch (option)
    {
    case 1:
        // Create new Account.
        create_acct(number_of_customers);
        number_of_customers++;
        break;
    case 2:
        // Delete new Account.
        number_of_customers--;
        break;
    case 3:
        // Modify Account details
        break;
    default:
    printf("Invalid Option.\n");
        break;
    }

}

void make_transactions(void)
{
    int option;
    printf("1. Deposit Money\n");
    printf("2. Withdraw Money\n");
    printf("3. Transfer Money.\n");


    scanf("%i",&option);

    switch (option)
    {
    case 1:
        // deposit(int money).
        break;
    case 2:
        // Withdraw Money.
        break;
    case 3:
        //Transfer Money.
    default:
        printf("Invalid Option");
        break;
    }
}

void check_balance(void)
{
    const int SIZE =100;
    char number[SIZE];
    char password[SIZE];
    // Performs Some form of Authentication before Checking the Balance
    printf("Account Number: ");
    
    scanf("%s",&number);

    printf("Password: ");
    scanf("%s",&password);
}

void create_acct(int customer_index)
{
    char name[100];
    char password[100];

    printf("Name: ");
    scanf("%s",&name);

    printf("\n Create password: ");
    scanf("%s",&password);

    customers[customer_index].name =name;
    customers[customer_index].password =password;
    customers[customer_index].acct_No="1234567890";
    customers[customer_index].acct_deleted=false;
    customers[customer_index].balance =0;

    
}
#include <stdio.h>
#include <cs50.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int balance;
    string name;
    int acct_No;
    bool acct_deleted;
    string password;
} customer;



customer customers[100];
int number_of_customers = 0;


//Function Prototypes
void create_acct(void);
void manage_acct(void);
int generate_acct_no(void);
int get_customer_index(int acct_num);
void delete_acct(int account_number,string passkey);
void modify_acct(string passKey ,int acct_num);
void make_transactions(void);
void deposit_money(int Acc_No);
void withdraw_money(int Acc_No,string password);
void transfer(string password,int giver);
void check_balance(int acct_no,string password);

int main(void)
{
    int option =22;
    while(option !=0)
    {
        printf("Enter The Index Of the operation you Want to Perform.\n");
        printf("1. Manage Account.\n");
        printf("2. Handle Transactions.\n");
        printf("3. Check Balance.\n");
        printf("4. Exit...\n");

        option =get_int("Enter Option: ");

        if(option ==1)
        {
            manage_acct();
        }
        else if(option ==2)
        {
            make_transactions();
        }
        else if(option == 3 )
        {
            int acc_no =get_int("Account Number: ");
            string password = get_string("Password: ");
            check_balance(acc_no,password);
        }
        else if(option ==4)
        {
            printf("Thank You For Banking with Us.\n");
            option =0;
        }
        else
        {
            printf("Invalid Operations.\n");
        }
    }  
}

// Helper Functions
int get_customer_index(int acct_num)
{
    // This Functions returns the index of a customer 
    //if the acct has not been deleted and returns -7 if the account doesnt exist.
    for(int i=0;i < number_of_customers; i++)
    {
        int check =customers[i].acct_No==acct_num;
        if( check == 1 && (!customers[i].acct_deleted))
        {
            return i;
        }
    }
    return -7;
}

int generate_acct_no(void)
{
    srand(time(NULL));

    long long min =1000000000;
    long long max =9999999999;

    int num = min + rand()%(max-min +1);

    return num;
}

// Programs Functions.

void manage_acct(void)
{
    printf("What do you want to do? \n");

    printf("1. Create Account. \n");
    printf("2. Delete Account. \n");
    printf("3. Modify Account.\n");

    int  option = get_int("Choose From the List Above. \n");

    if(option ==1)
    {
        create_acct();
    }
    else if(option ==2)
    {
        int account_number =get_int("Account Number: ");
        string password = get_string("Password: ");
        delete_acct(account_number,password);
    }
    else if(option ==3)
    {
        printf("Enter The Details of the  Account You Want to Modify.\n");

        string password =get_string("Password:  ");
        int acct_numb =get_int("Account Number: ");

        modify_acct(password,acct_numb);
    }
    else
    {
        printf("Invalid option.\n");
    }
    return;
}
void create_acct(void)
{
    int customer_index =number_of_customers;
    const int acc_no =generate_acct_no();
    
    customers[customer_index].acct_deleted =false;
    customers[customer_index].balance =0;
    customers[customer_index].name =get_string("Name: ");
    customers[customer_index].password =get_string("Password: ");
    customers[customer_index].acct_No = acc_no;

    printf("Account Successfully Created,Your account Number is %i\n",acc_no);

    number_of_customers++;
    return;
}

void delete_acct(int account_number,string passkey)
{
    int index =get_customer_index(account_number);

    if(index ==-7)
    {
        printf("Account Not Found.\n");
    }
    else if(strcmp(customers[index].password,passkey)==0)
    {
        customers[index].acct_deleted =true;
        printf("Account successfully Deleted.\n");
    }
    else
    {
        printf("Password is not a match.\n");
    }
    return;
}

void modify_acct(string passKey ,int acct_num)
{
    int acct_index =get_customer_index(acct_num);

    if(acct_index ==-7)
    {
        printf("Account Not Found.\n");
    }
    else if(strcmp(customers[acct_index].password,passKey) == 0)
    {
        customers[acct_index].password =get_string("New Password: ");
        customers[acct_index].name =get_string("New Name: ");

        printf("Account Successfully Modified.\n");
    }
    else
    {
        printf("Invalid Password.\n");
    }
}

void make_transactions(void)
{
    printf("What do you want to do? \n");

    printf("1. Deposit Funds. \n");
    printf("2. Withdraw Funds. \n");
    printf("3. Transfer Funds.\n");

    int option = get_int("Choose from the Options Above.");

    if(option == 1)
    {
        int acct_no = get_int("Enter The Account Number you want to Deposit into: ");

        deposit_money(acct_no);      
    }
    else if(option ==2)
    {
        int acct_no = get_int("Enter The Account Number you want to Withdraw from: ");
        string pasword =get_string("Password: ");   
        withdraw_money(acct_no,pasword);
    }
    else if(option ==3)
    {
        string password =get_string("Your password: ");
        int givers_acct =get_int("Givers Account Number: ");

        transfer(password,givers_acct);
    }
    else
    {
        printf("Invalid option.\n");
    }
}

void deposit_money(int Acc_No)
{
    int acct_index =get_customer_index(Acc_No);

    if(acct_index ==-7)
    {
        printf("Account is not on database.\n");
    }
    else
    {
        printf("Balance: %i\n",customers[acct_index].balance);
        int amount = get_int("Amount: ");
        if (amount >0)
        {
            customers[acct_index].balance +=amount;
            printf("Amount Successfully Deposited.\n");
            printf("Balance: %i\n",customers[acct_index].balance);
        }
        else
        {
            printf("Invalid Amount.\n");
        }
    }
    return;
}

void withdraw_money(int Acc_No,string password)
{
    int acct_index =get_customer_index(Acc_No);

    printf("Balance: %i\n",customers[acct_index].balance);

    if(acct_index ==-7)
    {
        printf("Account is not on database.\n");
    }
    else if(strcmp(customers[acct_index].password,password) == 0)
    {
        int amount = get_int("Amount: ");

        if ( amount < customers[acct_index].balance)
        {
            customers[acct_index].balance -=amount;
            printf("Amount Successfully Withdrawn.\n");
            printf("Balance: %i\n",customers[acct_index].balance);
        }
        else
        {
            printf("Balance: %i\n",customers[acct_index].balance);
            printf("InSufficient Funds.\n");
        }
    }
    else
    {
        printf("Incorrect password.\n");
    }
    return;
}

void transfer(string password,int giver)
{
    int receiver_index, receiver;
    int giver_index =get_customer_index(giver);
             
    if(giver_index ==-7)
    {
        printf("Your Account  is not on the Database.\n");
    }
    else if(strcmp(password,customers[giver_index].password) == 0)
    {
        receiver = get_int("Receivers Account: ");
        receiver_index =get_customer_index(receiver);
        if(receiver_index ==-7)
        {
            printf("Receivers Account is not on the database.\n");
        }
        else
        {
            int amount  = get_int("Enter Transfer Amount: ");

            if(amount < customers[giver_index].balance)
            {
                customers[giver_index].balance-=amount;
                customers[receiver_index].balance+=amount;

                printf("Transfer Successful.\n");
            }
            else
            {
                printf("Insufficient Funds.\n");
            }
        }
    }
    else
    {
        printf("Incorrect Password.\n");
    }
    return;
}

void check_balance(int acct_no,string password)
{
    int index =get_customer_index(acct_no);
    if(index == -7)
    {
        printf("Account is not on database.\n");
    }
    else if(strcmp(customers[index].password,password)==0)
    {
        printf("Your balance is: %i\n",customers[index].balance);
    }
    else
    {
        printf("Wrong password.\n");
    }
}
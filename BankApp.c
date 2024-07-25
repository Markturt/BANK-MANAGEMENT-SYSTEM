#include <stdio.h>
#include <cs50.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int balance;
    string name;
    string acct_No;
    bool acct_deleted;
    string password;
} customer;



customer customers[10000];
int number_of_customers = 0;


//Function Prototypes
void manage_acct(void);
void make_transactions(void);
void check_balance(void);
void create_acct(int customer_index);
string generate_acct_no(void);
void delete_acct(string acct_No,int number_of_customers);
void modify(string password,string acct_no);

int main(void)
{
    int option =22;

    printf("You are Welcome! \n");
    
    while(option != 4)
    {
        printf("Select from the options Below. \n\n");

        printf("1. Manage Account\n");
        printf("2. Handle Transactions\n");
        printf("3. Account Enquiry\n");
        printf("4. Exit\n");

        // scanf("%i",&option);
        option = get_int("Enter option:  ");

        if(option==1)
        {
            manage_acct();   
        }
        else if(option ==2)
        {
            make_transactions();
        }   
        else if(option ==3)
        {
            check_balance();
        }
        else if(option ==4)
        {
            printf("Exit.....\n");
            break;
        }
        else
        {
            printf("\nInvalid Option.\n\n");
            continue;
        }
    }       
}

void manage_acct(void)
{
    printf("1. Create new Account\n");
    printf("2. Delete Existing Account\n");
    printf("3. Modify Account Details.\n");

    int option =get_int("Enter Option: ");
    

    if(option == 1)
    {
        // Create new Account.
        create_acct(number_of_customers);
        number_of_customers++;
    }
    else if(option == 2)
    {
        // Delete  Account.
        string  acc_no= get_string("Enter Account Number to be Deleted: ");
        
        delete_acct(acc_no,number_of_customers);
    }
    else if(option == 3)
    {
        printf("Enter Account Details to be Modified.\n");

        string number = get_string("Account Number:  ");
        string password =get_string("Password: ");

        modify(password,number);
    }
    else
    {
        printf("\nInvalid option...\n\n");
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
    string number =get_string("Account Number: ");
    string password=get_string("Password: ");
    // Performs some sort of Authentication.
}

void create_acct(int customer_index)
{
    string name =get_string("Name: ");
    string password =get_string("Create Password: ");
    string acct_no =generate_acct_no();

    customers[customer_index].name =name;
    customers[customer_index].password =password;
    customers[customer_index].acct_No= acct_no;
    customers[customer_index].acct_deleted=false;
    customers[customer_index].balance =0;

    printf("\nAccount Successfully Created. Handle Your Details Confidentially.\n\n");

    printf("Account Name: %s\n", customers[customer_index].name);
    printf("Account Number: %s\n", customers[customer_index].acct_No);
    printf("Password: %s\n", customers[customer_index].password);
}

string generate_acct_no(void) 
{
    int min = 1000000000;
    long long max = 9999999999;
  
    srand(time(NULL));
    
    // Generate a 10-digit number.
    int num = min + rand() % (max - min + 1);

    static char bufer[20];

    // Convert the number to a string and store it in the provided buffer.
    
    itoa(num,bufer,10);

    return bufer;
}


void delete_acct(string acct_No,int number_of_customers)
{
    for(int i=0;i<number_of_customers;i++)
    {
        if((strcmp(customers[i].acct_No,acct_No) ==0) && (customers[i].acct_deleted==false))
        {
            customers[i].acct_deleted =true;
            printf("Account Successfully Deleted.\n");
            return;
        }
    }
    printf("\nAccount Does not Exist\n\n");
}

void modify(string password, string acct_no)
{
    for(int i=0;i < number_of_customers;i++)
    {
        if((strcmp(customers[i].password,password)==0)  && (strcmp(customers[i].acct_No,acct_no)==0) && (customers[i].acct_deleted==false))
        {
            string new_password;
            int count =0;
            do
            {
                if(count>0)
                {
                    printf("\nEnter a different password.\n\n");
                }
                new_password = get_string("Enter New Password: ");
                
                count++;
            } 
            while (strcmp(customers[i].password,new_password) ==0);
            
            customers[i].name = get_string("Enter new Name: ");;
            customers[i].password = new_password;
            printf("Account Successfully modified.\n");
            return;
        }
    }
    printf("Account Provided Isn't found on the DataBase.\n");
}


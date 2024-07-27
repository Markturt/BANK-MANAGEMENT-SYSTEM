# Banking System Application Documentation

## Introduction

This application is a simple banking system simulation written in C. It allows users to create accounts,manage account details, make transactions, and check balances. The system stores information about customers in a structured way and provides basicc banking operations.

## Table of Contents

1. [System Requirements](#system_requirements)
1. [Data Structures](#data-structures)
1. [Function Descriptions](#function-descriptions)
1. Usage
1. Troubleshooting
1. Contact Information


## System Requirements
- Programming Language: C
- Libraries:
    - `<stdio.h>`
    - `<cs50.h>` (for simplified user input functions)
    - `<time.h>`
    - `<stdlib.h>`
    - `<string.h>`
- Compiler: Any C compiler that supports the C99 standard.

## Data Structures
`customer` Struct

This structure stores customer information:

- `int balance`: The balance of the customer's account.
- `string name`: The customer's name.
- `int acct_No`: The customer's account number.
- `bool acct_deleted`: A flag indicating if the account is deleted.
- `string password`: The password for the account.

## Function Descriptions
### Main Functions
- `int main(void)`
    -This is the entry point of the application. It provides a menu for users to select options to manage accounts, handle transactions, check balances, or exit the application.
### Helper Functions
- `int get_customer_index(int acct_num)`

    -Returns the index of a customer in the `customers` array based on the account number. If the account is not found or is deleted, it returns `-7`.
- `int generate_acct_no(void)`

    - Generates a random account number in the range of 10-digit integers.

### Program Functions

- `void manage_acct(void)`
    - Provides options to create, delete, or modify accounts.
- `void create_acct(void)`
    - Creates a new account with a unique account number, initial balance, name, and password.
- `void delete_acct(int account_number, string passkey)`
    - Deletes an account if the provided account number and password     match.
- `void modify_acct(string passKey, int acct_num)`

    - Allows modification of an account's details (name and password) if the correct password is provided.
- `void make_transactions(void)`

    - Provides options for depositing funds, withdrawing funds, or transferring funds between accounts.
- `void deposit_money(int Acc_No)`
    - Deposits a specified amount of money into an account.

- `void withdraw_money(int Acc_No, string password)`
    - Withdraws a specified amount of money from an account, given the correct password.
- `void transfer(string password, int giver)`
    - Transfers a specified amount of money from one account to another, given the correct password and account details.
- void check_balance(int acct_no, string password)
    - Displays the balance of an account if the correct password is provided.

## Usage

To use the application, compile the code and run the executable. The main menu will prompt you to select from the following options:

1. Manage Account: Create, delete, or modify an account.
1. Handle Transactions: Deposit, withdraw, or transfer funds.
1. Check Balance: View the balance of an account.
1. Exit: Exit the application.

Each option will guide you through the necessary steps, requiring inputs such as account numbers, passwords, and amounts for transactions.

## Troubleshooting
- Invalid Inputs: Ensure that account numbers and passwords are entered correctly. The system will provide feedback if inputs are invalid or if operations cannot be performed.

- Account Not Found: The application will notify you if the account number does not exist or has been deleted.

## Contact Information
For further assistance or inquiries, please contact me via **Twitter** at [Praise Mark](https://x.com/Praise5Mark?t=DIrdFsJUjg52UN0eIHoVEQ&s=08).


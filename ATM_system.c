#include <stdio.h>
void deposit();
void withdraw();
void checkBalance();
void changePin();

static float balance = 100000;
float amt;
static int pin = 1214;
int enterPin;

int main()
{
    int choice;

    printf("Welcome to our ATM!\n");
    printf("Please enter your PIN: ");
    scanf("%d", &enterPin);

    if (enterPin == pin)
    {
        do
        {
            printf("1. Deposit Money\n");
            printf("2. Withdraw money\n");
            printf("3. Change your PIN\n");
            printf("4. Check your account balance\n");
            printf("5. Exit\n");
            printf("..............................\n");
            printf("Please choose your option(1-5): ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                deposit();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                changePin();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                printf("Thank you for working with us! Goodbye\n");
                break;

            default:
                printf("Error! Please enter a valid option (1-5)\n");
                break;
            }

        } while (choice != 5);
    }

    else
    {
        printf("Error! Please enter a valid PIN\n");
    }

    return 0;
}

void deposit()
{
    printf("Please enter the amount you want ot deposit: ");
    scanf("%f", &amt);
    printf("Please enter your PIN to continue: ");
    scanf("%d", &enterPin);

    if (enterPin == pin)
    {
        balance = balance + amt;

        printf("Rs. %.2f successfully deposited in your account\n", amt);
        printf("Your balance is now Rs. %.2f\n", balance);
    }

    else
    {
        printf("Error! Please enter valid PIN to continue\n");
    }
}

void withdraw()
{
    printf("Please enter the amount you want to withdraw: ");
    scanf("%f", &amt);
    printf("Please enter your PIN to continue: ");
    scanf("%d", &enterPin);

    if (enterPin == pin)
    {
        if (amt < balance)
        {
            balance = balance - amt;

            printf("Rs. %.2f successfully withdrawn from your account\n", amt);
            printf("Your balance is now Rs. %.2f\n", balance);
        }

        else
        {
            printf("Error! Your withdrawal amount exceeds balance amount\n");
            printf("Please enter a valid amount for withdrawal\n");
        }
    }
}

void changePin()
{
    int newPin;

    printf("enter your PIN to continue: ");
    scanf("%d", &enterPin);

    if (enterPin == pin)
    {
        printf("Enter your new pin: ");
        scanf("%d", &newPin);
        pin = newPin;
        printf("Your PIN is successfully changed!\n");
    }

    else
    {
        printf("Error! Please enter a valid PIN\n");
    }
}

void checkBalance()
{
    printf("Please enter your PIN to continue: ");
    scanf("%d", &enterPin);

    if (enterPin == pin)
    {
        printf("Your current balance is: %.2f", balance);
    }

    else
    {
        printf("Error! Enter valid PIN\n");
    }
}
	
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
 
char optionAccount, clientNo[10], firstName[10], lastName[10], accounts[30], closingBal[10], openingBal[10], optionclient;
int a, b, c, clientNocount = -1.0, savings, loan, credit, backspace;
int length, intoptionclient; 
int intoptionAccount, transfer1 = 0, transfer2 = 0, closingbals, openingbals, closingbalsfrom, openingbalsfrom;
  
 //Cross checking input with Authentication file to allow the user to enter their acount
bool Authentication() {
    char username[10], password[10], userName[10], pin[10];
 
    printf("Please enter your username-->");
    scanf("%s",username);
    printf("Please enter your password-->");
    scanf("%s",password);
 
    FILE *fp = fopen("Authentication.txt","r");
    if ( fp != NULL) {
        for (int i = 0; i <= 12; i++) {
            int userpos = 0;
            int passpos = 0;
            fscanf(fp,"%s""%s" "%s", &userName[i], &pin[i], &clientNo[i]);
            clientNocount++;
            if ((strcmp(&userName[i],username) == 0) && (strcmp(&pin[i],password) == 0)) {   
                return true;
            }
        }
    } else {
        printf("unable to open file\n");
    }
    printf("You entered either an incorrect Username or PIN --- disconnecting\n");
    return false;
}

//everything to do with the loan account menu
// void Transaction_listing() {
//     char fromAccount[10], toAccount[10], tranType[10], amount[10];
//     fscanf(fp,"%s""%s" "%s" "%s", fromAccount, toAccount, tranType, amount);
//     printf("===================================================\n\n");
//     printf("Account Name - %s %s\n\n", firstName, lastName);
//     printf("Current Balance for Loan Account %d : $%d\n\n", loan, closingbals);
//     printf("===================================================\n\n");
    
    
// }

//everything to do with the savings account menu
void Savings_account() {
    char temp[10];
    int z, y;
    FILE *fp = fopen("Accounts.txt","r");
    while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        if (z == savings) {
            closingbals = y;
        }
    }
    printf("===================================================\n\n");
    printf("Account Name - %s %s\n\n", firstName, lastName);
    printf("Current Balance for Savings Account %d : $%d\n\n", savings, closingbals);
    printf("===================================================\n\n");
    
    
}
//everything to do with the credit card account menu
void Credit_card_account() {
    char temp[10];
    int z, y;
    FILE *fp = fopen("Accounts.txt","r");
     while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        if (z == credit) {
            closingbals = y;
        }
    }
    printf("===================================================\n\n");
    printf("Account Name - %s %s\n\n", firstName, lastName);
    printf("Current Balance for Credit Account %d : $%d\n\n", credit, closingbals);
    printf("===================================================\n\n");
    
    
}
//everything to do with the loan account menu
void Loan_account() {
    char temp[10];
    int z, y;
    FILE *fp = fopen("Accounts.txt","r");
     while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        if (z == loan) {
            closingbals = y;
        }
    }
    printf("===================================================\n\n");
    printf("Account Name - %s %s\n\n", firstName, lastName);
    printf("Current Balance for Loan Account %d : $%d\n\n", loan, closingbals);
    printf("===================================================\n\n");
    
    
}
//everything to do with the credit card account withdraw menu
void Credit_card_account_withdraw() {
 char temp[10];
    int x, z, y,input;
    FILE *fp = fopen("Accounts.txt","r");
    FILE *fp1 = fopen("Accounts.txt","a");
    while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        sscanf(openingBal,"%d",&x);
        if (z == credit) {
            closingbals = y;
            openingbals = x;
        }
    }

    printf("===================================================\n\n");
    printf("Enter the amount to withdraw(E/e to exit) : $");
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            input = atoi(&optionAccount);
            while (input  > (5000 + closingbals) || input < 0) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nInsufficient Funds - Unable to process request - ");
                scanf("%s",&optionAccount);
                input = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    if (optionAccount == 'e' || optionAccount == 'E') {
          
    } else {
    closingbals = closingbals - input;
    fprintf(fp1,"\n%d         ""%d           ""%d",credit, openingbals, closingbals);
    printf("Withdrawal Completed: Closing Balance : $%d\n\n", closingbals);
    }
    printf("===================================================\n\n");
}

//everything to do with the savings account withdraw menu
void Savings_account_withdraw() {
 char temp[10];
    int x, z, y,input;
    FILE *fp = fopen("Accounts.txt","r");
    FILE *fp1 = fopen("Accounts.txt","a");
    while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        sscanf(openingBal,"%d",&x);
        if (z == savings) {
            closingbals = y;
            openingbals = x;
        }
    }

    printf("===================================================\n\n");
    printf("Enter the amount to withdraw(E/e to exit) : $");
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            input = atoi(&optionAccount);
            while ((closingbals - input ) < 0) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nInsufficient Funds - Unable to process request - ");
                scanf("%s",&optionAccount);
                input = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    if (optionAccount == 'e' || optionAccount == 'E') {
          
    } else {
        closingbals = closingbals - input;
    fprintf(fp1,"\n%d         ""%d           ""%d",savings, openingbals, closingbals);
    printf("Withdrawal Completed: Closing Balance : $%d\n\n", closingbals);
    }
    printf("===================================================\n\n");
}

//everything to do with the credit card account deposit menu
void Credit_card_account_deposit() {
 char temp[10];
    int x, z, y,input;
    FILE *fp = fopen("Accounts.txt","r");
    FILE *fp1 = fopen("Accounts.txt","a");
    while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        sscanf(openingBal,"%d",&x);
        if (z == credit) {
            closingbals = y;
            openingbals = x;
        }
    }

    printf("===================================================\n\n");
    printf("Enter the amount to deposit (E/e to exit) : $");
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            input = atoi(&optionAccount);
            while (input > 1000) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nYou cannot deposit more than $1000 per transaction please re-enter - ");
                scanf("%s",&optionAccount);
                input = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    if (optionAccount == 'e' || optionAccount == 'E') {
          
    } else {
        closingbals = closingbals + input;
    fprintf(fp1,"\n%d         ""%d           ""%d",credit, openingbals, closingbals);
    printf("Deposit Completed: Closing Balance : $%d\n\n", closingbals);
    }
    printf("===================================================\n\n");
}

//everything to do with the loan account deposit menu
void Loan_account_deposit() {
 char temp[10];
    int x, z, y,input;
    FILE *fp = fopen("Accounts.txt","r");
    FILE *fp1 = fopen("Accounts.txt","a");
    while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        sscanf(openingBal,"%d",&x);
        if (z == loan) {
            closingbals = y;
            openingbals = x;
        }
    }

    printf("===================================================\n\n");
    printf("Enter the amount to deposit (E/e to exit) : $");
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            input = atoi(&optionAccount);
            while (input > 1000) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nYou cannot deposit more than $1000 per transaction please re-enter - ");
                scanf("%s",&optionAccount);
                input = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    if (optionAccount == 'e' || optionAccount == 'E') {
          
    } else {
        closingbals = closingbals + input;
        fprintf(fp1,"\n%d         ""%d           ""%d",loan, openingbals, closingbals);
        printf("Deposit Completed: Closing Balance : $%d\n\n", closingbals);
    }
    printf("===================================================\n\n");
}

//everything to do with the savings account deposit menu
void Savings_account_deposit() {
 char temp[10];
    int x, z, y,input;
    FILE *fp = fopen("Accounts.txt","r");
    FILE *fp1 = fopen("Accounts.txt","a");
    while(!feof(fp)) {
        fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
        sscanf(temp,"%d",&z);
        sscanf(closingBal,"%d",&y);
        sscanf(openingBal,"%d",&x);
        if (z == savings) {
            closingbals = y;
            openingbals = x;
        }
    }

    printf("===================================================\n\n");
    printf("Enter the amount to deposit (E/e to exit) : $");
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            input = atoi(&optionAccount);
            while (input > 1000) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nYou cannot deposit more than $1000 per transaction please re-enter - ");
                scanf("%s",&optionAccount);
                input = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    if (optionAccount == 'e' || optionAccount == 'E') {
          
    } else {
    closingbals = closingbals + input;
    fprintf(fp1,"\n%d         ""%d           ""%d",savings, openingbals, closingbals);
    printf("Deposit Completed: Closing Balance : $%d\n\n", closingbals);
    }
    printf("===================================================\n\n");
}

void Savings_account_transfer() {

}

void External_account_transfer() {
    int x, y, z, input, value = 0, amount;
    FILE *fp = fopen("Accounts.txt","r");
    FILE *fp1 = fopen("Accounts.txt","a");
    FILE *fp2 = fopen("Transactions.txt","a");

    char temp[10];

    printf("===================================================\n\n");
    printf("Select destination account number (press E/e to exit)- ");
    scanf("%d",&input);
   //determining whether the input is a valid account number
    rewind(fp);
    while(!feof(fp)) {
            fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
            sscanf(temp,"%d",&z);
            sscanf(closingBal,"%d",&y);
            sscanf(openingBal,"%d",&x);
            if (z == input) {  
                closingbalsfrom = y;
                openingbalsfrom = x;
                value = 1;
            }
        }
    while (value != 1 || input == credit || input == savings || input == loan) { //HERE
        printf("\nInvalid desination account number try again E/e to exit) - ");
        scanf("%d",&input);
        rewind(fp);
        while(!feof(fp)) {
            fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
            sscanf(temp,"%d",&z);
            sscanf(closingBal,"%d",&y);
            sscanf(openingBal,"%d",&x);
            if (z == input) {  
                closingbalsfrom = y;
                openingbalsfrom = x;
                value = 1;
            }
        }
    }

    printf("Please enter the amount to be transferred - ");
    scanf("%d",&amount);

    printf("%d\n\n", openingbalsfrom);
    if (transfer1 == 1) {
        while ((closingbalsfrom - amount) < 0) { 
            printf("Insufficient funds - Unable to process request - ");
            // scanf("%d",&amount);
            printf("%d\n\n", amount);
        }
        printf("Deducted $%d From: Account %d - Closing balance - $%d\n", amount,savings,closingbalsfrom - amount);
        printf("Transfer $%d Dest: Account %d\n",amount, input);
        fprintf(fp1,"\n%d         ""%d           ""%d",savings, openingbals, closingbalsfrom - amount);
        fprintf(fp1,"\n%d         ""%d           ""%d",input, openingbalsfrom, closingbalsfrom - amount);
        fprintf(fp2,"\n%d         ""%d           ""4"           "%d",savings,input,amount);
    
    } else if (transfer2 == 1) {
        while (amount  > (5000 + closingbalsfrom) || amount < 0) {
            printf("Insufficient Funds - Unable to process request - ");
            scanf("%d",&amount);
        }
        printf("Deducted $%d From: Account %d - Closing balance - $%d\n", amount,credit,closingbalsfrom - amount);
        printf("Transfer $%d Dest: Account %d\n",amount, input);
        fprintf(fp1,"\n%d         ""%d           ""%d",credit, openingbals, closingbalsfrom - amount);
        fprintf(fp1,"\n%d         ""%d           ""%d",input, openingbalsfrom, closingbalsfrom - amount);
        fprintf(fp2,"\n%d         ""%d           ""4           %d",credit,input,amount);
    }
    


    printf("===================================================\n\n");
    
   
}
//determines which accounts the user owns
void All_accounts_owned() {
    intoptionclient = 0;
    int q;
    const char s[2] = " ,";
    char *token;
    //opening Client details txt and checking which and how many accounts a person has
    FILE *fp1 = fopen("Client_Details.txt","r");
    for (int i = 0; i <=clientNocount; i++) {
        fscanf(fp1,"%s""%s" "%s" "%s", &firstName[i-clientNocount], &lastName[i-clientNocount], &clientNo[i-clientNocount], &accounts[i-clientNocount]);
    }

    token = strtok(accounts,s);

    printf("Select Account Type\n");
    while (token != NULL) {
        sscanf(token,"%d",&q);
        token = strtok(NULL,s);
        if (q % 11 == 0) {
            printf("1. Savings Account\n\n");
            savings = q;
            a = 1;

        } else if (q % 12 == 0) {
            printf("2. Loan Acount\n\n");
            loan =  q;
            b = 1;

        } else if (q % 13 == 0) {
            printf("3. Credit Card\n\n");
            credit = q;
            c = 1;
        }
    }

    printf("Enter your selection (E/e to exit) -");
    
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            intoptionAccount = atoi(&optionAccount);
            while ((intoptionAccount < 1 || intoptionAccount > 3) || (intoptionAccount == 1 && a != 1) || (intoptionAccount == 2 && b != 1) || (intoptionAccount == 3 && c != 1)) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nPlease select a valid choice ->");
                scanf("%s",&optionAccount);
                intoptionAccount = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
}

//determines which accounts the user owns for withdrawal
void All_accounts_owned_withdraw() {
    int q;
    const char s[2] = " ,";
    char *token;
    //opening Client details txt and checking which and how many accounts a person has
    FILE *fp1 = fopen("Client_Details.txt","r");
    for (int i = 0; i <=clientNocount; i++) {
        fscanf(fp1,"%s""%s" "%s" "%s", &firstName[i-clientNocount], &lastName[i-clientNocount], &clientNo[i-clientNocount], &accounts[i-clientNocount]);
    }



    token = strtok(accounts,s);

    printf("Select Account Type\n");
    while (token != NULL) {
        sscanf(token,"%d",&q);
        token = strtok(NULL,s);
        if (q % 11 == 0) {
            printf("1. Savings Account\n\n");
            savings = q;
            a = 1;

        } else if (q % 13 == 0) {
            printf("2. Credit Card\n\n");
            credit = q;
            b = 1;
        }
    }

    printf("Enter your selection (E/e to exit) -");
    
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            intoptionAccount = atoi(&optionAccount);
            while ((intoptionAccount < 1 || intoptionAccount > 2) || (intoptionAccount == 1 && a != 1) || (intoptionAccount == 2 && b != 1)) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nPlease select a valid choice ->");
                scanf("%s",&optionAccount);
                intoptionAccount = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
}

void All_accounts_owned_transfer_from() {
    char temp[10];
    int q, z, y, x;
    const char s[2] = " ,";
    char *token;
    transfer1 = 0, transfer2 = 0;
    //opening Client details txt and checking which and how many accounts a person has
    FILE *fp1 = fopen("Client_Details.txt","r");
    for (int i = 0; i <=clientNocount; i++) {
        fscanf(fp1,"%s""%s" "%s" "%s", &firstName[i-clientNocount], &lastName[i-clientNocount], &clientNo[i-clientNocount], &accounts[i-clientNocount]);
    }

    token = strtok(accounts,s);

    printf("Select Account Type\n");
    while (token != NULL) {
        sscanf(token,"%d",&q);
        token = strtok(NULL,s);
        if (q % 11 == 0) {
            printf("1. Savings Account\n\n");
            savings = q;
            a = 1;

        } else if (q % 13 == 0) {
            printf("2. Credit Card\n\n");
            credit = q;
            b = 1;
        }
    }

    printf("Enter your selection (E/e to exit) -");
    
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            intoptionAccount = atoi(&optionAccount);
            while ((intoptionAccount < 1 || intoptionAccount > 2) || (intoptionAccount == 1 && a != 1) || (intoptionAccount == 2 && b != 1)) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nPlease select a valid choice ->");
                scanf("%s",&optionAccount);
                intoptionAccount = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    if (intoptionAccount == 1) {
        transfer1 = 1;
        FILE *fp = fopen("Accounts.txt","r");
        while(!feof(fp)) {
            fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
            sscanf(temp,"%d",&z);
            sscanf(closingBal,"%d",&y);
            sscanf(openingBal,"%d",&x);
            if (z == savings) {  
                closingbalsfrom = y;
                openingbalsfrom = x;
            }
        }
    } else if (intoptionAccount == 2) {
        transfer2 = 1;
        FILE *fp = fopen("Accounts.txt","r");
        while(!feof(fp)) {
            fscanf(fp,"%s""%s""%s",temp, openingBal, closingBal);
            sscanf(temp,"%d",&z);
            sscanf(closingBal,"%d",&y);
            sscanf(openingBal,"%d",&x);
            if (z == credit) { 
                closingbalsfrom = y;
                openingbalsfrom = x;
            }
        }
    }
}

void All_accounts_owned_transfer_to() {
    int q;
    const char s[2] = " ,";
    char *token;
    //opening Client details txt and checking which and how many accounts a person has
    FILE *fp1 = fopen("Client_Details.txt","r");
    for (int i = 0; i <=clientNocount; i++) {
        fscanf(fp1,"%s""%s" "%s" "%s", &firstName[i-clientNocount], &lastName[i-clientNocount], &clientNo[i-clientNocount], &accounts[i-clientNocount]);
    }

    token = strtok(accounts,s);

   printf("Select Account Type\n");
    while (token != NULL) {
        sscanf(token,"%d",&q);
        token = strtok(NULL,s);
        if (q % 11 == 0) {
            printf("1. Savings Account\n\n");
            savings = q;
            a = 1;

        } else if (q % 12 == 0) {
            printf("2. Loan Acount\n\n");
            loan =  q;
            b = 1;

        } else if (q % 13 == 0) {
            printf("3. Credit Card\n\n");
            credit = q;
            c = 1;
        }
    }

    printf("4. External Account\n\n");

    printf("Enter your selection (E/e to exit) -");
    
    while(1) {
        scanf(" %s",&optionAccount);
        if (optionAccount == 'e' || optionAccount == 'E') {
            break;
        }
        if (isdigit(optionAccount)) {
            intoptionAccount = atoi(&optionAccount);
            while ((intoptionAccount < 1 || intoptionAccount > 4) || (intoptionAccount == 1 && a != 1) || (intoptionAccount == 2 && b != 1) || (intoptionAccount == 3 && c != 1)) {
                if (optionAccount == 'e' || optionAccount == 'E') {
                    break;
                }
                printf("\nPlease select a valid choice ->");
                scanf("%s",&optionAccount);
                intoptionAccount = atoi(&optionAccount);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
}


 
void Client() {
     FILE *fp1 = fopen("Client_Details.txt","r");
 
    if ( fp1 != NULL) {
        for (int i = 0; i <= clientNocount; i++) {
            fscanf(fp1,"%s""%s" "%s" "%s", &firstName[i], &lastName[i], &clientNo[i], &accounts[i]);
        }
    } else {
        printf("unable to open file\n");
    }

    printf("You are currently logged in as %s %s\n",&firstName[clientNocount], &lastName[clientNocount]);
    printf("Client Number - %s\n\n\n",&clientNo[clientNocount]);
    printf("<1> Account Balance\n");
    printf("<2> Withdrawal\n");
    printf("<3> Deposit\n");
    printf("<4> Transfer\n");
    printf("<5> Transaction Listing\n");
    printf("<6> EXIT\n\n");
    printf("Select option 1-6 ->");
    while(1) {
        scanf(" %s",&optionclient);
        if (optionclient == 'e' || optionclient == 'E') {
            break;
        }
        if (isdigit(optionclient)) {
            intoptionclient = atoi(&optionclient);
            while ((intoptionclient < 1 || intoptionclient > 6)) {
                if (optionclient == 'e' || optionclient == 'E') {
                    break;
                }
                printf("\nPlease select a valid choice ->");
                scanf("%s",&optionclient);
                intoptionclient = atoi(&optionclient);
            }
            break;
        }  else {
            printf("\nPlease select a valid choice ->");

        }
    }
    printf("===================================================\n\n");      
}
 
 int main(int argc, char **argv) {
    if(Authentication()) {
        while(1) {
            Client();

            if (intoptionclient == 1) {
                while (1) {
                    if (optionAccount == 'e' || optionAccount == 'E') {
                        break;
                    }
                    All_accounts_owned();
                    if (intoptionAccount == 1 && a == 1) {
                        Savings_account();
                    } else if (intoptionAccount == 2 && b == 1) {
                        Loan_account();
                    } else if (intoptionAccount == 3 && c == 1) {
                        Credit_card_account();
                    }
                }

            } else if (intoptionclient == 2) {
                while (1) { 
                    if (optionAccount == 'e' || optionAccount == 'E') {
                        break;
                    }
                        All_accounts_owned_withdraw();
                    if (intoptionAccount == 1 && a == 1) {
                        Savings_account_withdraw();
                    } else if (intoptionAccount == 2 && b == 1) {
                       Credit_card_account_withdraw();
                    }     
                }
            } else if (intoptionclient == 3) {
                while (1) {
                    if (optionAccount == 'e' || optionAccount == 'E') {
                        break;
                    }
                    All_accounts_owned();
                    if (intoptionAccount == 1 && a == 1) {
                        Savings_account_deposit();
                    } else if (intoptionAccount == 2 && b == 1) {
                        Loan_account_deposit();
                    } else if (intoptionAccount == 3 && c == 1) {
                        Credit_card_account_deposit();
                    }
                }       
            } else if (intoptionclient == 4) {
                while (1) {
                    if (optionAccount == 'e' || optionAccount == 'E') {
                        break;
                    }
                    All_accounts_owned_transfer_from();
                    while (1) {
                        if (optionAccount == 'e' || optionAccount == 'E') {
                        break;
                    }
                        All_accounts_owned_transfer_to();
                        if (intoptionAccount == 1 && a == 1) {
                            Savings_account_transfer();// FIX FIX
                        } else if (intoptionAccount == 2 && b == 1) {
                            
                        } else if (intoptionAccount == 3 && c == 1) {
                            
                        } else if (intoptionAccount == 4) {
                            External_account_transfer();
                        } 
                    }
                }
            } else if (intoptionclient == 5) {
                // Transaction_listing();
            } else if (intoptionclient == 6) {
            }              
        }
    } else {
            exit(0);
    }
    return (0);
}


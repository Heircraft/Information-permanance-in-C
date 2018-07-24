  
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

char clientNo[10];
 
 void client() {
    for (int i = 0; i <= 12; i++) {
        printf("%c",*clientNo[i]);
    }
    
    int option;
    // printf("You are currently logged in as %c %c,");
    // printf("Client Number - %c,");
    printf("<1> Account Balance\n");
    printf("<2> Withdrawal\n");
    printf("<3> Deposit\n");
    printf("<4> Transfer\n");
    printf("<5> Transaction Listing\n");
    printf("<6> EXIT\n\n");
    printf("Select option 1-6 ->");
    while (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6) {
        scanf("%d",&option);
        if (option < 1 || option > 6) {
            printf("please enter a digit between 1-6\n");
        }
    }
    if (option == 1) {
 
    } else if (option == 2) {
             
    } else if (option == 3) {
             
    } else if (option == 4) {
             
    } else if (option == 5) {
             
    } else if (option == 6) {
             
    }
     
}

//Cross checking input with Authentication file to allow the user to enter their acount
bool Authentication() {
    char username[10], password[10], userName[10], pin[10];

    printf("Please enter your username-->");
    scanf("%s",username);
    printf("Please enter your password-->");
    scanf("%s",password);

    FILE *fp = fopen("Authentication.txt","r");

    if ( fp != NULL) {
        for (int i = 0; i < 12; i++) {
            int userpos = 0;
            int passpos = 0;
            fscanf(fp,"%s""%s" "%s", &userName[i], &pin[i], &clientNo[i]);
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
 
 

 
int main(int argc, char **argv) {
    if(Authentication()) {
        client();
    } else {
        exit(0);
    }
    return (0);
}
//for (int i = 0; i < 11; i++) {
    //      printf("%c",line[i]);
    //  }

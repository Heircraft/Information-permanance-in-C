	
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>
 
void Account_balance() {
    int q, w ,e;
    char clientNo[10], firstName[10], lastName[10], accounts[30];
    const char s[2] = ",";
    char *token, *token1, *token2;

    FILE *fp1 = fopen("Client_Details.txt","r");
    for (int i = 0; i <= 10; i++) {
        fscanf(fp1,"%s""%s" "%s" "%s", &firstName[i-10], &lastName[i-10], &clientNo[i-10], &accounts[i-10]);
    }

        token = strtok(accounts,s);
    while (token != NULL) {

    
        // printf("%s",token);
        sscanf(token,"%d",&q);
        printf("%d\n",q);
        token = strtok(NULL,s);

    //     if (q % 11 == 0) {
    //         printf("we did it");
    //     }
    }
   
   

       

        // token = strtok(NULL,s);
    // }
}   
  
  
 
  
int main(int argc, char **argv) {
   Account_balance();
}


#include <stdio.h>
#include <string.h>
#define MAX_ACC 100

typedef struct {
    char name[30];
    int password;
    int balance;
} User;

char name[30];
int pass;

int curr = 0;
User users[MAX_ACC];
int lidx = -1;

int create_acc() {
    printf("Enter The Name Of Account Owner : ");
    scanf("%s", users[curr].name);
    printf("Enter Password : ");
    scanf("%d", &users[curr].password);
    users[curr].balance = 1000;
    printf("\nAccount has been created successfully...\n");
    curr++;
    return 0;
}

int login() {
    char name[30];
    int pass;

    printf("Enter The Name Of The User : ");
    scanf("%s", name);
    printf("Enter The Password Of The User : ");
    scanf("%d", &pass);

    for(int i = 0; i < curr; i++) {
        if(strcmp(name, users[i].name) == 0 && pass == users[i].password) {
            lidx = i;
            printf("\nLogin successfully welcome, %s\n", users[lidx].name);
            return 0;
        }
    }

    printf("\nThe Input Details Are Invalid!!!\n");
    return 1;
}

int cheack_balance() {
    if(lidx == -1) {
        printf("\nYou Need To Login First!\n");
        return 1;
    }
    printf("\nThe Current Amount Is : %d\n", users[lidx].balance);
    return 0;
}

int deposit_money() {
    if(lidx == -1) {
        printf("\nYou Need To Login First!\n");
        return 1;
    }

    int amt;
    printf("Enter The Amount You Want To Deposit : ");
    scanf("%d", &amt);
    users[lidx].balance = users[lidx].balance + amt;
    printf("\nThe Amount Of %d Has Been Credited...\n", amt);
    return 0;
}

int withdraw_money() {
    if(lidx == -1) {
        printf("\nYou Need To Login First!\n");
        return 1;
    }

    int amt;
    printf("Enter The Amount You Want To Withdraw : ");
    scanf("%d", &amt);

    if(amt > users[lidx].balance) {
        printf("\nYou Dont't Have Sufficient Balance To Withdraw That Much Amount!!!\n");
        return -1;
    }

    users[lidx].balance = users[lidx].balance - amt;
    printf("\nYou Have Withdraw The Amount %d Successfully...\n", amt);
    return 0;
}

int logout() {
    lidx = -1;
    printf("\nYou Are Successfully Logged Out Now, Thank You...\n");
    return 0;
}

int main() {
    int choice;
    while(1) {
        printf("\n** BANK MANAGEMENT SYSTEM **\n");
        printf("1. Login\n");
        printf("2. create account\n");
        printf("3. cheack balance\n");
        printf("4. deposit money\n");
        printf("5. withdraw money\n");
        printf("6. Logout\n");
        printf("7. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                login();
                break;
        
            case 2: 
                create_acc();
                break;
        
            case 3:
                cheack_balance();
                break;

            case 4:
                deposit_money();
                break;

            case 5:
                withdraw_money();
                break;

            case 6:
                logout();
                break;

            case 7: 
                printf("\nExiting The Programme.\n");
                return 0;

            default :
                printf("\ninvalid choice\n");
                break;
        }
    }
    
    return 0;
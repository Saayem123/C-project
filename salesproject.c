#include <stdio.h>
#include <string.h>

#define MAX_FLAVORS 10

typedef struct flavor {
    char name[20];
    int stock;
} Flavor;

Flavor flavors[MAX_FLAVORS];
int num_flavors = 0;

int i;

int login(){

    int found=0;
    char username[100],password[100];
    char master_list[3][100]={"A","B","C"};

	printf("Welcome To AI Ice-Cream Parlor\n\n");

    printf("Enter username: ");
    scanf("%s",&username);

    printf("Enter password: ");
    scanf("%s",&password);

    for(i=0;i<3;i++){
        if((strcmp(master_list[i],username)==0) && (strcmp(password,"pass123")==0)){
            found=1;
            break;
        }
    }

    if(found==1){
        printf("\n------------------------------------------\n");
        printf("            || ACCESS GRANTED ||            \n");
        printf("------------------------------------------\n\n");
        printf("Welcome %s\n",username);
    }
    else{
        printf("\nUNAUTHORISED ACCESS. Enter Valid Username or Password\n");
    }

    return found;
}

void add_flavor(char* name, int stock) {
    if (num_flavors == MAX_FLAVORS) {
        printf("\nMaximum number of flavors reached.\n");
        return;
    }
    for (i = 0; i < num_flavors; i++) {
        if (strcmp(flavors[i].name, name) == 0) {
            printf("\n%s flavor already exists.\n",name);
            return;
        }
    }
    Flavor new_flavor;
    strcpy(new_flavor.name, name);
    new_flavor.stock = stock;
    flavors[num_flavors] = new_flavor;
    num_flavors++;
    printf("\n%s flavor added successfully.\n",name);
}

void remove_flavor(char* name) {
	int j;
    for (i = 0; i < num_flavors; i++) {
        if (strcmp(flavors[i].name, name) == 0) {
            for (j = i; j < num_flavors - 1; j++) {
                flavors[j] = flavors[j + 1];
            }
            num_flavors--;
            printf("\n%s flavor removed successfully.\n",name);
            return;
        }
    }
    printf("\n%s flavor not found.\n",name);
}

void print_flavors() {
    printf("\nFlavors available:\n");
    for (i = 0; i < num_flavors; i++) {
        printf("%s - %d\n", flavors[i].name, flavors[i].stock);
    }
}

int main() {

    FILE *flv;

    int found;

    found=login();

    if(found==1){

        int choice, stock;
        char name[20];
        do {
            printf("\nPLEASE SELECT AN OPTION FROM BELOW:- \n");
            printf("\n1. Add flavor");
            printf("\n2. Remove flavor");
            printf("\n3. View available flavors");
            printf("\n4. Exit\n");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Enter flavor name: ");
                    scanf("%s", name);
                    printf("Enter stock: ");
                    scanf("%d", &stock);
                    add_flavor(name, stock);

                    flv=fopen("flavors.txt","a");
                    fputs(name,flv);
                    fprintf(flv,"-%d\n",stock);
                    fclose(flv);

                    break;
                case 2:
                    printf("Enter flavor name: ");
                    scanf("%s", name);
                    remove_flavor(name);

                    break;
                case 3:
                    print_flavors();
                    break;
                case 4:
                    printf("\nExit Successful\n");
                    break;
                default:
                    printf("\nInvalid choice.\n");
                    break;
            }

        }while (choice != 4);
            return 0;
        
    }
    
}
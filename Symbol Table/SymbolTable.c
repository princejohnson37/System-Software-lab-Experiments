#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

int index;
struct SymbolTable{
    char symbol[20];
    char address[20];
    }s[100];

int search(char x[20]){
    bool found =false;
    char symbol[20];
    char address[20];
    int notFound = 404;
    for(int i = 1; i <= index; i++){
            strcpy(address,s[i].address);
            strcpy(symbol,s[i].symbol);

            if(strcmp(x,address) == 0 || strcmp(x,symbol)== 0){
                found = true;
                notFound = i;
                return i;
            }
    }
    if(found == false){
        return notFound;
    }
}

static int max = 100;

void main(){
    int ch,inp,location;
    index=0;
    char temp[20],yon;
    while(1){
        printf("\n");
        printf("1: Insert Symbol and Address\n"
               "2: Modify Symbol or Address\n"
               "3: Search Symbol or Addess\n"
               "4: Display Symbol Table\n"
               "0: Exit\n");
        printf("\nChoose Option: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: //Insert
                if(index == max){
                    printf("\nSymbol Table Full...Exit Program for new Table\n");
                }
                else{
                index++;
                printf("\nEnter Symbol: ");
                scanf("%s",&s[index].symbol);
                printf("\nEnter Address for the Symbol %s :",s[index].symbol);
                scanf("%s",&s[index].address);
                printf("\nSymbol Added...\n");
                }
                break;
            case 2: //Modify
                printf("\nEnter Symbol or Address to modify: ");
                scanf("%s",&temp);
                location = search(temp);
                if(location == 404){
                    printf("\nSymbol or Address not found...\n");
                }
                else{
                printf("\nThe Symbol is %s and Address is %s\n",s[location].symbol,s[location].address);
                printf("\nPress 1 for modifying symbol %s \nPress 2 for modifying Address of %s\n",s[location].symbol,s[location].symbol);
                scanf("%d",&inp);
                if(inp == 1){
                    printf("\nEnter Symbol to replace %s :",s[location].symbol);
                    scanf("%s",&s[location].symbol);
                    printf("\nDo you want to modify the address ? (y/n)\n");
                    scanf("%s",&yon);
                    if(tolower(yon) == 'y' ) {
                        printf("\nEnter address: ");
                        scanf("%s",&s[location].address);
                        printf("\nAddress and Symbol Modified\n");
                    }
                    else if(tolower(yon) == 'n'){
                        printf("\nSymbol Modified...\n");
                    }
                    else{
                        printf("\nWrong Input...Symbol Modified....Address not modified...\n");
                    }
                }
                else if(inp == 2){
                        printf("\nEnter Address: ");
                        scanf("%s",&s[location].address);
                        printf("\nDo you want to modify symbol ? (y/n)\n");
                        scanf("%s",&yon);
                        if(tolower(yon) == 'y'){
                            printf("\nEnter Symbol: ");
                            scanf("%s",&s[location].symbol);
                            printf("\nAddress and Symbol Modified...\n");
                        }
                        else if(tolower(yon) == 'n'){
                            printf("\nAddress modified...Symbol not Modified...\n");
                        }
                        else{
                                printf("\nWrong Input...Address Modified...Symbol not Modified...\n");
                            }
                        }
                else {
                        printf("\nWrong Input... Try again...\n");
                }
                break;
            case 3: //Search
                printf("\nEnter the Symbol or Address to search in the Symbol table : ");
                scanf("%s",&temp);
                location = search(temp);
                if(location == 404 ){
                    printf("\nSymbol or Address not found...\n");
                }
                else{
                    printf("\nSymbol %s | Address %s | found at %d\n",s[location].symbol,s[location].address,location);
                }
            }
                break;

            case 4: //Display
                printf("\n");
                printf("Symbol\tAddress");
                printf("\n");
                for(int i = 1; i<= index; i++){
                    printf("\n%s\t%s",s[i].symbol,s[i].address);
                }
                printf("\n");
                break;
            case 0:
                printf("\nExiting...\n");

                 exit(1);
                break;
           default :
               printf("\nWrong Choice... Try Again or Enter 0 for terminating the program\n");
               main();
                break;
            }
    }
    printf("\nProgram Terminated...");
}




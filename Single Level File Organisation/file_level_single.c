#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct file{
    char file_name[20];
//    char dir[20];
//    int i;
    struct file *lpt;
    //struct file *rpt;
    };
void main(){
    int file_found;
    int ch;
    char nameoffile[20];
    struct file *root,*file_ptr,*file_ptr_previous,*view_ptr,*future,*past;
    root = (struct file*)malloc(sizeof(struct file));
    root->lpt = NULL;
    strcpy(root->file_name, "root");
    //root->dir = {'r','o','o','t','\0'};
    //root->rpt = NULL;
    file_ptr_previous = root;
    while(1){
        printf("\nChoose Option");
        printf("\n1: Create File");
        printf("\n2: Delete File");
        printf("\n3: Display Files");
        printf("\n4: Exit\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            printf("\n---file creation---\n");
            printf("\nEnter File name\n");
            file_ptr = (struct file*)malloc(sizeof(struct file));
            scanf("%s",&file_ptr->file_name);
            if(root->lpt==NULL){
                root->lpt=file_ptr;
                file_ptr_previous = file_ptr;
                file_ptr->lpt = NULL;
            }
            else{
                file_ptr_previous->lpt = file_ptr;
                file_ptr_previous = file_ptr;
                file_ptr->lpt= NULL;
            }
            printf("\nFile Created\n");
            break;
        case 2: //delete files
            printf("\n Enter the File name you want to delete...\n");
            scanf("%s",&nameoffile);
            view_ptr = root;
            file_found = 0;
            while(view_ptr!=NULL){
                if(strcmp(view_ptr->file_name,nameoffile)==0){
                    printf("File found");
                    file_found=1;
                    future = view_ptr->lpt;
                    past->lpt = future;
                    //free(view_ptr); //freeing the deleted node from memory
                    printf("File Deleted");
                    break;
                }
                else{
                    past = view_ptr;
                    view_ptr = view_ptr->lpt;
                }
            }
            if(file_found==0){
                    printf("\n---------------\n");
                printf("File not found");
                printf("\n-------------\n");
            }
            break;
        case 3: //Display files
            printf("\n---The Files in root directory----\n");
            view_ptr=root->lpt;
            while(view_ptr!=NULL){
                printf(view_ptr->file_name);
                printf("\n");
                view_ptr= view_ptr->lpt;
            }
            break;
         case 4: exit(1);
        default : printf("\nWrong Input.. Enter 4 for exiting...\n");
        break;
        }
    }
}

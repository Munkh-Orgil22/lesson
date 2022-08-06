#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h> 
#include<windows.h>
void helps(char a[]){
	printf("Directory:  dir\nCreate :  create file_name.extension\nUgugdul oruulah: insert file_name.extension data\nDelete: remove file_name.extension\nRename : rename filename.extension new_name.extension\n Process vvsgeh: process\n");
}
void processes(char a[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
if (!CreateProcess(NULL, 
"C:\\WINDOWS\\system32\\mspaint.exe", NULL, NULL, FALSE, 0, NULL, NULL,&si,&pi))
	{
	fprintf(stderr, "Create Process Failed");
	}
		WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}

void creating(char a[]) {
    FILE *newfile;
    newfile = fopen(a, "w");
    fclose(newfile);
    printf("file created\n");
}
void removing(char a[]) {
    if(remove(a)) {
        printf("can't remove\n");
    }
    else{
        printf("removed\n");
    }
}

void inserting(char a[], char b[]) {
int i = 0 ;
    FILE *changefile;
    changefile = fopen(a, "w");
    for ( i = 0; b[i]!= '\0'; i++) {
        fputc(b[i], changefile);
    }
    fclose(changefile);
    printf("file saved\n");
}

void renaming(char a[], char b[]) {
    if(rename(a, b)){
        printf("can't rename\n");
    }
    else{
        printf("renamed\n");
    }
}



int main(void) {

    struct direct *dir; 
    char comm[20];
    char name[40];
    char data[200];
    char new_name[40];
    while(1){
        scanf("%s", comm);
        if(strcmp(comm, "dir")==0){
        	
            system("dir");
        }
        else if(strcmp(comm, "create")==0){
            creating(name);
        }
         else if(strcmp(comm, "process")==0){
            processes(name);
        }
        else if(strcmp(comm, "insert")==0){
            scanf("%[^\n]s", data);
            inserting(name, data);
        }
        else if(strcmp(comm, "rename")==0){
            scanf("%s", new_name);
            renaming(name, new_name);
        }
        else if(strcmp(comm, "remove")==0){
            removing(name);
        }
        else if(strcmp(comm, "help")==0){
            helps(name);
        }
        else if(strcmp(comm, "exit")==0){
            return 0;
        }
        else{
            printf("'%s' is not a command\n", comm);
        }
    }
    return 0;
}


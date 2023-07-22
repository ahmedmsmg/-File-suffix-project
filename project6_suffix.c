/*** Name: Ahmed Ghoneim..
 * This program is made to computer a suffix by reading an amount of characaters from each file and to be concatenated together into the suffix.
 * ***/




#include<stdio.h>
#include<string.h>

int M;

void read_file(FILE *file) {
        
       //input array
        char input[20];
	//array that contains the suffix 
	char suf[100] = "";       
	// the length for the suffix
        int c = 0;                      
        
        while(fgets(input, 20, file) != NULL) {
		//an if condition to see if suffix still have room for storager
                if(strlen(input)-1 > M) continue;
             
		//If not enough space then reset suffix
                if(strlen(input)-1 > M-c) {
                        strcpy(suf, "");
                }
		
                strncat(suf, input, strlen(input)-1);
		//update the the length
                c = strlen(suf);
        }
        
        printf("%s", suf);   
        fclose(file);                   
}
int main(int argc , char *argv[]) {

        printf("Enter the value of M = ");
        scanf("%i", &M);
       
        for(int i=1; i<argc; i++) {
                printf("%s : ", argv[i]); 
		// read the file of the given argument      
                read_file(fopen(argv[i], "r"));                 
                printf("\n");
        }
        
        
    return 0;
}

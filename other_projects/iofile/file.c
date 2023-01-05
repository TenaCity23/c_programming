// This code interacts with an existing file and allows the user to read and write to it. It prints the contents of the file to the terminal in the end.

#include <stdio.h> 

int main(void) 
{
    FILE *fp;

    fp = fopen("file.txt", "w+"); //writing mode allows user to write and edit contents of file

    fputs("This is Line 1\n", fp);
    fputs("This is Line 2\n", fp);

    fclose(fp);


    fp = fopen("test2.txt", "r+"); //writing mode allows user to read from file 
    
    char str_ex[20];
    while(fgets(str_ex, sizeof str_ex, fp) != NULL) {
        puts(str_ex);
    }

    fclose(fp);

    return 0;
}

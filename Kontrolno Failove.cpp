#include <stdio.h>
#include <stdlib.h>
void func1(){
    FILE *fp1,*fp2;
    if((fp1 = fopen("file1.txt","r")) == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    if((fp2 = fopen("file2.txt","w")) == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    while(1){
        char c = fgetc(fp1);
        if(feof(fp1)){ 
            break ;
        }
        printf("%c", c);
        if(c>='0' && c<='9'){
            fprintf(fp2,"%c\n",c);
        }
    }
    fclose(fp1);
    fclose(fp2);
}
void func2(){
    
}
void func3(){
    FILE *fp;
    if((fp = fopen("file3.txt","r")) == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    char input[9999];
    int i=0;
    while(1){
        input[i] = fgetc(fp);
        if(feof(fp)){ 
            break;
        }
        if(input[i]=='A' || input[i]=='E' || input[i]=='O' || input[i]=='U' || input[i]=='I'){
               input[i]+=(char)32;
        }
        else if(input[i]=='a' || input[i]=='e' || input[i]=='o' || input[i]=='u' || input[i]=='i'){
            input[i]-=(char)32;
        }
        i++;
    }
    fclose(fp);
    input[i]='\0';
    
    if((fp = fopen("file3.txt","w")) == NULL){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    for(int i=0;input[i]!='\0';i++){
        fputc(input[i],fp);
    }
    fclose(fp);
}
int main()
{
   func1();
    func2();
    func3();
}

 return 0;

//2.1 napishete funkciq koqto prochita sadarjanieto na binaren file sas sledniq format double , int , string , int ... i go otpechatva na ekrana 
// 2.2 Zapishete informaciqta v nov binaren file kato promenite formata po slednia nachin: 
//zapisvate | sled kraq na vseki string i ne zapisvate 
// int- a otgovariashtiat za razmera string 

    /* char ch;

    FILE *fpbr;
    fpbr = fopen("bin1.exe", "rb");

    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening");
    }

    fpbr= fopen("bin2.exe", "rb");
    
    while(1)
    {
        ch = fgetc(fpbr);
        if (ch==EOF)
             break;
         else
             fputc(ch, fpbr);
     }

     fclose(fpbr);
     
*/ 
    

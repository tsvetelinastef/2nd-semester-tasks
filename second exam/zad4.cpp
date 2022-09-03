//zad4
//trqbva da napishesh samo funkciqta ReadInput (bez int main i biblioteki) / t.e. 4-33 red
#include <stdio.h>
void ReadInput(){
	
	int isValid = 1,max=0;
	char word[100];
	
	while(isValid==1){
		char input[100];
		int sum=0;
		gets(input);
		
		//pochti sushtoto kato v zad2 (dobavena e proverka za cifri)
		for(int i=0;input[i]!='\0';i++){
			if( !( (input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') || (input[i]>='0' && input[i]<='9') ) ){ // covered in zad2
				isValid = 0;
				break; 
			}
		}
		
		for(int i=0;input[i]!='\0';i++) sum+=(int)input[i]; //presmqta se koda na dumata
		
		if(max<sum){ // ako segastniqt kod na dumata > max, max priema noviqt kod kato stoinost, a word vzema stoinostta na input
			max=sum;
			int i;
			for(i=0;input[i]!='\0';i++)word[i]=input[i];
			word[i] = '\0'; // kraqt na niza ne se kopira chrez cikula
		}
	}
	printf("\n");
	printf("%s",word);
}
int main()
{
	ReadInput();
	return 0;
}
//example input -> 41-43
/*
IvanPetrov
zzzzzzzzz
.asd
*/

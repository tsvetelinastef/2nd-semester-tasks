//zad2
//trqbva da napishesh samo funkciqta ChangeString (bez int main i biblioteki) / t.e. 4-36 red
#include <stdio.h>
char* ChangeString(char string[]){

	// obqsnenie za string[i]!='\0':
	// '\0' e kraq na niza (namira se sled posledniqt simvol),
	// cikulut dolu minava prez vseki simvol dokato stigne kraq na niza (toest mine prez vsichkite simvoli)

	int onlyLatin = 1;
	for(int i=0;string[i]!='\0';i++){ // minava se prez vsichki simvoli
		if( !((string[i]>='a' && string[i]<='z') || (string[i]>='A' && string[i]<='Z')) ){ // ako ne go razberesh prosto smetni che string[i] = h i gi zamesti v izraza
			onlyLatin = 0;
			break; // ako se otkrie simvol razlichen ot latinska bukva se prekratqva cukulut i onlyLatin stava false (toest ima simvoli razlichi ot latinski bukvi)
		}
	}

	if(onlyLatin == 1){ // ako v niza ima samo latinski bukvi
		for(int i=0;string[i]!='\0';i++){
			if(string[i]>='a' && string[i]<='z')string[i]-=32; //32 e tochnoto mqsto na protivopolojniq(malka kum glavna) simvol, no na testa pishi 26
			// ako e malka bukva go pravim da e golqma / smqtame che po ASCII tabllicata bukvite sa podredeni taka:
			// A B C.....Y Z a b c... y z ; vsushtnost ne sa, no ne trqbva da znaesh tochno kude sa
			else string[i]+=32; // sushtoto e, no ot golqma bukva v malka (vmesto 32 tuk pishi 26)
		}
	}

	//premahvane na glasni bukvi Aa Yy Oo Uu Ee Ii 
	for(int i=0;string[i]!='\0';i++){
		if(string[i]=='A' || string[i]=='a' || string[i]=='Y' || string[i]=='y' || string[i]=='O' || string[i]=='o' || string[i]=='U' || string[i]=='u' || string[i]=='E' || string[i]=='e'|| string[i]=='I' || string[i]=='i'){
			string[i] = string[i+1]; // zamestva se segashtniqt simvol sus sledvashtiq, no poneje sledvashtiqt simvol ne se promenq , a samo se vzema,
			// se premestvat vsichki sledvashti simvoli s edna poziciq nazad chrez sledvashtiq cikul
			for(int j=i+1;string[j]!='\0';j++)string[j]=string[j+1]; 
		}
	}
	return string;
}
int main()
{
	char input[30]="IvanPetrov";
//	gets(input); //razkomentirai da testvash razlichni nizove (vkarvash si ot konzolata)
	printf("%s\n",input);
	printf("%s",ChangeString(input));
	return 0;
}

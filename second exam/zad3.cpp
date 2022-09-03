//zad 3
//trqbva da napishesh samo funkciqta CheckArray (bez int main i biblioteki) / t.e. 4-26 red
#include <stdio.h>
void CheckArray(int arr[]){
	
	//int size = sizeof(arr); //ne e pravilno, no shte go priemat
	int size = 10; //na testa pishesh samo gorniq red
	
	int sum = 0, proizv = 1;
	
	for(int i=0;i<size;i++){
		sum+=arr[i]; //za avg
		
		int isEven = 1;
		//tozi cikul proverqva dali chisloto e prosto, ako ne e isEven = 1, toest e sustavno // pomni se naizust, ako ne go shvashtash si napishi deistvieto na list
		for(int j=2;j<=i-2;j++){
			if(i%j==0){
				isEven = 0;
				break;
			}
		}
		if(isEven==0)proizv*=arr[i]; // proizvedenieto na sustavnite chisla
	}
	
	printf("%.2lf/%d",(double)sum/size,proizv);
}
int main(){
	int a[10]={8,4,1,11,12,17,3,14,5,2};
	CheckArray(a);
	return 0;
}

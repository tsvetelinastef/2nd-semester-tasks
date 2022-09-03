//printirane na prostite chisla ot 1 do 100
#include <stdio.h>
int main(){
	for(int i=1;i<100;i++){
		int flag = 0;
		for(int j=2;j<=i-2;j++)
			if(i%j==0){
				flag = 1;
				break;
			}
		if(!flag)printf("%d ",i);
	}
	return 0;
}

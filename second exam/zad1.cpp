//zad 1
#include <stdio.h>
float w=3.4;
int f(int a,int *b) {a++; (*b)++; w++; return a+*b; };
int main(){
	int x,y,z,arr[]={1,5,7,3}, *p=arr;
	char m[]="successful",*pc;
	y=z=3; x = (y++ !=z); printf("1: %d %d %d\n",x,y,z);
	x=1;y=0;z=4; printf("2: %d %d %d %d\n",x||y&&!z,x,y,z);
	y=5; if(y)x=4;else x=2; printf("3: %d %d\n",x,y);
	y=3;if(z=(y++>5))x=5;else x=3; printf("4: %d %d %d\n",x,y,z);
	x=y=2; while(y++<2)x+=y; printf("5: %d %d\n",x,y);
	for(x=y=2;y<3;x=y++) printf("6: %d %d\n",x,y);
	printf("7: %d %d\n",p[1],*(arr+2));
	x=y=1;z=f(x,&y);printf("8: %d %d %d %4.2f\n",x,y,z,w);
	x=2;y=4;f(x,&y); printf("9: %d %d\n",x,y);
	for(pc=m;*pc;pc++)(*pc)++;
	printf("10: %s %c\n",m+2, *(m+1));
}

//obqsnenieto e nadolu (sled 50ti red) // predlagam purvo da si q reshish bez da gledash


























/*
1:
y=z=3; x = (y++ !=z); printf("1: %d %d %d\n",x,y,z);

y=3
z=3

x = y++ != z     // poneje y++ != z  e uslovie, stoinostta, koqto shte prieme promenlivata x shte e 1 ili 0
x = 3 != 3       // tuk y=4, no poneje ne e ++y, povreme na operaciqta (x=3!=3) y=3, a posle stava 4                 => y=4
x = 0 // false

x=0
y=4
z=3

1: 0 4 3
--------------------------------------
2:
x=1;y=0;z=4; printf("2: %d %d %d %d\n",x||y&&!z,x,y,z);

x=1
y=0
z=4

x || y && !z =      1 || 0 && !4    // !4 stava 0 (!4 = 0 (vsichko, koeto ne e 0 se priema za 1, toest 4 = 1 .... !1 = 0)  (i obratno !0 = 1);  
x || y && !z =      1 || 0 && 0     // purvo se izvurshva && (tova e logichesko umnojenie), 0 && 0 = 0
x || y && !z =      1 || 0
x || y && !z =      1

2: 1 1 0 4
--------------------------------------
3:
y=5; if(y)x=4;else x=2; printf("3: %d %d\n",x,y);

y = 5

if(5) //ako ne e 0, znachi e true, toest if se izpulnqva, a ne else  // pri if(0) se izpulnqva else
ima i zadachi kato if(a=3)b=1;else b=2;, tuk v if se izpulnqva deistvieto a=3, posle v if ostava samo novata stoinost na a, toest vse edno imame if(3), b=1  
=> x = 4

3: 4 5
--------------------------------------
4:
y=3;if(z=(y++>5))x=5;else x=3; printf("4: %d %d %d\n",x,y,z);

y=3
if(z=(y++>5))
=> if(z=(3>5) //tuk y stava 4, no pishem 3, poneje ne e ++y            => y=4
=> if(z=0) //                                                          => z=0
=> if(0) 

toest se izpulnqva else
=> x=3

x=3
y=4
z=0

4: 3 4 0
--------------------------------------
5:
x=y=2; while(y++<2)x+=y; printf("5: %d %d\n",x,y);

x=2
y=2

while(y++<2) 
=> while(2<2)          // y=3
=> while(0)

toest cikulut ne se izpulnqva (operaciqta x+=y; ne se izpulnqva)

x=2
y=3

5: 2 3
--------------------------------------
6:
for(x=y=2;y<3;x=y++) printf("6: %d %d\n",x,y);

kak raboti for:
1)inicializaciq (v sluchaq x=y=2, koeto oznachava x=2;y=2;), izpulnqva se pri purvoto izpulnenie na cikula
2)proverka na uslovie (v sluchaq y<3)
3)ako uslovieto e true se izpulnqva/t operatora/operatorite sled for() (v sluchaq printf)
4)inkrementaciq/dekrementaciq/aktualizaciq, kakvoto ime mu dadete (v sluchaq x=y++) / ako uslovieto e false, ne se izpulnqva /



1vo izpulnenie na cikula:

1) inicializaciq na cikula (izpulnqva se vednuj):
   x=2
   y=2

2) proverka na uslovie
   2<3 => true
3) izpulnqvane na operacii
   => printf("6: %d %d\n",x,y); se izpulnqva za pruv put
   toest se izvejda:
   6: 2 2
4) aktualizaciq
   x=y++;
   x=2
   y=3
----------------
2ro izpulnenie na cikula:

2)3<3 => false
3) ne se izpulnqva printf
4) ne se izpulnqva aktualizaciq

rezultat ot tozi red:
for(x=y=2;y<3;x=y++) printf("6: %d %d\n",x,y);
------------
x=2
y=3

izvejdane:
6: 2 2
--------------------------------------
7:
printf("7: %d %d\n",p[1],*(arr+2));

arr[]={1,5,7,3}
*p=arr


p[1] oznachava arr[1] => 5         //p[0] = 1, p[1] = 5, p[2] = 7, p[3] = 3;
*(arr+2) oznachava arr[2] => 7



bonus:
	ako beshe *p = arr+1 ukazatelqt zapochva ot 2riqt element na masiva, toest ot 5
	i taka zadachata se promenq
	primer:
	*p = arr+1;
	p[1] oznachava 1 element sled ukazatelq, toest arr+2 => 7

	*(arr+2) e nachinut, po koito kompilatorut vijda arr[2], toest nie pishem arr[2], no toi vijda *(arr+2)
	
bonus 2: pri dvumeren masiv e malko po razlichno => a[i][j] = *(*(a+i)+j), trimeren => a[i][j][k] = *(*(*(a+i)+j)+k)
	
7: 5 7
--------------------------------------
8:
x=y=1;z=f(x,&y);printf("8: %d %d %d %4.2f\n",x,y,z,w);
int f(int a,int *b) {a++; (*b)++; w++; return a+*b; };


x=1
y=1 (&y = FF00)
float w=3.4

f(x,&y) => int f(int a,int *b)// a = x, tova e prisvoqvane na stoinost | *b = &a, tova e prisvoqvane na adres
tova oznachava, che sled izlizane ot funkciqta x nqma da e promenen, a y shte bude, poneje promenqme stoinostta na y chrez ukazatel
	
izpulnenie na funkciq:
	a=x => a=1
	*b=&y => *b=2                 (b=FF00,*b=2,&b=FFAA)               FF00 e adresut na y, FFAA e adresut na b (ne sa tochni, a primerni adresi)
	
	a++ => a=2 (x=1, ne se promenq)
	(*b)++ => *b=2 (y=2)
	w++ => w=4.4
	
	return a+*b oznachava => 2+2 => 4
	toest z=4, poneje z=f(x,&y)              (stoinostta, koqto se vrushta)
	
kraini stoinosti:
x=1
y=2
z=4
w=4.4

zabelejka:
	imame %4.2f
	po default %f shteshe da izpishe w kato 4.400000     => 6 simvola sled desetichnata zapetaq
	%.2f shte izpishe w kato 4.40 => 2 simvola sled desetichnata zapetaq
	a tazi 4-ka za kakvo e?
	tq okazva kolko simvola da se izpishat za tazi promenliva, kakvo znachi tova:
		%15f shte da izpishe  -------4.400000, kudeto - sa space-ove (prazni mesta)
		%2f shte izpishe 4.400000, toest ako chisloto (2) e po malko ot broqt simvolite na chisloto (4.400000), ne se dobavqt prazni mesta, no ne se i mahat simvoli
		pri kombinirane se poluchava:
			%10.2f => izpisvane na 10 simvola, kato broqt na cifrite sled desetichnata zapetaq e 2 
				=> ------4.40           // desetichnata zapetaq se broi za simvol, zatova ima 6 prazni mesta (-),a ne 7
			%4.2f => 4.40 (izpisani sa 4 simvola, 2 sled desetichnata zapetaq)
			%5.2f => -4.40 (izpisani sa 5 simvola, 2 sled desetichnata zapetaq)
	

8: 1 2 4 4.40
--------------------------------------
9:
podobna e na predishnata (8)

x=2;y=4;f(x,&y); printf("9: %d %d\n",x,y);
int f(int a,int *b) {a++; (*b)++; w++; return a+*b; };

x=2
y=4
w=4.4 /ot predishnata zadacha/

f(x,&y) => int f(int a,int *b)

a=x => a=2
*b=&y => *b=4

a++ => a=3 (x si ostava 2)
(*b)++ => *b=5 (y=5)
w++ => w=5.4


9: 2 5
--------------------------------------
10:
char m[]="successful",*pc;
for(pc=m;*pc;pc++)(*pc)++;
printf("10: %s %c\n",m+2, *(m+1));

m[]="successful"
*pc

obqsnenie na cikula:
	inicializaciq: pc=m    => pc vzema adresa na m, toest pc[0]==m[0]
	uslovie: *pc
			primer: imame if(5), tova oznachava true (vsicho razlichno ot 0 e true), if(0) oznachava false
		*pc ima za stoinost simvol, naprimer s, posle u, posle c i taka... tezi stoinosti v ASCII tablicata sa naprimer 80,83 i taka. Ideqta e che ne sa 0
		toest dokato *pc e razlichno ot 0, cikulut se povtarq. *pc ima stoinost 0, kogato stigne kraqt na niza ('\0), toest togava cikulut spira da se izpulnqva
			primer: if(*pc) => if(83) => true
		samo che v for nqmame if, a napravo se pishe uslovieto
	operator: (*pc)++ 
		pri vsqko izpulnenie na cikula (tozi cikul minava prez vsichkite simvoli edin po edin), stoinostta na ukazatela (*pc) se uvelichava s 1
		tova oznachava che s stava t, u=v, c=d, (a stava b,c stava d)
		v kraqt na cukulut niza successful se prevrushta v tvddfttgvm
			primer:
			*pc (m[0]) = s
			*pc++ => t
			
			sled inkrementaciq(aktualizaciq) (pc++)
			*pc (m[1]) = u
			*pc++ => v
		=>m[] = "tvddfttgvm"

obasnenie na printf:
	%s izvejda cql niz
	%c izvejda edin edinstven simvol
	
	m+2 oznachava, che shte zapochne izvejdaneto na niza 2 simvola sled nachaloto => ot successful stava ccessful
	obache cikulut promeni stoinostta na niza, toi veche e tvddfttgvm
	
	toest m+2 izvejda ddfttgvm
	--------
	*(m+1) oznachava m[1] => v (m[]= "tvddfttgvm")



10: ddfttgvm v








Kakvo trqbva da se napishe na kontrolnoto:
-------------
1:
	x=y++!=z // y=4
	x=3!=3
	x=0 
	
	1: 0 4 3
	
2:
	x||y&&!z = 1||0&&!4 = 1||0&&0 = 1||0 = 1

	2: 1 1 0 4
	
3:
	if(5) //true
	=> x = 4
	
	3: 4 5
	
4:
	if(z=(3>5) // y=4
	if(z=0) //  false
	=> x=3
	
	4: 3 4 0
	
5:	
	while(2<2) // y=3
	=> while(0)
	=> operaciqta x+=y ne se izpulnqva
	
	5: 2 3
6:
	1vo izpulnenie na cikula:
	   2<3 => true
	   => 6: 2 2
	   x=y++; 
	   x=2
	   y=3
	----------------
	2ro izpulnenie na cikula:
		3<3 => false
		ne se izpulnqva printf
		ne se izpulnqva aktualizaciq
	
	6: 2 2
7:
	p[1] = arr[1] = 5
	*(arr+2) = arr[2] = 7
	
	7: 5 7
8:
	a++ => a=2 (x=1, ne se promenq)
	(*b)++ => *b=2 (y=2)
	w++ => w=4.4
	return a+*b => 2+2 => 4
	=> z=4
		
	8: 1 2 4 4.40
9:	
	a++ => a=3 (x=2)
	(*b)++ => *b=5 (y=5)
	w++ => w=5.4
	
	9: 2 5
10:	
	cikulut minava prez vsichkite simvoli na niza, kato pravi vsichkite simvoli s edin po-golqm
		
	inicializaciq: pc=m
	uslovie: *pc => if(*pc) <=> if('s') <=> if(82) => true, toest pri simvoli != (int)0 cikulut se izpulnqva
	=>m[] = "tvddfttgvm"

	m+2 oznachava, che shte se nizut shte zapochne da se izvejda 2 simvola sled nachaloto => izvejda ddfttgvm
	*(m+1) oznachava m[1] => v
	
	10: ddfttgvm v

*/

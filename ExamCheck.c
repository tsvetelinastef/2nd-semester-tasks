#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IN 1
#define OUT 0
#define MALE 0
#define FEMALE 1
#define STEP 2

typedef struct Person
{
    int age;
    char name[16];
    int gender;
}sPerson;

typedef struct time
{
    int hour;
    int minute;
    int second;
}sTime;

void zad1(void);
void zad2(void);
void zad3(void);
void zad4(void);
void zad5(void);
void zad6(void);

int main()
{
    zad6();

    return 0;
}

//Напишете програма, която брои изреченията в текстов файл
void zad1(void)
{
    FILE * pfile;
    pfile = fopen("test.txt", "r");
    int state = IN;
    int counter = 0;
    int c;

    if(NULL == pfile)
    {
        printf("Error: Opening file");
        exit(1);
    }

    while(EOF != (c = fgetc(pfile)))
    {
        switch(state)
        {
        case IN:
            if((c == '.') || (c == '!') || (c == '?'))
            {
                counter++;
                state = OUT;
            }
            break;
        case OUT:
            if((c != '.') && (c != '!') && (c != '?'))
            {
                state = IN;
            }
            break;
        default:
            printf("Error: This should not be printed!\n");
            break;
        }
    }

    fclose(pfile);

    printf("Count sentances: %d", counter);
}

//Напишете програма, която създава бинарен файл с информация за хора, въведена от потребителя
void zad2(void)
{
    int count;
    int i;
    sPerson temp;
    FILE * pfile = fopen("testbin.bin", "wb");
    if(NULL == pfile)
    {
        perror("Error");
        exit(1);
    }
    printf("How many people: ");
    scanf("%d", &count);

    for(i = 0; i < count; i++)
    {
        printf("Age: ");
        scanf("%d", &temp.age);

        printf("Name: ");
        scanf("%s", temp.name);

        printf("Gender: ");
        scanf("%d", &temp.gender);

        if(fwrite(&temp.age, sizeof(temp.age), 1, pfile) != 1)
        {
            perror("Error");
            exit(2);
        }
        if(fwrite(temp.name, sizeof(temp.name), 1, pfile) != 1)
        {
            perror("Error");
            exit(2);
        }
        if(fwrite(&temp.gender, sizeof(temp.gender), 1, pfile) != 1)
        {
            perror("Error");
            exit(2);
        }
        /*if(fwrite(&temp, sizeof(temp), 1, pfile) != 1)
        {
            perror("Error");
            exit(2);
        }*/
    }
    fclose(pfile);
}

//Напишете програма, която създава динамичен масив с информация от бинарен файл
void zad3(void)
{
    sPerson temp;
    FILE * pfile = fopen("testbin.bin", "rb");
    sPerson * pdarr = NULL;
    sPerson * preallocHelper = NULL;
    int dsize = 1;
    int i;

    if(NULL == pfile)
    {
        perror("Error");
        exit(1);
    }
    while(1)
    {
        if(fread(&temp.age, sizeof(temp.age), 1, pfile) != 1)
        {
            break;
        }
        if(fread(temp.name, sizeof(temp.name[0]), 16, pfile) != 16)
        {
            perror("Error");
            exit(2);
        }
        if(fread(&temp.gender, sizeof(temp.gender), 1, pfile) != 1)
        {
            perror("Error");
            exit(2);
        }
        /*if(fread(&temp, sizeof(temp), 1, pfile) != 1)
        {
            perror("Error");
            exit(2);
        }*/
        preallocHelper = pdarr;
        pdarr = (sPerson *)realloc(pdarr, sizeof(temp)*dsize);
        if(NULL == pdarr)
        {
            perror("Error");
            free(preallocHelper);
            exit(3);
        }
        pdarr[dsize-1] = temp;
        dsize++;
    }

    for(i = 0; i < dsize-1; i++)
    {
        printf("Name: %s\nAge: %d\nGender: %c\n", pdarr[i].name, pdarr[i].age, (pdarr[i].gender == 0)?'M':'F');
    }
    free(pdarr);
    fclose(pfile);
}
//Напишете програма, която брои думи в текстов файл
void zad4(void)
{
    FILE * pfile;
    int c;
    int state = OUT;
    int counter = 0;

    pfile = fopen("test.txt", "r");
    if(NULL == pfile)
    {
        perror("Error");
        exit(1);
    }

    while(EOF != (c = fgetc(pfile)))
    {
        switch(state)
        {
        case OUT:
            if(0 != isalnum(c))
            {
                state = IN;
                counter++;
            }
            break;
        case IN:
            if(0 == isalnum(c))
            {
                state = OUT;
            }
            break;
        default:
            printf("Should not be here!\n");
            break;
        }
    }

    printf("Words count: %d", counter);
    fclose(pfile);
}

//Напишете програма, която създава бинарен файл с информация за време, въведена от потребителя
void zad5(void)
{
    FILE * pfile;
    sTime temp;
    int count;
    int i;
    char symbol = ':';

    pfile = fopen("testbin2.bin", "wb");
    if(NULL == pfile)
    {
        perror("Error1");
        exit(1);
    }
    printf("Number of inputs: ");
    scanf("%d", &count);

    for(i = 0; i < count; i++)
    {
        printf("Enter time: ");
        scanf("%d %d %d", &temp.hour, &temp.minute, &temp.second);
        if(fwrite(&temp.hour, sizeof(temp.hour), 1, pfile) != 1)
        {
            perror("Error2");
            exit(2);
        }
        if(fwrite(&symbol, sizeof(symbol), 1, pfile) != 1)
        {
            perror("Error3");
            exit(2);
        }
        if(fwrite(&temp.minute, sizeof(temp.minute), 1, pfile) != 1)
        {
            perror("Error4");
            exit(2);
        }
        if(fwrite(&symbol, sizeof(symbol), 1, pfile) != 1)
        {
            perror("Error5");
            exit(2);
        }
        if(fwrite(&temp.second, sizeof(temp.second), 1, pfile) != 1)
        {
            perror("Error6");
            exit(2);
        }
    }

    fclose(pfile);
}

void zad6(void)
{
    FILE * pfile;
    sTime temp;
    char symbol;
    sTime * pdarr = malloc(sizeof(sTime)*STEP);
    sTime * preallocHelper = NULL;
    int dsize = STEP;
    int dcount = 0;
    int i;

    pfile = fopen("testbin2.bin", "rb");
    if(NULL == pfile)
    {
        perror("Error1");
    }
    if(NULL == pdarr)
    {
        perror("Error2");
        exit(3);
    }

    while(1)
    {
        if(fread(&temp.hour, sizeof(temp.hour), 1, pfile) != 1)
        {
            break;
        }
        if(fread(&symbol, sizeof(symbol), 1, pfile) != 1)
        {
            perror("Error3");
            exit(2);
        }
        if(fread(&temp.minute, sizeof(temp.minute), 1, pfile) != 1)
        {
            perror("Error4");
            exit(2);
        }
        if(fread(&symbol, sizeof(symbol), 1, pfile) != 1)
        {
            perror("Error5");
            exit(2);
        }
        if(fread(&temp.second, sizeof(temp.second), 1, pfile) != 1)
        {
            perror("Error6");
            exit(2);
        }

        if(dcount < dsize)
        {
            pdarr[dcount] = temp;
            dcount++;
        }
        else
        {
            //add memmory
            preallocHelper = pdarr;
            dsize += STEP;
            pdarr = (sTime *)realloc(pdarr, sizeof(sTime)*dsize);
            if(NULL == pdarr)
            {
                free(preallocHelper);
                perror("Error7");
                exit(3);
            }
            //add new element
            pdarr[dcount] = temp;
            dcount++;
        }
    }

    for(i = 0; i < dcount; i++)
    {
        printf("Time: %2d:%2d:%2d\n", pdarr[i].hour, pdarr[i].minute, pdarr[i].second);
    }

    fclose(pfile);
    free(pdarr);
}

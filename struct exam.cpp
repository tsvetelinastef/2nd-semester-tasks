 //write function that finds if one point is in the Rectangle . It returns 1 or 0
  //Demonstrate function q using rectangle and one point from ex 3

#include <stdio.h>
typedef struct Point{
    int x;
    int y;
}point_t;

typedef struct Rectangle{
    Point pt1;
    Point pt2;
}rect_t;

void pointInput(point_t *ptr){
    printf("x = ");
    scanf("%d",&ptr->x);
    printf("y = ");
    scanf("%d",&ptr->y);
    printf("\n");
}

void rectInput(rect_t *ptr){
    printf("Rectangle input:\n");
    printf("Rect Point 1:\n");
    pointInput(&ptr->pt1);
    printf("Rect Point 2:\n");
    pointInput(&ptr->pt2);
    printf("\n");
}

int pointMin(point_t *ptr){
    int min = ptr->x;
    int index;
    int count = 0;
    for(int i=0;i<10;i++)
        if(((ptr+i)->y)<0 && ((ptr+i)->x)<min){
            min = (ptr+i)->x;
            index = i;
            count++;
        }
    if(count!=0)return index;
    else return -1;
}

int main(){
    point_t ptArr[10];
    rect_t rect1;
    
    for(int i=0;i<3;i++){
        printf("Point %d:\n",i+1);
        pointInput(ptArr+i);
    }
    
    rectInput(&rect1);
    
    printf("Nai-lqvata tochka e:\tptArr[%d] = %d",pointMin(ptArr),ptArr[pointMin(ptArr)]);
    
    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include <math.h>

//для задания 2
typedef struct Rectangle
{
    int width;
    int height;
    int perimeter;
    int space;
} Rectangle;

void calcParams(Rectangle* inRectangle, int w, int h)
{
    inRectangle->width = w;
    inRectangle->height = h;
    inRectangle->perimeter = 2*(h+w);
    inRectangle->space = w*h;
    printf("Test width: %d\n",inRectangle->width);
    printf("Test height: %d\n",inRectangle->height);
    printf("Test perimeter: %d\n",inRectangle->perimeter);
    printf("Test space: %d\n",inRectangle->space);
}

//для задания 3
//точка
typedef struct Point
{
    int xVal;
    int yVal;
} Point;

//линия
typedef struct Line
{
    struct Point Point1;
    struct Point Point2;
    float length;
} Line;

//рассчитываем линию
Line calcLine(Point* X1, Point* X2)
{
    Line Y;
    Y.Point1 = *X1;
    Y.Point2 = *X2;
    Y.length = sqrt(pow(Y.Point2.xVal - Y.Point1.xVal,2)+pow(Y.Point2.yVal - Y.Point1.yVal,2));
    return Y;
};

//для задания 4
int* makeArray(int row_count, int column_count)
{
    //Инициализируем нулями
    int* inArray = calloc((row_count * column_count), sizeof(int*));
    //для проверки выводим нули
    printf("In the Function. The matrix elements initialized are:\n");
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < column_count; j++)
        {
            printf("%d ", *(inArray + i*column_count +j));
        }
        printf("\n");
    }

    //заполняем данные чем-нибудь и выводим для проверки
    printf("In the Function. The matrix elements changed are:\n");
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < column_count; j++)
        {
            *(inArray + i*column_count +j) = i +j;
            printf("%d ", *(inArray + i*column_count +j));
        }
        printf("\n");
    }
    return (inArray);
}

int main()
{
    //задание 1
    int a[10];
    int n;
    int i;
    printf("Enter your integer less then 2^10:\n");
    scanf("%d",&n);
    for(i=0;n>0;i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    printf("Binary is: ");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");

    //задание 2
    Rectangle* r1 = (Rectangle*) malloc (sizeof (Rectangle));
    calcParams(r1, 3, 4);

    //задание 3
    Line Y;
    Point X1;
    Point X2;

    X1.xVal = 3;
    X1.yVal = 1;
    X2.xVal = 7;
    X2.yVal = 2;

    Y=calcLine(&X1, &X2);

    printf("Line length: %f\n", Y.length);

    //задача 4
    int r = 3;
    int c = 4;

    int* arr1;
    arr1 = makeArray(r, c);

    printf("In the Main. The matrix elements changed are:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(arr1 + i*c +j) = i +j;
            printf("%d ", *(arr1 + i*c +j));
        }
        printf("\n");
    }

    return 0;
}
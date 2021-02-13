#include <stdio.h>
#include <math.h>

//для задания 1, функция вычисления корней
int calcSquareEq(int a, int b, int c, double* x1, double* x2)
{
    double Discriminant;
    Discriminant = pow(b, 2) - 4 * a * c;
    if (Discriminant > 0)
    {
        *x1 = (double)(-b + sqrt(Discriminant)) / (2 * a);
        *x2 = (double)(-b - sqrt(Discriminant)) / (2 * a);
        return 1;
    }
    else if (Discriminant == 0)
    {
        *x1 = (double)-b/(2*a);
        *x2 = *x1;
        return 0;
    }
    //исходя из формулировки задания предполагаем, что нам не надо заморачиваться с мнимыми числами
    else
    {
        return -1;
    }
}

//для задания 2, функция манипуляций с массивом
int arrayMagic(int* sampleArray, int* trigger, int* arraySize)
{
    *trigger = 0;
    for (int i = 0; i < *arraySize; i++)
    {
        if (sampleArray[i]%2>0)
        {
            sampleArray[i] = sampleArray[i] *2;
            if (*trigger == 0)
            {
                *trigger = *trigger + 1;
            }
            else
            {
                *trigger = *trigger;
            }
        }
        else
        {
            *trigger = *trigger;
        }
        //для понимания, что происходит внутри, выводим значения
        //printf("Values inside function: %d\n",sampleArray[i]);
    }
    return *trigger;
}

//для задания 3, функция преобразователь
//Это моё решение
void asShortPrintMain(unsigned* a, int len)
{
    for(int i=0; i < len; i++)
    {
        //Сдвигаем количество разрядов на 16. %hu - вывод в формате unsigned int
        printf("Main Input: %hu, Output: %hu\n", a[i], (a[i] >> 16));
    }
}

//факультативное решение. Полезно для разбора, но, на мой взгляд, слишком тяжело читается
//подсмотрено здесь:
//https://www.cyberforum.ru/c-beginners/thread2587936.html

void asShortPrintAdditional(unsigned* a, int len)
{
    unsigned* it;
    //тут работаем прямо с адресами
    for (it = a; it != a + len; ++it)
    {
        printf("Additional Input: %hu, Output: %hu\n", *it, *it >> 16);
    }
}

int main() {
    //задание 1
    int res;
    double x1;
    double x2;
    res = calcSquareEq(1, 4, 4, &x1, &x2);
    printf("Function result: %d\n",res);
    switch(res)
    {
        case -1:
            printf("No roots");
            break;
        case 0 :
            printf("One root: %f\n",x1);
            break;
        case 1 :
            printf("Two roots: %f, %f\n",x1, x2);
            break;
        default:
            printf("Something went wrong\n");
            break;
    }

    //задание 2
    int trigger;
    int sampleArray [5] = {6, 2, 3, 4, 5};
    //интереса ради решил посмотреть, как получить размер массива
    int arraySize = sizeof(sampleArray)/sizeof(sampleArray[0]);
    //передавать столько указателей, возможно, избыточно, но хотелось попрактироваться
    //!Так как массивы передаются автоматически как указатели, то нет необходимости ставить символ & перед sampleArray
    res = arrayMagic(sampleArray, &trigger, &arraySize);

    switch(res)
    {
        case 0 :
            printf("No changes\n");
            break;
        case 1 :
            for (int i = 0; i < arraySize; i++)
            {
                printf("Values changed to: %d\n",sampleArray[i]);
            }
            break;
        default:
            printf("Something went wrong\n");
            break;
    }

    //задание 3
    //тут надо иметь в виду, что максимальное значение unsigned int составляет 65535,
    //то есть последние 5 чисел по идее обрежутся и будут оторажены за минусом максимума + 1 (так как счёт начинается с 0)
    unsigned int inputArray[10] = {0, 1, 2, 3, 4, 65541, 65542, 65543, 65544, 65545};
    //unsigned short outputArray[10];
    asShortPrintMain(inputArray, 10);
    asShortPrintAdditional(inputArray, 10);

    return 0;
}

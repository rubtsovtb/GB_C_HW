#include <stdio.h>

//Задание 2
/*
 * Задание 2
 * Проект: Задания по первому уроку круса языка C
 * Автор: Рубцов Т. Б.
 * e-mail: roubtsov89@gmil.com
 * Среда разработки: CLion (Уж очень понравился ранее PyCharm. решил начать с уже проверенного бренда).
 * Попозже попробую ещё QTCreator
 * Проект выполнен в C11
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * В ходе выполнения задания не понял. как вывести в коносоль CLion текст printf на русском. setlocale(0,"Russian"); не сработал
 * Если вас не затруднит. поделитесь секретом. можно ли это как-то сделать.
 */

//Задание 1
int main() {
    printf("Hello, World!\n");

    //Задание 3
    int x;
    printf("Type Integer to square it:\n"); // выводим сообщение
    scanf("%i", &x); // вводим значения переменной x
    printf("Squared value=%i\n", (x*x)); // выводим значение переменной x в квадрате

    //Задание 4
    float Uout;
    float Uin;
    float R1;
    float R2;

    Uin = 220;
    R1 = 50;
    R2 = 100;
    Uout = Uin*(R1/(R1+R2));
    Uin = Uout/(R1/(R1+R2));
    R1 = Uout*R2/(Uin-Uout);
    R2 = R1*(Uin-Uout)/Uout;

    printf("Uout value=%f\n", Uout); // выводим по Uout
    printf("Uin value=%f\n", Uin); // выводим по Uin
    printf("R1 value=%f\n", R1); // выводим по R1
    printf("R2 value=%f\n", R2); // выводим по R2

    return 0;
}
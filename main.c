#include <stdio.h>
#include <stdlib.h> // для abs()

int main() {

    // задание 1
    int x;
    int trigger = 0;
    printf("Type your integer:\n");
    scanf("%i", &x);
    for (int y = 0; y <= 100; y += 1){
        trigger += ((x == y) ? 1 : 0);
    }
    if (trigger > 0){
        printf("Figure in {0:100} range\n");
    }
    else{
        printf("Figure not in {0:100} range\n");
    }

    // задание 2
    int x1;
    int trigger1 = 21;
    int result1;
    printf("Type your integer:\n");
    scanf("%i", &x1);
    result1 = ((x1 <= trigger1) ? abs(x1 - trigger1) : 2*(x1 - trigger1)); // для перестраховки сделал разницу по модулю
    printf("Your score:%i\n", result1); // выводим значение переменной x удвоенное

    // задание 3
    int x2 = 1001;
    int trigger2 = 1000;
    while ((x2 > trigger2) || (x2 < 0)){
        printf("Type your integer more then 0 and lees then 1000:\n");
        scanf("%i", &x2);
    }
    printf("\n");
    for(int y = 0; y <= x2; y += 2){
        printf("Enjoy your output:%i,\n", y);
    }


    // задание 4
    int input; // переменная количества строк, вводится пользователем
    int size; // техническая переменная, для корректной отработки алгоритма
    printf("Type your number of rows for triangle:\n");
    scanf("%i", &input); // вводим значения переменной количества строк
    size = ((input <= 1) ? 1 : 2*input-1); // обрабатываем исключения
    for (int y = 0; y < size; y += 2) { //Каждый новый уровень добавляет по 2 звездочки. поэтому шаг для уровня 2
        for (int x = 0; x < size; x++) { //Строим вывод для строки
            printf((x * 2 <= size && (size - y) / 2 <= x) || (x * 2 >= size && y >= x * 2 - size) ? "*" : " "); //алгоритм. выдающий звездочку или пробел в зависимости от уровня
        }
    printf("\n");
    }
    return 0;
}
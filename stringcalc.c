#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int chartoint (char literal){
    if (literal == '0'){
        return 0;
    }

    else if (literal == '1'){
        return 1;
    }

    else if (literal == '2'){
        return 2;
    }

    else if (literal == '3'){
        return 3;
    }

    else if (literal == '4'){
        return 4;
    }

    else if (literal == '5'){
        return 5;
    }

    else if (literal == '6'){
        return 6;
    }

    else if (literal == '7'){
        return 7;
    }

    else if (literal == '8'){
        return 8;
    }

    else if (literal == '9'){
        return 9;
    }

    else{
        printf("Error");
        return -1;
    }
}

float executer(int num1, int num2, char operand){
    if (operand == '+'){
        return num1 + num2;
    }

    else if (operand == '-'){
        return num1 - num2;
    }

    else if (operand == '*'){
        return num1 * num2;
    }

    else if (operand == '/'){
        return num1 / num2;
    }

    else if (operand == '%'){
        return num1 % num2;
    }

    else{
        printf("Error");
        return -1;
    }
}

int simpleParse(const char *exp){
    int literals[9];
    int il = 0;
    char operators[8];
    int io = 0;

    for (int i = 0; exp[i] != '\0'; i++){
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%'){
            operators[io] = exp[i];
            io++;
        }

        else if (isdigit(exp[i])){
            if (exp[i+1] == ' ' || exp[i+1] == '\0'){
                literals[il] = chartoint(exp[i]);
                il++;
            }

            else if (isdigit(exp[i+1])){
                if (exp[i+2] == ' ' || exp[i+2] == '\0'){
                    literals[il]= 10*chartoint(exp[i])+chartoint(exp[i+1]);
                    il++;
                    i++;
                }

                else if (isdigit(exp[i+2])){
                    if (exp[i+3] == ' ' || exp[i+3] == '\0'){
                    literals[il]= 100*chartoint(exp[i]) + 10*chartoint(exp[i+1]) + chartoint(exp[i+2]);
                    il++;
                    i+=2;
                    }
                }
            }
        }
    }

    float solution;
    int in = 0;
    int ia = 0;
    int nums[9];

    for (int i = 0; i < io; i++){
        if (operators[i] == '*' || operators[i] == '/' || operators[i] == '%'){
            literals[i+1]=executer(literals[i], literals[i+1], operators[i]);
            literals[i]=2147483647;
            solution = literals[i+1];
            operators[i] = '\0';
        }
    }
    
    for (int i = 0; i < io+1; i++){
        if (literals[i] < 2147483647){
            nums[in]=literals[i];
            in++;
        }
    }

    for (int i = 0; i < io; i++){
        if (operators[i] == '+' || operators[i] == '-'){
            nums[ia+1]=executer(nums[ia], nums[ia+1], operators[i]);
            nums[ia] = 0;
            solution = nums[ia+1];
            ia++;
            operators[i] = '\0';
        }
    }

    return solution;
};

int main() {
    //Test cases
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));
}

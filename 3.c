#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void codedstr(char* str){
    int i = 0;

    while(str[i] != '\0'){
        if(i % 2 == 0){
            str[i] = 'A' + (str[i] - '0');
        }
        else if(i % 2 != 0){
            switch (str[i])
            {
            case '0':
                str[i] = '!';
                break;
            case '1':
                str[i] = '#';
                break;
            case '2':
                str[i] = '/';
                break;
            case '3':
                str[i] = '~';
                break;
            case '4':
                str[i] = '=';
                break;
            case '5':
                str[i] = '`';
                break;
            case '6':
                str[i] = '\\';
                break;
            case '7':
                str[i] = '>';
                break;
            case '8':
                str[i] = '.';
                break;
            case '9':
                str[i] = ',';
                break;
            default:
                fprintf(stderr, "Error\n");
            }
        }
        i++;
    }
    printf("%s\n", str);
}

int main(){
    char str[501];

    scanf("%s", str);

    codedstr(str);

    printf("\n");

    return 0;
}

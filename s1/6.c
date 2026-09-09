#include <stdio.h>
int main() {
    int a;
    int max = 0;
    int l = 0;
    scanf("%i", &a);
    while (a!=1) {
        printf("%i ", a);
        if (a%2==0) {a = a/2;}
        else if (a%2==1) {a = 3*a + 1;}
        if (a>max) {max = a;}
        l++;
    }
    printf("1");
    printf("\n");
    if (l!=0){printf("Length:%i, Max:%i", l + 1, max);}
    else {printf("Length:%i, Max:%i", l + 1, max + 1);}
}
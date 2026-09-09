#include <stdio.h>
int main() {
    int a;
    scanf("%i", &a);
    if ( (0<=a && a<=20) || (100<a && a<200)) {
        printf("Yes");
    }
    else{printf("No");}
    return 0;
}
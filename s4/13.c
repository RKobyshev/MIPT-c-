#include <stdio.h>

struct game {
    char title[50];
    float rating;
};
typedef struct game Game;

int main() {
    int n;
    Game games[100];
    scanf("%i", &n);
    char temp;
    scanf("%c", &temp);

    for (int i = 0; i < n; i++) {
        int k;
        int sum = 0;
        scanf("%[^:]", games[i].title);
        scanf("%c", &temp);
        scanf("%i", &k);
        for (int j = 0; j < k; j++) {
            int rating;
            scanf("%i", &rating);
            sum += rating;
        }
        scanf("%c", &temp);
        games[i].rating = (float)sum / k;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (games[j].rating < games[j + 1].rating) {
                Game temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].rating);
    }
}

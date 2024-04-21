#include<stdio.h>

#define MAX_CITIES 10

int ary[MAX_CITIES][MAX_CITIES], completed[MAX_CITIES], n, cost=0;

void takeInput();
void mincost(int city);
int least(int c);

void takeInput() {
    int i, j;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Matrix\n");

    for(i = 0; i < n; i++) {
        printf("\nEnter Elements of Row: %d\n", i+1);

        for(j = 0; j < n; j++)
            scanf("%d", &ary[i][j]);

        completed[i] = 0;
    }

    printf("\n\nThe cost list is:");

    for(i = 0; i < n; i++) {
        printf("\n");

        for(j = 0; j < n; j++)
            printf("\t%d", ary[i][j]);
    }
}

void mincost(int city) {
    int i, next_city;

    completed[city] = 1;

    printf("%d--->", city+1);
    next_city = least(city);

    if(next_city == 999) {
        next_city = 0;
        printf("%d", next_city+1);
        cost += ary[city][next_city];
        return;
    }

    mincost(next_city);
}

int least(int c) {
    int i, next_city = 999;
    int min = 999, kmin;

    for(i = 0; i < n; i++) {
        if((ary[c][i] != 0) && (completed[i] == 0)) {
            if(ary[c][i] < min) {
                min = ary[c][i];
                kmin = ary[c][i];
                next_city = i;
            }
        }
    }

    if(min != 999)
        cost += kmin;

    return next_city;
}

int main() {
    takeInput();

    printf("\n\nThe Path is:\n");
    mincost(0); //passing 0 because starting vertex

    printf("\n\nMinimum cost is %d\n ", cost);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void quickSort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quickSort(a, left, j);
    }
    if(i < right) {
        quickSort(a, i, right);
    }
}

int main(){

    int a, b, countCase = 0;

    scanf("%d %d",&a,&b);

    int v;

    while (a != 0 && b != 0) {

        int *marbles = (int*) malloc(a * sizeof(int));

        for (int i = 0; i < a; i++) {
            scanf("%d",&marbles[i]);
        }

        quickSort(marbles, 0, a - 1);

        printf("CASE# %d:\n",++countCase);

        for (int i = 0; i < b; i++) {
            int pos = -1;
            int value;
            scanf("%d",&value);

            for (int x = 0; x < a; x++) {
                if (value == marbles[x]) {
                    pos = x + 1;
                    break;
                }
            }

            if (pos == -1)
                printf("%d not found\n",value);
            else
                printf("%d found at %d\n",value,pos);
        }
    
        scanf("%d %d",&a,&b);
    }
    return 0;
}
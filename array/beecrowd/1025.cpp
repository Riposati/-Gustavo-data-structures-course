#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){

    int a, b, countCase = 0;

    scanf("%d %d",&a,&b);

    int v;

    while (a != 0 && b != 0) {

        int marbles[a];

        for (int i = 0; i < a; i++) {
            scanf("%d",&marbles[i]);
        }

        qsort(marbles, a, sizeof(int), cmpfunc);

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
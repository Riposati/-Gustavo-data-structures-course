#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int>fila;

    int n;

    scanf("%d",&n);

    while(n!=0){

        for(int i=1;i<=n;i++){
            fila.push(i);
        }

        printf("Discarded cards: ");
        while(fila.size() > 1){

            if(fila.size() > 2)
                printf("%d, ",fila.front());
            else
                printf("%d",fila.front());
            fila.pop();
            fila.push(fila.front());
            fila.pop();
        }

        printf("\nRemaining card: %d\n",fila.front());
        fila.pop();
        scanf("%d",&n);
    }
    return 0;
}
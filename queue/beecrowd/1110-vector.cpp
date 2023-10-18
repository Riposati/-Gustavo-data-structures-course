#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>numeros;
    int a,i,t;

    scanf("%d",&a);

    while(a!=0){

        for(i=0;i<a;i++){
            numeros.insert(numeros.end(),i+1);
        }

        printf("Discarded cards: ");
        while(numeros.size() > 1){

            t = numeros.at(0);
            numeros.erase(numeros.begin());

            if(numeros.size() > 1)
            printf("%d, ",t);

            else
                printf("%d",t);

            numeros.insert(numeros.end(),numeros.at(0));
            numeros.erase(numeros.begin());
        }

        printf("\nRemaining card: %d\n",numeros.at(0));
        numeros.clear();
        scanf("%d",&a);
    }
    return 0;
}

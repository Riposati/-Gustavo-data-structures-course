#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a,b,c,i,j,cont,cont2;
    
    scanf("%d %d %d",&a, &b,&c);

    while(a!=0 && b!=0 && c!=0){
    
        cont = cont2 = 0;

        int m[b][a];

        for(i=0;i<b;i++){

            for(j=0;j<a;j++){

                scanf("%d",&m[i][j]);
            }
        }
        
        for(i=0;i<a;i++){

            for(j=0;j<b;j++){

                //printf("%d\n",m[j][i]);
                if(m[j][i]==1){

                    cont++;
                }else{
                    if(cont>=c){
                        cont2++;
                    }
                    cont=0;
                }
            }
            if(cont>=c){
                cont2++;
            }
            cont=0;
        }
        printf("%d\n",cont2);
        scanf("%d %d %d",&a, &b,&c);
    }
    return 0;
}
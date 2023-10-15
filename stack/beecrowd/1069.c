#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    char openDiamond;
    struct stack *below;
}typedef Stack;

Stack *createNode(char openDiamond){
    Stack *aux = malloc(sizeof(Stack));   
    aux->openDiamond = openDiamond;
    aux->below = NULL;
    return aux;
}

Stack *push(Stack *top, char openDiamond){
    Stack *aux = createNode(openDiamond);

    if(top==NULL)
        top = aux;
    else{
        aux->below = top;
        top = aux;
    }
    return top;
}

Stack *pop(Stack *top){
    Stack *aux = top;

    if(aux != NULL){
        top = aux->below;
        free(aux);
    }
    return top;
}

int main(){
    Stack *top;
    char str[1001];
    int tests, sumDiamonds,i;

    scanf("%d",&tests);
    getchar();

    while(tests > 0){

        top = NULL;
        sumDiamonds = i = 0;

        fgets(str,sizeof(str),stdin);	

        while(str[i]!='\0'){
            
            if(str[i]=='<')
                top = push(top, str[i]);

            if(top!=NULL && str[i]=='>'){
                top = pop(top);
                sumDiamonds++;
            }
            i++;
        }

        printf("%d\n", sumDiamonds);
        tests--;    
    }
    return 0;
}
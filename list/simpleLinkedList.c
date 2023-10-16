#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct linkedList{
    int key;
    struct linkedList *next;
}typedef LinkedList;

LinkedList *createNode(int key){
    LinkedList *aux = malloc(sizeof(LinkedList));
    aux->key = key;
    aux->next = NULL;
    return aux;
}

LinkedList *insertNode(LinkedList *firstNode, int key){
    LinkedList *aux = createNode(key);

    if(firstNode==NULL)
        firstNode = aux;
    else{
        LinkedList *lastNode = firstNode;
        
        while(lastNode->next!=NULL)
            lastNode = lastNode->next;
        
        lastNode->next = aux;
    }
    return firstNode;
}

LinkedList *deleteNode(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;
    LinkedList *aux2 = NULL;

    printf("key to be deleted from list -> (%d)\n",key);

    if(aux!=NULL){
        if(firstNode->key==key){ // first node
            aux = aux->next;
            firstNode = aux;
            free(aux);
        }else{
            while(aux!=NULL && aux->key!=key){
                aux2 = aux;
                aux = aux->next;
            }
            if(aux!=NULL){
                if(aux->next!=NULL){ // node in the middle
                    aux2->next = aux->next;
                    free(aux);
                }else{
                    aux2->next = NULL; // last node
                    free(aux);
                }
            }
        }
    }
    return firstNode;
}

void showList(LinkedList *firstNode){
    LinkedList *aux = firstNode;

    if(aux==NULL)
        printf("Empty List\n");

    while(aux != NULL){
        if(aux->next!=NULL)
            printf("%d -> ",aux->key);
        else
            printf("%d",aux->key);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    LinkedList *first = NULL;

    srand(time(0));
    int numberOfRandoms = 5;
    int arrayOfRandoms[numberOfRandoms];
    int random;

     for(int i=0;i<numberOfRandoms;i++){ // generate n random numbers
        random = rand()%10000;
        first = insertNode(first,random);
        arrayOfRandoms[i] = random;
    }

    showList(first);

    for(int i=0;i<rand()%numberOfRandoms;i++){
        first = deleteNode(first, arrayOfRandoms[rand()%numberOfRandoms]);
    }

    showList(first);

    return 0;
}
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct linkedList{
    int key;
    struct linkedList *next;
    struct linkedList *before;
}typedef LinkedList;

LinkedList *createNode(int key){
    LinkedList *aux = malloc(sizeof(LinkedList));
    aux->key = key;
    aux->next = aux;
    aux->before = aux;
    return aux;
}

LinkedList *insertNode(LinkedList *firstNode, int key){
    LinkedList *aux = createNode(key);

    if(firstNode==NULL)
        firstNode = aux;
    else{
        firstNode->before->next = aux;
        aux->next = firstNode;
        aux->before = firstNode->before;
        firstNode->before = aux;
    }
    return firstNode;
}

LinkedList *deleteNode(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;

    printf("key to be deleted from list -> (%d)\n",key);

    if(aux!=NULL){
        // TODO
    }
    return firstNode;
}

void showList(LinkedList *firstNode){
    LinkedList *aux = firstNode;

    if(aux==NULL)
        printf("Empty List\n");
    else{
        printf("List going:\n");
        while(aux->next != firstNode){
            printf("%d -> ",aux->key);
            aux = aux->next;
        }

        printf("%d\n",aux->key);
    }
}

void showListInverse(LinkedList *firstNode){
    LinkedList *aux = firstNode;

    if(aux==NULL)
        printf("Empty List\n");
    else{
        printf("List going back:\n");
        while(aux->before != firstNode){
            printf("%d -> ",aux->before->key);
            aux = aux->before;
        }

        printf("%d\n",aux->before->key);
    }
}

int main(){
    LinkedList *first = NULL;
    srand(time(0));
    int numberOfRandoms = 5;

    for(int i=0;i<numberOfRandoms;i++) // generate n random numbers
        first = insertNode(first,(rand()%1000));

    showList(first);
    showListInverse(first);

    return 0;
}
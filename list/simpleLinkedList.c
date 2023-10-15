#include<stdlib.h>
#include<stdio.h>

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
        printf("%d -> ",aux->key);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    LinkedList *first = NULL;

    first = insertNode(first, 1);
    first = insertNode(first, 2);
    first = insertNode(first, 3);
    first = insertNode(first, 4);
    first = insertNode(first, 5);
    showList(first);

    first = deleteNode(first,1);

    showList(first);

    return 0;
}
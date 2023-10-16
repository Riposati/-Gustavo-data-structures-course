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
    aux->next = NULL;
    aux->before = NULL;
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
        aux->before = lastNode;
    }
    return firstNode;
}

LinkedList *deleteNode(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;

    printf("key to be deleted from list -> (%d)\n",key);

    if(aux!=NULL){
        if(firstNode->key==key){
        
        if(firstNode->next!=NULL){ // first node with more than 1 node in the list
            firstNode->next->before = NULL;
            firstNode = firstNode->next;
            free(aux);
        }else{ // Single node in the list
            free(aux);
            firstNode = NULL;
        }

    }else if(aux->next!=NULL && aux->key!=key){

            while(aux->key!=key && aux->next!=NULL){
                aux = aux->next;
            }

            if(aux->next!=NULL && aux->key==key){ // node in the middle

                LinkedList *aux2 = aux;
                aux2->before->next=aux->next;
                aux2->next->before = aux->before;
                free(aux);

            }else if(aux->next==NULL && aux->key==key){ // node in the end

                LinkedList *aux2 = aux;
                aux2->before->next = NULL;
                free(aux);
            }
        }
    }
    return firstNode;
}

void showList(LinkedList *firstNode){
    LinkedList *aux = firstNode;

    if(aux==NULL)
        printf("Empty List\n");
    else{
        printf("List going:\n");
        while(aux != NULL){
            if(aux->next!=NULL)
                printf("%d -> ",aux->key);
            else
                printf("%d",aux->key);
            aux = aux->next;
        }
    }
    printf("\n");
}

void showListInverse(LinkedList *firstNode){
    LinkedList *aux = firstNode;

    if(aux==NULL)
        printf("Empty List\n");
    else{

        while(aux->next != NULL){
            aux = aux->next;
        }

        printf("List going back:\n");
        while(aux != NULL){
            if(aux->before!=NULL)
                printf("%d -> ",aux->key);
            else
                printf("%d",aux->key);
            aux = aux->before;
        }
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
    showListInverse(first);

    for(int i=0;i<rand()%numberOfRandoms;i++){
        first = deleteNode(first, arrayOfRandoms[rand()%numberOfRandoms]);
    }

    showList(first);
    showListInverse(first);

    return 0;
}
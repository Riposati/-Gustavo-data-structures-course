#include <stdio.h>
#include <stdlib.h>
  
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

    // printf("key to be deleted from list -> (%d)\n",key);

    if(aux!=NULL){
        if(firstNode->key==key){ // first node
        
        aux = firstNode->next;
        aux->before = firstNode->before;
        firstNode->before->next=aux;
        
        if(firstNode->next==firstNode && firstNode->before==firstNode){ // if the list has only one node
            free(firstNode);
            firstNode = NULL;

        }else{
            free(firstNode);
            firstNode = aux;
        }

    }else if(aux->next!=firstNode && aux->key!=key){

            while(aux->key!=key && aux->next!=firstNode){
                aux = aux->next;
            }

            if(aux->next!=firstNode && aux->key==key){ // node in the middle

                LinkedList *aux2 = aux->before;
                aux2->next=aux->next;
                aux2->next->before=aux2;
                free(aux);

            }else if(aux->next==firstNode && aux->key==key){ // node in the end

                LinkedList *aux2 = aux->before;
                aux2->next = firstNode;
                firstNode->before = aux2;
                free(aux);
            }
        }
    }
    return firstNode;
}

LinkedList *createNewQueue(LinkedList *first){
    if(first->next!=first){
        printf("%d",first->key);

        first = deleteNode(first,first->key);

        LinkedList *aux = first;

        aux->before = first->before;
        first->before->next = aux;
        aux->next = first->next;
        first->next->before = aux;
        first = first->next;
    }

    if(first->next!=first)
        printf(", ");

    return first;
}
  
int main()
{
    LinkedList *first = NULL;
    int i,v;
  
    scanf("%d",&v);
  
    while(v!=0){
  
        for(i=1;i<=v;i++){
            first = insertNode(first,i);
        }
    
        printf("Discarded cards: ");
        for(i=0;i<v;i++){
            first = createNewQueue(first);
        }
    
        printf("\n");
        printf("Remaining card: ");
        printf("%d", first->key);
    
        printf("\n");
        scanf("%d",&v);
        first = NULL;
    }
    return 0;
}

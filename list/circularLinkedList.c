#include<stdlib.h>
#include<stdio.h>

struct linkedList{
    int key;
    struct linkedList *next;
}typedef LinkedList;

LinkedList *createNode(int key){
    LinkedList *aux = malloc(sizeof(LinkedList));
    aux->key = key;
    aux->next = aux;
    return aux;
}

LinkedList *insertNode(LinkedList *firstNode, int key){
    LinkedList *aux = createNode(key);

    if(firstNode==NULL)
        firstNode = aux;
    else{
        LinkedList *lastNode = firstNode;
        
        while(lastNode->next!=firstNode)
            lastNode = lastNode->next;
        
        lastNode->next = aux;
        aux->next = firstNode;
    }
    return firstNode;
}

LinkedList *deleteNode(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;
    LinkedList *aux2 = NULL;

    printf("key to be deleted from list -> (%d)\n",key);

    if(aux!=NULL){
        if(firstNode->key==key){ // first node
            
            while(aux->next!=firstNode) // need to find last node to re-arrange pointers
                aux = aux->next;

            if(aux->next==aux){ // single node in the list
                free(aux);
                firstNode = NULL;
            }else{ // more than 1 node in the list
                aux2 = firstNode;
                firstNode = firstNode->next; // first node = second node
                aux->next = firstNode; // next from the last node = new firstNode
                free(aux2); // remove from memory old firstNode
            }
        }else{

            while(aux->next!=firstNode && aux->key!=key){ // need to find node with the key
                aux2 = aux;
                aux = aux->next;
            }
            
            if(aux->key==key){
                if(aux->next!=firstNode){ // node in the middle
                    aux2->next = aux->next;
                    free(aux);
                }else{
                    aux2->next = firstNode; // last node
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
    else{

        while(aux->next != firstNode){
            printf("%d -> ",aux->key);
            aux = aux->next;
        }

        printf("%d -> \n",aux->key);
    }
}

int main(){
    LinkedList *first = NULL;

    first = insertNode(first, 1);
    first = insertNode(first, 2);
    first = insertNode(first, 3);
    first = insertNode(first, 4);
    first = insertNode(first, 5);
    first = insertNode(first, 6);

    showList(first);

    first = deleteNode(first,1);
    
    showList(first);

    first = deleteNode(first,3);

    showList(first);

    return 0;
}
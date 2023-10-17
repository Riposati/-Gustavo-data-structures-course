#include <stdio.h>
#include <stdlib.h>
  
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
  
void showList(LinkedList *first){
    LinkedList *aux = first;
  
    while(aux!=NULL){
        printf("%d",aux->key);
        aux=aux->next;
    }
}
  
LinkedList *deleteNode(LinkedList *first){
    if(first->next!=NULL){ /// se o proximo do inicio nao for nulo
  
        LinkedList *aux = first; /// um aux = ini
    
        LinkedList *aux2 = first->next; /// aux2 = o da frente do inicio
        first = first->next;
        LinkedList *aux4 = first; /// o aux4 recebe o que deve ir para o fim da lista
    
        if(first->next==NULL)
            printf("%d",aux->key);
        else
            printf("%d, ",aux->key); /// pra mostra os que foram desalocados

        free(aux);
    
        while(aux2->next!=NULL){
            aux2 = aux2->next;
        } /// esse while e pra achar o ultimo
    
        /// aqui movimento os dados ///
        if(first->next!=NULL){
            first = first->next;
            aux4->next=NULL;
            aux2->next = aux4;
            return first;
        }
    }
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
            first = deleteNode(first);
        }
    
        printf("\n");
        printf("Remaining card: ");
        showList(first);
    
        printf("\n");
        scanf("%d",&v);
        first = NULL;
    }
    return 0;
}

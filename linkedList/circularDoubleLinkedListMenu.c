#include<stdlib.h>
#include<stdio.h>

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

LinkedList *insertNodeFront(LinkedList *firstNode, int key){
    LinkedList *aux = createNode(key);

    if(firstNode==NULL)
        firstNode = aux;
    else{
        aux->next = firstNode;
        aux->before = firstNode->before;
        firstNode->before->next = aux;
        firstNode->before = aux;
        firstNode = aux;
    }
    return firstNode;
}

LinkedList *insertNodeBack(LinkedList *firstNode, int key){
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

LinkedList *reverseList(LinkedList *firstNode){
    LinkedList *aux = firstNode;
    LinkedList *newFirst = NULL;

    if(aux==NULL)
        printf("Lista vazia\n");
    else{
        while(aux->before != firstNode){
            newFirst = insertNodeBack(newFirst, aux->before->key);
            aux = aux->before;
        }
        newFirst = insertNodeBack(newFirst, aux->before->key);
        firstNode = newFirst;
    }
    return firstNode;
}

LinkedList *deleteFromFront(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;
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
    return firstNode;   
}

LinkedList *deleteFromMiddle(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;

    while(aux->key!=key && aux->next!=firstNode){
        aux = aux->next;
    }

    if(aux->next!=firstNode && aux->key==key){

        LinkedList *aux2 = aux->before;
        aux2->next=aux->next;
        aux2->next->before=aux2;
        free(aux);
    }
    return firstNode;
}

LinkedList *deleteFromEnd(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode->before;
    LinkedList *aux2 = aux->before;
    aux2->next = firstNode;
    firstNode->before = aux2;
    free(aux);
    
    return firstNode;
}

LinkedList *deleteNode(LinkedList *firstNode, int key){
    LinkedList *aux = firstNode;

    printf("key to be deleted from list -> (%d)\n",key);

    if(aux!=NULL){
        if(firstNode->key==key)
            firstNode = deleteFromFront(firstNode, key);

        else if(firstNode->before->key==key)
            firstNode = deleteFromEnd(firstNode, key);
        else
           firstNode = deleteFromMiddle(firstNode,key);
    }

    return firstNode;
}

void showList(LinkedList *firstNode){
    LinkedList *aux = firstNode;

    if(aux==NULL)
        printf("Lista vazia\n");
    else{
        printf("Lista indo:\n");
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
        printf("Lista vazia\n");
    else{
        printf("Lista voltando:\n");
        while(aux->before != firstNode){
            printf("%d -> ",aux->before->key);
            aux = aux->before;
        }

        printf("%d\n",aux->before->key);
    }
}

int main(){
    LinkedList *first = NULL;
    int option,v;

    do{
        printf("1 - inserir atras\n");
        printf("2 - inserir na frente\n");
        printf("3 - mostrar lista na ordem\n");
        printf("4 - mostrar lista na ordem inversa\n");
        printf("5 - deletar chave\n");
        printf("6 - inverter lista\n");
        printf("7 - limpar lista\n");
        printf("0 - sair\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:
                printf("informe o valor e tecle enter:\n");
                scanf("%d",&v);
                first = insertNodeBack(first,v);
                break;
            case 2:
                printf("informe o valor e tecle enter:\n");
                scanf("%d",&v);
                first = insertNodeFront(first,v);
                break;
            case 3:
                showList(first);
                break;
            case 4:
                showListInverse(first);
                break;
            case 5:
                printf("informe o valor e tecle enter:\n");
                scanf("%d",&v);
                first = deleteNode(first,v);
                break;
            case 6:
                first = reverseList(first);
                break;
            case 7:
                while(first!=NULL){
                    first = deleteNode(first,first->key);
                }
                break;
            case 0:
                printf("Ate mais!\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        };

    }while(option!=0);

    return 0;
}
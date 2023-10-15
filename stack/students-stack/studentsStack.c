#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int id;
    char name[40];
    long long unsigned registration;
}typedef Student;

struct stack{
    Student student;
    struct stack *below;
}typedef Stack;

Stack *createNode(Student student){
    Stack *aux = malloc(sizeof(Stack));   
    aux->student.id = student.id;
    strcpy(aux->student.name, student.name);
    aux->student.registration = student.registration;
    aux->below = NULL;
    return aux;
}

Stack *push(Stack *top, Student student){
    Stack *aux = createNode(student);

    if(top==NULL)
        top = aux;
    else{
        aux->below = top;
        top = aux;
    }
    return top;
}

void showStack(Stack *top){
    int isEmptyStack = 1;

    while(top != NULL){
        isEmptyStack = 0;
        printf("%d | %s | %llu\n",top->student.id, top->student.name, top->student.registration);
        top = top->below;
    }

    if(isEmptyStack)
        printf("Empty Stack\n");

    printf("\n");
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
    Stack *top = NULL;
    
    Student student;
    student.id = 1;
    strcpy(student.name, "Gustavo");
    student.registration = 123;

    Student student2;
    student2.id = 2;
    strcpy(student2.name, "Maria");
    student2.registration = 456;

    Student student3;
    student3.id = 3;
    strcpy(student3.name, "Joao");
    student3.registration = 789;

    Student student4;
    student4.id = 4;
    strcpy(student4.name, "Siclano");
    student4.registration = 101112;

    top = push(top, student);
    top = push(top, student2);
    top = push(top, student3);
    top = push(top, student4);

    showStack(top);

    top = pop(top);
    showStack(top);

    top = pop(top);
    showStack(top);

    top = pop(top);
    showStack(top);

    top = pop(top);
    showStack(top);
    
    return 0;
}
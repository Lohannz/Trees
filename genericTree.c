#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int value;
    struct Node *irmao;
    struct Node *filho;
}Node;


Node *criarNo(int value){
    Node *novo = (Node *) malloc(sizeof(Node));
    novo->value = value;
    novo->filho = NULL;
    novo->irmao = NULL;
    return novo;
    
}

void add_filho(Node *pai, int value){
    Node *filho = criarNo(value);
    if(pai->filho == NULL)
        pai->filho = filho;
    
    else{
        Node *temp = pai->filho;
        while(temp->irmao!= NULL){
            temp = temp->irmao;
        }
        temp->irmao = filho;
    }
}


void traverseDFS(Node *no){
    if( no == NULL) return;

    printf("%i ", no->value);
    traverseDFS(no->filho);
    traverseDFS(no->irmao);

    
}

int main(){
    Node *raiz = criarNo(10);

    add_filho(raiz, 20);
    add_filho(raiz->filho, 30);
    traverseDFS(raiz);
    return 0;
}
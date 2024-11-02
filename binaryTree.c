#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node *esquerda;
    struct Node *direita;
}Node;

Node *empty_tree(){
    return NULL;
}

int empty(Node *tree){
    if(tree == NULL)
        return 1;
    return 0;
}
Node *CriarNovoNo(int value){
    Node *novoNo = (Node*) malloc(sizeof(Node));
    novoNo->value = value;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

Node *insert(Node *tree, int value){
    if(empty(tree)){
        tree = CriarNovoNo(value);
    }

    else if (value <= tree->value)
        tree->esquerda = insert(tree->esquerda, value);
    else 
        tree->direita = insert(tree->direita, value);

    return tree;
}

// Em ordem (in-order): esquerda, raiz, direita
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->esquerda);
        printf("%d ", root->value);
        inOrder(root->direita);
    }
}

// Pré-ordem (pre-order): raiz, esquerda, direita
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->esquerda);
        preOrder(root->direita);
    }
}

// Pós-ordem (post-order): esquerda, direita, raiz
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->esquerda);
        postOrder(root->direita);
        printf("%d ", root->value);
    }
}

int verifica_valor_arv(Node *tree, int value){
    if(empty(tree) == 1) return 0;

    if (tree->value == value) return 1;
    else if (tree->value > value) return verifica_valor_arv(tree->esquerda, value);
    else return verifica_valor_arv(tree->direita, value);

}

int main(){
    Node* Minha_Arvore = CriarNovoNo(3);

    Minha_Arvore = insert(Minha_Arvore, 2);
    Minha_Arvore = insert(Minha_Arvore, 9);
    Minha_Arvore = insert(Minha_Arvore, 3);
    Minha_Arvore = insert(Minha_Arvore, 4);

    preOrder(Minha_Arvore);
    return 0;
}
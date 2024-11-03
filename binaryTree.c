#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Pessoa{
    int id;
    char nome[21];
    int idade;
} Pessoa;

typedef struct Node{
    Pessoa *data;
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
Node *CriarNovoNo(Pessoa *p){
    Node *novoNo = (Node*) malloc(sizeof(Node));
    novoNo->data = p;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

Node *insert(Node *tree, Pessoa *p){
    if(empty(tree)){
        tree = CriarNovoNo(p);
    }

    else if (p->id <= tree->data->id)
        tree->esquerda = insert(tree->esquerda, p);
    else 
        tree->direita = insert(tree->direita, p);

    return tree;
}

// Em ordem (in-order): esquerda, raiz, direita
void inOrder(struct Node* root) {
    if (root != NULL) {
        
        inOrder(root->esquerda);

        printf("---------------------------\n");
        printf("id:%i\n", root->data->id);
        printf("nome:%s\n", root->data->nome);
        printf("idade:%d ", root->data->idade);
        printf("\n---------------------------\n");
        inOrder(root->direita);
    }
}

// Pré-ordem (pre-order): raiz, esquerda, direita
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("---------------------------\n");
        printf("id:%i\n", root->data->id);
        printf("nome:%s\n", root->data->nome);
        printf("idade:%d ", root->data->idade);
        printf("\n---------------------------\n");;
        preOrder(root->esquerda);
        preOrder(root->direita);
    }
}

// Pós-ordem (post-order): esquerda, direita, raiz
void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->esquerda);
        postOrder(root->direita);
        printf("---------------------------\n");
        printf("id:%i\n", root->data->id);
        printf("nome:%s\n", root->data->nome);
        printf("idade:%d ", root->data->idade);
        printf("\n---------------------------\n");
    }
}

Pessoa *verifica_pessoa_arv(Node *tree, int id_procurado){
    if(empty(tree) == 1) return NULL;

    if (tree->data->id == id_procurado) 
        return tree->data;

    else if (tree->data->id > id_procurado) return verifica_pessoa_arv(tree->esquerda, id_procurado);
    else return verifica_pessoa_arv(tree->direita, id_procurado);

}

int main(){

    Pessoa p1 = {1,"Lohan", 19};
    Pessoa p2 = {2,"Luiza", 20};
    Pessoa p3 = {3,"Lavinia", 18};

    Node* Minha_Arvore = CriarNovoNo(&p1);
    insert(Minha_Arvore, &p2);
    insert(Minha_Arvore, &p3);

    Pessoa *pessoa_procurada = verifica_pessoa_arv(Minha_Arvore, 2);

    printf("%s", pessoa_procurada->nome);
    

    return 0;
}
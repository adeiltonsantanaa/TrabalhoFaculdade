#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100000

struct Contato{
    char* nome;
    char telefone[17];
    char* email;
}pessoa[MAX];

void exibirMenu(){
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t01 - Inserir contato\n"
           "\t02 - Listar contatos\n"
           "\t03 - Pesquisar contato\n"
           "\t04 - Alterar contato\n"
           "\t99 - Sair\n\n");
}

char* alocarMemoria(int tamanho){
    char* info = NULL;
    info = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }
    return info;
}

void cadastrarContato(int registro){
    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].nome = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].nome, dados);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", pessoa[registro].telefone);
    setbuf(stdin, NULL);

    printf("\t\tE-mail: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].email = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].email, dados);
}

void listarContatos(int qtdeContatos){
    int i;
    int contagem = 1;
    for(i = 0; i < qtdeContatos; i++){
        printf("\n\tContato nº: %d\n", contagem++);
        printf("\tNome: %s\n", pessoa[i].nome);
        printf("\tTelefone: %s\n", pessoa[i].telefone);
        printf("\tE-email: %s\n", pessoa[i].email);
    }
    printf("\n\n");
}

void exibirContato(int indice){
    printf("\n\tNome: %s\n", pessoa[indice].nome);
    printf("\tTelefone: %s\n", pessoa[indice].telefone);
    printf("\tEndereço: %s\n", pessoa[indice].email);
}

int pesquisarContato(int qtdeContatos, char* nomeBuscado){
    int i;

    for(i = 0; i < qtdeContatos; i++){
        if(strcmp(nomeBuscado, pessoa[i].nome) == 0)
            return i;
    }
    return -1;
}

void atualizarContato(int indice){
    char* nome;
    char fone[16];
    char* email;

    char dados[MAX];
    printf("\t\t\tNome: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    nome = alocarMemoria(strlen(dados));
    strcpy(nome, dados);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", fone);
    setbuf(stdin, NULL);

    printf("\t\tE-mail: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    email = alocarMemoria(strlen(dados));
    strcpy(email, dados);

    pessoa[indice].nome = nome;
    strcpy(pessoa[indice].telefone, fone);
    pessoa[indice].email = email;
}

int leitor(){
    int opcao;

    printf("\n\tOpção escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

int main(){
    char nome[MAX];
    int numeroRegistro = 0;
    int opcaoEscolhida;
    int indice;

    do{
        exibirMenu();
        opcaoEscolhida = leitor();

        switch(opcaoEscolhida){
            case 1:
                cadastrarContato(numeroRegistro++);
                break;
            case 2:
                listarContatos(numeroRegistro);
                break;
            case 3:
                printf("\n\tNome: ");
                scanf("%[^\n]s", nome);
                indice = pesquisarContato(numeroRegistro, nome);

                if(indice >= 0 && indice <= 99)
                    exibirContato(indice);
                else
                    printf("\n\tContato não cadastrado!");
                break;
            case 4:
                printf("\n\tContato número [1 - 99]: ");
                scanf("%d", &indice);
                indice -= 1;
                if(indice >= 0 && indice <= 99)
                    atualizarContato(indice);
                else
                    printf("\n\tContato inválido!");
                break;
            case 99:
                printf("\n\tSaindo...");
                break;
            default:
                printf("Opção inválida!");
                exibirMenu();
                opcaoEscolhida = leitor();
        }

    }while(opcaoEscolhida != 99);
}

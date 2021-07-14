#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#define PI 3.1415926535
double tinta = 0.0;
double totalTinta = 0.0;

//Declarando os solidos que vao ser utilizados e seus atributos
typedef struct Esfera {
    double peso;
    double volume;
    double area;
    char material[30];
} Esfera;

typedef struct Paralelepipedo {
    double peso;
    double volume;
    double area;
    char material[30];
} Paralelepipedo;

typedef struct Cilindro {
    double peso;
    double volume;
    double area;
    char material[30];
} Cilindro;

//Declarando a estrutura celula que vai ser utilizada para criar a lista
typedef struct Celula {
    struct Esfera *esfera;
    struct Cilindro *cilindro;
    struct Paralelepipedo *paralelepipedo;
    struct Celula *prox;
} Celula;

//Nova celula padrao
Celula* new_celula(Esfera *sphere, Cilindro *cylinder, Paralelepipedo *parallelepiped) {
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    temp->esfera = (Esfera*)malloc(sizeof(Esfera));
    temp->esfera->area = sphere->area;
    strcpy(temp->esfera->material, sphere->material);
    temp->esfera->volume = sphere->volume;
    temp->esfera->peso = sphere->peso;

    temp->cilindro = (Cilindro*)malloc(sizeof(Cilindro));
    temp->cilindro->area = cylinder->area;
    strcpy(temp->cilindro->material, cylinder->material);
    temp->cilindro->volume = cylinder->volume;
    temp->cilindro->peso = cylinder->peso;

    temp->paralelepipedo = (Paralelepipedo*)malloc(sizeof(Paralelepipedo));
    temp->paralelepipedo->area = parallelepiped->area;
    strcpy(temp->paralelepipedo->material, parallelepiped->material);
    temp->paralelepipedo->volume = parallelepiped->volume;
    temp->paralelepipedo->peso = parallelepiped->peso;

    temp->prox = NULL;

    return temp;
}

//Nova celula do tipo esfera, com valores iniciais passados como parametro o restante valores padroes
Celula* new_celula_esfera(Esfera *sphere) {
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    temp->esfera = (Esfera*)malloc(sizeof(Esfera));
    temp->esfera->area = sphere->area;
    strcpy(temp->esfera->material, sphere->material);
    temp->esfera->volume = sphere->volume;
    temp->esfera->peso = sphere->peso;

    temp->cilindro = (Cilindro*)malloc(sizeof(Cilindro));
    temp->cilindro->area = 0;
    strcpy(temp->cilindro->material, "");
    temp->cilindro->volume = 0;
    temp->cilindro->peso = 0;

    temp->paralelepipedo = (Paralelepipedo*)malloc(sizeof(Paralelepipedo));
    temp->paralelepipedo->area = 0;
    strcpy(temp->paralelepipedo->material, "");
    temp->paralelepipedo->volume = 0;
    temp->paralelepipedo->peso = 0;

    temp->prox = NULL;

    return temp;
}

//Nova celula do tipo cilindro, com valores iniciais passados como parametro o restante valores padroes
Celula* new_celula_cilindro(Cilindro *cylinder) {
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    temp->esfera = (Esfera*)malloc(sizeof(Esfera));
    temp->esfera->area = 0;
    strcpy(temp->esfera->material, "");
    temp->esfera->volume = 0;
    temp->esfera->peso = 0;

    temp->cilindro = (Cilindro*)malloc(sizeof(Cilindro));
    temp->cilindro->area = cylinder->area;
    strcpy(temp->cilindro->material, cylinder->material);
    temp->cilindro->volume = cylinder->volume;
    temp->cilindro->peso = cylinder->peso;

    temp->paralelepipedo = (Paralelepipedo*)malloc(sizeof(Paralelepipedo));
    temp->paralelepipedo->area = 0;
    strcpy(temp->paralelepipedo->material, "");
    temp->paralelepipedo->volume = 0;
    temp->paralelepipedo->peso = 0;

    temp->prox = NULL;

    return temp;
}

//Nova celula do tipo paralelepipedo, com valores iniciais passados como parametro o restante valores padroes
Celula* new_celula_paralelepipedo(Paralelepipedo *parallelepiped) {
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    temp->esfera = (Esfera*)malloc(sizeof(Esfera));
    temp->esfera->area = 0;
    strcpy(temp->esfera->material, "");
    temp->esfera->volume = 0;
    temp->esfera->peso = 0;

    temp->cilindro = (Cilindro*)malloc(sizeof(Cilindro));
    temp->cilindro->area = 0;
    strcpy(temp->cilindro->material, "");
    temp->cilindro->volume = 0;
    temp->cilindro->peso = 0;

    temp->paralelepipedo = (Paralelepipedo*)malloc(sizeof(Paralelepipedo));
    temp->paralelepipedo->area = parallelepiped->area;
    strcpy(temp->paralelepipedo->material, parallelepiped->material);
    temp->paralelepipedo->volume = parallelepiped->volume;
    temp->paralelepipedo->peso = parallelepiped->peso;

    temp->prox = NULL;

    return temp;
}

//Declarando a lista e seus metodos e funcoes
typedef struct Lista {
    struct Celula *primeiro, *ultimo;
} Lista;

void inserir(Lista *lista, Esfera *sphere, Cilindro *cylinder, Paralelepipedo *parallelepiped) {
    lista->ultimo->prox = new_celula(sphere, cylinder, parallelepiped);
    lista->ultimo = lista->ultimo->prox;
}

void mostrar(Lista *lista) {
    int x = 0;
    for (Celula *i = lista->primeiro->prox; i != NULL; i = i->prox) {
        printf("[%d]\n", x);
        printf("==== Esfera ====\n");
        printf("material = %s\n", i->esfera->material);
        printf("area = %lf\n", i->esfera->area);
        printf("volume = %lf\n", i->esfera->volume);
        printf("peso = %lf\n", i->esfera->peso);
        printf("==== Cilindro ====\n");
        printf("material = %s\n", i->cilindro->material);
        printf("area = %lf\n", i->cilindro->area);
        printf("volume = %lf\n", i->cilindro->volume);
        printf("peso = %lf\n", i->cilindro->peso);
        printf("==== Paralelepipedo ====\n");
        printf("material = %s\n", i->paralelepipedo->material);
        printf("area = %lf\n", i->paralelepipedo->area);
        printf("volume = %lf\n", i->paralelepipedo->volume);
        printf("peso = %lf\n\n", i->paralelepipedo->peso);
        x++;
    }
}

//Declarando as casas que vao conter uma lista e um valor total
typedef struct CasaZe {
    struct Lista *lista;
    double valorTotal;
} CasaZe;

typedef struct CasaPaulo {
    struct Lista *lista;
    double valorTotal;
} CasaPaulo;

typedef struct CasaJoao {
    struct Lista *lista;
    double valorTotal;
} CasaJoao;

typedef struct CasaChico {
    struct Lista *lista;
    double valorTotal;
} CasaChico;

typedef struct CasaMane {
    struct Lista *lista;
    double valorTotal;
} CasaMane;

typedef struct CasaAlfa {
    struct Lista *lista;
    double valorTotal;
} CasaAlfa;

typedef struct CasaBeta {
    struct Lista *lista;
    double valorTotal;
} CasaBeta;

typedef struct TodasAsCasas {
    //Estrutura da casa alfa
    struct CasaAlfa *casaalfa;

    //Estrutura da casa beta
    struct CasaBeta *casabeta;

    //Estrutura da casa chico
    struct CasaChico *casachico;

    //Estrutura da casa joao
    struct CasaJoao *casajoao;

    //Estrutura da casa mane
    struct CasaMane *casamane;

    //Estrutura da casa paulo
    struct CasaPaulo *casapaulo;

    //Estrutura da casa ze
    struct CasaZe *casaze;

} TodasAsCasas;

//"Construtor" da esfera
Esfera new_esfera() {
    Esfera m1;

    m1.area = 0.0;
    strcpy(m1.material, "");
    m1.peso = 0.0;
    m1.volume = 0.0;

    return m1;
}

//"Construtor" da esfera
Esfera* new_esfera_pointer() {
    Esfera *m1;

    m1->area = 0.0;
    strcpy(m1->material, "");
    m1->peso = 0.0;
    m1->volume = 0.0;

    return m1;
}

//"Construtor" do cilindro
Cilindro new_cilindro() {
    Cilindro m1;

    m1.area = 0.0;
    strcpy(m1.material, "");
    m1.peso = 0.0;
    m1.volume = 0.0;

    return m1;
}

//"Construtor" do cilindro
Cilindro* new_cilindro_pointer() {
    Cilindro *m1;

    m1->area = 0.0;
    strcpy(m1->material, "");
    m1->peso = 0.0;
    m1->volume = 0.0;

    return m1;
}

//"Construtor" do paralelepipedo
Paralelepipedo new_paralelepipedo() {
    Paralelepipedo m1;

    m1.area = 0.0;
    strcpy(m1.material, "");
    m1.peso = 0.0;
    m1.volume = 0.0;

    return m1;
}

//"Construtor" do paralelepipedo
Paralelepipedo* new_paralelepipedo_pointer() {
    Paralelepipedo *m1;

    m1->area = 0.0;
    strcpy(m1->material, "");
    m1->peso = 0.0;
    m1->volume = 0.0;

    return m1;
}

//Alocar memoria pra toda a estrutura de todas as casas
TodasAsCasas* new_todas_as_casas(TodasAsCasas *todasascasas) {
    Esfera esfera = new_esfera();
    Cilindro cilindro = new_cilindro();
    Paralelepipedo paralelepipedo = new_paralelepipedo();

    //Alocando espaco na memoria para casa alfa
    todasascasas->casaalfa = (CasaAlfa*)malloc(sizeof(CasaAlfa));
    todasascasas->casaalfa->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casaalfa->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casaalfa->lista->ultimo = todasascasas->casaalfa->lista->primeiro;

    //Alocando espaco na memoria para casa beta
    todasascasas->casabeta = (CasaBeta*)malloc(sizeof(CasaBeta));
    todasascasas->casabeta->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casabeta->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casabeta->lista->ultimo = todasascasas->casabeta->lista->primeiro;

    //Alocando espaco na memoria para casa chico
    todasascasas->casachico = (CasaChico*)malloc(sizeof(CasaChico));
    todasascasas->casachico->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casachico->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casachico->lista->ultimo = todasascasas->casachico->lista->primeiro;

    //Alocando espaco na memoria para casa joao
    todasascasas->casajoao = (CasaJoao*)malloc(sizeof(CasaJoao));
    todasascasas->casajoao->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casajoao->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casajoao->lista->ultimo = todasascasas->casajoao->lista->primeiro;

    //Alocando espaco na memoria para casa mane
    todasascasas->casamane = (CasaMane*)malloc(sizeof(CasaMane));
    todasascasas->casamane->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casamane->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casamane->lista->ultimo = todasascasas->casamane->lista->primeiro;

    //Alocando espaco na memoria para casa paulo
    todasascasas->casapaulo = (CasaPaulo*)malloc(sizeof(CasaPaulo));
    todasascasas->casapaulo->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casapaulo->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casapaulo->lista->ultimo = todasascasas->casapaulo->lista->primeiro;

    //Alocando espaco na memoria para casa ze
    todasascasas->casaze = (CasaZe*)malloc(sizeof(CasaZe));
    todasascasas->casaze->lista = (Lista*)malloc(sizeof(Lista));
    todasascasas->casaze->lista->primeiro = new_celula(&esfera, &cilindro, &paralelepipedo);
    todasascasas->casaze->lista->ultimo = todasascasas->casaze->lista->primeiro;

    return todasascasas;
}

void comprarTinta(TodasAsCasas *todasascasas, int valor, int opcaoTinta) {

    printf("\n- Identificamos que voce nao tem tinta suficiente!\n");
    do {
        printf("\nEscolha uma opcao de tinta para comprar \n");
        printf ( " 0 - Lata de tinta 10L (R$ 120,5)\n" );
        printf ( " 1 - Lata de tinta 4L (R$ 70,25)\n" );
        printf ( " 2 - Lata de tinta 1L (R$ 30,85)\n" );
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoTinta);

        if (opcaoTinta == 0) {
            tinta = tinta + 10;

            if (valor == 0) {
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + 120.5;
            } else if (valor == 1) {
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + 120.5;
            } else if (valor == 2) {
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + 120.5;
            } else if (valor == 3) {
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + 120.5;
            } else if (valor == 4) {
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + 120.5;
            } else if (valor == 5) {
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + 120.5;
            } else if (valor == 6) {
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + 120.5;
            }
        } else if (opcaoTinta == 1) {
            tinta = tinta + 4;
            
            if (valor == 0) {
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + 70.25;
            } else if (valor == 1) {
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + 70.25;
            } else if (valor == 2) {
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + 70.25;
            } else if (valor == 3) {
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + 70.25;
            } else if (valor == 4) {
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + 70.25;
            } else if (valor == 5) {
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + 70.25;
            } else if (valor == 6) {
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + 70.25;
            }
        } else if (opcaoTinta == 2) {
            tinta = tinta + 1;
            
            if (valor == 0) {
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + 30.85;
            } else if (valor == 1) {
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + 30.85;
            } else if (valor == 2) {
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + 30.85;
            } else if (valor == 3) {
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + 30.85;
            } else if (valor == 4) {
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + 30.85;
            } else if (valor == 5) {
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + 30.85;
            } else if (valor == 6) {
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + 30.85;
            }
        } else {
            printf("\nERRO: Voce nao escolheu uma das tintas oferecidas\n");
        }
    } while (opcaoTinta != 0 && opcaoTinta != 1 && opcaoTinta != 2);

    system("cls");
}

//Metodos e funcoes utilizadas no trabalho
void comprandoEsfera(TodasAsCasas *todasascasas, int valor, Cilindro *cilindro, Paralelepipedo *paralelepipedo) {
    system("cls");
    int opcao = -1;
    int opcaoTinta = -1;
    int precoAco = 0;
    int precoAluminio = 0;
    int precoCobre = 0;
    double raio = 0.0;
    double area = 0.0;
    double volume = 0.0;
    double consumo = 0.0;
    double tmp = 0.0;
    char material[30];

    //Verificar qual o tamanho da esfera
    printf("\nQual o raio da esfera : ");
    scanf("%lf", &raio);

    //Calcular area e volume
    area = 4 * PI * (pow(raio, 2));
    volume = ((double) 4/(double) 3) * PI * (pow(raio, 3));

    //Verificar qual opcao foi escolhida e atribuir valor as variaveis correspondentes
    if (valor == 0) {
        precoAco = 100;
        precoAluminio = 80;
        precoCobre = 130;
    } else if (valor == 1) {
        precoAco = 110;
        precoAluminio = 75;
        precoCobre = 120;
    } else if (valor == 2) {
        precoAco = 150;
        precoAluminio = 90;
        precoCobre = 115;
    } else if (valor == 3) {
        precoAco = 110;
        precoAluminio = 100;
        precoCobre = 160;
    } else if (valor == 4) {
        precoAco = 110;
        precoAluminio = 50;
        precoCobre = 160;
    } else if (valor == 5) {
        precoAco = 90;
        precoAluminio = 50;
        precoCobre = 110;
    } else if (valor == 6) {
        precoAco = 140;
        precoAluminio = 100;
        precoCobre = 180;
    }

    //Verificar qual material o cliente deseja comprar
    do {
        printf("\nQual o material da esfera ? \n");
        printf ( " 0 - Aco (R$ %d)\n", precoAco );
        printf ( " 1 - Aluminio (R$ %d)\n", precoAluminio );
        printf ( " 2 - Cobre (R$ %d)\n", precoCobre );
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        if (valor == 0) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casaze->lista, todasascasas->casaze->lista->ultimo->esfera, cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casaze->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casaze->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 1) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casapaulo->lista, todasascasas->casaze->lista->ultimo->esfera, cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casapaulo->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casapaulo->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 2) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casajoao->lista, todasascasas->casajoao->lista->ultimo->esfera, cilindro, paralelepipedo);
            
            //Atribuir volume
            todasascasas->casajoao->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casajoao->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 3) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casachico->lista, todasascasas->casachico->lista->ultimo->esfera, cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casachico->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casachico->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 4) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casamane->lista, todasascasas->casamane->lista->ultimo->esfera, cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casamane->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casamane->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 5) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casaalfa->lista, todasascasas->casaalfa->lista->ultimo->esfera, cilindro, paralelepipedo);
            
            //Atribuir volume
            todasascasas->casaalfa->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casaalfa->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 6) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casabeta->lista, todasascasas->casabeta->lista->ultimo->esfera, cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casabeta->lista->ultimo->esfera->volume = volume;

            //Atribuir area
            todasascasas->casabeta->lista->ultimo->esfera->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->esfera->material, "Aco");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->esfera->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->esfera->material, "Aluminio");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->esfera->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->esfera->material, "Cobre");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->esfera->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        }
    } while (opcao != 0 && opcao != 1 && opcao != 2);

    //Fazer a verificacao antes de comprar tinta
    if (opcao == 0) {
        tmp = 0.02;
    } else if (opcao == 1) {
        tmp = 0.01;
    } else {
        tmp = 0.015;
    }

    //Calculando consumo
    consumo = area * tmp;

    //Verificar a condicao para ver se precisa comprar mais tinta
    if (tinta == 0.0 || tinta - (consumo) <= 0) {
        do {
            printf("Consumo = %lfL\n", consumo);
            printf("Tinta atual = %lf\n", tinta);
            comprarTinta(todasascasas, valor, opcaoTinta);
        } while(tinta - consumo <= 0 || tinta == 0.0);
    }

    //Pintar a peca
    if (opcao == 0 || opcao == 1 || opcao == 2) {
        tinta = tinta - consumo;
        totalTinta = totalTinta + consumo;
    }

    system("cls");
}

void comprandoParalelepipedo(TodasAsCasas *todasascasas, int valor, Esfera *esfera, Cilindro *cilindro) {
    system("cls");
    int opcao = -1;
    int opcaoTinta = -1;
    int precoAco = 0;
    int precoAluminio = 0;
    int precoCobre = 0;
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double area = 0.0;
    double volume = 0.0;
    double consumo = 0.0;
    double tmp = 0.0;
    char material[30];

    //Verificar quais as dimensoes do paralelepipedo
    printf("\nQual o valor da altura : ");
    scanf("%lf", &a);
    printf("\nQual o valor da largura : ");
    scanf("%lf", &b);
    printf("\nQual o valor da profundidade : ");
    scanf("%lf", &c);

    //Calculando area e volume
    area = 2*(a*b) + 2*(b*c) + 2*(a*c);
    volume = a * b * c;

    //Verificar qual opcao foi escolhida e atribuir valor as variaveis correspondentes
    if (valor == 0) {
        precoAco = 100;
        precoAluminio = 80;
        precoCobre = 130;
    } else if (valor == 1) {
        precoAco = 110;
        precoAluminio = 75;
        precoCobre = 120;
    } else if (valor == 2) {
        precoAco = 150;
        precoAluminio = 90;
        precoCobre = 115;
    } else if (valor == 3) {
        precoAco = 110;
        precoAluminio = 100;
        precoCobre = 160;
    } else if (valor == 4) {
        precoAco = 110;
        precoAluminio = 50;
        precoCobre = 160;
    } else if (valor == 5) {
        precoAco = 90;
        precoAluminio = 50;
        precoCobre = 110;
    } else if (valor == 6) {
        precoAco = 140;
        precoAluminio = 100;
        precoCobre = 180;
    }

    //Verificar qual material o cliente deseja comprar
    do {
        printf("\nQual o material do paralelepipedo ? \n");
        printf ( " 0 - Aco (R$ %d)\n", precoAco );
        printf ( " 1 - Aluminio (R$ %d)\n", precoAluminio );
        printf ( " 2 - Cobre (R$ %d)\n", precoCobre );
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        if (valor == 0) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casaze->lista, esfera, cilindro, todasascasas->casaze->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casaze->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casaze->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 1) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casapaulo->lista, esfera, cilindro, todasascasas->casapaulo->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casapaulo->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casapaulo->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 2) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casajoao->lista, esfera, cilindro, todasascasas->casajoao->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casajoao->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casajoao->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 3) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casachico->lista, esfera, cilindro, todasascasas->casachico->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casachico->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casachico->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 4) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casamane->lista, esfera, cilindro, todasascasas->casamane->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casamane->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casamane->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 5) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casaalfa->lista, esfera, cilindro, todasascasas->casaalfa->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casaalfa->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casaalfa->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 6) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casabeta->lista, esfera, cilindro, todasascasas->casabeta->lista->ultimo->paralelepipedo);

            //Atribuir volume
            todasascasas->casabeta->lista->ultimo->paralelepipedo->volume = volume;

            //Atribuir area
            todasascasas->casabeta->lista->ultimo->paralelepipedo->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->paralelepipedo->material, "Aco");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->paralelepipedo->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->paralelepipedo->material, "Aluminio");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->paralelepipedo->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->paralelepipedo->material, "Cobre");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->paralelepipedo->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        }
    } while (opcao != 0 && opcao != 1 && opcao != 2);

    //Fazer a verificacao antes de comprar tinta
    if (opcao == 0) {
        tmp = 0.02;
    } else if (opcao == 1) {
        tmp = 0.01;
    } else {
        tmp = 0.015;
    }

    //Calculando consumo
    consumo = area * tmp;

    //Verificar a condicao para ver se precisa comprar mais tinta
    if (tinta == 0.0 || tinta - (consumo) <= 0) {
        do {
            printf("Consumo = %lfL\n", consumo);
            printf("Tinta atual = %lf\n", tinta);
            comprarTinta(todasascasas, valor, opcaoTinta);
        } while(tinta - consumo <= 0 || tinta == 0.0);
    }

    //Pintar a peca
    if (opcao == 0 || opcao == 1 || opcao == 2) {
        tinta = tinta - consumo;
        totalTinta = totalTinta + consumo;
    }

    system("cls");
}

void comprandoCilindro(TodasAsCasas *todasascasas, int valor, Esfera *esfera, Paralelepipedo *paralelepipedo) {
    system("cls");
    int opcao = -1;
    int opcaoTinta = -1;
    int precoAco = 0;
    int precoAluminio = 0;
    int precoCobre = 0;
    double raio = 0.0;
    double altura = 0.0;
    double area = 0.0;
    double volume = 0.0;
    double consumo = 0.0;
    double tmp = 0.0;
    char material[30];

    //Verificar qual as dimensoes do cilindro
    printf("\nQual o valor de raio : ");
    scanf("%lf", &raio);
    printf("\nQual o valor de altura : ");
    scanf("%lf", &altura);

    //Calculando area e volume
    area = 2 * (PI * (pow(raio, 2))) + 2 * (PI * raio * altura);
    volume = PI * (pow(raio, 2)) * altura;

    //Verificar qual opcao foi escolhida e atribuir valor as variaveis correspondentes
    if (valor == 0) {
        precoAco = 100;
        precoAluminio = 80;
        precoCobre = 130;
    } else if (valor == 1) {
        precoAco = 110;
        precoAluminio = 75;
        precoCobre = 120;
    } else if (valor == 2) {
        precoAco = 150;
        precoAluminio = 90;
        precoCobre = 115;
    } else if (valor == 3) {
        precoAco = 110;
        precoAluminio = 100;
        precoCobre = 160;
    } else if (valor == 4) {
        precoAco = 110;
        precoAluminio = 50;
        precoCobre = 160;
    } else if (valor == 5) {
        precoAco = 90;
        precoAluminio = 50;
        precoCobre = 110;
    } else if (valor == 6) {
        precoAco = 140;
        precoAluminio = 100;
        precoCobre = 180;
    }

    //Verificar qual material o cliente deseja comprar
    do {
        printf("\nQual o material do cilindro ? \n");
        printf ( " 0 - Aco (R$ %d)\n", precoAco );
        printf ( " 1 - Aluminio (R$ %d)\n", precoAluminio );
        printf ( " 2 - Cobre (R$ %d)\n", precoCobre );
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        if (valor == 0) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casaze->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casaze->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casaze->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaze->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casaze->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casaze->valorTotal = todasascasas->casaze->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 1) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casapaulo->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casapaulo->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casapaulo->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casapaulo->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casapaulo->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casapaulo->valorTotal = todasascasas->casapaulo->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 2) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casajoao->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casajoao->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casajoao->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casajoao->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casajoao->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casajoao->valorTotal = todasascasas->casajoao->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 3) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casachico->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casachico->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casachico->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casachico->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casachico->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casachico->valorTotal = todasascasas->casachico->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 4) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casamane->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casamane->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casamane->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casamane->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casamane->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casamane->valorTotal = todasascasas->casamane->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 5) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casaalfa->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casaalfa->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casaalfa->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casaalfa->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casaalfa->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casaalfa->valorTotal = todasascasas->casaalfa->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        } else if (valor == 6) {
            //Criar mais uma celula na lista
            inserir(todasascasas->casabeta->lista, esfera, todasascasas->casaze->lista->ultimo->cilindro, paralelepipedo);

            //Atribuir volume
            todasascasas->casabeta->lista->ultimo->cilindro->volume = volume;

            //Atribuir area
            todasascasas->casabeta->lista->ultimo->cilindro->area = area;
            if (opcao == 0) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->cilindro->material, "Aco");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->cilindro->peso = 7.8 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoAco;
            } else if (opcao == 1) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->cilindro->material, "Aluminio");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->cilindro->peso = 2.6 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoAluminio;
            } else if (opcao == 2) {
                //Copiar o nome para dentro do material
                strcpy(todasascasas->casabeta->lista->ultimo->cilindro->material, "Cobre");

                //Calcular o peso
                todasascasas->casabeta->lista->ultimo->cilindro->peso = 8.8 * volume;

                //Somar valor
                todasascasas->casabeta->valorTotal = todasascasas->casabeta->valorTotal + precoCobre;
            } else {
                printf("\nERRO: Voce nao escolheu um dos materiais oferecidos\n");
            }
        }
    } while (opcao != 0 && opcao != 1 && opcao != 2);

    //Ver qual material e utilizado na peca para saber o consumo
    if (opcao == 0) {
        tmp = 0.02;
    } else if (opcao == 1) {
        tmp = 0.01;
    } else {
        tmp = 0.015;
    }

    //Calculando consumo
    consumo = area * tmp;

    //Verificar a condicao para ver se precisa comprar mais tinta
    if (tinta == 0.0 || tinta - (consumo) <= 0) {
        do {
            printf("Consumo = %lfL\n", consumo);
            printf("Tinta atual = %lf\n", tinta);
            comprarTinta(todasascasas, valor, opcaoTinta);
        } while(tinta - consumo <= 0 || tinta == 0.0);
    }

    //Pintar a peca
    if (opcao == 0 || opcao == 1 || opcao == 2) {
        tinta = tinta - consumo;
        totalTinta = totalTinta + consumo;
    }

    system("cls");
}

//Faz porra nenhuma
void Sair() {

}

void initialCasas(TodasAsCasas *todasascosas, int valor, Esfera *esfera, Cilindro *cilindro, Paralelepipedo *paralelepipedo) {
    int x = 0;
    char casa[40] = "";

    //Verificar qual casa esta sendo tratada
    if (valor == 0) {
        strcpy(casa, "Casa Ze");
    } else if (valor == 1) {
        strcpy(casa, "Casa Paulo");
    } else if (valor == 2) {
        strcpy(casa, "Casa Joao");
    } else if (valor == 3) {
        strcpy(casa, "Casa Chico");
    } else if (valor == 4) {
        strcpy(casa, "Casa Mane");
    } else if (valor == 5) {
        strcpy(casa, "Casa Alfa");
    } else if (valor == 6) {
        strcpy(casa, "Casa Beta");
    }

    //Outro menu para fazer a escolha do solido desejado
    do {
        system("cls");
        printf ( "Bem vindo a %s\n", casa);
        printf ( "\n" ); 

        printf ( "Escolha uma opcao de solido para comprar: \n" );
        printf ( " 0 - Esfera\n" );
        printf ( " 1 - Paralelepipedo\n" );
        printf ( " 2 - Cilindro\n" );
        printf ( " 3 - Sair\n" );
        printf ( "\n" );

        printf("Entrar com uma opcao: ");
        scanf("%d", &x);

        switch(x) {
            case 0:
                comprandoEsfera(todasascosas, valor, cilindro, paralelepipedo);
            break;
            case 1:
                comprandoParalelepipedo(todasascosas, valor, esfera, cilindro);
            break;
            case 2:
                comprandoCilindro(todasascosas, valor, esfera, paralelepipedo);
            break;
            case 3:
                Sair();
            break;
            default:
            break;
            printf("ERRO: Valor invalido.");
        }
    } while (x != 3);

    printf("Apertar ENTER para terminar");
}

double calcularPesoTotalEstatua(TodasAsCasas *todasascasas, double *pesoTotal, double *pesoEsferasAco, double *pesoEsferasAluminio, double *pesoEsferasCobre, int *quantidadeEsferasAco, int *quantidadeEsferasAluminio, int *quantidadeEsferasCobre) {
    double pesoTotalSolidos = 0.0;
    double pesoTotalEsferasAco = 0.0;
    double pesoTotalEsferasAluminio = 0.0;
    double pesoTotalEsferasCobre = 0.0;
    int quantidadeTotalEsferasAco = 0;
    int quantidadeTotalEsferasAluminio = 0;
    int quantidadeTotalEsferasCobre = 0;

    //Calcular o peso total da casa alfa
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    //Calcular o peso total da casa beta
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    //Calcular o peso total da casa chico
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    //Calcular o peso total da casa joao
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    //Calcular o peso total da casa mane
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    //Calcular o peso total da casa paulo
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    //Calcular o peso total da casa ze
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        pesoTotalSolidos = pesoTotalSolidos + (i->cilindro->peso + i->esfera->peso + i->paralelepipedo->peso);
        
        if (strcmp(i->esfera->material, "Aco") == 0) {
            pesoTotalEsferasAco = pesoTotalEsferasAco + i->esfera->peso;
            quantidadeTotalEsferasAco++;
        } else if (strcmp(i->esfera->material, "Aluminio") == 0) {
            pesoTotalEsferasAluminio = pesoTotalEsferasAluminio + i->esfera->peso;
            quantidadeTotalEsferasAluminio++;
        } else if(strcmp(i->esfera->material, "Cobre") == 0) {
            pesoTotalEsferasCobre = pesoTotalEsferasCobre + i->esfera->peso;
            quantidadeTotalEsferasCobre++;
        }
    }

    *pesoTotal = pesoTotalSolidos;
    *pesoEsferasAco = pesoTotalEsferasAco;
    *pesoEsferasAluminio = pesoTotalEsferasAluminio;
    *pesoEsferasCobre = pesoTotalEsferasCobre;
    *quantidadeEsferasAco = quantidadeTotalEsferasAco;
    *quantidadeEsferasAluminio = quantidadeTotalEsferasAluminio;
    *quantidadeEsferasCobre = quantidadeTotalEsferasCobre;
}

void calcularMaiorPeso(TodasAsCasas *todasascasas, double *maiorPesoAco, double *maiorPesoAluminio, double *maiorPesoCobre) {
    double maiorAco = 0;
    double maiorAluminio = 0;
    double maiorCobre = 0;
    
    //Calcular o maior peso da casa alfa
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    //Calcular o maior peso da casa beta
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    //Calcular o maior peso da casa chico
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    //Calcular o maior peso da casa joao
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    //Calcular o maior peso da casa mane
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    //Calcular o maior peso da casa paulo
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    //Calcular o maior peso da casa ze
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior peso entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->peso > maiorAco) {
            maiorAco = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->peso > maiorAco) {
            maiorAco = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->peso > maiorAco) {
            maiorAco = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->peso > maiorAluminio) {
            maiorAluminio = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->peso > maiorAluminio) {
            maiorAluminio = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->peso > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->peso;
        }

        //Procurando o maior peso entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->peso > maiorCobre) {
            maiorCobre = i->cilindro->peso;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->peso > maiorCobre) {
            maiorCobre = i->esfera->peso;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->peso > maiorCobre) {
            maiorCobre = i->paralelepipedo->peso;
        }
    }

    *maiorPesoAco = maiorAco;
    *maiorPesoAluminio = maiorAluminio;
    *maiorPesoCobre = maiorCobre;
}

void calcularMaiorVolume(TodasAsCasas *todasascasas, double *maiorVolumeAco, double *maiorVolumeAluminio, double *maiorVolumeCobre) {
    double maiorAco = 0;
    double maiorAluminio = 0;
    double maiorCobre = 0;
    
    //Calcular o maior volume da casa alfa
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    //Calcular o maior volume da casa beta
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    //Calcular o maior volume da casa chico
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    //Calcular o maior volume da casa joao
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    //Calcular o maior volume da casa mane
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    //Calcular o maior volume da casa paulo
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    //Calcular o maior volume da casa ze
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o maior volume entre todos os solidos do tipo aco
        if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume > maiorAco) {
            maiorAco = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume > maiorAco) {
            maiorAco = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume > maiorAco) {
            maiorAco = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo aluminio
        if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume > maiorAluminio) {
            maiorAluminio = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume > maiorAluminio) {
            maiorAluminio = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume > maiorAluminio) {
            maiorAluminio = i->paralelepipedo->volume;
        }

        //Procurando o maior volume entre todos os solidos do tipo cobre
        if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume > maiorCobre) {
            maiorCobre = i->cilindro->volume;
        }

        if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume > maiorCobre) {
            maiorCobre = i->esfera->volume;
        }

        if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume > maiorCobre) {
            maiorCobre = i->paralelepipedo->volume;
        }
    }

    *maiorVolumeAco = maiorAco;
    *maiorVolumeAluminio = maiorAluminio;
    *maiorVolumeCobre = maiorCobre;
}

void calcularMenorVolume(TodasAsCasas *todasascasas, double *menorVolumeAco, double *menorVolumeAluminio, double *menorVolumeCobre) {
    double menorAco = 999999;
    double menorAluminio = 999999;
    double menorCobre = 999999;

    //Calcular o menor volume da casa alfa
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    //Calcular o menor volume da casa beta
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    //Calcular o menor volume da casa chico
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    //Calcular o menor volume da casa joao
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    //Calcular o menor volume da casa mane
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    //Calcular o menor volume da casa paulo
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    //Calcular o menor volume da casa ze
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Procurando o menor volume entre todos os solidos do tipo aco
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aco") == 0 && i->cilindro->volume < menorAco) {
                menorAco = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aco") == 0 && i->esfera->volume < menorAco) {
                menorAco = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aco") == 0 && i->paralelepipedo->volume < menorAco) {
                menorAco = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo aluminio
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Aluminio") == 0 && i->cilindro->volume < menorAluminio) {
                menorAluminio = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Aluminio") == 0 && i->esfera->volume < menorAluminio) {
                menorAluminio = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Aluminio") == 0 && i->paralelepipedo->volume < menorAluminio) {
                menorAluminio = i->paralelepipedo->volume;
            }
        }

        //Procurando o menor volume entre todos os solidos do tipo cobre
        if (i->cilindro->volume != 0.0) {
            if (strcmp(i->cilindro->material, "Cobre") == 0 && i->cilindro->volume < menorCobre) {
                menorCobre = i->cilindro->volume;
            }
        }

        if (i->esfera->volume != 0.0) {
            if (strcmp(i->esfera->material, "Cobre") == 0 && i->esfera->volume < menorCobre) {
                menorCobre = i->esfera->volume;
            }
        }

        if (i->paralelepipedo->volume != 0.0) {
            if (strcmp(i->paralelepipedo->material, "Cobre") == 0 && i->paralelepipedo->volume < menorCobre) {
                menorCobre = i->paralelepipedo->volume;
            }
        }
    }

    if (menorAco == 999999) {
        *menorVolumeAco = 0.0;
    } else {
        *menorVolumeAco = menorAco;
    }

    if (menorAluminio == 999999) {
        *menorVolumeAluminio = 0.0;
    } else {
        *menorVolumeAluminio = menorAluminio;
    }

    if (menorCobre == 999999) {
        *menorVolumeCobre = 0.0;
    } else {
        *menorVolumeCobre = menorCobre;
    }
}

void calcularQuantidadePecasCasaZe(TodasAsCasas *todasascasas, int *esferasCasaZe, int *paralelepipedosCasaZe, int *cilindrosCasaZe) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaZe = totalEsferas;
    *paralelepipedosCasaZe = totalParalelepipedos;
    *cilindrosCasaZe = totalCilindros;
}

void calcularQuantidadePecasCasaPaulo(TodasAsCasas *todasascasas, int *esferasCasaPaulo, int *paralelepipedosCasaPaulo, int *cilindrosCasaPaulo) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaPaulo = totalEsferas;
    *paralelepipedosCasaPaulo = totalParalelepipedos;
    *cilindrosCasaPaulo = totalCilindros;
}

void calcularQuantidadePecasCasaJoao(TodasAsCasas *todasascasas, int *esferasCasaJoao, int *paralelepipedosCasaJoao, int *cilindrosCasaJoao) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaJoao = totalEsferas;
    *paralelepipedosCasaJoao = totalParalelepipedos;
    *cilindrosCasaJoao = totalCilindros;
}

void calcularQuantidadePecasCasaChico(TodasAsCasas *todasascasas, int *esferasCasaChico, int *paralelepipedosCasaChico, int *cilindrosCasaChico) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaChico = totalEsferas;
    *paralelepipedosCasaChico = totalParalelepipedos;
    *cilindrosCasaChico = totalCilindros;
}

void calcularQuantidadePecasCasaMane(TodasAsCasas *todasascasas, int *esferasCasaMane, int *paralelepipedosCasaMane, int *cilindrosCasaMane) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaMane = totalEsferas;
    *paralelepipedosCasaMane = totalParalelepipedos;
    *cilindrosCasaMane = totalCilindros;
}

void calcularQuantidadePecasCasaAlfa(TodasAsCasas *todasascasas, int *esferasCasaAlfa, int *paralelepipedosCasaAlfa, int *cilindrosCasaAlfa) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaAlfa = totalEsferas;
    *paralelepipedosCasaAlfa = totalParalelepipedos;
    *cilindrosCasaAlfa = totalCilindros;
}

void calcularQuantidadePecasCasaBeta(TodasAsCasas *todasascasas, int *esferasCasaBeta, int *paralelepipedosCasaBeta, int *cilindrosCasaBeta) {
    int totalEsferas = 0;
    int totalParalelepipedos = 0;
    int totalCilindros = 0;
    
    //Calcular a quantidade de esferas, cilindros e paralelepipedos
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar se existe uma esfera na celula
        if (i->esfera->area != 0) {
            totalEsferas++;
        }

        //Verificar se existe um cilindro na celula
        if (i->cilindro->area != 0) {
            totalCilindros++;
        }

        //Verificar se existe um paralelepipedo na celula
        if (i->paralelepipedo->area != 0) {
            totalParalelepipedos++;
        }
    }

    *esferasCasaBeta = totalEsferas;
    *paralelepipedosCasaBeta = totalParalelepipedos;
    *cilindrosCasaBeta = totalCilindros;
}

void calcularMaiorVolumeTotal(TodasAsCasas *todasascasas, double *maiorVolume) {
    double maiorVolumeEncontrado = 0;

    //Calcular o maior volume da casa alfa
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    //Calcular o maior volume da casa beta
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    //Calcular o maior volume da casa chico
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    //Calcular o maior volume da casa joao
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    //Calcular o maior volume da casa mane
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    //Calcular o maior volume da casa paulo
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    //Calcular o maior volume da casa ze
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        //Verificar o maior volume do cilindro
        if (i->cilindro->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->cilindro->volume;
        }

        //Verificar o maior volume do paralelepipedo
        if (i->paralelepipedo->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->paralelepipedo->volume;
        }

        //Verificar o maior volume da esfera
        if (i->esfera->volume > maiorVolumeEncontrado) {
            maiorVolumeEncontrado = i->esfera->volume;
        }
    }

    *maiorVolume = maiorVolumeEncontrado;
}

void calcularVolumeVendas(TodasAsCasas *todasascasas, double *maiorVolumeVendas) {
    double maiorVendas = 0.0;

    if (todasascasas->casaalfa->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casaalfa->valorTotal;
    }

    if (todasascasas->casabeta->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casabeta->valorTotal;
    }

    if (todasascasas->casachico->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casachico->valorTotal;
    }

    if (todasascasas->casajoao->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casajoao->valorTotal;
    }

    if (todasascasas->casamane->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casamane->valorTotal;
    }

    if (todasascasas->casapaulo->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casapaulo->valorTotal;
    }

    if (todasascasas->casaze->valorTotal > maiorVendas) {
        maiorVendas = todasascasas->casaze->valorTotal;
    }

    *maiorVolumeVendas = maiorVendas;
}

void calcularMaiorCilindroVolume(TodasAsCasas *todasascasas, double *maiorCilindroVolume) {
    double maiorCilindro = 0.0;

    //Calcular o peso total da casa alfa
    for (Celula *i = todasascasas->casaalfa->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    //Calcular o peso total da casa beta
    for (Celula *i = todasascasas->casabeta->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    //Calcular o peso total da casa chico
    for (Celula *i = todasascasas->casachico->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    //Calcular o peso total da casa joao
    for (Celula *i = todasascasas->casajoao->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    //Calcular o peso total da casa mane
    for (Celula *i = todasascasas->casamane->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    //Calcular o peso total da casa paulo
    for (Celula *i = todasascasas->casapaulo->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    //Calcular o peso total da casa ze
    for (Celula *i = todasascasas->casaze->lista->primeiro->prox; i != NULL; i = i->prox) {
        if (i->cilindro->volume > maiorCilindro) {
            maiorCilindro = i->cilindro->volume;
        }
    }

    *maiorCilindroVolume = maiorCilindro;
}

//Calcular o peso medio de cada material de uma esfera
void calcularPesoMedio(TodasAsCasas *todasascasas, double *pesoMedioEsferasAco, double *pesoMedioEsferasAluminio, double *pesoMedioEsferasCobre, int *quantidadeEsferasAco, int *quantidadeEsferasAluminio, int *quantidadeEsferasCobre, double *pesoEsferasAco, double *pesoEsferasAluminio, double *pesoEsferasCobre) {
    if (quantidadeEsferasAco != 0) {
        *pesoMedioEsferasAco = (double) *pesoEsferasAco / (double) *quantidadeEsferasAco;
    } else {
        *pesoMedioEsferasAco = 0.0;
    }

    if (quantidadeEsferasAluminio != 0) {
        *pesoMedioEsferasAluminio = (double) *pesoEsferasAluminio / (double) *quantidadeEsferasAluminio;
    } else {
        *pesoMedioEsferasAco = 0.0;
    }

    if (quantidadeEsferasCobre != 0) {
        *pesoMedioEsferasCobre = (double) *pesoEsferasCobre / (double) *quantidadeEsferasCobre;
    } else {
        *pesoMedioEsferasAco = 0.0;
    }
}

void Relatorio(TodasAsCasas *todasascasas) {
    system("cls");
    int x = 0;
    double pesoTotal, pesoEsferasAco, pesoEsferasAluminio, pesoEsferasCobre = 0.0;
    int quantidadeEsferasAco, quantidadeEsferasAluminio, quantidadeEsferasCobre = 0;
    calcularPesoTotalEstatua(todasascasas, &pesoTotal, &pesoEsferasAco, &pesoEsferasAluminio, &pesoEsferasCobre, &quantidadeEsferasAco, &quantidadeEsferasAluminio, &quantidadeEsferasCobre);
    double maiorPesoAco, maiorPesoAluminio, maiorPesoCobre = 0.0;
    calcularMaiorPeso(todasascasas, &maiorPesoAco, &maiorPesoAluminio, &maiorPesoCobre);
    double maiorVolumeAco, maiorVolumeAluminio, maiorVolumeCobre = 0.0;
    calcularMaiorVolume(todasascasas, &maiorVolumeAco, &maiorVolumeAluminio, &maiorVolumeCobre);
    double menorVolumeAco, menorVolumeAluminio, menorVolumeCobre = 0.0;
    calcularMenorVolume(todasascasas, &menorVolumeAco, &menorVolumeAluminio, &menorVolumeCobre);
    int esferasCasaZe, paralelepipedosCasaZe, cilindrosCasaZe = 0;
    calcularQuantidadePecasCasaZe(todasascasas, &esferasCasaZe, &paralelepipedosCasaZe, &cilindrosCasaZe);
    int esferasCasaPaulo, paralelepipedosCasaPaulo, cilindrosCasaPaulo = 0;
    calcularQuantidadePecasCasaPaulo(todasascasas, &esferasCasaPaulo, &paralelepipedosCasaPaulo, &cilindrosCasaPaulo);
    int esferasCasaJoao, paralelepipedosCasaJoao, cilindrosCasaJoao = 0;
    calcularQuantidadePecasCasaJoao(todasascasas, &esferasCasaJoao, &paralelepipedosCasaJoao, &cilindrosCasaJoao);
    int esferasCasaChico, paralelepipedosCasaChico, cilindrosCasaChico = 0;
    calcularQuantidadePecasCasaChico(todasascasas, &esferasCasaChico, &paralelepipedosCasaChico, &cilindrosCasaChico);
    int esferasCasaMane, paralelepipedosCasaMane, cilindrosCasaMane = 0;
    calcularQuantidadePecasCasaMane(todasascasas, &esferasCasaMane, &paralelepipedosCasaMane, &cilindrosCasaMane);
    int esferasCasaAlfa, paralelepipedosCasaAlfa, cilindrosCasaAlfa = 0;
    calcularQuantidadePecasCasaAlfa(todasascasas, &esferasCasaAlfa, &paralelepipedosCasaAlfa, &cilindrosCasaAlfa);
    int esferasCasaBeta, paralelepipedosCasaBeta, cilindrosCasaBeta = 0;
    calcularQuantidadePecasCasaBeta(todasascasas, &esferasCasaBeta, &paralelepipedosCasaBeta, &cilindrosCasaBeta);
    double maiorVolume = 0.0;
    calcularMaiorVolumeTotal(todasascasas, &maiorVolume);
    double maiorCilindroVolume = 0.0;
    calcularMaiorCilindroVolume(todasascasas, &maiorCilindroVolume);
    double pesoMedioEsferasAco, pesoMedioEsferasAluminio, pesoMedioEsferasCobre = 0.0;
    calcularPesoMedio(todasascasas, &pesoMedioEsferasAco, &pesoMedioEsferasAluminio, &pesoMedioEsferasCobre, &quantidadeEsferasAco, &quantidadeEsferasAluminio, &quantidadeEsferasCobre, &pesoEsferasAco, &pesoEsferasAluminio, &pesoEsferasCobre);

    //Calcular o valor total gasto na construção da estatua
    double valorTotalGasto = todasascasas->casaalfa->valorTotal + todasascasas->casabeta->valorTotal + todasascasas->casachico->valorTotal + todasascasas->casajoao->valorTotal + todasascasas->casamane->valorTotal + todasascasas->casapaulo->valorTotal + todasascasas->casaze->valorTotal;
    
    //Maior volume de vendas
    double maiorVolumeVendas = 0.0;
    calcularVolumeVendas(todasascasas, &maiorVolumeVendas);

    do {
        system("cls");
        printf("- Peso total da estatua = %lf KG\n", pesoTotal/1000);
        printf("- Maior peca em peso de cada material = Aco[%lf KG] Aluminio[%lf KG] Cobre[%lf KG]\n", maiorPesoAco/1000, maiorPesoAluminio/1000, maiorPesoCobre/1000);
        printf("- Maior peca em volume de cada material = Aco[%lf] Aluminio[%lf] Cobre[%lf]\n", maiorVolumeAco, maiorVolumeAluminio, maiorVolumeCobre);
        printf("- Menor peca em volume de cada material = Aco[%lf] Aluminio[%lf] Cobre[%lf]\n", menorVolumeAco, menorVolumeAluminio, menorVolumeCobre);
        printf("- Quantidade de pecas compradas Casa Ze = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaZe, paralelepipedosCasaZe, cilindrosCasaZe);
        printf("- Quantidade de pecas compradas Casa Paulo = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaPaulo, paralelepipedosCasaPaulo, cilindrosCasaPaulo);
        printf("- Quantidade de pecas compradas Casa Joao = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaJoao, paralelepipedosCasaJoao, cilindrosCasaJoao);
        printf("- Quantidade de pecas compradas Casa Chico = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaChico, paralelepipedosCasaChico, cilindrosCasaChico);
        printf("- Quantidade de pecas compradas Casa Mane = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaMane, paralelepipedosCasaMane, cilindrosCasaMane);
        printf("- Quantidade de pecas compradas Casa Alfa = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaAlfa, paralelepipedosCasaAlfa, cilindrosCasaAlfa);
        printf("- Quantidade de pecas compradas Casa Beta = Esfera[%d] Paralelepipedo[%d] Cilindro[%d]\n", esferasCasaBeta, paralelepipedosCasaBeta, cilindrosCasaBeta);
        printf("- Total de tinta gasta para pintar as pecas = %lf L\n", totalTinta);
        printf("- Valor a ser pago a Casa Ze = R$ %lf\n", todasascasas->casaze->valorTotal);
        printf("- Valor a ser pago a Casa Paulo = R$ %lf\n", todasascasas->casapaulo->valorTotal);
        printf("- Valor a ser pago a Casa Joao = R$ %lf\n", todasascasas->casajoao->valorTotal);
        printf("- Valor a ser pago a Casa Chico = R$ %lf\n", todasascasas->casachico->valorTotal);
        printf("- Valor a ser pago a Casa Mane = R$ %lf\n", todasascasas->casamane->valorTotal);
        printf("- Valor a ser pago a Casa Alfa = R$ %lf\n", todasascasas->casaalfa->valorTotal);
        printf("- Valor a ser pago a Casa Beta = R$ %lf\n", todasascasas->casabeta->valorTotal);
        printf("- Peso medio das esferas de cada material = Aco[%lf KG] Aluminio[%lf KG] Cobre[%lf KG]\n", pesoMedioEsferasAco/1000, pesoMedioEsferasAluminio/1000, pesoMedioEsferasCobre/1000);
        printf("- O maior cilindro em volume = %lf\n", maiorCilindroVolume);
        printf("- Valor total gasto na construcao da estatua = R$ %lf\n", valorTotalGasto);
        printf("- Loja que obteve o maior volume de vendas = R$ %lf\n", maiorVolumeVendas);

        printf ( "\nEscolha uma opcao:" );
        printf ( "\n0 - Sair\n" );
        printf ( "\n" );

        printf("Entrar com uma opcao: ");
        scanf("%d", &x);
        system("cls");

        switch(x) {
            case 0:
                Sair();
            break;
            default:
            break;
            printf("ERRO: Valor invalido.");
        }
    } while (x != 0);

    system("cls");
}

int main(void) {
    system("cls");
    //Declarando a estrutura que contem todas as casas e alocando memoria
    TodasAsCasas *todasascasas;
    todasascasas = (TodasAsCasas*) malloc (sizeof(TodasAsCasas));

    //"Construtor" dessa estrutura muito louca
    todasascasas = new_todas_as_casas(todasascasas);

    //Definindo o valor total igual a zero
    todasascasas->casaalfa->valorTotal = 0.0;
    todasascasas->casabeta->valorTotal = 0.0;
    todasascasas->casamane->valorTotal = 0.0;
    todasascasas->casachico->valorTotal = 0.0;
    todasascasas->casajoao->valorTotal = 0.0;
    todasascasas->casapaulo->valorTotal = 0.0;
    todasascasas->casaze->valorTotal = 0.0;

    //Estruturas usadas para zerar alguns valores das celulas
    Esfera esfera = new_esfera();
    Cilindro cilindro = new_cilindro();
    Paralelepipedo paralelepipedo = new_paralelepipedo();

    int x = 0;

    //Menu inicial
    do {
        system("cls");
        printf ( "Trabalho Pratico\n");
        printf ( "\n" );

        printf ( "Escolha uma casa para comprar os materiais: \n" );
        printf ( " 0 - Casa Ze\n" );
        printf ( " 1 - Casa Paulo\n" );
        printf ( " 2 - Casa Joao\n" );
        printf ( " 3 - Casa Chico\n" );
        printf ( " 4 - Casa Mane\n" );
        printf ( " 5 - Casa Alfa\n" );
        printf ( " 6 - Casa Beta\n" );
        printf ( " 7 - Relatorio\n" );
        printf ( " 8 - Sair do programa\n" );
        printf ( "\n" );
        
        printf("Entrar com uma opcao: ");
        scanf("%d", &x);
        system("cls");

        switch(x) {
            case 0:
                initialCasas(todasascasas, 0, &esfera, &cilindro, &paralelepipedo);
            break;
            case 1:
                initialCasas(todasascasas, 1, &esfera, &cilindro, &paralelepipedo);
            break;
            case 2:
                initialCasas(todasascasas, 2, &esfera, &cilindro, &paralelepipedo);
            break;
            case 3:
                initialCasas(todasascasas, 3, &esfera, &cilindro, &paralelepipedo);
            break;
            case 4:
                initialCasas(todasascasas, 4, &esfera, &cilindro, &paralelepipedo);
            break;
            case 5:
                initialCasas(todasascasas, 5, &esfera, &cilindro, &paralelepipedo);
            break;
            case 6:
                initialCasas(todasascasas, 6, &esfera, &cilindro, &paralelepipedo);
            break;
            case 7:
                Relatorio(todasascasas);
            break;
            case 8:
                Sair();
            break;
            default:
            break;
            printf("ERRO: Valor invalido.");
        }
    } while (x != 8);

    //Liberando espaco na memoria que foi utilizado durante a execucao do programa
    free(todasascasas);

    return 0;
}
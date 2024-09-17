#include <stdio.h>
#include <stdlib.h>

typedef struct Venda{
    int nota;
    int vendedor;
    int data;
    int valor;
}temp;


typedef struct TreeReg{
    struct TreeReg *Pai;
    struct TreeReg *Esq;
    struct TreeReg *Dir;
    struct Venda Dado;
}reg;


int qntdias(int mes);
temp* criaAB(int dado);

void main(){
    int dias,qntfunc,temp;
    do{
        printf("Entre com o mes em que as vendas foram realizadas: ");
        scanf("%i",&dias);printf("\n\n");

        if (dias<=0 || dias>12){
            printf("Mes deve ser maior ou igual a 1 e menor ou igual a 12\n\n");
        }
    }while(dias<=0 || dias>12);

    dias = qntdias(dias);
    do{
        printf("Entre com o numero de vendedores que trabalharam no mes: ");
        scanf("%i",&qntfunc);printf("\n\n");

        if(qntfunc<1){
            printf("Numero de vendedores deve ser maior do que zero\n\n");
        }
    }while(qntfunc<1);

    printf("Entre com as vendas. Para cada venda realizada no mes informar o numero da nota fiscal que a identifica, o codigo do vendedor responsavel, o dia do mes em que foi feita e o valor da venda em reais. Quando desejar finalizar a entrada de dados digite o numero zero para a nota fiscal.\n\n");
        do{
            printf("Venda: ");
            scanf("%i",&temp);
            if (temp==0){
                continue;
            }


        }while(temp!=0);

}

int qntdias(int mes){
    int dias;
    if (mes==2){
        dias = 28;
        return dias;
    }
    if (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        dias = 31;
        return dias;
    }else{
        dias = 30;
        return dias;
    }
    return dias;
}

temp* criaAB(struct Venda dado){
	reg *tree = (temp*)malloc(sizeof(temp));    // Aloca memória para o novo nó.

	tree->Dado = dado;   // Define o dado do nó.

	tree->Esq = NULL;    // Inicializa os filhos da esquerda e direita e o pai como NULL.
	tree->Dir = NULL;
	tree->Pai = NULL;
	return tree;
}

int insereAB(reg *raiz, struct Venda dado)
{
	if (raiz->Dado.nota == dado.nota)
		return 0;
	else {
		if (dado.nota > raiz->Dado.nota){
			if (direita(raiz) != NULL){
				raiz = direita(raiz);
				insereAB(raiz, dado);
			}
			else {
				filhoDir(raiz, dado);
				return 1;
			}
		} else {
			if (esquerda(raiz) != NULL){
				raiz = esquerda(raiz);
				insereAB(raiz, dado);
			}
			else {
				filhoEsq(raiz, dado);
				return 1;
			}
		}
	}
}

int filhoEsq(reg *raiz, struct Venda dado)
{
	reg *node = criaAB(dado);
	if (raiz->Esq == NULL){
		raiz->Esq = node;
		raiz->Esq->Pai = raiz;
		return 1;
	} else {
		return 0;
	}
}

int filhoDir(reg *raiz, struct Venda dado)
{
	reg *node = criaAB(dado);
	if (raiz->Dir == NULL){
		raiz->Dir = node;
		raiz->Dir->Pai = raiz;
		return 1;
	} else {
		return 0;
	}
}

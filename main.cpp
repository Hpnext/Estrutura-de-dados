#include <iostream>
#include<string.h>
using namespace std;

typedef struct elemento{
	int conteudo;
	struct elemento *prox;
}elemento;

typedef struct pilha{
	struct elemento *topo;
}pilha;


elemento *criar_elemento(int c){

	elemento *e = (elemento *) malloc (sizeof(elemento));
	e->conteudo = c;
	e->prox = NULL;

	return e;

}

pilha *criar_pilha(){
	pilha *p = (pilha *) malloc (sizeof(pilha));
	p->topo = NULL;

	return p;
}

void
imprime(pilha *p){


	if(p->topo == NULL){
		printf("Lista vazia...\n");
	}else{
		elemento *aux = p->topo;
		while(aux != NULL){
      cout<<aux->conteudo<<" ";


			aux = aux->prox;

		}

		cout<<endl;

	}
}
int pegar_topo(pilha *p){
int b;
  elemento *aux = p->topo;
b=aux->conteudo;
			return b;

}

void
empilhar(elemento *e, pilha *p){
	e->prox = p->topo;
	p->topo = e;
}
void insere_fim(elemento *e, pilha *fila ){
	if (fila->topo == NULL){
		fila->topo = e;
	}else{
		elemento *aux = fila->topo;
		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = e;
	}
}

int remove_topo(pilha *p){
  int valor=0;
	if(p->topo != NULL){
		elemento *aux = p->topo;
    valor=aux->conteudo;
	       	p->topo = aux->prox;
		free(aux);

	}
  return valor;

}
void remove_todos(pilha *p){
  while(p->topo!=NULL){
     remove_topo(p);
  }
  }


float *
getElements(char *line, int *tamanho){
	float *elementos = (float *) malloc (0*sizeof(float));
	int i = 0;

	char* token = strtok(line, " ");
	while (token) {
		i += 1;
		elementos = (float *) realloc (elementos, sizeof(int)*i);
		elementos[i-1] = atof(token);
		token = strtok(NULL, " ");
        }

	*tamanho = i;
	free(token);
	return (elementos);

}
int  pega_final(pilha *p){
  int b;
if(p->topo != NULL){
elemento *aux = p->topo;
while (aux->prox->prox!=NULL){
    aux=aux->prox;
}
 b=aux->prox->conteudo;
  free(aux->prox);
  aux->prox=NULL;



}
   return b;
  }





void  imprimir_inversa(pilha *p){
  int b;
  elemento *aux = p->topo;
  while(p->topo->prox!=NULL){
    while (aux->prox->prox!=NULL){
    aux=aux->prox;
}
 b=aux->prox->conteudo;
  free(aux->prox);
  aux->prox=NULL;

cout<<b<<" ";

  aux=p->topo;

    }

   b=pegar_topo(p);
  cout<<b;
  remove_topo(p);



cout<<endl;

  }

void colocar_fila(pilha *p, pilha *p2, pilha *fila, pilha *fila2){
elemento *aux=p->topo;
  while(aux->prox!=NULL){
    empilhar(criar_elemento(aux->conteudo),fila);

    aux=aux->prox;
  }
  empilhar(criar_elemento(aux->conteudo),fila);
  aux=p2->topo;
   while(aux->prox!=NULL){
    empilhar(criar_elemento(aux->conteudo),fila2);

    aux=aux->prox;
  }
    empilhar(criar_elemento(aux->conteudo),fila2);


}
void alocar_terceira_fila(pilha *fila, pilha *fila2, pilha *fila3){
  int a=0;
elemento *aux=fila->topo;
elemento *aux2=fila2->topo;
while(aux->prox!=NULL && aux2->prox!=NULL){
insere_fim(criar_elemento(aux->conteudo),fila3);
  insere_fim(criar_elemento(aux2->conteudo),fila3);
  aux=aux->prox;
  aux2=aux2->prox;
}
if (aux->prox==NULL && aux2->prox==NULL){
insere_fim(criar_elemento(aux->conteudo),fila3);
  insere_fim(criar_elemento(aux2->conteudo),fila3);

}


else if(aux2->prox==NULL){

  while(aux->prox!=NULL){
   insere_fim(criar_elemento(aux->conteudo),fila3);
    if(a==0){
      insere_fim(criar_elemento(aux2->conteudo),fila3);
      a++;
    }
    aux=aux->prox;
    }
  insere_fim(criar_elemento(aux->conteudo),fila3);
    }
else if (aux->prox==NULL){
  insere_fim(criar_elemento(aux->conteudo),fila3);
   while(aux2->prox!=NULL){
   insere_fim(criar_elemento(aux2->conteudo),fila3);
     aux2=aux2->prox;
}
  insere_fim(criar_elemento(aux2->conteudo),fila3);
}
  }





int
main(void){


  int contador=0;

	pilha *p = criar_pilha();
  pilha *p2=criar_pilha();
  pilha *fila=criar_pilha();
  pilha *fila2=criar_pilha();
  pilha *fila3=criar_pilha();

	char *line = NULL;
	size_t len = 0;
	getline(&line, &len, stdin);

	int total_linhas = atoi(line);


	for(int j = 0; j < total_linhas; j++){


		int *tamanho = (int *) malloc (1*sizeof(int));

		line = NULL;
		len = 0;
		getline(&line, &len, stdin);
		float* elementos = getElements(line, tamanho);


		for(int i = 0; i < *tamanho; i++){
      if(j==0)
      empilhar(criar_elemento(elementos[i]), p);
      else{
        empilhar(criar_elemento(elementos[i]), p2);

       contador++;
      }



		}

		free(elementos);
		free(tamanho);

	}

	free(line);

  colocar_fila(p,p2,fila,fila2);
  imprimir_inversa(p);
 imprimir_inversa(p2);
   imprime(fila);
  imprime(fila2);
 alocar_terceira_fila(fila,fila2,fila3);
  imprime(fila3);
  remove_todos(fila);
  remove_todos(fila2);
  remove_todos(fila3);

	return EXIT_SUCCESS;

}

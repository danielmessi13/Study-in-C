#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Novo {
	public:
		int mat;
		string nome;
		Novo *prox;

		Novo(int m, string palavra) {
			mat = m;
			nome = palavra;
			prox = NULL;
		}	
};

class Lista {
	private:
		Novo *inicio;
		Novo *fim;
	
	public:
	    Lista() {
	    	inicio = NULL;
	    	fim = NULL;
		}

		void pushFront(Novo *novo) {
			if (inicio == NULL)
				fim = novo;
			novo->prox = inicio;
			inicio = novo;
		}
		
		void pushBack(Novo *novo) {
			if (inicio == NULL) {
				inicio = novo;
				fim = novo;
			} else {
				fim -> prox = novo;
				fim = novo;
			}
		}
		
		void pushOrd(Novo *novo) {
			ordena();
			
			Novo *auxiliar;
			auxiliar = new Novo(0, "Auxilar");
			auxiliar->prox = inicio;
			
			while (auxiliar->prox != NULL) {
				if (auxiliar->prox->mat > novo->mat) {
					if (auxiliar->prox == inicio) {
						novo->prox = inicio;
						inicio = novo;
					} else {
						novo->prox = auxiliar->prox;
						auxiliar->prox = novo;
					}
					break;
				}
				if (auxiliar->prox == fim) {
					fim->prox = novo;
					fim = novo;
					break;
				}
				auxiliar = auxiliar->prox;
			}
		}
		
		void imprimeNomes() {
			Novo *aux = inicio;
			while (aux != NULL) {
				cout << aux->nome << endl;
				aux = aux->prox;
			}
		}
		
		void inverte() {
			Novo *anterior, *atual, *temp;
			anterior = NULL;
			atual = inicio;

			while (atual != NULL) {
				temp = atual->prox;
				atual->prox = anterior;
				anterior = atual;
				
				atual = temp;
			}
			temp = inicio;
			inicio = fim;
			fim = temp;
		}
		
		void ordena() {
			Novo *auxiliar, *auxiliar2, *temp;
			auxiliar = new Novo(0, "Auxiliar");
			auxiliar->prox = inicio;
			auxiliar2 = inicio;
			
			bool primeiro = true;
			while (auxiliar->prox->prox != NULL) {
				if (auxiliar->prox != inicio) {
					primeiro = false;
				}
				while (auxiliar2->prox != NULL) {
					if (auxiliar->prox->mat > auxiliar2->prox->mat) {
						if (auxiliar2 == auxiliar->prox) {
							temp = auxiliar2->prox;
							auxiliar2->prox = auxiliar2->prox->prox;
							temp->prox = auxiliar->prox;
							auxiliar->prox = temp;
							auxiliar2 = auxiliar->prox;
						} else {
							temp = auxiliar2->prox->prox;
							auxiliar2->prox->prox = auxiliar->prox->prox;
							auxiliar->prox->prox = temp;
							
							temp = auxiliar2->prox;
							auxiliar2->prox = auxiliar->prox;
							auxiliar->prox = temp;
						}
					}
					auxiliar2 = auxiliar2->prox;
				}
				if (primeiro){
					inicio = auxiliar->prox;
					free(auxiliar);
					auxiliar = inicio;
				} else {
				auxiliar = auxiliar->prox;
				auxiliar2 = auxiliar->prox;
				}
			}
			fim = auxiliar2;
		}
	
		void remover(int matricula) {
			Novo *anterior, *atual;
			anterior = NULL;
			atual = inicio;
			
			while (atual != NULL) {
				if (atual->mat == matricula) {
					if (anterior == NULL) {
						inicio = atual->prox;
					} else {
						anterior->prox = atual->prox;
					}
					if(atual == fim) {
						fim = anterior;
					}
					break;
				}
				anterior = atual;
				atual = atual->prox;
			}
		}
	
		int consultar(int matricula) {
			Novo *auxiliar = inicio;
			
			while (auxiliar != NULL) {
				if (auxiliar->mat == matricula) {
					cout<<"Nome: "<<auxiliar->nome<<endl<<"Matricula: "<<auxiliar->mat<<endl;
					return -1;
				}
				auxiliar = auxiliar->prox;
			}
			cout<<"Aluno inexistente!"<<endl;
			return -1;
		}

		void listar() {
			Novo *auxiliar = inicio;
			
			while (auxiliar != NULL) {
				cout<< "Nome: "<< auxiliar->nome<< endl<< "Matricula: "<< auxiliar->mat<< endl<<endl;
				auxiliar = auxiliar->prox;
			}
		}
		
};

main() {
	Lista *lista = new Lista();

		
	Novo *novo = new Novo(0, "Daniel");
	lista->pushFront(novo);
	novo = new Novo(2, "Vini");
	lista->pushBack(novo);
	novo = new Novo(1, "Filipe");
	lista->pushBack(novo);
	novo = new Novo(3, "Micael");
	lista->pushBack(novo);
	
	lista->ordena();
	lista->imprimeNomes();	
	cout<<endl;
	
	lista->inverte();
	lista->imprimeNomes();	
	cout<<endl;
	
	novo = new Novo(5, "Jesus");
	lista->pushOrd(novo);
	
	novo = new Novo(4, "Paulo");
	lista->pushOrd(novo);
	
	novo = new Novo(-1, "Marcelo");
	lista->pushOrd(novo);
	
	lista->imprimeNomes();	
	cout<<endl;
	
	lista->remover(-1);
	lista->imprimeNomes();
	cout<<endl;
	
	lista->consultar(-1);
	cout<<endl;
	
	lista->listar();

}



#include <iostream>
#include <cstring>

using namespace std;

class Delimitador{

	private:
		char delimitador;

	public:
		Delimitador *anterior;

		Delimitador(char delimi){
			delimitador = delimi;
			anterior = NULL;

		}


		char getChar(){
			return delimitador;
		}


};

class Pilha{

	private:

		Delimitador *topo;
		int quant;

	public:

		Pilha(){
			topo = NULL;
			quant = 0;
		}
		void empilhar(Delimitador *novo){
			novo->anterior = topo;
			topo = novo;
			quant++;
		}

		void desempilhar(){
			if (quant > 0){
				Delimitador *aux = topo;
				aux = topo;
				topo = topo->anterior;
				aux = NULL;
				quant--;
			}
		}

		void mostrar(){
			Delimitador *aux = topo;
			while(aux != NULL){
				cout << aux->getChar();
				aux = aux->anterior;

			}
		}

		bool combina(char x){
			if (x == topo->getChar()){
				return true;
			}
			return false;
		}


		int getQuant(){
			return quant;
		}
};

bool isTheDelimitador(char x){
	if(x == '(' || x == '{' || x == '['){
		return true;
	}
	return false;
}

bool isTheClose(char x){
	if(x == ')' || x == '}' || x == ']'){
		return true;
	}
	return false;
}

char pegaOposto(char x) {
    if (x == '(')
        return ')';
    if (x == '[')
        return ']';
    if (x == '{')
        return '}';
}

main(){

	Pilha pilha1;
	Delimitador *delimitador;

	char expressao [30];

	cout << "Digite a expressao" << endl;
	cin.getline(expressao,30);

	for (int i = 0; i < strlen(expressao); i++){
		if (isTheDelimitador(expressao[i])){
			delimitador = new Delimitador(pegaOposto(expressao[i]));
			pilha1.empilhar(delimitador);
		}else if (isTheClose(expressao[i])){
			if (pilha1.combina(expressao[i])){
				pilha1.desempilhar();
			}
		}
	}

    if (pilha1.getQuant() == 0){
        cout << "Expressão correta!";
    }else{
        cout << "Expressão incorreta!";
    }
}

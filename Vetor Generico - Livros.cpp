#include <stdio.h>
#include <iostream>

using namespace std;

template <class Trans>
class Lista{
	private:
		int ultimo;
	public:
		Trans v[30];
		Trans deletado;	
	
		Lista(){
		   	ultimo = 0;
		}	
		
		void inserir(Trans e){
			v[ultimo] = e;
			ultimo++;
		}
		
		int len(){
			return ultimo;
		}
		
		Trans get(int i){      			
			return v[i];

		}
			
		Trans pop(int p = -1){
			if (p == -1){
				p = ultimo;
			}
			
			for (int i = p; i < ultimo; i++){
				v[i] = v[i+1];
			}
			
			ultimo--;
			deletado = v[ultimo-1];
			return deletado;
		}
};

typedef struct Livro
	{
		int codigo;
		string nome;
		double valor;
	}Livro; 

main(){
	
	// A class com o struct Livro
	Lista <Livro> livros;
	
	// Criando classes
	Livro l1;
	l1.codigo = 1;
	l1.nome = "Algoritmos 10/10";
	l1.valor = 10;
	
	Livro l2;
	l2.codigo = 2;
	l2.nome = "Como treinar seu dragão";
	l2.valor = 1000;
	
	Livro l3;
	l3.codigo = 3;
	l3.nome = "Biografia de Dorgival Dantas";
	l3.valor = 9999;
	
	// Inserindo
	livros.inserir(l1);
	livros.inserir(l2);
	livros.inserir(l3);
	
	// Printando
	cout << livros.get(0).codigo << endl;
	cout << livros.get(0).nome << endl;
	cout << livros.get(0).valor << endl;
	cout << endl;
	
	cout << livros.get(1).codigo << endl;
	cout << livros.get(1).nome << endl;
	cout << livros.get(1).valor << endl;
	cout << endl;
	
	cout << livros.get(2).codigo << endl;
	cout << livros.get(2).nome << endl;
	cout << livros.get(2).valor << endl;
	cout << endl;
	
	// Quantidade de livros
	cout << livros.len() << endl;
}
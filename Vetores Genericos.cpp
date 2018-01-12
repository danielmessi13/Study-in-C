#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

template <class Transgenico>

class Lista{
    public:
        Transgenico vetor[30];
        int ultimo = 0;



        void append(Transgenico e){
            vetor[ultimo] = e;
            ultimo++;
        }

        Transgenico pop(int p = -1){
            if (p == -1)
                p =  ultimo-1;

            Transgenico v = vetor[p];
            for (int i = p; i < ultimo; i++)
                vetor[i] = vetor[i+1];
            ultimo--;
            return v;
        }

        int index(Transgenico valor){
            for(int i = 0; i < ultimo; i++){
                if (vetor[i] == valor)
                    return i;
            }
            return -1;
        }

        void remove(Transgenico valor){
           int p = index(valor);
           if (p != -1){
              for(int i = p; i < ultimo; i++)
                  vetor[i] = vetor[i+1];
               ultimo--;
            }
        }

        void inserir(int p, Transgenico valor){
            for(int i = ultimo; i > p; i--)
                vetor[i] = vetor[i-1];
            ultimo++;
            vetor[p]=valor;
        }

        int count(Transgenico valor){
            int cont = 0;
            for(int i = 0; i < ultimo; i++){
                if (vetor[i] == valor)
                   cont++;
            }
            return cont;
        }

        void percorre(){
            for(int i=0;i<ultimo;i++){
                cout<< vetor[i];
            }
        }

        int len(){
            return ultimo;
        }

};


typedef struct aluno{
	int mat;
	string nome;
}Aluno;


main(){
    Lista<Aluno> l1;

    Aluno a1;
    a1.mat = 123;
    a1.nome = "micael";

    //cout<<a1[0]<<endl;

}

#include <iostream>

using namespace std;


template<class T>
class Novo {
	public:
		T valor;
		Novo <T> *left,*right;
		Novo(){
			left = right = NULL;
		}
		Novo(T e, Novo<T> *l = NULL, Novo <T> *r = NULL){
			valor = e;
			left = l;
			right = r;
		}
};

template<class T>
class Arvore {
	protected:
		Novo <T> *root;
	public:
		Arvore(){
			root = NULL;
		}

		~Arvore(){
			clear();
		}

		void clear(){
			clear(root);
			root = 0;
		}

		bool isEmpty() const {
		   return root = NULL;
        }

		void visit(Novo <T> *p){
			cout << p->valor << " ";
		}

		void insertSemRecursao(T valor){
		    Novo <T> *aux = root;
		    while (true){
                if (root == NULL){
                    root = new Novo <T>(valor);
                    break;
                }if (valor < aux->valor){
                    if (aux->left == NULL){
                        aux->left = new Novo <T>(valor);
                        break;
                    }
                    aux = aux->left;
                }else if (valor > aux->valor){
                    if (aux->right == NULL){
                        aux->right = new Novo <T>(valor);
                        break;
                    }
                    aux = aux->right;
                }
            }
        }

        void insertComRecursao(T valor){
            if (root == NULL){
                root = new Novo <T>(valor);
            }else{
                insertAux(root, valor);
            }
        }

		void insertAux(Novo <T> *raiz, T valor){
		    if (valor < raiz->valor){
                if (raiz->left == NULL){
                    raiz->left = new Novo <T> (valor);
                }else{
                    insertAux(raiz->left, valor);
                }

            }else if (valor > raiz->valor){
                if (raiz->right == NULL){
                    raiz->right = new Novo <T> (valor);
                }else{
                    insertAux(raiz->right, valor);
                }
            }
        }


		void percusoExtensao(){
		    int op;
            cout << "Deseja percorrer em ordem (1), pós ordem (2), pré ordem (3) ?" << endl;
            cin >> op;
            if (op == 1){
                emOrdem(root);
            }else if (op == 2){
                posOrdem(root);
            }else if (op == 3){
                preOrdem(root);
            }else{
                cout << "Opção invalida!" << endl;
            }
		}

		void emOrdem(Novo <T> * raiz){
            if (raiz != NULL){
                emOrdem(raiz->left);
                visit(raiz);
                emOrdem(raiz->right);
            }
        }

        void preOrdem(Novo <T> * raiz){
            if(raiz != NULL){
                visit(raiz);
                preOrdem(raiz->left);
                preOrdem(raiz->right);
            }
        }

        void posOrdem(Novo <T> * raiz){
            if(raiz != NULL){
                posOrdem(raiz->left);
                posOrdem(raiz->right);
                visit(raiz);
            }
        }



};

main(){

	Arvore<int> *a = new Arvore <int> ();

	a->insertSemRecursao(8);
	a->insertSemRecursao(10);
	a->insertSemRecursao(14);
	a->insertSemRecursao(13);
	a->insertSemRecursao(3);
	a->insertSemRecursao(1);
	a->insertSemRecursao(6);
	a->insertSemRecursao(4);
	a->insertSemRecursao(7);


//	a->insertComRecursao(8);
//	a->insertComRecursao(10);
//	a->insertComRecursao(14);
//	a->insertComRecursao(13);
//	a->insertComRecursao(3);
//	a->insertComRecursao(1);
//	a->insertComRecursao(6);
//	a->insertComRecursao(4);
//	a->insertComRecursao(7);


	a->percusoExtensao();


}


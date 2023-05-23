#include<iostream>
#include<cstddef>
using namespace std;

template<typename T>
class Nodo {
private:
    T elem;
public:
    Nodo<T>* hijoIz;
    Nodo<T>* hijoDer;

    Nodo() {
        hijoIz = NULL;
        hijoDer = NULL;
    }

    Nodo(T elem, Nodo<T>* hijoDer, Nodo<T>* hijoIz) {
        this->elem = elem;
        this->hijoDer = hijoDer;
        this->hijoIz = hijoIz;
    }

    void insertar(T dato) {
        if (dato < elem) {
            if (hijoIz == NULL) {
                hijoIz = new Nodo<T>(dato, NULL, NULL);
            } else {
                hijoIz->insertar(dato);
            }
        } else {
            if (hijoDer == NULL) {
                hijoDer = new Nodo<T>(dato, NULL, NULL);
            } else {
                hijoDer->insertar(dato);
            }
        }
    }

    void preOrderTraversal(int x) {
        for (int i = 0; i < x; i++) {
            cout << "  ";
        }
        cout << elem << endl;
        if (hijoIz != NULL) {
            hijoIz->preOrderTraversal(x + 1);
        }
        if (hijoDer != NULL) {
            hijoDer->preOrderTraversal(x + 1);
        }
    }

    void inOrderTraversal(int x) {
        if (hijoIz != NULL) {
            hijoIz->inOrderTraversal(x + 1);
        }
        for (int i = 0; i < x; i++) {
            cout << "  ";
        }
        cout << elem << endl;
        if (hijoDer != NULL) {
            hijoDer->inOrderTraversal(x + 1);
        }
    }

    void postOrderTraversal(int x) {
        if (hijoIz != NULL) {
            hijoIz->postOrderTraversal(x + 1);
        }
        if (hijoDer != NULL) {
            hijoDer->postOrderTraversal(x + 1);
        }
        for (int i = 0; i < x; i++) {
            cout << "  ";
        }
        cout << elem << endl;
    }

    T getElem() {
        return this->elem;
    }

    void setElem(T nElem) {
        this->elem = nElem;
    }
};

template<typename T>
class Arbol {
private:
    Nodo<T>* raiz;
public:
    Arbol() {
        raiz = NULL;
    }

    bool vacia() {
        return (raiz == NULL);
    }

    void insertar(T dato) {
        if (vacia()) {
            raiz = new Nodo<T>(dato, NULL, NULL);
        } else {
            raiz->insertar(dato);
        }
    }

    void preOrderTraversal() {
        if (!vacia()) {
            raiz->preOrderTraversal(0);
            cout << endl;
        }
    }

    void inOrderTraversal() {
        if (!vacia()) {
            raiz->inOrderTraversal(0);
            cout << endl;
        }
    }

    void postOrderTraversal() {
        if (!vacia()) {
            raiz->postOrderTraversal(0);
            cout << endl;
        }
    }

    T buscar(T n) {
        if (!vacia()) {
            Nodo<T>* aux = raiz;
            while (aux != NULL) {
                if (n == aux->getElem()) {
                    return n;
                } else if (n < aux->getElem()) {
                    aux = aux->hijoIz;
                } else {
                    aux = aux->hijoDer;
                }
            }
        }
        return -1;
    }

    void eliminar(T n) {
        if (!vacia()) {
            if (buscar(n) == n) {
                Nodo<T>* padre = NULL;
                Nodo<T>* actual = raiz;
                bool encontrado = false;

                while (actual != NULL && !encontrado) {
                    if (n == actual->getElem()) {
                        encontrado = true;
                    } else {
                        padre = actual;
                        if (n < actual->getElem()) {
                            actual = actual->hijoIz;
                        } else {
                            actual = actual->hijoDer;
                        }
                    }
                }

                if (encontrado) {
                    if (actual->hijoIz == NULL && actual->hijoDer == NULL) {
                        if (padre == NULL) {
                            raiz = NULL;
                        } else if (padre->hijoIz == actual) {
                            padre->hijoIz = NULL;
                        } else {
                            padre->hijoDer = NULL;
                        }
                        delete actual;
                    } else if (actual->hijoIz == NULL) {
                        if (padre == NULL) {
                            raiz = actual->hijoDer;
                        } else if (padre->hijoIz == actual) {
                            padre->hijoIz = actual->hijoDer;
                        } else {
                            padre->hijoDer = actual->hijoDer;
                        }
                        delete actual;
                    } else if (actual->hijoDer == NULL) {
                        if (padre == NULL) {
                            raiz = actual->hijoIz;
                        } else if (padre->hijoIz == actual) {
                            padre->hijoIz = actual->hijoIz;
                        } else {
                            padre->hijoDer = actual->hijoIz;
                        }
                        delete actual;
                    } else {
                        Nodo<T>* sucesor = actual->hijoDer;
                        Nodo<T>* padreSucesor = actual;

                        while (sucesor->hijoIz != NULL) {
                            padreSucesor = sucesor;
                            sucesor = sucesor->hijoIz;
                        }
                        actual->setElem(sucesor->getElem());
                        if (padreSucesor->hijoIz == sucesor) {
                            padreSucesor->hijoIz = sucesor->hijoDer;
                        } else {
                            padreSucesor->hijoDer = sucesor->hijoDer;
                        }
                        delete sucesor;
                    }
                } else {
                    cout << "El numero no existe en el arbol." << endl;
                }
            } else {
                cout << "El numero no existe en el arbol." << endl;
            }
        } else {
            cout << "El arbol está vacío." << endl;
        }
    }

    void anular() {
        if (!vacia()) {
            anular(raiz);
            raiz = NULL;
        }
    }

    void anular(Nodo<T>* nodo) {
        if (nodo != NULL) {
            anular(nodo->hijoIz);
            anular(nodo->hijoDer);
            delete nodo;
        }
    }
};

int main() {
    int opc = 0, opcSec, x;
    Arbol<int> miArbol;
    while (opc != 9) {
        system("cls");
        cout << "\t--MENU--" << endl;
        cout << "1. Insertar numero" << endl;
        cout << "2. Eliminar numero" << endl;
        cout << "3. Buscar numero" << endl;
        cout << "4. Recorrido preorder" << endl;
        cout << "5. Recorrido postorder" << endl;
        cout << "6. Recorrido order" << endl;
        cout << "7. Consultar vacio" << endl;
        cout << "8. Anular" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion (1-9): ";
        cin >> opc;
        system("cls");
        switch (opc) {
            case 1:
                cout << "Escribe el numero que deseas insertar: ";
                cin >> x;
                miArbol.insertar(x);
                break;
            case 2:
                if (!miArbol.vacia()) {
                    cout << "Escribe el numero que deseas eliminar: ";
                    cin >> x;
                    miArbol.eliminar(x);
                } else
                    cout << "El arbol esta vacío" << endl;
                system("pause");
                break;
            case 3:
                if (!miArbol.vacia()) {
                    cout << "Escribe el numero que deseas buscar: ";
                    cin >> x;
                    if (miArbol.buscar(x) == x)
                        cout << "El numero si esta registrado" << endl;
                    else
                        cout << "Numero no encontrado" << endl;
                } else
                    cout << "El arbol esta vacío" << endl;
                system("pause");
                break;
            case 4:
                if (!miArbol.vacia()) {
                    cout << "Recorrido en preorden" << endl;
                    miArbol.preOrderTraversal();
                } else
                    cout << "El arbol esta vacío" << endl;
                system("pause");
                break;
            case 5:
                if (!miArbol.vacia()) {
                    cout << "Recorrido en postorden" << endl;
                    miArbol.postOrderTraversal();
                } else
                    cout << "El arbol esta vacío" << endl;
                system("pause");
                break;
            case 6:
                if (!miArbol.vacia()) {
                    cout << "Recorrido en orden" << endl;
                    miArbol.inOrderTraversal();
                } else
                    cout << "El arbol esta vacío" << endl;
                system("pause");
                break;
            case 7:
                if (miArbol.vacia())
                    cout << "El arbol esta vacío" << endl;
                else
                    cout << "El arbol no esta vacío" << endl;
                system("pause");
                break;
            case 8:
                miArbol.anular();
                break;
        }
    }
    return 0;
}


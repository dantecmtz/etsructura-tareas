#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

template<class T>
class LDLLSE;

class SocioClub {
private:
    int NumeroSocio;
    string NombreSocio;
    string Domicilio;
    int AnioIngreso;

public:
    SocioClub() : NumeroSocio(0), AnioIngreso(0) {}
    SocioClub(int numSocio, const string& nombre, const string& domicilio, int anioIngreso)
        : NumeroSocio(numSocio), NombreSocio(nombre), Domicilio(domicilio), AnioIngreso(anioIngreso) {}

    bool operator==(const SocioClub& otro) const {
        return NumeroSocio == otro.NumeroSocio;
    }

    bool operator!=(const SocioClub& otro) const {
        return NumeroSocio != otro.NumeroSocio;
    }

    friend ostream& operator<<(ostream& os, const SocioClub& socio) {
        os << "Número de socio: " << socio.NumeroSocio << endl;
        os << "Nombre: " << socio.NombreSocio << endl;
        os << "Domicilio: " << socio.Domicilio << endl;
        os << "Año de ingreso: " << socio.AnioIngreso << endl;
        return os;
    }

    friend istream& operator>>(istream& is, SocioClub& socio) {
        cout << "Ingrese el número de socio: ";
        is >> socio.NumeroSocio;
        cout << "Ingrese el nombre: ";
        is >> socio.NombreSocio;
        cout << "Ingrese el domicilio: ";
        is >> socio.Domicilio;
        cout << "Ingrese el año de ingreso: ";
        is >> socio.AnioIngreso;
        return is;
    }
};

template<class T>
class nodo {
private:
    T data;
    T* sig;
    T* ant;

public:
    nodo() : sig(NULL), ant(NULL) {}
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE {
private:
    T* ancla;

public:
    LDLLSE() : ancla(NULL) {}
    bool vacia() const;
    nodo<T>* primero() const;
    nodo<T>* ultimo() const;
    nodo<T>* anterior(nodo<T>*) const;
    nodo<T>* siguiente(nodo<T>*) const;
    nodo<T>* localiza(const T&) const;
    T recupera(nodo<T>*) const;
    void imprime() const;
    void anula();
    void inserta(const T& elem, nodo<T>* pos);
    void elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(const T& elem, nodo<T>* pos) {
    nodo<T>* aux = new nodo<T>();
    aux->data = elem;

    if (pos == NULL) {
        aux->ant = NULL;
        aux->sig = ancla;
        if (ancla != NULL)
            ancla->ant = aux;
        ancla = aux;
    } else {
        aux->ant = pos;
        aux->sig = pos->sig;
        if (pos->sig != NULL)
            pos->sig->ant = aux;
        pos->sig = aux;
    }
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos) {
    if (vacia() || pos == NULL) {
        cout << "\nError: La lista está vacía o la posición es inválida." << endl;
        return;
    } else {
        if (pos->ant != NULL)
            pos->ant->sig = pos->sig;
        if (pos->sig != NULL)
            pos->sig->ant = pos->ant;
        if (pos == ancla)
            ancla = ancla->sig;
        delete pos;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::primero() const {
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo() const {
    if (vacia()) {
        return ancla;
    } else {
        nodo<T>* aux = ancla;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos) const {
    if (vacia() || pos == NULL) {
        return NULL;
    } else {
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos) const {
    if (vacia() || pos == NULL) {
        return NULL;
    } else {
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(const T& elem) const {
    if (vacia()) {
        return NULL;
    } else {
        nodo<T>* aux = ancla;
        while (aux->sig != NULL && aux->data != elem) {
            aux = aux->sig;
        }
        return aux;
    }
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos) const {
    if (vacia() || pos == NULL) {
        // Manejar el caso de error
        // Aquí simplemente se retorna un objeto T por defecto
        return T();
    } else {
        return pos->data;
    }
}

template<class T>
bool LDLLSE<T>::vacia() const {
    return ancla == NULL;
}

template<class T>
void LDLLSE<T>::imprime() const {
    if (!vacia()) {
        nodo<T>* aux = ancla;
        while (aux != NULL) {
            cout << aux->data << endl;
            aux = aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula() {
    nodo<T>* aux;
    while (ancla != NULL) {
        aux = ancla;
        ancla = aux->sig;
        delete aux;
    }
}

int main() {
    LDLLSE<SocioClub> listaSocios;

    int opcion;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Registrar un nuevo socio" << endl;
        cout << "2. Dar de baja un socio" << endl;
        cout << "3. Generar un reporte con los datos de todos los socios" << endl;
        cout << "4. Buscar por nombre y domicilio a un socio" << endl;
        cout << "5. Imprimir los socios registrados" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            SocioClub nuevoSocio;
            cin >> nuevoSocio;

            // Verificar si ya existe un socio con el mismo número
            nodo<SocioClub>* encontrado = listaSocios.localiza(nuevoSocio);
            if (encontrado != NULL) {
                cout << "Error: Ya existe un socio con el mismo número de socio." << endl;
            } else {
                listaSocios.inserta(nuevoSocio, listaSocios.ultimo());
                cout << "Socio registrado exitosamente." << endl;
            }
        } else if (opcion == 2) {
            int numeroSocio;
            cout << "Ingrese el número de socio a dar de baja: ";
            cin >> numeroSocio;

            SocioClub socioBuscado;
            socioBuscado.NumeroSocio = numeroSocio;

            nodo<SocioClub>* encontrado = listaSocios.localiza(socioBuscado);
            if (encontrado != NULL) {
                listaSocios.elimina(encontrado);
                cout << "Socio dado de baja exitosamente." << endl;
            } else {
                cout << "Error: No se encontró un socio con el número especificado." << endl;
            }
        } else if (opcion == 3) {
            listaSocios.imprime();
        } else if (opcion == 4) {
            string nombre;
            string domicilio;
            cout << "Ingrese el nombre del socio a buscar: ";
            cin >> nombre;
            cout << "Ingrese el domicilio del socio a buscar: ";
            cin >> domicilio;

            SocioClub socioBuscado;
            socioBuscado.NombreSocio = nombre;
            socioBuscado.Domicilio = domicilio;

            nodo<SocioClub>* encontrado = listaSocios.localiza(socioBuscado);
            if (encontrado != NULL) {
                cout << "Socio encontrado:" << endl;
                cout << *encontrado->data << endl;
            } else {
                cout << "No se encontró un socio con el nombre y domicilio especificados." << endl;
            }
        } else if (opcion == 5) {
            listaSocios.imprime();
        } else if (opcion == 6) {
            break;
        } else {
            cout << "Opción inválida. Intente nuevamente." << endl;
        }
    }

    return 0;
}


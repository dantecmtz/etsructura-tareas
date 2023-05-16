#include <iostream>
#include <string>
#include<cstddef>
template<class T>
class Cola;

class Constancia{
private:
    std::string nombre;
    std::string carrera;
    int materias_aprobadas;
    float promedio_general;
public:
    Constancia():nombre(""), carrera(""), materias_aprobadas(0), promedio_general(0){};
    Constancia(std::string n, std::string c, int ma, float pg):nombre(n), carrera(c), materias_aprobadas(ma), promedio_general(pg){};
    friend std::ostream& operator<<(std::ostream& os, const Constancia& c){
        os << "Nombre: " << c.nombre << ", Carrera: " << c.carrera << ", Materias aprobadas: " << c.materias_aprobadas << ", Promedio general: " << c.promedio_general << std::endl;
        return os;
    }
};

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(NULL){};
    node(T d):data(d), sig(NULL){};
    friend class Cola<T>;
};

template<class T>
class Cola{
private:
    node<T>* lista;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
public:
    Cola():lista(NULL){};
    bool vacia()const;
    void imprimir()const;
    void Enqueue(T elem);
    void Dequeue();
    T Front();
};

template<class T>
T Cola<T>::Front(){
    if(!vacia()){
       return primero()->data;
    }
}

template<class T>
void Cola<T>::Dequeue(){
    eliminar(primero());
}

template<class T>
void Cola<T>::Enqueue(T elem){
    insertar(ultimo(),elem);
}

template<class T>
void Cola<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=NULL){
        std::cout<<aux->data<<std::endl;
        aux=aux->sig;
    }
}

template<class T>
bool Cola<T>::eliminar(node<T>* pos){
    if(vacia() || pos==NULL){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void Cola<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>(elem);
    if(pos==NULL){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* Cola<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==NULL){
        return NULL;
    }
    node<T>* aux=lista;
    while(aux!=NULL && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* Cola<T>::primero()const{
    if(vacia()){
        return NULL;
    }
    return lista;
}


template<class T>
node<T>* Cola<T>::ultimo()const{
    if(vacia()){
        return NULL;
    }
    node<T>* aux=lista;
    while(aux->sig!=NULL){
        aux=aux->sig;
    }
    return aux;
}
template<class T>
bool Cola<T>::vacia()const{
return lista==NULL;
}

// Sobrecarga del operador << para poder encolar objetos de la clase Constancia en la cola
template<class T>
std::ostream& operator<<(std::ostream& os, const Constancia& c){
os << c.nombre << "," << c.carrera << "," << c.materias_aprobadas << "," << c.promedio_general;
return os;
}

int main(){
Cola<Constancia> cola_constancias;
int opcion = 0;
do {
    std::cout << "MENU:" << std::endl;
    std::cout << "1. Dar de alta una constancia" << std::endl;
    std::cout << "2. Elaborar una constancia" << std::endl;
    std::cout << "3. Salir" << std::endl;
    std::cout << "Ingrese una opcion: ";
    std::cin >> opcion;

    switch(opcion){
        case 1:{
            std::string nombre;
            std::string carrera;
            int materias_aprobadas;
            float promedio_general;

            std::cout << "Ingrese el nombre del alumno: ";
            std::cin >> nombre;

            std::cout << "Ingrese la carrera que cursa: ";
            std::cin >> carrera;

            std::cout << "Ingrese el total de materias aprobadas: ";
            std::cin >> materias_aprobadas;

            std::cout << "Ingrese el promedio general: ";
            std::cin >> promedio_general;

            Constancia nueva_constancia(nombre, carrera, materias_aprobadas, promedio_general);

            // Se encola la constancia recién creada
            cola_constancias.Enqueue(nueva_constancia);

            std::cout << "La constancia ha sido encolada correctamente." << std::endl;
            break;
        }
        case 2:{
            if(cola_constancias.vacia()){
                std::cout << "No hay constancias en la cola." << std::endl;
                break;
            }
            else{
                std::cout << "Se elaboró la siguiente constancia: " << std::endl;
                std::cout << cola_constancias.Front() << std::endl;
                cola_constancias.Dequeue(); // Se quita la constancia de la cola
            }
            break;
        }
        case 3:{
            std::cout << "Saliendo del programa." << std::endl;
            break;
        }
        default:{
            std::cout << "Opción inválida." << std::endl;
            break;
        }
    }
} while(opcion != 3);

return 0;
}

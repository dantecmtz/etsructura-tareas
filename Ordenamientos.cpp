#include <iostream>
#define TAM 50

class Constancia {
    private:
        std::string nombre;
        std::string carrera;
        int tma;
        float promG;
    public:
        Constancia():nombre(""),carrera(""),tma(-1),promG(-1) {};

        Constancia(const Constancia& c) {
            nombre = c.nombre;
            carrera = c.carrera;
            tma = c.tma;
            promG = c.promG;
            }

        Constancia& operator = (Constancia& c) {
            nombre = c.nombre;
            carrera = c.carrera;
            tma = c.tma;
            promG = c.promG;
            return *this;
            }

        friend bool operator==(Constancia x,Constancia y) {
            if(x.nombre.compare(y.nombre)==0 && x.carrera.compare(y.carrera)==0 && x.tma == y.tma && x.promG == y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator!=(Constancia& x,Constancia& y) {
            if(x.nombre.compare(y.nombre)==0 && x.carrera.compare(y.carrera)==0 && x.tma == y.tma && x.promG == y.promG) {
                return 0;
                }
            else {
                return 1;
                }

            }

        friend bool operator>(Constancia x,Constancia y) {
            if(x.promG > y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator>=(Constancia& x,Constancia& y) {
            if(x.promG >= y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator<(Constancia x,Constancia y) {
            if(x.promG < y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend bool operator<=(Constancia x,Constancia y) {
            if(x.promG <= y.promG) {
                return 1;
                }
            else {
                return 0;
                }

            }

        friend std::ostream & operator<<(std::ostream &O, Constancia &x) {
            O<<"\n Nombre: "<<x.nombre<<std::endl;
            O<<"\n Carrera: "<<x.carrera<<std::endl;
            O<<"\n Materias Aprobadas: "<<std::to_string(x.tma)<<std::endl;
            O<<"\n Promedio General: "<<std::to_string(x.promG)<<std::endl;
            return O;
            }
        friend std::istream & operator>>(std::istream &O, Constancia &x) {
            std::cout<<"\n Nombre: ";
            O>>x.nombre;
            std::cout<<"\n Carrera: ";
            O>>x.carrera;
            std::cout<<"\n Total de Materias Aprobadas: ";
            O>>x.tma;
            std::cout<<"\n Promedio General: ";
            O>>x.promG;
            return O;
            }

        std::string getNombre() const {
            return nombre;
            }


        std::string getCarrera() const {
            return carrera;
            }

        int getTma() const {
            return tma;
            }

        float getPromG() const {
            return promG;
            }

        void setNombre(const std::string& n) {
            nombre = n;
            }

        void setCarrera(const std::string& c) {
            carrera = c;
            }

        void setTma(const int& t) {
            tma = t;
            }

        void setPromG(const float& p) {
            promG = p;
            }
    };

//plantillas
template<class T>
class Lista {
    private:
        T datos[TAM];
        int ult;

    public:
        Lista():ult(-1) {}
        bool inserta(T, int);
        bool elimina(int);
        T& recupera(int);
        int primero()const;
        int ultimo()const;
        void imprime()const;
        bool vacia()const;
        bool llena()const;
        void quicksort(const int& le, const int& re);
        int busquedaL(Constancia& c) const;
        int busquedaB(Constancia& c) const;
    };


template<class T>
void Lista<T>::imprime()const {
    if(!vacia()) {
        for(int i=0; i<=ult; i++) {
            Constancia x=datos[i];
            std::cout<<x<<std::endl;
            }
        }
    }

template<class T>
bool Lista<T>::vacia()const {
    return ult==-1;
    }

template<class T>
bool Lista<T>::llena()const {
    return ult==TAM-1;
    }

template<class T>
bool Lista<T>::inserta(T elem, int pos) {
    if(llena() || pos<-1 || pos>ult+1) {
        std::cout<<"\n No se pudo insertar";
        return false;
        }
    int i=ult;
    while(i>pos) {
        datos[i]=datos[i-1];
        i--;
        }
    datos[pos+1]=elem;
    ult++;
    return true;
    }

template<class T>
bool Lista<T>::elimina(int pos) {
    if(vacia() || pos<0 || pos>ult) {
        std::cout<<"\n No se pudo eliminar";
        return false;
        }
    int i=pos;
    while(i<ult) {
        datos[i]=datos[i+1];
        i++;
        }
    ult--;
    return true;
    }

template<class T>
T& Lista<T>::recupera(int pos) {
    if(vacia() || pos<0 || pos>ult) {
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
        }
    else {
        return datos[pos];
        }
    }

template<class T>
int Lista<T>::primero()const {
    if(vacia()) {
        return -1;
        }
    return 0;
    }

template<class T>
int Lista<T>::ultimo()const {
    if(vacia()) {
        return -1;
        }
    return ult;
    }

template<class T>
int Lista<T>::busquedaL(Constancia& c) const {
    for(int i=0; i<=ult; i++) {
        if(datos[i] == c) {
            return i;
            }
        }
    return -1;
    }

template<class T>
int Lista<T>::busquedaB(Constancia& c) const {
    int i(0),j(ult),medio;
    while(i<=j) {
        medio = (i+j)/2;
        if(datos[medio]== c) {
            return medio;
            }

        if(c > datos[medio]) {
            j = medio-1;
            }
        else {
            i = medio+1;
            }
        }


return -1;
    }


template<class T>
void Lista<T>::quicksort(const int& le, const int& re) {
    if(le >= re) {
        return;
        }
    else {
        T aux;
        int i(le), j(re);

        aux = datos[re];
        datos[re] = datos[(le+re)/2];
        datos[(le+re)/2] = aux;

        while(i<j) {
            while(i < j and datos[i] >= datos[re]) {
                i++;
                }

            while(i < j and datos[j] <= datos[re]) {
                j--;
                }

            if(i != j) {
                aux = datos[i];
                datos[i] = datos[j];
                datos[j] = aux;
                }
            }

        if(i != re) {
            aux = datos[i];
            datos[i] = datos[re];
            datos[re] = aux;
            }

        quicksort(le,i-1);
        quicksort(i+1,re);
        }
    }

int main() {
    Lista<Constancia> MiLista;
    Constancia x;
    int op,p;

    do {
        std::cout<<"1. Dar de alta solicitud de alumno"<<std::endl;
        std::cout<<"2. Buscar una constancia"<<std::endl;
        std::cout<<"3. Salir"<<std::endl;
        std::cout<<"Opcion: ";
        std::cin>>op;

        switch(op) {
            case 1:
                std::cin>>x;
                MiLista.inserta(x,MiLista.ultimo());
                break;
            case 2:
                std::cin>>x;
                MiLista.quicksort(MiLista.primero(),MiLista.ultimo());
                p = MiLista.busquedaB(x);
                if(p >= 0) {
                    std::cout<<p;
                    x = MiLista.recupera(p);
                    std::cout<<"***********Constancia**********\nDatos del alumno: \n";
                    std::cout<<x;
                    std::cout<<"Su constancia se encuentra esperando en la posicion "<<p+1<<", por favor espere.....\n";
                    }
                else {
                    std::cout<<"Su constancia no se encuentra en la Lista, cree una por favor.....\n";
                    }
            }
        }
    while(op!=4);


    return 0;
    }

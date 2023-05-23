#include <iostream>
#include <cstddef>
using namespace std;

template<class T>
class LDLLSE;

template<class T>
class nodo{
private:
    T data;
    T* sig, ant;
public:
    nodo():sig(NULL), ant(NULL){};
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
private:
    T* ancla;
public:
    LDLLSE(): ancla(NULL){};
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(T elem,nodo<T>* pos);
    void elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(T elem,nodo<T>* pos){
    /*aqui va su código*/
    nodo<T>* aux= new nodo<T>*(elem);
    if(pos==NULL){
    	aux->ant=NULL;
    	aux->sig=ancla;
    	if(ancla!=NULL)
    		ancla->ant=aux;
		ancla=aux;
	}else{
		aux->ant=pos;
		aux->sig=pos->sig;
		if(pos->sig!=NULL)
			pos->sig->ant=aux;
		pos->sig=aux;
	}
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos){
    /*aqui va su código*/
    if(vacia()||pos==NULL){
    	cout<<"\nError: La lista esta vacia o la posicion es invalida."<<endl;
    	return;
	}else{
		if(pos->ant!=NULL)
			pos->ant->sig=pos->sig;
		if(pos->sig!=NULL)
			pos->sig->ant=pos->ant;
		if(pos==ancla)
			ancla=ancla->sig;
		delete pos;
	} 
}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia){
        return ancla;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==NULL){
        return NULL;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==NULL){
        return NULL;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    if(vacia()){
        return NULL;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=NULL && aux->data!=elem){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==NULL){

    }
    else{
        return pos->data;
    }
}


template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==NULL){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux=ancla;
        while(aux!=NULL){
            cout<<aux->data<<endl;
            aux=aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=NULL){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}

int main()
{
    return 0;
}

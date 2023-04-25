#include <iostream>
#include <cstddef>
using namespace std;

class SocioClub{
private:
	int numSocio;
	string nomSocio;
	string domicilio;
	int aIngreso;
public:
	//Constructores
	SocioClub(int nNumSocio,string nNomSocio, string nDomicilio, int nAIngreso){
		numSocio=nNumSocio;
		nomSocio=nNomSocio;
		domicilio=nDomicilio;
		aIngreso=nAIngreso;
	}
	SocioClub(){
		numSocio=0;
		nomSocio="NULL";
		domicilio="NULL";
		aIngreso=0;
	}
	//Sobrecargas
	bool operator==(const SocioClub& other) const {
		if(numSocio == other.numSocio&&nomSocio == other.nomSocio&&domicilio==other.domicilio&&aIngreso==other.aIngreso)
        	return true;
    }
    bool operator!=(const SocioClub& other) const {
        return !(*this == other);
    }
    SocioClub operator+(const SocioClub& other) const {
        int nNumSocio = numSocio + other.numSocio;
        string nuevoNombre = nomSocio + " y " + other.nomSocio;
        string nuevoDomicilio = domicilio + " y " + other.domicilio;
        int nAIngreso = aIngreso+other.aIngreso;
        return SocioClub(nNumSocio, nuevoNombre,nuevoDomicilio,nAIngreso);
    }
    bool operator<(const SocioClub& other) const {
        return aIngreso < other.aIngreso;
    }
    bool operator>(const SocioClub& other) const {
        return aIngreso > other.aIngreso;
    }
    //gets, sets
    int getNum(){return numSocio;}
    void setNum(int nNum){numSocio=nNum;}
    string getNom(){return nomSocio;}
    void setNom(string nNom){nomSocio=nNom;}
    string getDom(){return domicilio;}
    void setDom(string nDom){domicilio=nDom;}
    int getAIngreso(){return aIngreso;}
    void setAIngreso(int nAIngreso){aIngreso=nAIngreso;}
    
    void Mostrar(){
    	cout<<"\nNumero de socio: "<<numSocio<<"\nNombre de socio: "<<nomSocio<<"\nDomicilio: "<<domicilio<<"\nIngreso: "<<aIngreso<<endl;
	}
	friend class Nodo;
};
class Nodo{	
public:
	SocioClub socio;
	Nodo* sig;
	Nodo(SocioClub nSocio){
		socio=nSocio;
		sig=NULL;
	}	
};
class Lista{
private:
	Nodo* h;
	int contador;
public:
	//constructor
	Lista(){
		h=NULL;
		contador=0;
	}
	//metodos	
	void Insertar(SocioClub nSocio){
		Nodo* aux=new Nodo(nSocio);
		if(h==NULL)
			h=aux;
		else{
			Nodo* temp=h;
			while(temp->sig!=NULL){
				temp=temp->sig;
			}
			temp->sig= aux;
		}
		contador++;
	}	
	void Eliminar(int socioE){
		Nodo* temp= h;
		Nodo* ant= NULL;
		while(temp!=NULL){
			if(temp->socio.getNum()==socioE){
				if(ant==NULL)
					h=temp->sig;
				else{
					ant->sig=temp->sig;
				}
				delete temp;
				contador--;
				return;
			}else{
				ant=temp;
				temp=temp->sig;	
			}
		}
		cout<<"\nERROR: No se ha encontrado el socio a eliminar."<<endl;
	}	
	void LocalizaNombre(string nombre){
		Nodo* aux=h;
		while(aux!=NULL){
			if(aux->socio.getNom()==nombre){
				aux->socio.Mostrar();
				return;
			}
			else{
				aux=aux->sig;
			}
		}
		cout<<"\nERROR: El nombre que busca no se ha encontrado.";
	}	
	void LocalizaDomicilio(string domicilio){
		Nodo* aux=h;
		while(aux!=NULL){
			if(aux->socio.getDom()==domicilio){
				aux->socio.Mostrar();
				return;
			}
			else{
				aux=aux->sig;
			}
		}
		cout<<"\nERROR: El nombre que busca no se ha encontrado.";
	}	
	void Imprimir()const{
		Nodo* aux=h;
		while(aux!=NULL){
			aux->socio.Mostrar();
			aux=aux->sig;
		}
		cout<<"\nTotal de registros: "<<contador;
	}
};
int main(){
	int opc=0,nAIngreso,contadorX=0,opcSec;
	string nNom,nDom;
	Lista registro;
	SocioClub socioT;
	while(opc!=6){
		cout<<"\n\t--Menu--\n1.Registrar\n2.Eliminar\n3.Mostrar todos\n4.Buscar por nombre\n5.Buscar por Domicilio\n6.Salir\nSeleccione una opcion (1-6): ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\nInroduzca el nombre del nuevo socio: ";
				cin>>nNom;
				socioT.setNom(nNom);
				cout<<"\nInroduzca el domicilio del nuevo socio: ";
				cin>>nDom;
				socioT.setDom(nDom);
				cout<<"\nInroduzca el anio de ingreso del nuevo socio: ";
				cin>>nAIngreso;
				socioT.setAIngreso(nAIngreso);
				socioT.setNum(contadorX+1);
				registro.Insertar(socioT);
				cout<<"\nSu numero de socio es: "<<contadorX+1;
				contadorX++;
				break;
			case 2:
				cout<<"\nIntroduzca el numero del socio que desea eliminar: ";
				cin>>opcSec;
				registro.Eliminar(opcSec);
				break;
			case 3:
				registro.Imprimir();
				break;
			case 4:
				cout<<"\nIntroduzca el nombre del socio que busca: ";
				cin>>nNom;
				registro.LocalizaNombre(nNom);
				break;
			case 5:
				cout<<"\nIntroduzca el domicilio del socio que busca: ";
				cin>>nDom;
				registro.LocalizaDomicilio(nDom);
				break;	
		}
	}
 	return 0;
 }

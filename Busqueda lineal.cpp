#include <iostream>
const int TAM=100;
using namespace std;

class Constancia{
private:
	int MateriasAprobadas;
    string Nombre;
    string Carrera;
    float PromedioGeneral;
public:
    Constancia(){}
    Constancia(int ce,string n,string d, float s):MateriasAprobadas(ce),Nombre(n),Carrera(d), PromedioGeneral(s){}
    
    void Imprime(){
        cout<<this;
    }
    void CambiarCarrera(){
    	string nuevoCarrera;
    	cout<<"\n Introduzca la nueva carrera: ";
    	cin>>nuevoCarrera;
    	Carrera=nuevoCarrera;
    	cout<<"\n Se ha realizado el cambio exitosamente."<<endl;  	
	}
	void ActualPromedioGeneral(){
    	float nuevoPromedioGeneral;
    	cout<<"\n Introduzca el nuevo PromedioGeneral: $";
    	cin>>nuevoPromedioGeneral;
    	PromedioGeneral=nuevoPromedioGeneral;
    	cout<<"\n Se ha realizado el cambio exitosamente."<<endl;  	
	}
	string getNombre(){
		return Nombre;
	}
    friend Constancia operator +(Constancia& e1, Constancia& e2){
        return Constancia(e1.MateriasAprobadas+e2.MateriasAprobadas, e1.Nombre+e2.Nombre,e1.Carrera+e2.Carrera,e1.PromedioGeneral+e2.PromedioGeneral);
    }
    bool operator ==(Constancia& e){
        return ((MateriasAprobadas==e.MateriasAprobadas) && (Nombre==e.Nombre)&&(Carrera==e.Carrera)&&(PromedioGeneral==e.PromedioGeneral));
    }
    bool operator !=(Constancia& e){
        return ((MateriasAprobadas!=e.MateriasAprobadas) && (Nombre!=e.Nombre)&&(Carrera!=e.Carrera)&&(PromedioGeneral!=e.PromedioGeneral));
    }
    bool operator <(Constancia& e){
        return ((PromedioGeneral<e.PromedioGeneral));
    }
    bool operator >(Constancia& e){
        return ((PromedioGeneral>e.PromedioGeneral));
    }
    friend istream& operator >>(istream& i, Constancia& e){
        cout<<"\n Ingresa nombre: ";
        i>>e.Nombre;
        cout<<"\n Ingresa Carrera: ";
        i>>e.Carrera;
        cout<<"\n Ingresa total de materias aprobadas: ";
        i>>e.MateriasAprobadas;
        cout<<"\n Ingresa el promedio general: ";
        i>>e.PromedioGeneral;
        return i;
    }
    friend ostream& operator <<(ostream& o, Constancia& e){
		o<<" Nombre: "<<e.Nombre;
        o<<"\n Carrera: "<<e.Carrera;
        o<<"\n Materias aprobadas: "<<e.MateriasAprobadas;
        o<<"\n PromedioGeneral: "<<e.PromedioGeneral;
        return o;
    }
};

class Pila{
private:
    Constancia datos[TAM];
    int ult;
public:
    Pila():ult(-1){}
    bool vacia()const{
        if(ult==-1)
            return true;
        return false;
    }
    bool llena()const{
        if(ult==TAM-1)
            return true;
        return false;
    }
    int inserta(Constancia elem, int pos){
        if(llena()|| pos<0 || pos>ult+1){
            cout<<"\n Error de insercion";
            return 0;
        }
        int i=ult+1;
        while(i>pos){
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=elem;
        ult++;
        return 1;
    }
	void encolar(Constancia e){
		inserta(e,ultimo()+1);
	}
	void desencolar(){
		elimina(0);
	}
	Constancia& top(){
		return datos[ult];
	}
    bool elimina(int pos){
        if(vacia() || pos<0 || pos>ult){
            cout<<"\n error de eliminacion";
            return true;
        }
        int i=pos;
        while(i<ult){
            datos[i]=datos[i+1];
            i++;
        }
        ult--;
        return false;
    }
    int ultimo()const{
        return ult;
    }

    friend ostream& operator<<(ostream & o, Pila& P){
        int i=0;
        cout<<"\n";
        while(i<=P.ultimo()){;
            o<<P.datos[i];
            i++;
        }
        return o;
    }
    int localiza(string nombreBuscado){
    	int i=0;
    	while(i<ult){
        	if(datos[i].getNombre()==nombreBuscado)       		
        		return i;
			i++;
		}
		cout<<"\nNo se ha encontrado el alumno que busca.";
		return false;
	}
	void mostrar(){
		cout<<datos[0];
	}
	bool buscar(){
		int i=0;
		string nombreBuscado;
		if(vacia()){
            cout<<"\n La lista esta vacia";
            return false;
        }
        cout<<"Introduzca el nombre del alumno que busca: ";
        cin>>nombreBuscado;
        while(i<=ult){
        	if(datos[i].getNombre()==nombreBuscado){
        		cout<<datos[i];
        		return true;
			}
			i++;
		}
		cout<<"\nNo se ha encontrado el alumno que busca.";
		return false;
	}
	int busquedaBinaria(Constancia elem){
		int i=0,j=ultimo();
		while(i<=j){
			int medio=(i+j)/2;
			if(datos[medio]==elem)
				return medio;
			if(elem<datos[medio]){
				j=medio--;
			}else{
				i=medio++;
			}
		}
		return -1;
	}
};

int main()
{
    Pila MiPila;
    Constancia molde;
    int menu=0;
	char opc;
    while(menu!=5){
    	cout<<"\n\t --MENU--";
    	cout<<"\n1.Dar de alta a un alumno";
    	cout<<"\n2.Buscar";
    	cout<<"\n3.Elaborar constancia";
    	cout<<"\n4.Mostrar";
    	cout<<"\n5.Salir";
    	cout<<"\nSelecccione una opcion (1-5): ";
    	cin>>menu;
    	switch(menu){
    		case 1: 
				cin>>molde;
				MiPila.encolar(molde);
				cout<<"\nIntroduzca cualquier caracter: ";
				cin>>opc;
				system("cls");
				break;
			case 2:
				MiPila.buscar();
				cout<<"\nIntroduzca cualquier caracter: ";
				cin>>opc;
				system("cls");
				break;
			case 3:
				cout<<"Datos del alumno:\n";
				MiPila.mostrar();
				cout<<"\n\n1.Generar constancia, 2. Cancelar: ";
				cin>>opc;
				if(opc=='1'){
					MiPila.desencolar();
					cout<<"\nSe ha generado la constancia con exito.";
					cout<<"\nIntroduzca cualquier caracter: ";
				}else{
					system("cls");
					break;
				}
				cin>>opc;
				system("cls");
				break;
			case 4:
				if(MiPila.vacia())
					cout<<"\nNo hay alumnos registrados.";
				else{
					cout<<MiPila;
				}
				cout<<"\n\nIntroduzca cualquier caracter: ";
				cin>>opc;
				system("cls");
				break;
			default: 
				system("cls");
		}
	}
    return 0;
}

#include <iostream>
const int TAM=100;
using namespace std;

class Empleado{
private:
	int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;
public:
    Empleado(){}
    Empleado(int ce,string n,string d, float s,string ra):ClaveEmpleado(ce),Nombre(n),Domicilio(d), Sueldo(s),ReportaA(ra){}
    
    void Imprime(){
        cout<<this;
    }
    void CambiarDomicilio(){
    	string nuevoDomicilio;
    	cout<<"\n Introduzca el nuevo domicilio: ";
    	cin>>nuevoDomicilio;
    	Domicilio=nuevoDomicilio;
    	cout<<"\n Se ha realizado el cambio exitosamente."<<endl;  	
	}
	void CambiarReportaA(){
    	string nuevoReportaA;
    	cout<<"\n Introduzca la nueva persona a la que reporta: ";
    	cin>>nuevoReportaA;
    	ReportaA=nuevoReportaA;
    	cout<<"\n Se ha realizado el cambio exitosamente."<<endl;  	
	}
	void ActualSueldo(){
    	float nuevoSueldo;
    	cout<<"\n Introduzca el nuevo sueldo: $";
    	cin>>nuevoSueldo;
    	Sueldo=nuevoSueldo;
    	cout<<"\n Se ha realizado el cambio exitosamente."<<endl;  	
	}
	int getClave(){
		return ClaveEmpleado;
	}
    friend Empleado operator +(Empleado& e1, Empleado& e2){
        return Empleado(e1.ClaveEmpleado+e2.ClaveEmpleado, e1.Nombre+e2.Nombre,e1.Domicilio+e2.Domicilio,e1.Sueldo+e2.Sueldo,e1.ReportaA+e2.ReportaA);
    }
    bool operator ==(Empleado& e){
        return ((ClaveEmpleado==e.ClaveEmpleado) && (Nombre==e.Nombre)&&(Domicilio==e.Domicilio)&&(Sueldo==e.Sueldo)&&(ReportaA==e.ReportaA));
    }
    bool operator !=(Empleado& e){
        return ((ClaveEmpleado!=e.ClaveEmpleado) && (Nombre!=e.Nombre)&&(Domicilio!=e.Domicilio)&&(Sueldo!=e.Sueldo)&&(ReportaA!=e.ReportaA));
    }
    bool operator <(Empleado& e){
        return ((ClaveEmpleado<e.ClaveEmpleado));
    }
    bool operator >(Empleado& e){
        return ((ClaveEmpleado>e.ClaveEmpleado));
    }
    friend istream& operator >>(istream& i, Empleado& e){
        cout<<"\n Ingresa clave: ";
        i>>e.ClaveEmpleado;
        cout<<"\n Ingresa nombre: ";
        i>>e.Nombre;
        cout<<"\n Ingresa domicilio: ";
        i>>e.Domicilio;
        cout<<"\n Ingresa sueldo: $";
        i>>e.ReportaA;
        cout<<"\n Ingresa la persona a la que reporta: ";
        i>>e.ReportaA;
        return i;
    }
    friend ostream& operator <<(ostream& o, Empleado& e){
        o<<"\n Clave: "<<e.ClaveEmpleado;
		o<<"\n Nombre: "<<e.Nombre;
        o<<"\n Domicilio: "<<e.Domicilio;
        o<<"\n Sueldo: $"<<e.Sueldo;
        o<<"\n Reporta a: "<<e.ReportaA;
        return o;
    }
};

class Pila{
private:
    Empleado datos[TAM];
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
    int inserta(Empleado elem, int pos){
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
	void push(Empleado e){
		inserta(e,ultimo()+1);
	}
	void pop(){
		elimina(ultimo());
	}
	Empleado& top(){
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
    int localiza(int claveBuscada){
    	int i=0;
    	while(i<ult){
        	if(datos[i].getClave()==claveBuscada)       		
        		return i;
			i++;
		}
		cout<<"\nNo se ha encontrado el empleado que busca.";
		return false;
	}
	bool buscar(){
		int i=0,claveBuscada;
		if(vacia()){
            cout<<"\n La lista esta vacia";
            return false;
        }
        cout<<"\nIntroduzca la clave del empleado que busca: ";
        cin>>claveBuscada;
        while(i<=ult){
        	if(datos[i].getClave()==claveBuscada){
        		cout<<datos[i];
        		return true;
			}
			i++;
		}
		cout<<"\nNo se ha encontrado el empleado que busca.";
		return false;
	}

};

int main()
{
    Pila MiPila;
    Empleado molde;
    int menu=0,claveBuscada,posE;
    while(menu!=6){
    	cout<<"\n\t --MENU--";
    	cout<<"\n1.Push";
    	cout<<"\n2.Buscar";
    	cout<<"\n3.Pop";
    	cout<<"\n4.Top";
    	cout<<"\n5.Mostrar";
    	cout<<"\n6.Salir";
    	cout<<"\nSelecccione una opcion (1-6): ";
    	cin>>menu;
    	switch(menu){
    		case 1: 
				cin>>molde;
				MiPila.push(molde);
				break;
			case 2:
				MiPila.buscar();
				break;
			case 3:
				MiPila.pop();
				break;
			case 4:
				cout<<MiPila.top();
				break;
			case 5:
				cout<<MiPila;
				break;
		}
	}
    return 0;
}

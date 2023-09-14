#include <iostream>
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
int main(){
    int menu=0,codigoBuscado;
    Empleado JefePlanta(1,"Juan","No se",500,"Simon"),JefePersonal(2,"Jose","Tampoco se jaja",200,"Arre");
    while(menu!=5){
    	cout<<"\n\t--MENU--";
    	cout<<"\n1. Imprimir datos";
    	cout<<"\n2. Cambiar domicilio";
    	cout<<"\n3. Cambiar superior";
    	cout<<"\n4. Actualizar sueldo";
    	cout<<"\n5. Salir";
    	cout<<"\nSeleccione una opcion (1-5): ";
    	cin>>menu;
    	switch(menu){
    		case 1:
    			cout<<"\nIntroduzca el codigo del empleado que quiere mostrar: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==JefePlanta.getClave()){
    				cout<<JefePlanta;
				}else if(codigoBuscado==JefePersonal.getClave()){
					cout<<JefePersonal;
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
			case 2:
				cout<<"\nIntroduzca el codigo del empleado que quiere cambiar domicilio: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==JefePlanta.getClave()){
    				JefePlanta.CambiarDomicilio();
				}else if(codigoBuscado==JefePersonal.getClave()){
					JefePersonal.CambiarDomicilio();
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
			case 3:
				cout<<"\nIntroduzca el codigo del empleado que quiere cambiar su superior: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==JefePlanta.getClave()){
    				JefePlanta.CambiarReportaA();
				}else if(codigoBuscado==JefePersonal.getClave()){
					JefePersonal.CambiarReportaA();
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
			case 4:
				cout<<"\nIntroduzca el codigo del empleado que quiere actualizar sueldo: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==JefePlanta.getClave()){
    				JefePlanta.ActualSueldo();
				}else if(codigoBuscado==JefePersonal.getClave()){
					JefePersonal.ActualSueldo();
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
		}
	}
    return 0;
}

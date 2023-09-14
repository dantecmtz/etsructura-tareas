#include <iostream>
using namespace std;

class Materia{
private:
	int Clave;
    string Nombre;
    string ProfesorTit;
    string LibroTexto;
public:
    Materia(){}
    Materia(int c,string n,string pt,string lt):Clave(c),Nombre(n),ProfesorTit(pt),LibroTexto(lt){}
    
    void Imprime(){
        cout<<this;
    }
    void CambiaClave(){
    	int nuevaClave;
    	cout<<"\n Introduzca la nueva clave: ";
    	cin>>nuevaClave;
    	Clave=nuevaClave;
    	cout<<"\n Se ha realizado el cambio exitosamentm."<<endl;  	
	}
	void CambiaProfe(){
    	string nuevoProfe;
    	cout<<"\n Introduzca la nueva persona a la que reporta: ";
    	cin>>nuevoProfe;
    	ProfesorTit=nuevoProfe;
    	cout<<"\n Se ha realizado el cambio exitosamentm."<<endl;  	
	}
	int getClave(){
		return Clave;
	}
    friend Materia operator +(Materia& m1, Materia& m2){
        return Materia(m1.Clave+m2.Clave, m1.Nombre+m2.Nombre,m1.ProfesorTit+m2.ProfesorTit,m1.LibroTexto+m2.LibroTexto);
    }
    bool operator ==(Materia& m){
        return ((Clave==m.Clave) && (Nombre==m.Nombre)&&(ProfesorTit==m.ProfesorTit)&&(LibroTexto==m.LibroTexto));
    }
    bool operator !=(Materia& m){
        return ((Clave=m.Clave) && (Nombre!=m.Nombre)&&(ProfesorTit!=m.ProfesorTit)&&(LibroTexto!=m.LibroTexto));
    }
    bool operator <(Materia& m){
        return ((Clave<m.Clave));
    }
    bool operator >(Materia& m){
        return ((Clave>m.Clave));
    }
    friend istream& operator >>(istream& i, Materia& m){
        cout<<"\n Ingresa clave: ";
        i>>m.Clave;
        cout<<"\n Ingresa nombre: ";
        i>>m.Nombre;
        cout<<"\n Ingresa el profesor titular: ";
        i>>m.ProfesorTit;
        cout<<"\n Ingresa el libro de texto: ";
        i>>m.LibroTexto;
        return i;
    }
    friend ostream& operator <<(ostream& o, Materia& m){
        o<<"\n Clave: "<<m.Clave;
		o<<"\n Nombre: "<<m.Nombre;
        o<<"\n Profesor titular: "<<m.ProfesorTit;
        o<<"\n Libro de texto: "<<m.LibroTexto;
        return o;
    }
};
int main(){
    int menu=0,codigoBuscado;
    Materia Programacion(1,"Programacion","No se","la guia del ligue"),BasesDatos(2,"Bases de datos","Tampoco se jaja","La Biblia");
    while(menu!=4){
    	cout<<"\n\t--MENU--";
    	cout<<"\n1. Imprimir datos";
    	cout<<"\n2. Cambiar clave";
    	cout<<"\n3. Cambiar profesor";
    	cout<<"\n4. Salir";
    	cout<<"\nSeleccione una opcion (1-4): ";
    	cin>>menu;
    	switch(menu){
    		case 1:
    			cout<<"\nIntroduzca el codigo del Materia que quiere mostrar: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==Programacion.getClave()){
    				cout<<Programacion;
				}else if(codigoBuscado==BasesDatos.getClave()){
					cout<<BasesDatos;
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
			case 2:
				cout<<"\nIntroduzca el codigo del Materia que quiere cambiar su clave: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==Programacion.getClave()){
    				Programacion.CambiaClave();
				}else if(codigoBuscado==BasesDatos.getClave()){
					BasesDatos.CambiaClave();
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
			case 3:
				cout<<"\nIntroduzca el codigo del Materia que quiere cambiar su superior: ";
    			cin>>codigoBuscado;
    			if(codigoBuscado==Programacion.getClave()){
    				Programacion.CambiaProfe();
				}else if(codigoBuscado==BasesDatos.getClave()){
					BasesDatos.CambiaProfe();
				}else{
					cout<<"\nCodigo invalido.";
				}
				break;
		}
	}
    return 0;
}

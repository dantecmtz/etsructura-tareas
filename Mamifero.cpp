#include<iostream>
using namespace std;
class Mamifero{
	private:
		int fechaNacimiento;
		string lugarNacimiento;
	public:
		//constructores
		Mamifero(){
			fechaNacimiento=0;
			lugarNacimiento="NULL";
		}
		Mamifero(int fecha, string lugar){
			fechaNacimiento=fecha;
			lugarNacimiento=lugar;
		}
		//gets, sets
		int getFecha(){return fechaNacimiento;}
		void setFecha(int nuevaFecha){fechaNacimiento=nuevaFecha;}
		string getLugar(){return lugarNacimiento;}
		void setLugar(int nuevoLugar){lugarNacimiento=nuevoLugar;}
		//sobrecargas
		bool operator==(const Mamifero& other) const {
            return fechaNacimiento == other.fechaNacimiento;
        }
        bool operator!=(const Mamifero& other) const {
            return !(*this == other);
        }
        Mamifero operator+(const Mamifero& other) const {
            int nuevaFecha = fechaNacimiento + other.fechaNacimiento;
            string nuevoLugar = lugarNacimiento + " y " + other.lugarNacimiento;
            return Mamifero(nuevaFecha, nuevoLugar);
        }
        bool operator<(const Mamifero& other) const {
            return fechaNacimiento < other.fechaNacimiento;
        }
        bool operator>(const Mamifero& other) const {
            return fechaNacimiento > other.fechaNacimiento;
        }
};
class Felino:public Mamifero{
	private:
		string raza;
		string proprietario;
		string dieta;
	public:
		//constructores
		Felino():Mamifero(0,"NULL"){
			raza="NULL";
			proprietario="NULL";
			dieta="NULL";
		}
		Felino(string nRaza,string nProprietario,string nDieta,int nFecha,string nLugar):Mamifero(nFecha,nLugar),raza(nRaza),proprietario(nProprietario),dieta(nDieta){}
		//gets,sets		
		string getRaza(){return raza;}
		void setRaza(string nuevaRaza){raza=nuevaRaza;}
		string getProprietario(){return proprietario;}
		void setProprietario(string nuevoProprietario){proprietario=nuevoProprietario;}
		string getDieta(){return dieta;}
		void setDieta(string nuevaDieta){dieta=nuevaDieta;}
};
class GatoDomestico:public Felino{
	private:
		string dueno;
	public:
		//constructores
		GatoDomestico():Felino("NULL","NULL","NULL",0,"NULL"){
			dueno="NULL";
		}
		GatoDomestico(string nDueno,string nRaza,string nProprietario,string nDieta,int nFecha,string nLugar):Felino(nRaza,nProprietario,nDieta,nFecha,nLugar),dueno(nDueno){}
		//gets,sets
		string getDueno(){return dueno;}
		void setDueno(string nuevoDueno){dueno=nuevoDueno;}
};
int main(){
	GatoDomestico Minino("Juan","Palico","NULL","Narcoticos",2012,"Mexico");
	Felino EstrellaCirco("Leon","Circo del Sol","Peces",2010,"Africa");
	string nDueno,nProprietario;
	int opc=0;
	while (opc!=4){
		cout<<"\t--MENU--\n1. Imprimir animales\n2. Cambiar dueno\n3. Cambiar proprietario\n4. Salir\nSeleccione una opcion (1-4): ";
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"\nAnimal 1\nRaza: "<<EstrellaCirco.getRaza()<<"\nProprietario: "<<EstrellaCirco.getProprietario()<<"\nDieta: "<<EstrellaCirco.getDieta()<<"\nDetalles de nacimiento: "<<EstrellaCirco.getFecha()<<", "<<EstrellaCirco.getLugar()<<endl;
				cout<<"\nAnimal 2\nRaza: "<<Minino.getRaza()<<"\nDueno: "<<Minino.getDueno()<<"\nDieta: "<<Minino.getDieta()<<"\nDetalles de nacimiento: "<<Minino.getFecha()<<", "<<Minino.getLugar()<<endl;
				break;
			case 2:
				cout<<"\nIntroduzca el nuevo dueno: ";
				cin>>nDueno;
				Minino.setDueno(nDueno);
				break;
			case 3:
				cout<<"Introduzca el nuevo proprietario: ";
				cin>>nProprietario;
				EstrellaCirco.setProprietario(nProprietario);
				break;
		}
	}	
	return 0;
}

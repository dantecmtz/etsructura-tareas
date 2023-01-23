#include <iostream>
#include <string>

class Materia {
  private:
    int clave;
    std::string nombre;
    std::string profesorTit;
    std::string libroTexto;
  public:
    // Constructor
    Materia(int clave, std::string nombre, std::string profesorTit, std::string libroTexto) {
        this->clave = clave;
        this->nombre = nombre;
        this->profesorTit = profesorTit;
        this->libroTexto = libroTexto;
    }
  
    int getClave() { return clave; }
    void setClave(int nuevaClave) { clave = nuevaClave; }
    void setProfesorTit(std::string nuevoProfesorTit) { profesorTit = nuevoProfesorTit; }
    void mostrarMateria(){
    	std::cout << "Clave: " << clave << "\nNombre: " << nombre << "\nProfesor titular: " << profesorTit << "Libro de texto: " << libroTexto << std::endl;
	}
		
};

int main() {
    
    Materia Programacion(1, "Programacion", "Juan Perez", "Programacion en C++");
    Materia BasesDatos(2, "Bases de Datos", "Maria Rodriguez", "Oracle Database");
    Materia *materia;

    int opcion;
    int clave, nuevaClave;
    std::string nuevoProfesor;
    while(opcion!=4){
        std::cout << "Menu: " << std::endl;
        std::cout << "1. Cambiar clave de una materia" << std::endl;
        std::cout << "2. Cambiar profesor titular" << std::endl;
        std::cout << "3. Mostrar datos de una materia" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la clave de la materia que desea modificar: ";
                std::cin >> clave;
                std::cout << "Ingrese la nueva clave: ";
                std::cin >> nuevaClave;
                if(clave == Programacion.getClave()){
                    Programacion.setClave(nuevaClave);
                }else if (clave == BasesDatos.getClave()){
                    BasesDatos.setClave(nuevaClave);
                }else{
                    std::cout << "Clave no encontrada" << std::endl;
                    break;
                }
                break;
            case 2:
            	std::cout << "Ingrese la clave de la materia que desea modificar: ";
                std::cin >> clave;
                std::cout << "Ingrese el nuevo profesor: ";
                std::cin >> nuevoProfesor;
                if(clave == Programacion.getClave()){
                    Programacion.setProfesorTit(nuevoProfesor);
                }else if (clave == BasesDatos.getClave()){
                    BasesDatos.setProfesorTit(nuevoProfesor);
                }else{
                    std::cout << "Clave no encontrada" << std::endl;
                    break;
                }
                break;
            case 3:
            	std::cout << "Ingrese la clave de la materia que desea mostrar: ";
                std::cin >> clave;
                if(clave == Programacion.getClave()){
                    materia = &Programacion;
                }else if (clave == BasesDatos.getClave()){
                    materia = &BasesDatos;
                }else{
                    std::cout << "Clave no encontrada" << std::endl;
                    break;
                }
                materia->mostrarMateria();
                break;
        }
    }
}
            	


#include <iostream>
#include <string>

class Empleado {
    private:
        int clave;
        std::string nombre;
        std::string domicilio;
        float sueldo;
        std::string reportaA;

    public:
        Empleado(int clave, std::string nombre, std::string domicilio, float sueldo, std::string reportaA) {
            this->clave = clave;
            this->nombre = nombre;
            this->domicilio = domicilio;
            this->sueldo = sueldo;
            this->reportaA = reportaA;
        }

        void printClave() { std::cout << "Clave: " << clave << std::endl; }
        void printNombre() { std::cout << "Nombre: " << nombre << std::endl; }
        void printDomicilio() { std::cout << "Domicilio: " << domicilio << std::endl; }
        void printSueldo() { std::cout << "Sueldo: $" << sueldo << std::endl; }
        void printReportaA() { std::cout << "Reporta a: " << reportaA << std::endl; }
        
        int getClave() { return clave; }

        void setDomicilio(std::string newDomicilio) { domicilio = newDomicilio; }
        void actualizarSueldo(float porcentaje) { sueldo += sueldo * (porcentaje / 100); }
        void setReportaA(std::string newReportaA) { reportaA = newReportaA; }
};

int main() {
    Empleado jefePlanta(1, "Juan", "Calle 123", 10000, "Nadie");
    Empleado jefePersonal(2, "Pedro", "Calle 456", 8000, "Juan");

    int opcion = 0;
    int clave = 0;
    std::string newDomicilio, newReportaA;
    float porcentaje;
    Empleado *empleado;

    while (opcion != 5) {
        std::cout << "Seleccione una opcion:" << std::endl;
        std::cout << "1. Cambiar domicilio" << std::endl;
        std::cout << "2. Actualizar sueldo" << std::endl;
        std::cout << "3. Imprimir datos de empleado" << std::endl;
        std::cout << "4. Cambiar a quien reporta un empleado" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese el nuevo domicilio: ";
                std::cin >> newDomicilio;

                if (clave == jefePlanta.getClave()) {
                    jefePlanta.setDomicilio(newDomicilio);
                } else if (clave == jefePersonal.getClave()) {
                    jefePersonal.setDomicilio(newDomicilio);
                } else {
                    std::cout << "Empleado no encontado.";
                    break;
                }
				break;
			case 2:
				std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese el porcentaje de incremento a aumentar al sueldo: ";
                std::cin >> porcentaje;

                if (clave == jefePlanta.getClave()) {
                    jefePlanta.actualizarSueldo(porcentaje);
                } else if (clave == jefePersonal.getClave()) {
                    jefePersonal.actualizarSueldo(porcentaje);
                } else {
                    std::cout << "Empleado no encontado.";
                    break;
                }
				break;
			case 3:
				std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                if (clave == jefePlanta.getClave()) {
                    empleado = &jefePlanta;
                } else if (clave == jefePersonal.getClave()) {
                    empleado = &jefePersonal;
                } else {
                    std::cout << "Empleado no encontado.";
                    break;
                }
                empleado->printClave();
                empleado->printNombre();
                empleado->printDomicilio();
                empleado->printSueldo();
                empleado->printReportaA();
				break;			
			case 4:
				std::cout << "Ingrese la clave del empleado: ";
                std::cin >> clave;
                std::cout << "Ingrese la nueva persona a la que reporta: ";
                std::cin >> newReportaA;

                if (clave == jefePlanta.getClave()) {
                    jefePlanta.setReportaA(newReportaA);
                } else if (clave == jefePersonal.getClave()) {
                    jefePersonal.setReportaA(newReportaA);
                } else {
                    std::cout << "Empleado no encontado.";
                    break;
                }
				break;
		}
	}
}


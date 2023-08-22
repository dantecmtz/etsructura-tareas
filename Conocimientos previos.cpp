#include <stdio.h>
#include <string.h>
int indiceCodigo=0;
struct CD{
	int codigo;
	char artista[30];
	char album[30];
	int noCanciones;
	float precio;
	int existencias;
};

void Agregar(CD arreglo[50]){
	CD nuevoCD;
	printf("\nIntroduzca el artista: ");
	scanf("%s",nuevoCD.artista);
	printf("\nIntroduzca el album: ");
	scanf("%s",nuevoCD.album);
	printf("\nIntroduzca el precio: $");
	scanf("%f",&nuevoCD.precio);
	printf("\nIntroduzca las existencias: ");
	scanf("%i",&nuevoCD.existencias);
	nuevoCD.codigo=indiceCodigo;
	arreglo[indiceCodigo]=nuevoCD;
	printf("\nEl codigo del CD es: %i",indiceCodigo);
	indiceCodigo++;
}
void MostrarCDs(CD arreglo[50]){
	int contador;
	for(contador=0;contador<indiceCodigo;contador++){
		printf("\n\nCodigo de CD: %i\nArtista: %s\nAlbum:%s\nPrecio: $%.2f\nExistencias: %i",arreglo[contador].codigo,arreglo[contador].artista,arreglo[contador].album,arreglo[contador].precio,arreglo[contador].existencias);
	}
}
void BuscarCD(CD arreglo[50]){
	int codigoBuscado;
	printf("\nIntroduzca el codigo del CD que busca: ");
	scanf("%i",&codigoBuscado);
	if(codigoBuscado==arreglo[codigoBuscado].codigo){
		printf("\n\nCodigo de CD: %i\nArtista: %s\nAlbum:%s\nPrecio: $%.2f\nExistencias: %i",arreglo[codigoBuscado].codigo,arreglo[codigoBuscado].artista,arreglo[codigoBuscado].album,arreglo[codigoBuscado].precio,arreglo[codigoBuscado].existencias);
	}else{
		printf("\nNo se ha encontrado CD que busca.");
	}
}
void ModificarCD(CD arreglo[50]){
	int codigoBuscado;
	CD nuevoCD;
	printf("\nIntroduzca el codigo del CD que desea modificar: ");
	scanf("%i",&codigoBuscado);
	if(codigoBuscado==arreglo[codigoBuscado].codigo){		
		printf("\nIntroduzca el nuevo artista: ");
		scanf("%s",nuevoCD.artista);
		printf("\nIntroduzca el nuevo album: ");
		scanf("%s",nuevoCD.album);
		printf("\nIntroduzca el nuevo precio: $");
		scanf("%f",&nuevoCD.precio);
		printf("\nIntroduzca las nuevas existencias: ");
		scanf("%i",&nuevoCD.existencias);
		nuevoCD.codigo=arreglo[codigoBuscado].codigo;
		arreglo[codigoBuscado]=nuevoCD;
	}else{
		printf("\nNo se ha encontrado el CD que desea modificar.");
	}
}
void VentaCD(CD arreglo[50]){
	int numDeseado;
	int codigoBuscado;
	printf("\nIntroduzca el codigo del CD que desea comprar: ");
	scanf("%i",&codigoBuscado);
	if(codigoBuscado==arreglo[codigoBuscado].codigo){
		printf("\n\nCodigo de CD: %i\nArtista: %s\nAlbum:%s\nPrecio: $%.2f\nExistencias: %i",arreglo[codigoBuscado].codigo,arreglo[codigoBuscado].artista,arreglo[codigoBuscado].album,arreglo[codigoBuscado].precio,arreglo[codigoBuscado].existencias);
		printf("\nIntroduzca la cantidad que desea comprar: ");
		scanf("%i",&numDeseado);
		if(numDeseado>arreglo[codigoBuscado].existencias||arreglo[codigoBuscado].existencias==0){
			printf("\nNo hay existencias suficientes.");
			
		}else{
			arreglo[codigoBuscado].existencias-=numDeseado;
			printf("\nVenta realizada de forma exitosa. ");
		}
	}
}
int main(){
	CD tienda[50];
	int menu=0;
	while(menu!=6){
		printf("\n\t--MENU--\n1.Agregar CD\n2.Mostrar todos los CDs\n3.Buscar por codigo\n4.Modificar\n5.Realizar una venta\n6.Salir\nIntoduzca una opcion (1-6): ");
		scanf("%i",&menu);
		switch(menu){
			case 1: Agregar(tienda);break;
			case 2: MostrarCDs(tienda);break;
			case 3: BuscarCD(tienda);break;
			case 4: ModificarCD(tienda);break;
			case 5: VentaCD(tienda);break;
			case 6: break;
		}
	}
	
}

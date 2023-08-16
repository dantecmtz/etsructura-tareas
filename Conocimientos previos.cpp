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
	indiceCodigo++;
}
void MostrarCDs(CD arreglo[50]){
	int contador;
	for(contador=0;contador<indiceCodigo;contador++){
		printf("\n\nCodigo de CD: %i\nArtista: %s\nAlbum:%s\nPrecio: $%.2f\nExistencias: %i",arreglo[contador].codigo,arreglo[contador].artista,arreglo[contador].album,arreglo[contador].precio,arreglo[contador].existencias);
	}
}
void buscarCD(CD arreglo[50]){
	int codigoBuscado;
	printf("\nIntroduzca el codigo del CD que busca: ");
	scanf("%i",&codigoBuscado);
	if(codigoBuscado==arreglo[codigoBuscado-1].codigo){
		printf("\n\nCodigo de CD: %i\nArtista: %s\nAlbum:%s\nPrecio: $%.2f\nExistencias: %i",arreglo[codigoBuscado-1].codigo,arreglo[codigoBuscado-1].artista,arreglo[codigoBuscado-1].album,arreglo[codigoBuscado-1].precio,arreglo[codigoBuscado-1].existencias);
	}
}
int main(){
	CD tienda[50];
	
}

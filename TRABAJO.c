#include <stdio.h>
#include <stdlib.h>

struct Tbarrios {
	float ph;
	int coliformes;
	int conductividad;
	int turbidez;
};
int main () {
	char opcion;
	int i;
	do {
		printf("Seleccione el barrio del cual desee obtener informacion:\n");
		printf("C.Coslada\n");
		printf("Q.Quintana\n");
		printf("E.Embajadores\n");
		printf("S.San blas\n");
		printf("B.Berruguete\n");
		printf("P.Pacifico\n");
		printf("V.Vallehermoso\n");
		printf("T.Trafalgar\n");
		printf("A.Atocha\n");
		printf("L.Legazpi\n");  //¿Hay que poner mas barrios o asi con 10 esta bien?
		scanf("%c", &opcion);
		fflush(stdin);
		
		if((opcion=='C') || (opcion == 'Q') || (opcion == 'E') || (opcion == 'S') || (opcion == 'B') || (opcion == 'P') || (opcion == 'V') ||(opcion == 'T')|| (opcion == 'A')||(opcion == 'L')){
			if(opcion=='C'){
				system("cls");
				printf("Has seleccionado Coslada\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			}
			break;
			if(opcion == 'S'){
				system("cls");
				printf("Has seleccionado San Blas\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			}
			break;
			if(opcion == 'A'){
				system("cls");
				printf("Has seleccionado Atocha\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'T'){
				system("cls");
				printf("Has seleccionado Trafalgar\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'L'){
				system("cls");
				printf("Has seleccionado Legazpi\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'V'){
				system("cls");
				printf("Has seleccionado Vallehermoso\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'B'){
				system("cls");
				printf("Has seleccionado Berruguete\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'P'){
				system("cls");
				printf("Has seleccionado Pacifico\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'Q'){
				system("cls");
				printf("Has seleccionado Quintana\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
			if(opcion == 'E'){
				system("cls");
				printf("Has seleccionado Embajadores\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
			break;
			}
	
	} else{
		printf("Letra no valida.Vuelve a introducir la letra\n");
		}
	
	} while((opcion=='C') || (opcion == 'Q') || (opcion == 'E') || (opcion == 'S') || (opcion == 'B') || (opcion == 'P') || (opcion == 'V') || (opcion == 'T') || (opcion == 'A') || (opcion == 'L'));
	
	
	return 0;

}



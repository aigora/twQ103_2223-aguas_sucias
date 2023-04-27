#include <stdio.h>
#include <stdlib.h>

struct Tbarrios {
	float ph;
	int coliformes;
	int conductividad;
	int turbidez;
};
float MediaPh(float);

int main () {
	/* FILE *dfe,*dfs; // datos de las fuentes (fichero de entrada con el modo read) y datos de fuentes (fichero de salida con el modo write)
	
	dfe = fopen("202211_Coslada.csv", "r");
	
	if (dfe == NULL) {
		printf("Error, no puede abrirse el fichero.\n");   
		return 0;
	} 
	*/
	
	
	char opcion;
	int opcion1,eleccion;
	int i;
	do {
		printf("Seleccione el barrio del cual desee obtener informacion:\n");
		printf("C.Coslada (20 fuentes)\n");
		printf("Q.Quintana (15 fuentes)\n");
		printf("E.Embajadores (26 fuentes)\n");
		printf("S.San blas (10 fuentes)\n");
		printf("B.Berruguete (21 fuentes)\n");
		printf("P.Pacifico (18 fuentes)\n");
		printf("V.Vallehermoso (16 fuentes)\n");
		printf("T.Trafalgar (24 fuentes)\n");
		printf("A.Atocha (14 fuentes)\n");
		printf("L.Legazpi (22 fuentes)\n");  //�Hay que poner mas barrios o asi con 10 esta bien?
		scanf("%c", &opcion);
		fflush(stdin);
		
		if((opcion=='C') || (opcion == 'Q') || (opcion == 'E') || (opcion == 'S') || (opcion == 'B') || (opcion == 'P') || (opcion == 'V') ||(opcion == 'T')|| (opcion == 'A')||(opcion == 'L')){
			if(opcion =='C'){
				
				system("cls");
				do {
				printf("Has seleccionado Coslada\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				scanf("%d", &opcion1);
				}while (opcion1<1 || opcion1>4);
				
				switch(opcion1) {
					case 1:
						system("cls");
						printf("Que operacion estadistica deseas realizar:\n");
						printf("1.Media del pH\n");
						printf("2.Media de la conductividad\n");
						printf("3.Comparacion del pH (orden de mayor a menor)\n");
						printf("4.Comparacion de la conductividad (orden de mayor a menor)\n");
						printf("5.Fuente con mayor turbidez\n");
						printf("6.Fuentes con la misma conductividad\n");
						scanf("%d", &eleccion);
						
						if(eleccion == 1) {
							
						}else if(eleccion ==2) {
							
						}else if(eleccion ==3) {
							
						}else if(eleccion ==4) {
							
						}else if(eleccion ==5) {
							
						}else if(eleccion ==6) {
							
						}
						
						
						break;
					case 2:
						system("cls");
						printf("Que desea consultar sobre las caracteristicas del agua:\n");
						printf("1.Potabilidad del agua\n");
						printf("2.Temperatura del agua (es decir, si esta fria o caliente)\n");
						printf("3.Datos sobre el pH\n");
						break;
					case 3:
						system("cls");
						printf("Que grafica desea consultar:\n");
						printf("1.Grafica pH\n");
						printf("2.Grafica turbidez\n");
						printf("3.Grafica coliformes\n");
						printf("3.Grafica conductividad\n");
						break;
					case 4:
						system("cls");
						printf("�Hasta pronto!");
						break;
					default:
					system("cls");	
				}
			break;
			} else if(opcion == 'S'){
				system("cls");
				printf("Has seleccionado San Blas\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'A'){
				system("cls");
				printf("Has seleccionado Atocha\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'T'){
				system("cls");
				printf("Has seleccionado Trafalgar\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'L'){
				system("cls");
				printf("Has seleccionado Legazpi\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			}else if(opcion == 'V'){
				system("cls");
				printf("Has seleccionado Vallehermoso\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'B'){
				system("cls");
				printf("Has seleccionado Berruguete\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'P'){
				system("cls");
				printf("Has seleccionado Pacifico\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'Q'){
				system("cls");
				printf("Has seleccionado Quintana\n");
				printf("Seleccione una opcion:\n");
				printf("1.Operaciones estadisticas (media,comparaciones...)\n");
				printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
				printf("3.Graficar funciones(seleccione parametro a graficar(pH,conductividad))\n");
				printf("4.Salir del programa\n");
				break;
			} else if(opcion == 'E'){
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
	} while((opcion!='C') || (opcion != 'Q') || (opcion != 'E') || (opcion != 'S') || (opcion != 'B') || (opcion != 'P') || (opcion != 'V') ||(opcion != 'T')|| (opcion != 'A')||(opcion != 'L'));
	
	return 0;
	
}

 #include <stdio.h>
#include <stdlib.h>

struct Tbarrios {
	char nombre[50];
	float ph;
	int coliformes;
	int conductividad;
	int turbidez;
	float ph[500];
	int coliformes[500];
	int conductividad[500];
	int turbidez[500];
};

float MediaPh(float[],int); //funcion que nos calcula la media del ph de todas las fuentes

int main () {
	
	struct Tbarrios fuentes[500];
	int i;
	
	int i=0;
	// Abrir el fichero
	FILE *dfe; // datos de las fuentes (fichero de entrada con el modo read) y datos de fuentes (fichero de salida con el modo write)
	
	dfe = fopen("202211_Coslada.csv.txt", "r");
@ -25,12 +22,6 @@ int main () {
		printf("Error, no puede abrirse el fichero.\n");   
		return 0;
	} 
	while (fscanf(dfe,"%s %f %d %d %d", fuentes[i].nombre,&fuentes[i].ph, &fuentes[i].coliformes, &fuentes[i].conductividad, &fuentes[i].turbidez) != EOF){
		/*printf("%s %f %d %d %d\n", fuentes[i].nombre,&fuentes[i].ph, &fuentes[i].coliformes, &fuentes[i].conductividad, &fuentes[i].turbidez);*/
		
		i++;
	}
	fclose(dfe);

	char opcion;
	int opcion1,eleccion;
@ -75,9 +66,16 @@ int main () {
						printf("6.Fuentes con la misma conductividad\n");
						scanf("%d", &eleccion);
						
						
						if(eleccion == 1) {
							/*MediaPh(fuentes[i].ph , 20);*/
							printf("%s %f %d %d %d\n", fuentes[i].nombre,&fuentes[i].ph, &fuentes[i].coliformes, &fuentes[i].conductividad, &fuentes[i].turbidez);
							struct Tbarrios fuentes[500];
							i = 0;
							while (fscanf(dfe,"%f %d %d %d", &fuentes[i].ph, &fuentes[i].coliformes, &fuentes[i].conductividad, &fuentes[i].turbidez) != EOF){
								printf("%f\n", fuentes[i].ph);
								 MediaPh(fuentes[i].ph , 20);
								i++;
							}
							fclose(dfe);
							printf("La media del pH es: %f",MediaPh);
							
						}else if(eleccion ==2) {
@ -91,133 +89,134 @@
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
						printf("?Hasta pronto!");
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

float MediaPh(float v[], int dim)  {     // funcion generica tanto como si son 5 elementos como si son 7 elementos ---> IMPORTANTE
	int i;
	float media =0;
	
	for(i=0;i<dim;i++) {   //no hay ninguna marca que me indique que el vector termina en el \0 por ejemplo como en las cadenas,por eso ponemos la dimension(dim) que ademas tambien tendra que entrar como parametro a la funcion
		media += v[i];
	}
	return (media/dim);

}

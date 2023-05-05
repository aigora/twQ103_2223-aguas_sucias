#include <stdio.h>
#include <stdlib.h>
#define MAX_FUENTES 100
#include <string.h>
#include <windows.h>
typedef struct {
    char nombre[50];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
} Barrio;

float comparacionpH(Barrio fuentes[], int num_fuentes) {
    float max_ph = 0.0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        if (fuentes[i].ph > max_ph) {
            max_ph = fuentes[i].ph;
        }
    }
    return max_ph;
}

int comparacionConductividad(Barrio fuentes[], int num_fuentes) {
    int max_conductividad = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        if (fuentes[i].conductividad > max_conductividad) {
            max_conductividad = fuentes[i].conductividad;
        }
    }
    return max_conductividad;
}

int funciondetectorph(Barrio fuentes[], int num_fuentes) {
	int i;
	for(i=0;i< num_fuentes; i++){
	
		if(	fuentes[i].ph >14||	fuentes[i].ph<0){
		
		printf("Algunos de los datos del ph son erroneos por ser mayores de 14 o negativos\n");
		break;
		}
	}
}



void funcionmenu(){
	
    char palabra[] ="    ***           ***  *********  *******    **   ********  ";
	char palabra1[] ="    ****         ****  **         **    ***  **  **      **";
	char palabra2[] ="    ** **       ** **  **         **      *  **  **      **";
	char palabra3[] ="    **  **     **  **  **         **      *  **  **      **";
	char palabra4[] ="    **   **   **   **  *********  **      *  **  **      **";
	char palabra5[] ="    **    ** **    **  **         **      *  **  **      **";
	char palabra6[] ="    **     ***     **  **         **      *  **  **      **";
	char palabra7[] ="    **             **  **         **    ***  **  **      **";
	char palabra8[] ="    **             **  *********  *******    **   ******** ";
	char palabra9[] ="       00000 00   00 0000  00000 00000 0   0 00000 00000";
	char palabra10[] ="       0   0 0 0 0 0 0   0   0   0     00  0   0   0";
	char palabra11[] ="       00000 0  0  0 0000    0   0000  0 0 0   0   0000";
	char palabra12[] ="       0   0 0     0 0   0   0   0     0  00   0   0";
	char palabra13[] ="       0   0 0     0 0000  00000 00000 0   0   0   00000";
	char frase[]="AGUAS SUCIAS.SL PRESENTS:";
    int x = 0; // Posición inicial en la coordenada x
    int y = 5; // Posición en la coordenada y
    int mitad_pantalla = 50; // Mitad de la pantalla

    while(x < mitad_pantalla) // Bucle que se detiene en la mitad de la pantalla
    {
        system("cls"); // Limpia la pantalla
        printf("\033[%d;%dH%s", y, x, palabra);
		int y1=6;
        printf("\033[%d;%dH%s", y1, x, palabra1);
        int y2=7;
        printf("\033[%d;%dH%s", y2, x, palabra2);
        int y3=8;
        printf("\033[%d;%dH%s", y3, x, palabra3);
        int y4=9;
        printf("\033[%d;%dH%s", y4, x, palabra4);
        int y5=10;
        printf("\033[%d;%dH%s", y5, x, palabra5);
        int y6=11;
        printf("\033[%d;%dH%s", y6, x, palabra6);
         int y7=12;
        printf("\033[%d;%dH%s", y7, x, palabra7);
        int y8=13;
        printf("\033[%d;%dH%s", y8, x, palabra8);
         int y9=15;
        printf("\033[%d;%dH%s", y9, x, palabra9);
           int y10=16;
        printf("\033[%d;%dH%s", y10, x, palabra10);
           int y11=17;
        printf("\033[%d;%dH%s", y11, x, palabra11);
           int y12=18;
        printf("\033[%d;%dH%s", y12, x, palabra12);
           int y13=19;
        printf("\033[%d;%dH%s", y13, x, palabra13);
           int y14=1;
        printf("\033[%d;%dH%s", y14, x, frase);
        fflush(stdout); // Limpia el buffer de salida

        x++; // Incrementa la posición en x

        Sleep(100); // Espera 100 milisegundos antes de volver a imprimir
    }

    system("cls"); // Limpia la pantalla
    fflush(stdout); // Limpia el buffer de salida

 
}

float calcular_sumatorio_ph(Barrio fuentes[], int num_fuentes) {
    float sumatorioph = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        sumatorioph += fuentes[i].ph;
    }
    return sumatorioph;
}

float calcular_sumatorio_conductividad(Barrio fuentes[], int num_fuentes) {
    float sumatorioconductividad = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        sumatorioconductividad += fuentes[i].conductividad;
    }
    return sumatorioconductividad;
}
int lectorficheros() {
    Barrio Fuentes[MAX_FUENTES];
    int i = 0,contador=-1, opcion, segundaopcion, cuartaopcion;
    char nombrefichero[100];

    
     printf("Ingrese el nombre del archivo con los datos de las fuentes: ");
    scanf("%s", nombrefichero);

    // Abrir el archivo para lectura
    FILE* ficherofuentes;
	ficherofuentes = fopen(nombrefichero, "r");
    
    if (ficherofuentes == NULL) {
		printf("Error, no puede abrirse el fichero.\n");   
		return 0;
	} 
	


    // Leer el archivo línea por línea
    while (!feof(ficherofuentes) && i < MAX_FUENTES) {
        fscanf(ficherofuentes, "%s %f %d %d %d", Fuentes[i].nombre, &Fuentes[i].ph, &Fuentes[i].conductividad,&Fuentes[i].turbidez,&Fuentes[i].coliformes);
        i++;
        contador++;
    }

    // Cerrar el archivo
    fclose(ficherofuentes);

    // Imprimir los datos
    int j;
    for ( j = 0; j < contador; j++) {
        printf("%s tiene un ph de %.2f una conductividad de: %d turbidez de: %d y coliformes: %d\n", Fuentes[j].nombre, Fuentes[j].ph, Fuentes[j].conductividad, Fuentes[j].turbidez, Fuentes[j].coliformes);
    }
    
    funciondetectorph(Fuentes, contador+1);

return 1;
}


int main(){
	funcionmenu();
	do{
	
	lectorficheros();
	}while (lectorficheros()==0);
	int i = 0, opcion, segundaopcion, cuartaopcion, contador=-1;
	Barrio Fuentes[MAX_FUENTES];
	do{
	
   printf("Seleccione una opcion:\n");
	printf("1.Operaciones estadisticas (medias)\n");
	printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
	printf("3.Comparaciones\n");
	printf("4.Salir del programa\n");
	scanf("%d",& opcion);
	}while(opcion<1 || opcion>4);
		system("cls");
	   if(opcion==1){
		do{
		
		printf("Seleccione una de las siguientes operaciones estadisticas:\n");
	    printf("1. Media de los niveles de pH de las fuentes\n");
	    printf("2.Media de los niveles de conductividad de las fuentes\n");
	    printf("3.Salir del programa\n");
	    scanf("%d",& segundaopcion);
		}while(segundaopcion<1 || segundaopcion>3);
		system("cls");
		if(segundaopcion==1){
			float sumatorioph = calcular_sumatorio_ph(Fuentes, contador+1);
			printf("La media del pH de todas las fuentes es: %f", sumatorioph/contador);
		}else if(segundaopcion==2){
			float sumatorioconductividad = calcular_sumatorio_conductividad(Fuentes, contador+1);
            printf("La conductividad media es: %f", sumatorioconductividad/contador);
		}
	}else if(opcion == 2) {
		
	}else if(opcion==3) {
		do{
		printf("Selecciona una opcion:\n");
		printf("1.Imprimir mayor pH\n");
		printf("2.Imprimir mayor conductividad\n");
		scanf("%d",&cuartaopcion);
		}while(cuartaopcion<1 || cuartaopcion>2);
		
		if(cuartaopcion==1){
		  
		float mayorPh= comparacionpH(Fuentes, contador+1);
		printf("El mayor pH es: %f\n", mayorPh);
		   
		}else if(cuartaopcion==2){
		   	
		int mayorconductividad= comparacionConductividad(Fuentes, contador+1);
		printf("La mayor conductividad es: %d\n", mayorconductividad);
		}
	    
	}
}







	




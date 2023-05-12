#include <stdio.h>
#include <math.h>
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

void graficoph(Barrio fuentes[], int num_fuentes) {
	int i,j, valorph;
	for(i=0; i<num_fuentes;i++){
		printf("\n%s:", fuentes[i].nombre);
		valorph =(int)fuentes[i].ph;
		for(j=0;j<valorph;j++){
			printf("*");
		}
	}
}

void graficoconductividad(Barrio fuentes[], int num_fuentes) {
	int i,j,valorconductividad;
	for(i=0; i<num_fuentes;i++){
		printf("\n%s:", fuentes[i].nombre);
		valorconductividad=(int)(fuentes[i].conductividad/3);
		for(j=0;j<valorconductividad;j++){
			printf("*");
		}
	}
}
void graficoturbidez(Barrio fuentes[], int num_fuentes) {
	int i,j;
	for(i=0; i<num_fuentes;i++){
		printf("\n%s:", fuentes[i].nombre);
		for(j=0;j<fuentes[i].turbidez;j++){
			printf("*");
		}
	}
}

void graficocoliformes(Barrio fuentes[], int num_fuentes) {
	int i,j;
	for(i=0; i<num_fuentes;i++){
		printf("\n%s:", fuentes[i].nombre);
		for(j=0;j<fuentes[i].coliformes;j++){
			printf("*");
		}
	}
}
void aguacaliente(Barrio fuentes[], int num_fuentes) {
	int i;
	for (i = 0; i < num_fuentes; i++){
		if (fuentes[i].turbidez > 5 ) {
           printf("El agua de la %s esta caliente\n",fuentes[i].nombre);
        }
        else {
        	printf("El agua de la %s esta fria\n",fuentes[i].nombre);
		}
	}
}

void aguapotable(Barrio fuentes[], int num_fuentes) {
	int i;
	for(i=0;i<num_fuentes;i++) {
	   if((6.5>fuentes[i].ph) || (fuentes[i].ph>9.5)||(fuentes[i].conductividad >200)||(fuentes[i].turbidez>5)||(fuentes[i].coliformes >2)) {
		 printf("El agua de la %s NO es potable\n",fuentes[i].nombre);
	   }else {
		  printf("El agua de la %s  es potable\n",fuentes[i].nombre);
		}
	}
	
}
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

float calcular_desviaciontipica_ph(Barrio fuentes[], int num_fuentes){
    int i;
    float sumatorio_de_cuadrados=0.0,sumatoriodividido,Media_ph;
    Media_ph=calcular_sumatorio_ph(fuentes,num_fuentes)/num_fuentes;
    printf("%f\n", Media_ph);
    for(i=0;i<num_fuentes;i++){
    	sumatorio_de_cuadrados+=pow((fuentes[i].ph-Media_ph),2);
	}
	printf("%f\n", sumatorio_de_cuadrados);
	sumatoriodividido=sumatorio_de_cuadrados/num_fuentes;
    return sqrt(sumatoriodividido);
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

int main() {
    Barrio Fuentes[MAX_FUENTES];
	int  opcion, segundaopcion, cuartaopcion,terceraopcion, quintaopcion;
    char nombrefichero[100];

	
    funcionmenu();
     printf("Ingrese el nombre del archivo con los datos de las fuentes: ");
    scanf("%s", nombrefichero);

    // Abrir el archivo para lectura
    FILE* ficherofuentes;
	ficherofuentes = fopen(nombrefichero, "r");
    
    if (ficherofuentes == NULL) {
		printf("Error, no puede abrirse el fichero.\n");   
		return 0;
	} 
	char nombre1[20], nombre2[20], nombre3[20], nombre4[20], nombre5[20];
    fscanf(ficherofuentes, "%s %s %s %s %s", nombre1, nombre2, nombre3, nombre4, nombre5);

    // Leer el archivo línea por línea
    int i = 0;
    int contador = 0;
    while (!feof(ficherofuentes) && i < MAX_FUENTES) {
      fscanf(ficherofuentes, "%s %f %d %d %d", Fuentes[i].nombre, &Fuentes[i].ph, &Fuentes[i].conductividad, &Fuentes[i].turbidez, &Fuentes[i].coliformes);
       i++;
    contador++;
    }
    printf("Hay un total de %d fuentes\n", contador);
    // Cerrar el archivo
    fclose(ficherofuentes);

    // Imprimir los datos
    int j;
for (j = 0; j < contador; j++) {
        printf("%s tiene un %s de %.2f, una %s de %d, una %s de %d y %s de %d\n",
           Fuentes[j].nombre, nombre2, Fuentes[j].ph, nombre3, Fuentes[j].conductividad,
           nombre4, Fuentes[j].turbidez, nombre5, Fuentes[j].coliformes);
    }   
    
    funciondetectorph(Fuentes, contador+1);
    while (1){
    	Sleep(1000);
	
    do{
   printf("Seleccione una opcion:\n");
	printf("1.Operaciones estadisticas (medias,desviacion tipica)\n");
	printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n");
	printf("3.Comparaciones\n");
	printf("4.Graficos de asteriscos\n");
	printf("5.Salir del programa\n");
	scanf("%d",& opcion);
	}while(opcion<1 || opcion>5);
		system("cls");
	   if(opcion==1){
		do{
		
		printf("Seleccione una de las siguientes operaciones estadisticas:\n");
	    printf("1. Media de los niveles de pH de las fuentes\n");
	    printf("2.Media de los niveles de conductividad de las fuentes\n");
	    printf("3.Desviacion tipica del pH con los datos de las fuentes\n");
	    printf("4. Desviacion tipica de la conductividad con los datos de las fuentes\n");
	    printf("5.Salir del programa\n");
	    scanf("%d",& segundaopcion);
		}while(segundaopcion<1 || segundaopcion>5);
		
		system("cls");

		if(segundaopcion==1){
			float sumatorioph = calcular_sumatorio_ph(Fuentes, contador);
			printf("La media del pH de todas las fuentes es: %.2f\n", sumatorioph/contador);
		}else if(segundaopcion==2){
			float sumatorioconductividad = calcular_sumatorio_conductividad(Fuentes, contador);
            printf("La conductividad media es: %.2f\n", sumatorioconductividad/contador);
		}else if(segundaopcion==3) {
	
		 printf("La Desviacion tipica es: %.2f\n",calcular_desviaciontipica_ph(Fuentes, contador));
			
		}else if(segundaopcion==4) {
			
		}else if(segundaopcion==5) {
		 printf("Saliendo del programa...Hasta pronto...");
		 break;
		}
		
		
	} else if(opcion == 2) {
		do {
		
		printf("Selecciona una opcion:\n");
		printf("1.Informacion sobre la temperatura del agua\n");
		printf("2.Informacion sobre la potabilidad del agua\n");
		scanf("%d",&terceraopcion);
		}while(terceraopcion<1 || terceraopcion>2);
		
		if(terceraopcion==1){
		  aguacaliente(Fuentes,contador);
	
		}else if (terceraopcion==2){
			aguapotable(Fuentes,contador);
		}
		
	} else if(opcion==3) {
		do{
		printf("Selecciona una opcion:\n");
		printf("1.Imprimir mayor pH\n");
		printf("2.Imprimir mayor conductividad\n");
		scanf("%d",&cuartaopcion);
		}while(cuartaopcion<1 || cuartaopcion>2);
		
		if(cuartaopcion==1){
		  
			float mayorPh= comparacionpH(Fuentes, contador);
			printf("El mayor pH es: %.2f\n", mayorPh);
		   
		}else if(cuartaopcion==2){
		   	
			int mayorconductividad= comparacionConductividad(Fuentes, contador);
			printf("La mayor conductividad es: %d\n", mayorconductividad);
		}
	    
	}else if(opcion==4) {
		do{
	    	printf("Selecciona una opcion:\n");
		printf("1.Grafico de asteriscos del ph del agua\n");
		printf("2.Grafico de asteriscos de la conductividad del agua\n");
		printf("3.Grafico de asteriscos de la turbidez del agua\n");
		printf("4.Grafico de asteriscos de los coliformes del agua\n");
		scanf("%d",&quintaopcion);
		}while(quintaopcion<1 || quintaopcion>4);
		if(quintaopcion==1){
		  graficoph(Fuentes,contador);
		  printf("\n");	   
		}else if(quintaopcion==2){
			graficoconductividad(Fuentes,contador);
			printf("\n");
		}else if(quintaopcion==3){
			graficoturbidez(Fuentes,contador);
			printf("\n");
		}else if(quintaopcion==4){
			graficocoliformes(Fuentes,contador);
			printf("\n");
	    }	
	}else if(opcion==5){
	 printf("Saliendo del programa...Hasta pronto...");
		break;
	}
	
}
 

   return 0;
}


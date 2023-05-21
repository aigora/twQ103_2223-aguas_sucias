#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_FUENTES 100
#include <string.h>
#include <windows.h>

// Definimos la funcion estructura llamada barrio que recoge los datos de las fuentes (ph,conductividad...)
typedef struct { 
    char nombre[50];
    float ph;
    int conductividad;
    int turbidez;
    int coliformes;
} Barrio;
void leerPrimerFicheroQ() {
    FILE* fichero_lectura; 
    FILE* fichero_fusion; 
    
    fichero_lectura = fopen("202201_Quintana.csv.txt", "r");
    fichero_fusion = fopen("fusion.txt", "w");
    if (fichero_lectura == NULL || fichero_fusion == NULL) {
        printf("Error al abrir los ficheros.\n");
        return;
    }

    char nombres[5][50];//Aquí decaramos una matriz de caracteres bidimensional llamada nombres con 5 filas una cadena de caracteres 
    Barrio barrio;
    int i;

    // Leemos y escaneamos los 5 primeros nombres que son (nombre, pH Conductividad, turbidez y coliformes.
    for (i = 0; i < 5; i++) {
        fscanf(fichero_lectura, "%s", nombres[i]);
    }

    
    for (i = 0; i < 5; i++) {// y los escribimos en el fichero fusion.txt
        fprintf(fichero_fusion, "%s ", nombres[i]);
    }
    fprintf(fichero_fusion, "\n");

    // Leemos el resto de datos y los imprimimos en el fichero fusion.txt
    while (fscanf(fichero_lectura, "%s %f %d %d %d",
                  barrio.nombre, &barrio.ph, &barrio.conductividad, &barrio.turbidez, &barrio.coliformes) == 5) {
        fprintf(fichero_fusion, "%s %.2f %d %d %d\n",
                barrio.nombre, barrio.ph, barrio.conductividad, barrio.turbidez, barrio.coliformes);
    }

    fclose(fichero_lectura);
    fclose(fichero_fusion);// cerramos ambos ficheros 
}

void fusionarFicherosQ() {
    FILE* fichero_fusion;
    
    fichero_fusion = fopen("fusion.txt", "a");// abrimos de nuevo ficherofusion.txt modo 'a' que permite añadir datos al fichero
    
    if (fichero_fusion == NULL) {
        printf("Error al abrir el fichero de fusión.\n");
        return;
    }

    int i;

    for (i = 2; i <= 12; i++) {
        char nombre_fichero[50];
        sprintf(nombre_fichero, "2022%02d_Quintana.csv.txt", i);

        FILE* fichero_lectura = fopen(nombre_fichero, "r");

        if (fichero_lectura == NULL) {
            printf("Error al abrir el fichero %s.\n", nombre_fichero);
            continue;
        }

        char linea[100];

        // Ignorar la primera línea
        fgets(linea, sizeof(linea), fichero_lectura);

        // Salto de línea antes de imprimir el contenido del siguiente fichero
        fprintf(fichero_fusion, "\n");

        // Copiar el contenido del fichero al fichero fusion.txt
        while (fgets(linea, sizeof(linea), fichero_lectura) != NULL) {
            fprintf(fichero_fusion, "%s", linea);
        }

        fclose(fichero_lectura);
    }

    fclose(fichero_fusion);
}
// Comienzo de definicion de funciones
// Usamos esta funcion para crear un grafico con asteriscos del ph (si el ph es 7.6 lo redondearia a 8 y entonces imprimiria por pantalla 8 asteriscos, mientras que si es un numero entero lo dejaria tal cual)
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
// Usamos esta funcion para crear un grafico con asteriscos de la conductividad
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
// Usamos esta funcion para crear un grafico con asteriscos de la turbidez
void graficoturbidez(Barrio fuentes[], int num_fuentes) {
	int i,j;
	for(i=0; i<num_fuentes;i++){
		printf("\n%s:", fuentes[i].nombre);
		for(j=0;j<fuentes[i].turbidez;j++){
			printf("*");
		}
	}
}
// Usamos esta funcion para crear un grafico con asteriscos de los coliformes
void graficocoliformes(Barrio fuentes[], int num_fuentes) {
	int i,j;
	for(i=0; i<num_fuentes;i++){
		printf("\n%s:", fuentes[i].nombre);
		for(j=0;j<fuentes[i].coliformes;j++){
			printf("*");
		}
	}
}

// Usamos esta funcion para saber si el agua esta caliente o fria dependiendo de si la turbidez es > o < 5
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
// Usamos esta funcion para saber si el agua es o no potable
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
// Usamos esta funcion para saber cual es el mayor ph de entre todas las fuentes
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
//Usamos esta funcion para saber cual es el mayor valor de la conductividad de entre todas las fuentes
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
// Usamos esta funcion para saber si el ph de alguna fuente es erroneo o no (es decir ,no esta entre el rango 0-14) 
int funciondetectorph(Barrio fuentes[], int num_fuentes) {
	int i;
	for(i=0;i< num_fuentes; i++){
	
		if(	fuentes[i].ph >14||	fuentes[i].ph<0){
		
		printf("Algunos de los datos del ph son erroneos por ser mayores de 14 o negativos\n");
		break;
		}
	}
}
// Usamos esta funcion para calcular el sumatorio de todos los ph de las fuentes y luego poder calcular la media y la desviacion total del ph
float calcular_sumatorio_ph(Barrio fuentes[], int num_fuentes) {
    float sumatorioph = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        sumatorioph += fuentes[i].ph;
    }
    return sumatorioph;
}
// Usamos esta funcion para calcular el sumatorio de la conductividad de las fuentes y luego poder calcular la media total y la desviacion de la conductividad
float calcular_sumatorio_conductividad(Barrio fuentes[], int num_fuentes) {
    float sumatorioconductividad = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        sumatorioconductividad += fuentes[i].conductividad;
    }
    return sumatorioconductividad;
}
// Usamos esta funcion para calcular el sumatorio de la turbidez de todas las fuentes y luego poder calcular la media total  y la desviacion de la turbidez
float calcular_sumatorio_turbidez(Barrio fuentes[], int num_fuentes) {
    float sumatorioturbidez = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        sumatorioturbidez += fuentes[i].turbidez;
    }
    return sumatorioturbidez;
}
// Usamos esta funcion para calcular el sumatorio de la turbidez de todas las fuentes y luego poder calcular la media total  y la desviacion de la turbidez

float calcular_sumatorio_coliformes(Barrio fuentes[], int num_fuentes) {
    float sumatoriocoliformes = 0;
    int i;
    for (i = 0; i < num_fuentes; i++) {
        sumatoriocoliformes += fuentes[i].coliformes;
    }
    return sumatoriocoliformes;
}
// Usamos esta funcion para calcular la desviacion tipica  del ph
float calcular_desviaciontipica_ph(Barrio fuentes[], int num_fuentes){
    int i;
    float sumatorio_de_cuadrados=0.0,sumatoriodividido=0,Media_ph;
    Media_ph=calcular_sumatorio_ph(fuentes,num_fuentes)/num_fuentes;
    int j;
    for(j=0;j<num_fuentes;j++){
  
    	sumatorio_de_cuadrados+=((fuentes[j].ph-Media_ph)*(fuentes[j].ph-Media_ph));
	}
	sumatoriodividido=sumatorio_de_cuadrados/num_fuentes;
    return sqrt(sumatoriodividido);
}
// Usamos esta funcion para calcular la desviacion tipica de la conductividad
float calcular_desviaciontipica_Conductividad(Barrio fuentes[], int num_fuentes){
    int i;
    float sumatorio_de_cuadrados=0.0,sumatoriodividido=0,Media_conductividad;
    Media_conductividad=calcular_sumatorio_conductividad(fuentes,num_fuentes)/num_fuentes;
    int j;
    for(j=0;j<num_fuentes;j++){
  
    	sumatorio_de_cuadrados+=((fuentes[j].conductividad-Media_conductividad)*(fuentes[j].conductividad-Media_conductividad));
	}
	sumatoriodividido=sumatorio_de_cuadrados/num_fuentes;
    return sqrt(sumatoriodividido);
}
// Usamos esta funcion para calcular la desviacion tipica de la turbidez
float calcular_desviaciontipica_turbidez(Barrio fuentes[], int num_fuentes){
    int i;
    float sumatorio_de_cuadrados=0.0,sumatoriodividido=0,Media_turbidez;
    Media_turbidez=calcular_sumatorio_turbidez(fuentes,num_fuentes)/num_fuentes;
    int j;
    for(j=0;j<num_fuentes;j++){
  
    	sumatorio_de_cuadrados+=((fuentes[j].turbidez-Media_turbidez)*(fuentes[j].turbidez-Media_turbidez));
	}
	sumatoriodividido=sumatorio_de_cuadrados/num_fuentes;
    return sqrt(sumatoriodividido);
}
// Usamos esta funcion para calcular la desviacion tipica de los coliformes
float calcular_desviaciontipica_coliformes(Barrio fuentes[], int num_fuentes){
    int i;
    float sumatorio_de_cuadrados=0.0,sumatoriodividido=0,Media_coliformes;
    Media_coliformes=calcular_sumatorio_coliformes(fuentes,num_fuentes)/num_fuentes;
    int j;
    for(j=0;j<num_fuentes;j++){
  
    	sumatorio_de_cuadrados+=((fuentes[j].coliformes-Media_coliformes)*(fuentes[j].coliformes-Media_coliformes));
	}
	sumatoriodividido=sumatorio_de_cuadrados/num_fuentes;
    return sqrt(sumatoriodividido);
}
// Esta funcion nos presenta por pantalla el inicio del programa con el titulo (MEDIO AMBIENTE)
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
// Inicio del programa

int main() {
	
	//Declaracion de variables
	
    Barrio Fuentes[MAX_FUENTES];
	int  opcion, segundaopcion, cuartaopcion,terceraopcion, quintaopcion;
    char nombrefichero[100];

    funcionmenu();
     printf("Ingrese el nombre del archivo con los datos de las fuentes:\a");// ponemos \a para que pite 
    scanf("%s", nombrefichero);

    // Abrir el fichero (modo lectura)
    
    FILE* ficherofuentes;
    FILE* ficheroresultados;
    
	ficherofuentes = fopen(nombrefichero, "r");
	ficheroresultados = fopen("resultadosfuentes.txt", "w");
    //Si no se encuentra el fichero, el programa emite un mensaje dando un aviso
    if (ficherofuentes == NULL) {
		printf("Error, no puede abrirse el fichero.\n");   
		return 0;
	} 
	if (ficheroresultados == NULL) {
		printf("Error, no puede crear el fichero.\n");   
		return 0;
	} 
	
	// Lee la primera linea del fichero con los datos de las fuentes
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
    // Imprimir los datos por pantalla
    int j;
for (j = 0; j < contador; j++) {
        printf("%s tiene un %s de %.2f, una %s de %d, una %s de %d y %s de %d\n",
           Fuentes[j].nombre, nombre2, Fuentes[j].ph, nombre3, Fuentes[j].conductividad,
           nombre4, Fuentes[j].turbidez, nombre5, Fuentes[j].coliformes);
    }   
    
    funciondetectorph(Fuentes, contador+1);
    // Bucle infinito para pedir varios datos al usuario hasta que desee salir del programa pulsando 5
    while (1){
    	Sleep(1000);
    	
	// Menu de opciones
	
    do{
   printf("Seleccione una opcion:\n\n");
	printf("1.Operaciones estadisticas (medias,desviacion tipica)\n\n\a");
	printf("2.Caracteristicas del agua (potable o no, caliente o fria...)\n\n");
	printf("3.Comparaciones\n\n");
	printf("4.Graficos de asteriscos\n\n");
	printf("5.Fusionador ficheros de Quintana de un anio entero\n\n");
	printf("6.Salir del programa\n\n");
	scanf("%d",& opcion);
	}while(opcion<1 || opcion>6);
		system("cls");
	   if(opcion==1){
		do{
		printf("Seleccione una de las siguientes operaciones estadisticas:\n\n");
	    printf("1. Media de los niveles de pH de las fuentes\n\n");
	    printf("2.Media de los niveles de conductividad de las fuentes\n\n");
	    printf("3.Media de los niveles de turbidez de las fuentes\n\n");
	    printf("4.Media de los niveles de coliformes de las fuentes\n\n");
	    printf("5.Desviacion tipica y varianza del pH con los datos de las fuentes\n\n");
	    printf("6. Desviacion tipica y varianza de la conductividad con los datos de las fuentes\n\n");
	    printf("7. Desviacion tipica y varianza de la turbidez con los datos de las fuentes\n\n");
	    printf("8. Desviacion tipica y varianza de los coliformes con los datos de las fuentes\n\n");
	    printf("9.Salir del programa\n\n");
	    scanf("%d",& segundaopcion);
		} while(segundaopcion<1 || segundaopcion>9);
		
		system("cls");

		if(segundaopcion==1){	
			float sumatorioph = calcular_sumatorio_ph(Fuentes, contador);
			printf("La media del pH de todas las fuentes es: %.3f\n\n", sumatorioph/contador);
			fprintf(ficheroresultados,"La media del pH de todas las fuentes es: %.3f\n\n", sumatorioph/contador);
		}else if(segundaopcion==2){
			
			float sumatorioconductividad = calcular_sumatorio_conductividad(Fuentes, contador);
            printf("La conductividad media es: %.2f\n\n", sumatorioconductividad/contador);
            fprintf(ficheroresultados,"La conductividad media es: %.2f\n\n", sumatorioconductividad/contador);
        
		}else if(segundaopcion==3){
			
			float sumatorioturbidez = calcular_sumatorio_turbidez(Fuentes, contador);
            printf("La turbidez media de las fuentes es: %.2f\n\n", sumatorioturbidez/contador);
           fprintf(ficheroresultados,"La turbidez media de las fuentes es: %.2f\n\n", sumatorioturbidez/contador);
            
		}else if(segundaopcion==4){
			
            float sumatoriocoliformes = calcular_sumatorio_coliformes(Fuentes, contador);
            printf("La media de coliformes en el agua de las fuentes es de: %.2f\n\n", sumatoriocoliformes/contador);
            fprintf(ficheroresultados,"La media de coliformes en el agua de las fuentes es de: %.2f\n\n", sumatoriocoliformes/contador);
            
		}else if(segundaopcion==5) {
	
		 printf("La Desviacion tipica de los datos del pH es: %.3f\n\n",calcular_desviaciontipica_ph(Fuentes, contador));
		 fprintf(ficheroresultados,"La Desviacion tipica de los datos del pH es: %.3f\n\n",calcular_desviaciontipica_ph(Fuentes, contador));
		 printf("La Varianza de los datos del pH es: %.3f\n\n",(calcular_desviaciontipica_ph(Fuentes, contador)*calcular_desviaciontipica_ph(Fuentes, contador)));	
		 fprintf(ficheroresultados,"La Varianza de los datos del pH es: %.3f\n\n",(calcular_desviaciontipica_ph(Fuentes, contador)*calcular_desviaciontipica_ph(Fuentes, contador)));
		 
		}else if(segundaopcion==6) {
			
		 printf("La Desviacion tipica de los datos de la conductividad es: %.3f\n\n",calcular_desviaciontipica_Conductividad(Fuentes, contador));
		 fprintf(ficheroresultados,"La Desviacion tipica de los datos de la conductividad es: %.3f\n\n",calcular_desviaciontipica_Conductividad(Fuentes, contador));
		 printf("La Varianza de los datos de la conductividad es: %.3f\n\n",(calcular_desviaciontipica_Conductividad(Fuentes, contador)*calcular_desviaciontipica_Conductividad(Fuentes, contador)));
		 fprintf(ficheroresultados,"La Varianza de los datos de la conductividad es: %.3f\n\n",(calcular_desviaciontipica_Conductividad(Fuentes, contador)*calcular_desviaciontipica_Conductividad(Fuentes, contador)));
		}else if(segundaopcion==7) {
			
		 printf("La Desviacion tipica de los datos de la turbidez es: %.3f\n\n",calcular_desviaciontipica_turbidez(Fuentes, contador));
		 fprintf(ficheroresultados,"La Desviacion tipica de los datos de la turbidez es: %.3f\n\n",calcular_desviaciontipica_turbidez(Fuentes, contador));
		 printf("La Varianza de los datos de la turbidez es: %.3f\n\n",(calcular_desviaciontipica_turbidez(Fuentes, contador)*calcular_desviaciontipica_turbidez(Fuentes, contador)));
		 fprintf(ficheroresultados,"La Varianza de los datos de la turbidez es: %.3f\n\n",(calcular_desviaciontipica_turbidez(Fuentes, contador)*calcular_desviaciontipica_turbidez(Fuentes, contador)));	
		}else if(segundaopcion==8) {
			
		 printf("La Desviacion tipica de los datos de los coliformes es: %.3f\n\n",calcular_desviaciontipica_coliformes(Fuentes, contador));
		 fprintf(ficheroresultados,"La Desviacion tipica de los datos de los coliformes es: %.3f\n\n",calcular_desviaciontipica_coliformes(Fuentes, contador));	
		 printf("La Varianza de los datos de los coliformes es: %.3f\n\n",(calcular_desviaciontipica_coliformes(Fuentes, contador)*calcular_desviaciontipica_coliformes(Fuentes, contador)));
		fprintf(ficheroresultados,"La Varianza de los datos de los coliformes es: %.3f\n\n",(calcular_desviaciontipica_coliformes(Fuentes, contador)*calcular_desviaciontipica_coliformes(Fuentes, contador)));	
		}else if(segundaopcion==9) {
			
		 printf("Saliendo del programa...Hasta pronto...");
		 // Al poner un break lo que hacemos es salir del programa
		 break;
		}		
	} else if(opcion == 2) {
		
		do {
		  printf("Selecciona una opcion:\n");
		  printf("1.Informacion sobre la temperatura del agua\n\n");
		  printf("2.Informacion sobre la potabilidad del agua\n\n");
		  scanf("%d",&terceraopcion);
		}while(terceraopcion<1 || terceraopcion>2);
		
		if(terceraopcion==1){
		  aguacaliente(Fuentes,contador);
		}else if (terceraopcion==2){
		  aguapotable(Fuentes,contador);
		}
		
	} else if(opcion==3) {
		do{
		  printf("Selecciona una opcion:\n\n");
		  printf("1.Imprimir mayor pH\n\n");
		  printf("2.Imprimir mayor conductividad\n\n");
		  scanf("%d",&cuartaopcion);
		}while(cuartaopcion<1 || cuartaopcion>2);
		
		if(cuartaopcion==1){
		  
			float mayorPh= comparacionpH(Fuentes, contador);
			printf("El mayor pH es: %.2f\n\n", mayorPh);
		    fprintf(ficheroresultados,"El mayor pH es: %.2f\n\n", mayorPh);
		}else if(cuartaopcion==2){
		   	
			int mayorconductividad= comparacionConductividad(Fuentes, contador);
			printf("La mayor conductividad es: %d\n\n", mayorconductividad);
			fprintf(ficheroresultados, "La mayor conductividad es: %d\n\n", mayorconductividad);
		}
	    
	}else if(opcion==4) {
		do{
	      printf("Selecciona una opcion:\n\n");
		  printf("1.Grafico de asteriscos del ph del agua\n\n");
		  printf("2.Grafico de asteriscos de la conductividad del agua\n\n");
		  printf("3.Grafico de asteriscos de la turbidez del agua\n\n");
		  printf("4.Grafico de asteriscos de los coliformes del agua\n\n");
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
	  leerPrimerFicheroQ();
     fusionarFicherosQ();
     printf("Se ha creado correctamente el fichero fusion.txt con los datos de las fuentes de todo un anio.\nAhora sal del programa e ingrese el fichero fusion.txt para trabajar con el");
		break;
	}else if(opcion==6){
	 printf("Saliendo del programa...Hasta pronto...");
	  // Al poner un break lo que hacemos es salir del programa
		break;
	}
	
}
 
	fclose(ficheroresultados);
   return 0;
}


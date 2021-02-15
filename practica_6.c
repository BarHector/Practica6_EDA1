#include <stdio.h>

int inserta(int *apunta, int tope);
int elimina(int *apunta, int tope);
void imprime(int *apunta, int tope);

int main(){
	int cola[10];  
	int tope = 0, opcion; 
	int *apunta;
	apunta=cola;

	do{
		printf("\t***** MENU ***** \n1. Insertar \n2. Eliminar \n3. Imprimir todo \n4. Imprimir cabeza \n5. Imprimir cola \n6. Salir \nOpcion:  ");
		scanf("%d",&opcion);
		fflush(stdin);
        printf("\n");
		switch(opcion){
			case 1: tope=inserta(apunta,tope);
					break;
			case 2: tope=elimina(apunta,tope);
					break;
			case 3: imprime(apunta,tope);
					break;
			case 4: printf("Cabeza: %i\n", *apunta);
					break;
            case 5: printf("Cola: %i\n", *(apunta+(tope-1)));
                    break;
            case 6: printf("VUELVE PRONTO");
                    break;
			default: printf("OPCION INVALIDA, CERRANDO PROGRAMA\n");
					break; 
		}
        printf("\n");
	}while(opcion>=1 && opcion<=5);

	return 0;
}

int inserta(int *apunta, int tope){
	if(tope<10){
		printf("Insertar el dato: ");
		scanf("%i",apunta+tope);
        fflush(stdin);
		tope++;
		return tope;
	}else{
		printf("No hay espacio\n");
		return tope;
	}
}

int elimina(int *apunta, int tope){
	int i;
	if(tope==0){
		printf("COLA VACIA\n");
		return tope;
	}else{
		printf("Elemento borrado %c\n",*(apunta));

		for(i=0;i<tope;i++)
			*(apunta+i)=*(apunta+1+i);   
		    *(apunta+tope)='\0';

		tope--;
		return tope;
	}
}

void imprime(int *apunta, int tope){
	int i;

	if(tope==0){
		printf("COLA VACIA\n");
	}else{
        printf("ELEMENTOS DE LA COLA\n");
		for(i=0;i<tope;i++)
			printf("\t%i \n",*(apunta+i));
	}
}
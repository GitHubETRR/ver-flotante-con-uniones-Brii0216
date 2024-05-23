#include <stdio.h>

union numeros{
    float nf;
    unsigned char vector[4];
    struct{
        unsigned int mantisa : 23;
        unsigned int exponente : 8;    
        unsigned int signo : 1;
    }bits;
};

void menu();
int ingresar_opcion();
union numeros ingresar_numero(union numeros);
void print_numero(union numeros);



int main(void){
    union numeros numero;
    int opcion;
    do{
        menu();
        opcion = ingresar_opcion();

        switch (opcion){

            case 1:
                numero=ingresar_numero(numero);
                break;
            
            case 2:
                print_numero(numero);
                break;
        }
    }while(opcion != 3);

    return 0;
}

void menu(){
    printf("menu\n");
    printf("1-Ingresar numero\n");
    printf("2-Ver numero\n");
    printf("3-Salir\n");
}

int ingresar_opcion(){
    int opcion;
    do{
        scanf("%d", &opcion);
    }while(opcion!=1 && opcion!=2 && opcion!=3); 

    return opcion;
}

union numeros ingresar_numero(union numeros numero){
    printf("Ingrese su numero flotante\n");
    scanf("%f", &numero.nf);

    return numero;
}


void print_numero(union numeros numero){
    printf("El numero ingresado esta guardado como: 0x");
    for(int i = 3; i>=0; i--){
        printf("%02X", numero.vector[i]);
    }

    if(numero.bits.signo==0){
        printf("\nSu signo es positivo\n"); 
    }
    else{
        printf("\nSu signo es negativo\n");
    }

    printf("La mantisa es 0x%02X\n",numero.bits.mantisa);
    printf("El exponente es %d\n", numero.bits.exponente-127);
    printf("El numero ingresado fue %f\n", numero.nf);
    
}

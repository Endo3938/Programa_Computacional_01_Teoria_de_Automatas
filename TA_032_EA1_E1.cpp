/* 

  Programa Computacional 01


Ernesto Guadalupe Rincon Ortiz    1903481

Rafael Barboza Garza              1897498

Hiram Josué García Niño           1894398

Jair Azael Sánchez Tovar          1918174

*/

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de la Funcion Validacion 

bool Validacion (char x []) ;

// Inicializando el Alfabeto como Variable Global

char Alfabeto[16] = {'r','a','f','e','l','b','o','z','g','1','8','9','7','4','.' ,'\0'} ;

int main (int argc, char const *argv[]) {

  // La Variable Cadena es para que el Usuario Ingrese la Cadena que Guste

  char Cadena[50] ;

  // La Variable Respuesta Sirve para Cuando le Salga la Pregunta "¿Quiere Ingresar Otra Cadena?"
  
  char Respuesta[2] ;
  

  do {
    
    // Esta Variable nos va Servir para la Validacion de la Respuesta
    
    bool Flag = false;
    
    // Se le pide al usuario que ingrese una cadena que luego el programa va a validar
    
    // Imprime Titulo
    
    std::cout << "\n\t\t\t\t\t\tPrograma Computacional 01\n\n" ; 
    
    // Imprime "Ingrese una Cadena"

    std::cout << "\n Ingrese una Cadena : " ;

    // Aqui Guarda la Cadena y le damos como limite 50 caracteres como se inicializó la variable , el '\n' sirve para cuando acabó de escribir la cadena presione un Enter

    std::cin.getline (Cadena , 50 , '\n');

    // La función del fflush, realiza la limpieza del buffer de entrada (stdin)

    fflush (stdin) ;

    //Se procede a validar si la cadena cumple con las condicioens específicadas
    
    Flag = Validacion (Cadena) ;

    //Ciclo para ver si se desea seguir ingresando más cadenas o no

    do {

      Flag = false ;
      
      printf ("\n\n %cDesea Ingresar Otra Cadena [Si - No]? : " , 168) ;
      std::cin >> Respuesta ;
      fflush (stdin) ;
      
      //Se crea una variable para que solo estas puedan ser las respuestas correctas
      
      bool Validacion_Respuesta = (strcmp ("No" , Respuesta)) && (strcmp ("NO" , Respuesta)) && (strcmp ("no" , Respuesta)) && (strcmp ("Si" , Respuesta)) && (strcmp ("SI" , Respuesta)) && (strcmp ("si" , Respuesta))  ;
      
      if (Validacion_Respuesta == 0) {

        Flag = true ;

      }
      
      //Si se ingresa una respuesta no válida el programa le pedirá al usuario que ingrese una cadena válida
      
      else {
        
        std::cout << "\n Error al Ingresar la Respuesta. Favor de Volver a Intentarlo , Presione Enter." << "\n\n " ;
        getch () ;

      }

      system ("cls") ;

    } while ( !Flag ) ;
    
    //En el caso de que el usuario ingrese que ya no quiere seguir utilizando sel programa se daldrá del ciclo, en el caso opuesto seguirá pidiendo y validando cadenas


  } while ((strcmp ("No" , Respuesta)) && (strcmp ("NO" , Respuesta)) && (strcmp ("no" , Respuesta))) ;  
  
  //Finalización del programa con un mensaje de despedida

  // Esto es Cuando ya sale del bucle , es un mensaje de despedida
  
  printf ("\n\n Gracias por Utilizar nuestro Programa, Tenga un Buen D%ca , Presione Enter Para Salir. :)\n\n " , 161) ;

  // Para que el Ejecutable no se Cierre
  
  getch () ;
  std::cout << std::endl ;
  return 0 ;

}


bool Validacion (char x[]) {

  // Validacion de que no sea una Cadena Vacia

  if ( x[0] == '\0') {
  
    printf("\n Ingres%c una Cadena inv%clida. La Cadena es vac%ca.\n", 162, 160, 161);
    return 0;
  
  }
  
  // Validacion de que el primer Símbolo sea un Dígito

  bool Flag = true ;
  
  // Este arreglo de booleanos ayudarán a identificar los distintos errores posibles

  bool Error[5] = {false , false , false , false , false } ; 


  char Digitos[11] = {'0','1' ,'2' ,'3' ,'4','5','6','7','8','9','\0'} ;
  
  for (size_t i = 0 ; i < 10 ; i++) {

    if ( x[0] == Digitos[i] ) {

      break ;

    } 
    
    else if ( i == 9 ) {
    
      Error[0] = true;
      Flag = false  ;
      break ;
      
    
    }

  }

  // Validacion de que no tenga puntos consecutivos

  for (size_t i = 0 ; i < strlen (x) ; i++) {
  
    if ( x[i] == 46 ) {
    
      if ( x[i+1] == 46 ) {
        
        Error[1] = true;
        Flag = false ;
        break;  
          
      }
      
      if ( i == strlen (x) - 1 ){

        break; 
        
        
      }
      
    }
  
  }

  // Validacion de que la Cadena este en el Alfabeto

  for (size_t i = 0 ; i < strlen (x) ; i++) {

    for (size_t j = 0 ; j < strlen ( Alfabeto ) ; j++) {
      
      if (x[i] == Alfabeto[j]) {
        
        break;

      }

      else if ( j == strlen ( Alfabeto ) - 1 ) { 
 
        Error[2] = true;
        Flag = false ;
        break;
        
      }
      
    }

  }

  // Validar que existan las iniciales del Nombre (rbg)

  for (size_t i = 0 ; i < strlen (x) ; i++) {

    if ( x[i] == 'r' &&  x[i+1] == 'b' && x[i+2] == 'g'){
 
      break;      

    } 
    
    else if ( i == strlen (x) - 1 ) {
    
      Error[3] = true;
      Flag = false;
      break;
    
    } 
  
  }

  // Validar que exista el punto y matricula al Final
  

  char CadenaMatricula[] = {'.','1','8','9','7','4','9','8','\0'}  ;
  
  short j = strlen (CadenaMatricula) ;

  for (short i = strlen (x) ; i >= 0 ; i--) {

    if ( x[i] != CadenaMatricula[j] ) {
      
      
      Error[4] = true;      
      Flag = false;
      break;
    
    } 

    if ( j == 0 ) {

      break;
      
    }   

    j--;

  }

  // Imprimiendo los Errores

  for (size_t i = 0 ; i < 5 ; i++) {

    if (Error[i] == 1 ) {
      
      printf("\n Cadena inv%clida: \n\n" , 160)  ;
      break;
      
    }
  
  }
  
  
  if ( Error[0] == 1 ) {

    printf("\n\t-El primer S%cmbolo no es un D%cgito. \n" , 161, 161)  ;       
  
  }

  if ( Error[1] == 1 ) {
  
    printf("\n\t-Ingres%c el Car%ccter %c . %c Consecutivamente. \n", 162, 160, 34, 34) ; 
  
  }

  if ( Error[2] == 1 ) {
  
    printf("\n\t-Ingres%c un Car%ccter que no Forma Parte del Alfabeto. \n" , 162, 160) ; 
  
  }

  if ( Error[3] == 1 ) {
  
    printf("\n\t-La Cadena no Contiene las Iniciales de su Nombre Consecutivamente Escritas (rbg). \n")  ;
  
  }
  
  if ( Error[4] == 1 ) {

    printf("\n\t-La Cadena no Contiene un Punto Seguido con su Matricula al Finalizar (.1897498). \n")  ;
  
  }

  // Retornando el Valor Bandera e imprimiendo si la cadena es valida
    

  if (Flag){

    printf("\n\n La Cadena Ingresada es V%clida para el Alfabeto Dado \n",160);
    return Flag;

  }
  
  else {

    return Flag;
  
  }

}
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado; // si esta en 0, esta vacio. Si esta en 1, esta lleno.

}EPersona;

/** \brief Inicializa el array,  le da valor 0 a todas variable estado del array.
 *
 * \param lista el array se pasa como parametro
 * \param cantidadItems la cantidad total de items
 *
 */
void initArray( EPersona lista[], int );


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param cantidadItems la cantidad total de items
 * @return el primer indice disponible o [-1] si no hay espacio libre
 */
int obtenerEspacioLibre(EPersona lista[], int );


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param cantidadItems la cantidad total de items
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
   o [-1] si no existe.
 */
int buscarPorDni(EPersona lista[], int cantidadItems, int dni);

void mostrarPersona(EPersona persona);


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);


/**
* \brief Solicita una cadena de caracteres de solo letras y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief carga los datos pasados por parametro a un elemento del array
 *
 * \param edad la edad de tipo entera se pasa como parametro
 * \param dni el dni de tipo entera se pasa como parametro
 * \param nombre se para por parametro
 * \return una variable del tipo Epersona con los campos completos
 *
 */
EPersona cargarPersona(int, int, char nombre[]);


/** \brief Muestra los datos de  persona
 *
 * \param persona una variable de tipo EPersona con los datos llenos
 * \return Nada, imprime (si estan llenos los campos) por pantalla los datos del campo
 *
 */
void mostrarUna(EPersona persona);


/** \brief Muestra los datos del array lista
 *
 * \param lista array que contiene los datos a ser mostrados
 * \param cantidadItems la cantidad de items que tiene el array
 * \return Nada, imprime (si estan llenos los campos) por pantalla los datos del array
 *
 */
void mostrarPersonas(EPersona lista[], int cantidadItems);


/** \brief ordena por nombre los elementos del array
 *
 * \param lista array de los datos a ser ordenamos
 * \param cantidadItems la cantidad de items que tiene el array
 * \return Nada, ordena los elementos del array por nombre
 *
 */
void ordenarPorNombre(EPersona lista[], int cantidadItems);


/** \brief segun el indice que se le da por parametro, borra un elemento
 *
 * \param lista array donde busca el elemento a ser borrado
 * \param indice de los datos que van a ser borrados
 * \return Nada, borra el elemento segun el indice
 *
 */
void borrarPersona(EPersona lista[], int indice);


/** \brief Pide al usuario los datos pasados por parametro
 *
 * \param *edad direccion de memoria se va a guardar la edad pedida al usuario
 * \param *dni direccion de memoria se va a guardar el dni pedido al usuario
 * \param *nombre direccion de memoria se va a guardar el nombre pedido al usuario
 * \return devuelve [0] si se logro pedir todo y [-1] si no
 *
 */
int pedirDatos(int* edad, int* dni,char*nombre);


/** \brief Extrae las edades de un array de estructuras y los guarda en un array de enteros
 *
 * \param lista De donde extrae los datos
 * \param edades array de enteros donde guarda los datos
 * \param cantidadItems la cantidad de items que tiene el array
 * \return Nada, solamente guarda los datos en el array edades
 *
 */
void extraerDatosEdades(EPersona lista[], int edades[], int cantidadItems);


/** \brief Crea un grafico a partir de los datos pasados por parametros
 * \param edades array que utiliza para crear el grafico
 * \return Nada, imprime por pantalla el grafico.
 *
 */

void crearGrafico(int edades[]);

#endif // FUNCIONES_H_INCLUDED

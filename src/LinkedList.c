#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;
	this = (LinkedList*) calloc(1, sizeof(LinkedList));
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;
	if (this != NULL) {

		returnAux = this->size;

	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList *this, int nodeIndex) {
	Node *auxiliar = NULL;
	int tam;
	if (this != NULL) {

		tam = ll_len(this);

		if (nodeIndex < tam && nodeIndex > -1) {
			auxiliar = this->pFirstNode;

			if (nodeIndex != 0) {
				for (int i = 0; i < nodeIndex; i++) {
					auxiliar = auxiliar->pNextNode;

				}

			}

		}

	}

	return auxiliar;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {

	Node *nuevoNodo;
	Node *NodoAnterior;
	int returnAux = -1;
	int tam;
	nuevoNodo = (Node*) malloc(sizeof(Node));

	tam = ll_len(this);
	if (this != NULL && nuevoNodo != NULL) {
		if (nodeIndex < tam + 1 && nodeIndex > -1) {
			nuevoNodo->pElement = pElement;
			if (nodeIndex == 0) {
				nuevoNodo->pNextNode = this->pFirstNode;

				this->pFirstNode = nuevoNodo;

			} else {
				NodoAnterior = getNode(this, (nodeIndex - 1));
				nuevoNodo->pNextNode = NodoAnterior->pNextNode;
				NodoAnterior->pNextNode = nuevoNodo;
			}
			returnAux = 0;
			this->size = this->size + 1;
		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int tam;
	if (this != NULL) {
		tam = ll_len(this);
		addNode(this, tam, pElement);
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	Node *node = NULL;
	void *returnAux = NULL;
	int tam;
	tam = ll_len(this);
	if (this != NULL && index < tam && index > -1) {
		node = getNode(this, index);
		if (node != NULL) {
			returnAux = node->pElement;
		}

	}

	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	Node *node;
	int returnAux = -1;
	int tam;

	if (this != NULL) {
		tam = ll_len(this);
		if (index < tam && index > -1) {

			node = getNode(this, index);
			if (node != NULL) {

				node->pElement = pElement;
				returnAux = 0;

			}
		}

	}
	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	int tam;
	Node *nodo;
	Node *nodoAnterior;
	Node *nodoSiguiente;
	tam = ll_len(this);
	if (this != NULL && index < tam && index > -1) {
		nodoAnterior = getNode(this, (index - 1));
		nodoSiguiente = getNode(this, (index + 1));
		nodo = getNode(this, index);

		if (index == 0) {
			this->pFirstNode = nodoSiguiente;

		} else {
			nodoAnterior->pNextNode = nodoSiguiente;
		}
		returnAux = 0;
		free(nodo);
		this->size--;

	}
	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;
	int tam;
	if (this != NULL) {
		// mal lo que hice fue cambiar lo que habia hecho que era
		tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			ll_remove(this, 0);
		}

		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		if (ll_clear(this) == 0) {
			free(this);
			returnAux = 0;
		}

	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int i;
	int tam;

	if (this != NULL && this != pElement) {
		tam = ll_len(this);
		for (i = 0; i < tam; i++) {
			if (ll_get(this, i) == pElement) {
				returnAux = i;
				break;
			}

		}

	}

	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista e_sta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;
	int tam;
	if (this != NULL) {
		tam = ll_len(this);
		returnAux = 1;
		if (tam != 0) {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {

		if (addNode(this, index, pElement) == 0) {
			returnAux = 0;

		}

	}
	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;
	if (this != NULL) {
		returnAux = ll_get(this, index);
		ll_remove(this, index);

	}
	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;
	if (this != NULL) {
		returnAux = 0;
		if (ll_indexOf(this, pElement) != -1) {
			returnAux = 1;
		}
	}
	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	int tamDos;

	tamDos = ll_len(this2);

	if (this != NULL && this2 != NULL) {
		returnAux = 1;
		for (int i = 0; i < tamDos; i++) {

			if (ll_contains(this, ll_get(this2, i)) != 1) {
				returnAux = 0;
				break;
			}

		}
	}

	return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	int tam;
	tam = ll_len(this);
	if (this != NULL && from > -1 && to > from && to <= tam) {
		cloneArray = ll_newLinkedList(); //newLInked
		if (cloneArray != NULL) {
			for (int i = from; i < to; i++) {
				addNode(cloneArray, i, ll_get(this, i));

			}
		}

	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;
	int tam;

	if (this != NULL) {
		tam = ll_len(this);
		cloneArray = ll_subList(this, 0, tam);

	}

	return cloneArray;

}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	void *auxPElement;
	void *parametroUno;
	void *parametroDos;
	int returnAux = -1;
	int comparacion;
	int tam;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {

		tam = ll_len(this);
		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {
				parametroUno = ll_get(this, i);
				parametroDos = ll_get(this, j);

				comparacion = pFunc(parametroUno, parametroDos);

				if ((order == 1 && comparacion > 0)
						|| (order == 0 && comparacion < 0)) {
					auxPElement = parametroUno;
					ll_set(this, i, parametroDos);
					ll_set(this, j, auxPElement);
					//MEJORAR ESTA.
				}

			}

		}
		returnAux = 0;
	}

	return returnAux;
}

LinkedList* ll_filter(LinkedList *this, int (*fn)(void *element)) {
	LinkedList *nuevaLista;
	void *element;
	int tam;
	nuevaLista = ll_newLinkedList();
	if (this != NULL && fn != NULL && nuevaLista != NULL) {
		tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			element = ll_get(this, i);
			if (fn(element)) {
				ll_add(nuevaLista, element);
			}
		}
	}
	return nuevaLista;
}

int ll_count(LinkedList *this, int (*fn)(void*)) {
	void *elemento;
	int retorno;
	int tam;
	retorno = -1;
	if (this != NULL && fn != NULL) {
		retorno = 0;
		tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			elemento = ll_get(this, i);
			retorno += fn(elemento);
		}

	}

	return retorno;
}

int ll_map(LinkedList *this, int (*fn)(void *element)) {
	int retorno;
	void *element;
	int tam;
	retorno = -1;
	if (this != NULL && fn != NULL) {
		tam = ll_len(this);
		for (int i = 0; i < tam; i++) {
			element = ll_get(this, i);
			if (fn(element) == 0) {
				retorno = 0;
			}
		}

	}
	return retorno;
}


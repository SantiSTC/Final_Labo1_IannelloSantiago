/*
 * LinkedList.c
 *
 *  Created on: 6 jul. 2023
 *      Author: santi
 */

#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
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
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxiliar;

	auxiliar = NULL;

	if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this))
	{
		auxiliar = this->pFirstNode;
		for(int i=0; i<nodeIndex; i++)
		{
			auxiliar = auxiliar->pNextNode;
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
Node* test_getNode(LinkedList* this, int nodeIndex)
{
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNuevoNodo;
    Node* pAnteriorNodo;

    pNuevoNodo = NULL;
    pAnteriorNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	pNuevoNodo = (Node*) malloc(sizeof(Node));

    	if(pNuevoNodo != NULL)
    	{
    		pNuevoNodo->pElement = pElement;

    		if(nodeIndex == 0)
    		{
    			pNuevoNodo->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNuevoNodo;
    		}
    		else
    		{
    			pAnteriorNodo = getNode(this, nodeIndex-1);

    			if(pAnteriorNodo != NULL)
    			{
    				pNuevoNodo->pNextNode = pAnteriorNodo->pNextNode;
    				pAnteriorNodo->pNextNode = pNuevoNodo;
    			}
    		}

    		this->size++;
    		returnAux = 0;
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
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
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
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo = NULL;

    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNodo = getNode(this, index);

    	if(pNodo != NULL)
    	{
    		returnAux = pNodo->pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;

    if(this != NULL && index >= 0)
    {
    	if(index < ll_len(this))
    	{
    		pNodo = getNode(this, index);

    		if(pNodo != NULL)
    		{
    			pNodo->pElement = pElement;
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
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodoAux;
    Node* pAnteriorNodo;

    pNodoAux = NULL;
    pAnteriorNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	pNodoAux = getNode(this, index);

    	if(pNodoAux != NULL)
    	{
    		if(index == 0)
    		{
    			this->pFirstNode = pNodoAux->pNextNode;
    		}
    		else
    		{
    			pAnteriorNodo = getNode(this, index-1);

    			if(pAnteriorNodo != NULL)
    			{
    				pAnteriorNodo->pNextNode = pNodoAux->pNextNode;
    			}
    		}

			free(pNodoAux);
			this->size--;
			returnAux = 0;
    	}
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
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_isEmpty(this))
    	{
    		for(int i=0; i<ll_len(this); i++)
    		{
    			ll_remove(this, 0);
    			returnAux = 0;
    		}
    	}
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
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
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
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* aux;

    if(this != NULL)
    {
    	if(ll_isEmpty(this) == 0)
    	{
    		for(int i=0; i<ll_len(this);i++)
    		{
    			aux = ll_get(this, i);

    			if(aux != NULL && aux == pElement)
    			{
    				returnAux = i;
    				break;
    			}
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
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 1;

    	if(ll_len(this) > 0)
    	{
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
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
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
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
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_isEmpty(this) == 0)
    	{
    		if(ll_indexOf(this, pElement) > -1)
    		{
    			returnAux = 1;
    		}
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElementoAux;

    pElementoAux = NULL;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	for(int i=0; i<ll_len(this2); i++)
    	{
    		pElementoAux = ll_get(this2, i);

    		if(pElementoAux != NULL)
    		{
    			if(ll_contains(this, pElementoAux) == 0)
    			{
    				returnAux = 0;
    				break;
    			}
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementoAux;

    pElementoAux = NULL;

    if(this != NULL && from > -1 && from < to && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(int i=from; i<to; i++)
    		{
    			pElementoAux = ll_get(this, i);
    			ll_add(cloneArray, pElementoAux);
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
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pElementoI = NULL;
    void* pElementoJ = NULL;
    int comp;

    if(this != NULL && (order == 1 || order == 0) && pFunc != NULL)
    {
    	for(int i=0; i<(ll_len(this)-1); i++)
    	{
    		for(int j=i+1; j<ll_len(this); j++)
    		{
    			pElementoI = ll_get(this, i);
    			pElementoJ = ll_get(this, j);

    			comp = pFunc(pElementoI, pElementoJ);

    			if((comp > 0 && order == 1) || (comp < 0 && order == 0))
    			{
    				ll_set(this, i, pElementoJ);
    				ll_set(this, j, pElementoI);
    			}
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;
}

/*
 * La función ll_filter recibirá una lista y una función criterio fn. Se deberá iterar todos los elementos
 * de la lista y pasarlos a la función fn. La función fn devolverá 1 si ese ítem se debe agregar a la
 * lista resultado o 0 si no debe agregarse. La función ll_filter generará
 * */
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* newList = NULL;

    void* pElement = NULL;

    newList = ll_newLinkedList();

    if(this != NULL && newList != NULL)
    {
        for(int i = 0;i<ll_len(this);i++)
        {
            pElement= ll_get(this,i);

            if(pFunc(pElement)==1)
            {
                ll_add(newList,pElement);
            }
        }
    }
  return newList;
}

/*
 * La funcion ll_map recibirá la lista y una función criterio fn. La función fn podrá realizar un cálculo
 * con el elemento recibido y modificar alguno de sus campos si es necesario. Al finalizar la iteración,
 * los elementos de la lista quedarán modificados.
 * */
LinkedList* ll_map(LinkedList* this, int (*pFunc)(void*))
{
    void* pElement;

    LinkedList* listaMapeada = ll_newLinkedList();

    if(this!=NULL && pFunc!=NULL && listaMapeada != NULL)
    {
        for(int i = 0; i < ll_len(this); i++)
        {
            pElement = ll_get(this, i);

            if(pFunc(pElement))
            {
            	ll_add(listaMapeada, pElement);
            }
        }
    }

    return listaMapeada;
}

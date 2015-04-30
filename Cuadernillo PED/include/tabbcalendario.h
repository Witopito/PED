/*
 * tabbcalendario.h
 *
 *  Created on: 29/04/2015
 *      Author: hmb6
 */

#ifndef TABBCALENDARIO_H_
#define TABBCALENDARIO_H_
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <iostream>

class TNodoABB;
class TABBCalendario;

class TABBCalendario {
	friend class TNodoABB;
public:
	// Constructor por defecto
	TABBCalendario ();
	// Constructor de copia
	TABBCalendario (const TABBCalendario &);
	// Destructor
	~TABBCalendario ();
	// Sobrecarga del operador asignación
	TABBCalendario & operator=(const TABBCalendario &);


	// Sobrecarga del operador igualdad
	bool operator==( TABBCalendario &);
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio();
	// Inserta el elemento en el árbol
	bool Insertar(const TCalendario &);
	// Borra el elemento en el árbol
	bool Borrar(TCalendario &);
	// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
	bool Buscar(TCalendario &);
	// Devuelve el elemento en la raíz del árbol
	TCalendario Raiz();
	// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
	int Altura();
	// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
	int Nodos();
	// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
	int NodosHoja();
	// Devuelve el recorrido en inorden sobre un vector
	TVectorCalendario Inorden();
	// Devuelve el recorrido en preorden sobre un vector
	TVectorCalendario Preorden();
	// Devuelve el recorrido en postorden sobre un vector
	TVectorCalendario Postorden();
	// Devuelve el recorrido en niveles
	TVectorCalendario Niveles();
	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, TABBCalendario &);
	// Suma de dos ABB
	TABBCalendario operator+( TABBCalendario &);
	// Resta de dos ABB
	TABBCalendario operator-( TABBCalendario &);

private:
	//Puntero al nodo raíz
	TNodoABB *raiz;
	// Devuelve el recorrido en inorden
	void InordenAux(TVectorCalendario &, int &);
	// Devuelve el recorrido en preorden
	void PreordenAux(TVectorCalendario &, int &);
	// Devuelve el recorrido en postorden
	void PostordenAux(TVectorCalendario &, int &);
	void Copiar(const TABBCalendario &);
	//void Enraizar(TABBCalendario &iz, const TCalendario c, TABBCalendario &de);
	bool buscaCalendario(const TCalendario &c,TABBCalendario sub);
	void insertarOrdenado(TCalendario c);
	bool auxBuscar(TABBCalendario a);

};


class TNodoABB {
	friend class TABBCalendario;
public:
	TNodoABB();
	TNodoABB(const TNodoABB &);
	~TNodoABB();
	TNodoABB & operator=(const TNodoABB &);
private:
	TCalendario item;
	TABBCalendario iz,de;
};

#endif /* TABBCALENDARIO_H_ */

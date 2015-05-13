/*
 * tavlcalendario.h
 *
 *  Created on: 13/05/2015
 *      Author: hmb6
 */

#ifndef TAVLCALENDARIO_H_
#define TAVLCALENDARIO_H_
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include <iostream>
#include <queue>

class TNodoAVL;
class TAVLCalendario;


class TNodoAVL {
	friend class TAVLCalendario;
public:
	//--------PARTE CANÓNICA------------
	//Constructor por defecto
	TNodoAVL ();
	//Constructor copia
	TNodoAVL (TNodoAVL &);
	//Destructor
	~TNodoAVL ();
	// Sobrecarga del operador asignación
	TNodoAVL & operator=( TNodoAVL &);
private:
	// El elemento (etiqueta) del nodo
	TCalendario item ;
	// Subárbol izquierdo y derecho
	TAVLCalendario iz, de ;
	// Factor de equilibrio
	int fe ;
};


class TAVLCalendario {
	friend class TNodoAVL;
public:
	//--------PARTE CANÓNICA------------
	// Constructor por defecto
	TAVLCalendario ();
	// Constructor de copia
	TAVLCalendario (TAVLCalendario &);
	// Destructor
	~ TAVLCalendario ();
	// Sobrecarga del operador asignación
	TAVLCalendario & operator=( TAVLCalendario &);

	//--------PARTE MÉTODOS--------------
	// Sobrecarga del operador igualdad
	bool operator==( TAVLCalendario &);
	// Sobrecarga del operador desigualdad
	bool operator!=( TAVLCalendario &);
	// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
	bool EsVacio();
	// Inserta el elemento en el árbol
	bool Insertar(TCalendario &);
	// Devuelve true si el elemento está en el árbol, false en caso contrario
	bool Buscar(TCalendario &);
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
	// Borra un TCalendario del árbol AVL
	bool Borrar(TCalendario &);
	// Devuelve el elemento TCalendario raíz del árbol AVL
	TCalendario Raiz();
	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, TAVLCalendario &);

private:
	// Puntero al nodo raíz
	TNodoAVL *raiz;
	// Devuelve el recorrido en inorden
	void InordenAux(TVectorCalendario &, int &);
	// Devuelve el recorrido en preorden
	void PreordenAux(TVectorCalendario &, int &);
	// Devuelve el recorrido en postorden
	void PostordenAux(TVectorCalendario &, int &);
};




#endif /* TAVLCALENDARIO_H_ */

/*
 * tlistacalendario.h
 *
 *  Created on: 18/04/2015
 *      Author: hector
 */

#ifndef TLISTACALENDARIO_H_
#define TLISTACALENDARIO_H_
#include <iostream>
#include "tcalendario.h"

class TNodoCalendario {
public:
	//forma canonica
	TNodoCalendario();
	TNodoCalendario(TNodoCalendario &);
	~TNodoCalendario();
	TNodoCalendario & operator=(TNodoCalendario &);

private:
	TCalendario c; //Layering
	TNodoCalendario *siguiente;
};


class TListaCalendario{
	friend ostream & operator <<(ostream &, TListaCalendario &);
	friend class TListaPos;
public:
	//Forma canonica
	TListaCalendario();
	TListaCalendario(TListaCalendario &);
	~TListaCalendario();
	TListaCalendario & operator=(TListaCalendario &);

	//Metodos
	bool operator==(TListaCalendario &);
	TListaCalendario operator+(TListaCalendario &);
	TListaCalendario operator-(TListaCalendario &);
	bool Insertar(TCalendario &);
	bool Borrar(TCalendario &);
	bool Borrar(TListaPos &);
	bool Borrar(int,int,int);
	bool EsVacia();
	TCalendario Obtener(TListaPos &);
	bool Buscar(TCalendario &);
	int Longitud();
	TListaPos Primera();
	TListaPos Ultima();
	TListaCalendario SumarSub1(int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
	TListaCalendario ExtraerRango(int n1, int n2);
private:
	TNodoCalendario *primero;
};

class TListaPos{
public:
	//forma canonica
	TListaPos();
	TListaPos(TListaPos &);
	~TListaPos();
	TListaPos & operator=(TListaPos &);

	//metodos
	bool operator==(TListaPos &);
	bool operator!=(TListapos &);
	TListaPos Siguiente();
	bool EsVacia();
private:
	TNodoCalendario *pos;

};





#endif /* TLISTACALENDARIO_H_ */

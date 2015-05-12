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


class TNodoCalendario;
class TListaPos;


class TNodoCalendario {
	friend class TListaPos;
	friend class TListaCalendario;
public:
	//forma canonica
	TNodoCalendario();
	TNodoCalendario(const TNodoCalendario &);
	~TNodoCalendario();
	TNodoCalendario & operator=(const TNodoCalendario &);

private:
	TCalendario c; //Layering
	TNodoCalendario *siguiente;
};


class TListaCalendario{
	friend ostream & operator <<(ostream &,const TListaCalendario &);
	friend class TListaPos;
	friend class TNodoCalendario;
public:
	//Forma canonica
	TListaCalendario();
	TListaCalendario(const TListaCalendario &);
	~TListaCalendario();
	TListaCalendario & operator=(const TListaCalendario &);

	//Metodos
	bool operator==(const TListaCalendario &);
	TListaCalendario operator+(const TListaCalendario &);
	TListaCalendario operator-(const TListaCalendario &);
	bool Insertar(const TCalendario &);
	bool Borrar(const TCalendario &);
	bool Borrar(const TListaPos &);
	bool Borrar(int,int,int);
	bool EsVacia() const;
	TCalendario Obtener(const TListaPos &) const;
	bool Buscar(const TCalendario &);
	int Longitud();
	TListaPos Primera() const;
	TListaPos Ultima() const;
	TListaCalendario SumarSubl(int I_L1, int F_L1,const TListaCalendario & L2, int I_L2, int F_L2);
	TListaCalendario ExtraerRango(int n1, int n2);
private:
	TNodoCalendario *primero;
	bool InsertarCopia(const TCalendario &cal);
};

class TListaPos{
	friend class TNodoCalendario;
	friend class TListaCalendario;
public:
	//forma canonica
	TListaPos();
	TListaPos(const TListaPos &);
	~TListaPos();
	TListaPos & operator=(const TListaPos &);

	//metodos
	bool operator==(const TListaPos &);
	bool operator!=(const TListaPos &);
	TListaPos Siguiente();
	bool EsVacia();
private:
	TNodoCalendario *pos;

};





#endif /* TLISTACALENDARIO_H_ */

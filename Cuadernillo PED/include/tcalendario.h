/*
 * TCalendario.h
 *
 *  Created on: 04/02/2015
 *      Author: hmb6
 */

#ifndef TCALENDARIO_H_
#define TCALENDARIO_H_

#include <iostream>
#include <string.h>

using namespace std;

class TCalendario {

	friend ostream & operator<<(ostream &,const TCalendario &);


public:
	TCalendario();
	TCalendario(int dia, int mes, int anyo, char* mens);
	TCalendario(const TCalendario &);
	virtual ~TCalendario();

	TCalendario & operator=(const TCalendario &);
	// Sobrecarga del operador SUMA de fecha + un número de dias;
	TCalendario operator+(int a);
	// Sobrecarga del operador RESTA de fecha - un número de dias;
	TCalendario operator-(int);
	// Modifica la fecha incrementandola en un dia (con postincremento);
	TCalendario operator++(int);
	// Modifica la fecha incrementandola en un dia (con preincremento);
	TCalendario & operator++();
	// Modifica la fecha decrementándola en un dia (con postdecremento);
	TCalendario operator--(int);
	// Modifica la fecha decrementándola en un día (con predecremento);
	TCalendario & operator--();


	// Modifica la fecha
	bool ModFecha (int, int, int);
	// Modifica el mensaje
	bool ModMensaje(char *);
	// Sobrecarga del operador igualdad;
	bool operator ==(const TCalendario &);
	// Sobrecarga del operador desigualdad;
	bool operator !=(const TCalendario &);
	// Sobrecarga del operador >; (ver ACLARACIÓN sobre ORDENACIÓN)
	bool operator>(const TCalendario &);
	// Sobrecarga del operador <; (ver ACLARACIÓN sobre ORDENACIÓN)
	bool operator<(const TCalendario &);
	//TCalendario vacío
	bool EsVacio() const;
	// Devuelve el día del calendario;
	int Dia();
	// Devuelve el mes del calendario;
	int Mes();
	// Devuelve el año del calendario;
	int Anyo();
	// Devuelve el mensaje del calendario;
	char *Mensaje();
	TCalendario FechaSiguiente();
	//Comprueba si la fecha es valida
	bool comprobarFecha();
	bool comprobarFecha(int d,int m, int a);
	bool mayorFecha(const TCalendario &);
	bool mayorMensaje(const TCalendario &);
	bool menorFecha(const TCalendario &);




private:
	int dia, mes, anyo;
	char* mensaje;


};

#endif /* TCALENDARIO_H_ */

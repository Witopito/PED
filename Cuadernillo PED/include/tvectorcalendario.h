/*
 * TVectorCalendario.h
 *
 *  Created on: 18/03/2015
 *      Author: hmb6
 */

#ifndef TVECTORCALENDARIO_H_
#define TVECTORCALENDARIO_H_

#include <iostream>
#include "tcalendario.h"

using namespace std;

class TVectorCalendario {
friend ostream & operator<<(ostream &,const TVectorCalendario &);

public:
//forma canónica
TVectorCalendario();
TVectorCalendario(int);
TVectorCalendario(const TVectorCalendario &);
~TVectorCalendario();
TVectorCalendario & operator=(const TVectorCalendario &);

//metodos
bool operator==(const TVectorCalendario &);
bool operator!=(const TVectorCalendario&);
TCalendario & operator[](int);
TCalendario operator[](int) const;
int Tamano() const;
int Ocupadas();
bool ExisteCal(const TCalendario &);
void MostrarMensajes(int,int,int);
bool Redimensionar(int);

private:
TCalendario *c;
int tamano;
TCalendario error;
};

#endif /* TVECTORCALENDARIO_H_ */

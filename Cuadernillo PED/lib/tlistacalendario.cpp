/*
 * tlistacalendario.cpp
 *
 *  Created on: 18/04/2015
 *      Author: hector
 */

#include "tlistacalendario.h"

TListaCalendario::TListaCalendario() {
	primero=NULL;
}

TListaCalendario::TListaCalendario(TListaCalendario &l)
{
	primero=l.primero;
}

TListaCalendario::~TListaCalendario() {
	TListaPos p,q;

	q=primero;
	while(q!=q.EsVacia())
	{
		p=q;
		q=q.Siguiente();
		delete p.pos;
	}
	primero=NULL;
}

TListaCalendario &
TListaCalendario::operator=(TListaCalendario &l)
{
	return *this;
}

bool
TListaCalendario::operator==(TListaCalendario &l)
{

}

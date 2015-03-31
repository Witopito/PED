#include "../include/TCalendario.h"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	TCalendario cal;
	TCalendario cal2;
	TCalendario calsuma;
	TCalendario calmens(15,10,2010,"Bartolo tenia una flauta con un agujero solo");

	TCalendario caldecremento(1,1,1900,"Postdecremento");
	TCalendario caldecremento2(1,1,1900,"Predecremento");
	TCalendario calresta(10,1,1900,"Resta");
/*
	cout << "PRUEBA DEL POSTINCREMENTO" << endl;
	cout << "Fecha actual: " << cal.Dia() << "-" << cal.Mes() << "-" << cal.Anyo()<< endl;
	cal++;
	cout << "Fecha sumada: " << cal.Dia() << "-" << cal.Mes() << "-" << cal.Anyo() << endl << endl;

	cout << "PRUEBA DEL PREINCREMENTO" << endl;
	cout << "Fecha actual: " << cal2.Dia() << "-" << cal2.Mes() << "-" << cal2.Anyo()<< endl;
	++cal2;
	cout << "Fecha sumada: " << cal2.Dia() << "-" << cal2.Mes() << "-" << cal2.Anyo()<< endl << endl;

	cout << "PRUEBA DE SUMA" << endl;
	cout << "Fecha actual: " << calsuma.Dia() << "-" << calsuma.Mes() << "-" << calsuma.Anyo()<< endl;
	calsuma + 46;
	cout << "Fecha sumada: " << calsuma.Dia() << "-" << calsuma.Mes() << "-" << calsuma.Anyo() << endl << endl;
	calsuma = calsuma + 10;
	cout << "Fecha sumada: " << calsuma.Dia() << "-" << calsuma.Mes() << "-" << calsuma.Anyo() << endl << endl;
*/

/*
	cout << "PRUEBA DEL POSTDECREMENTO" << endl;
	cout << "Fecha actual: " << caldecremento << endl;
	caldecremento--;
	cout << "Fecha sumada: " << caldecremento << endl << endl;

	cout << "PRUEBA DEL PREDECREMENTO" << endl;
	cout << "Fecha actual: " << caldecremento2 << endl;
	--caldecremento2;
	cout << "Fecha sumada: " << caldecremento2 << endl << endl;

*/
	/*
	cout << "PRUEBA DE RESTA" << endl;
	cout << "Fecha actual: " << calresta << endl;
	calresta - 20;
	cout << "Fecha sumada: " << calresta << endl << endl;
	calresta = calresta - 20;
	cout << "Fecha sumada: " << calresta << endl << endl;

*/

	TCalendario comprobar1(1,1,1900,"lalala");
	TCalendario comprobar2(1,1,1889,"lelele");
	TCalendario comprobar3(32,11,2000,"lololo");
	TCalendario comprobar4(24,13,2000,"lilili");
	TCalendario comprobar5(29,2,2015,"lululu");
	TCalendario comprobar6(29,2,2016,"lklklk");
/*
	cout << "COMPROBAR FECHAS" << endl;
	cout << comprobar1 << " " << comprobar1.comprobarFecha() << endl;
	cout << comprobar2 << " " << comprobar2.comprobarFecha() << endl;
	cout << comprobar3 << " " << comprobar3.comprobarFecha() << endl;
	cout << comprobar4 << " " << comprobar4.comprobarFecha() << endl;
	cout << comprobar5 << " " << comprobar5.comprobarFecha() << endl;
	cout << comprobar6 << " " << comprobar6.comprobarFecha() << endl;
*/

	TCalendario correcta(25,2,1989,"lalalala");
	TCalendario incorrecta(30,2,1992,NULL);
	TCalendario otra = incorrecta;

/*
	cout << "COMPROBAR CONSTRUCTOR" << endl;
	cout << "Fecha correcta: " << correcta << endl;
	cout << "Fecha incorrecta: " << incorrecta << endl;
	cout << "Fecha con null: " << otra << endl;
*/


	TCalendario modificada(21,5,1990, "lalalalalalon");
/*
	cout << "COMPROBAR MODIFICAR FECHA" << endl;
	cout << "Fecha antes de modificar: " << modificada << endl;
	modificada.ModFecha(21, 5, 1889);
	cout << "Fecha con mala modificacion: " << modificada << endl;
	modificada.ModFecha(27,2,1989);
	cout << "Fecha modificada correctamente: " << modificada << endl;
	modificada.ModMensaje("Cumpleaños Hector");
	cout << "Fecha con mensaje modificado: " << modificada << endl;
*/


	TCalendario igual1(20,2,1980,NULL);
	TCalendario igual2(20,2,1980,NULL);
	TCalendario igual3(20,2,1980,"");
	TCalendario igual4(20,3,1980,"");
	TCalendario igual5(20,3,1980,"Mensaje wapo wapo");
/*
	cout << "COMPROBAR IGUALDAD" << endl;
	cout << "Compara 1 y 2 debe dar 1: " << (igual1==igual2) << endl;
	cout << "Compara 2 y 3 debe dar 0: " << (igual2==igual3) << endl;
	cout << "Compara 3 y 4 debe dar 0: " << (igual3==igual4) << endl;
	cout << "Compara 4 y 5 debe dar 0: " << (igual4==igual5) << endl;

*/
/*
	cout << "COMPROBAR DESIGUALDAD" << endl;
	cout << "Compara 1 y 2 debe dar 0: " << (igual1!=igual2) << endl;
	cout << "Compara 2 y 3 debe dar 1: " << (igual2!=igual3) << endl;
	cout << "Compara 3 y 4 debe dar 1: " << (igual3!=igual4) << endl;
	cout << "Compara 4 y 5 debe dar 1: " << (igual4!=igual5) << endl;
*/
	TCalendario mayor1(20,2,1980,NULL);
	TCalendario mayor2(20,2,1980,NULL);
	TCalendario mayor3(20,3,1960,NULL);
	TCalendario mayor4(20,3,1960,"");
	TCalendario mayor5(20,3,1960," ");
	TCalendario mayor6(20,3,1960,"Mensaje wapo wapo");
/*
	cout << "COMPROBAR MAYOR" << endl;
	cout << "Compara 1 y 2 debe dar 0: " << (mayor1>mayor2) << endl;
	cout << "Compara 2 y 3 debe dar 1: " << (mayor2>mayor3) << endl;
	cout << "Compara 4 y 3 debe dar 1: " << (mayor4>mayor3) << endl;
	cout << "Compara 5 y 4 debe dar 1: " << (mayor5>mayor4) << endl;
	cout << "Compara 6 y 5 debe dar 1: " << (mayor6>mayor5) << endl;
*/
	cout << "COMPROBAR MENOR" << endl;
	cout << "Compara 1 y 2 debe dar 0: " << (mayor1<mayor2) << endl;
	cout << "Compara 2 y 3 debe dar 0: " << (mayor2<mayor3) << endl;
	cout << "Compara 3 y 4 debe dar 1: " << (mayor3<mayor4) << endl;
	cout << "Compara 4 y 5 debe dar 1: " << (mayor4<mayor5) << endl;
	cout << "Compara 5 y 6 debe dar 1: " << (mayor5<mayor6) << endl;


	return 0;
}

#pragma once
#include "FuncionesCustom.h"
//#include "GestionRecursos.h"
#include "Enemigo.h"
#include "Agua.h"
#include "Semilla.h"
#include "Arbol.h"
#include "Basura.h"
#include "vector"
//#include "Guardian.h"

using namespace std;

class GestionJuego
{
private:
	//ArregloElementos* objElementos;
	//Guardian* objGuardian;
	vector<Agua*> arregloAgua;
	vector<Semilla*> arregloSemillas;
	vector<Arbol*> arregloArboles;
	vector<Basura*> arregloBasuras;
	vector<Enemigo*> arregloEnemigos;

	int cantidadInicialEnemigos;
public:
	GestionJuego()
	{
		// iniciamos los arreglos siuuu
		arregloAgua = vector<Agua*>();
		arregloSemillas = vector<Semilla*>();
		arregloArboles = vector<Arbol*>();
		arregloBasuras = vector<Basura*>();
		arregloEnemigos = vector<Enemigo*>();

		cantidadInicialEnemigos = 5;
	}
	~GestionJuego() {}

	void IniciarElementos(int ancho, int alto) 
	{
		// inicializar enemigos
		for (int i = 0; i < cantidadInicialEnemigos; i++)
		{
			int x = GenerarNumeroAleatorio(500, 80);
			int y = GenerarNumeroAleatorio(500, 300);
			Enemigo* e = new Enemigo(x, y, ancho, alto);
			arregloEnemigos.push_back(e);
		}
	}

	void DibujarTodo(Graphics^ g, Bitmap^ bmpEnemigo)
	{
		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			arregloEnemigos[i]->Dibujar(g, bmpEnemigo);
		}
	}

	void MoverTodo(Graphics^ g) 
	{
		int r = GenerarNumeroAleatorio(0, 100);
		Direccion tecla = Ninguna;

		switch (r)
		{
		case 1:
			tecla = Arriba; break;
		case 15:
			tecla = Abajo; break;
		case 30:
			tecla = Izquierda; break;
		case 45:
			tecla = Derecha; break;
		default:
			break;
		}

		for (int i = 0; i < arregloEnemigos.size(); i++)
		{
			arregloEnemigos[i]->Mover(g, tecla);
		}
	}
	void RevisarColisiones() 
	{
		//for (int i = 0; i < objElementos->sizeBasura(); i++)
		//{
		//	for (int j = 0; j < objElementos->sizeSemilla(); j++)
		//	{
		//		if (objElementos->returnBasura(i)->getRectangle().IntersectsWith(objElementos->returnSemilla(j)->getRectangle()))
		//		{
		//			objElementos->deleteBasura(i);
		//			objElementos->deleteSemilla(j);
		//			//Eliminar la basura y la semilla al realizar la colision
		//		}
		//	}
		//}

		//for (int i = 0; i < objElementos->sizeEnemigo(); i++)
		//{
		//	if (objElementos->returnEnemigo(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//Perder Vidas 
		//		objGuardian->setVidas(-1);
		//		objElementos->deleteEnemigo(i);
		//	}
		//}

		//for (int i = 0; i < objElementos->sizeBasura(); i++)
		//{
		//	if (objElementos->returnBasura(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//Perder Vidas
		//		objGuardian->setVidas(-1);
		//	}
		//}

		//for (int i = 0; i < objElementos->sizeAgua(); i++)
		//{
		//	if (objElementos->returnAgua(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//Aumentar agua
		//		objElementos->addAgua(objAgua);
		//	}
		//}
		//for (int i = 0; i < objElementos->sizeArbol(); i++)
		//{
		//	if (objElementos->returnArbol(i)->getRectangle().IntersectsWith(objGuardian->getRectangle()))
		//	{
		//		//No se si este es la semilla que se encuentra por el suelo, en ese caso en vez de ser
		//		//return arbol, es return Semilla
		//		//Aumentar semillas
		//	}
		//}
	}
	void DeterminarGanador() 
	{
		//Poner la funcion de determinar ganador
	}

	//bool AnalizarGAMEOVER()
	//{
	//	if (objGuardian->getVidas()==0)
	//	{
	//		//Poner GAMEOVER
	//	}
	//}
};
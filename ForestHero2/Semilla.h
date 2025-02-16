#pragma once
#include "Agente.h"

class Semilla : public Agente
{
private:
	bool seMueve;
public:
	Semilla(int x, int y, int ancho, int alto) : Agente(x, y, velocidad, ancho, alto)
	{
		seMueve = false;
		velocidad = 0;
	}

	Semilla(int x, int y, int ancho, int alto, Direccion direccionActual) : Agente(x, y, velocidad, ancho, alto)
	{
		seMueve = true;
		velocidad = 40;
		this->direccionActual = direccionActual;
	}

	~Semilla() {}

	bool getSeMueve() { return seMueve; }

	void Dibujar(Graphics^ g, Bitmap^ bmp) override 
	{
		g->DrawImage(bmp, x, y, ancho, alto);
	}

	void Mover(Graphics^ g) override
	{
        switch (direccionActual)
        {
        case Arriba:
            if (y > 70) {
                dx = 0;
                dy = -velocidad;
                y += dy;
            }
            break;
        case Abajo:
        case Ninguna:
            if (y + alto < 830) {
                dx = 0;
                dy = velocidad;
                y += dy;
            }
            break;
        case Izquierda:
            if (x > 30) {
                dx = -velocidad;
                dy = 0;
                x += dx;
            }
            break;
        case Derecha:
            if (x + ancho < 1100) {
                dx = velocidad;
                dy = 0;
                x += dx;
            }
            break;
        }
	}
};


#pragma once
#include "Personagem.h"
class Musico :
	public Personagem
{
public:
	Musico();
	~Musico();
	void inicializar(int x_, int y_);
	void atualizar();
	void castar();
	void especial();
	void desEspecial();
	bool getCastou();

private:
	Timer tempoCastar;
};


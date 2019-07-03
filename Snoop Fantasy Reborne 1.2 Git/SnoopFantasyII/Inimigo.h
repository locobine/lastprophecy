#pragma once

#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include "Timer.h"
#include "Collision.h"

using namespace std;
using namespace sf;

enum tipoMonstro
{
	Cobra1, Cobra2, Cobra3
};

enum estadoMonstro
{
	Stopped, Roaming, Reacting, Dashing, Aciding
};

enum Animacao2
{
	Parado2, Andando2, Atacando2, TomaDano2, Morrer2, Morto2, Especializando2
};

class Inimigo
{
public:
	Inimigo();
	~Inimigo();
	void inicializar(int tipo, float x_, float y_);
	void atualizar();
	AnimatedSprite desenhar();
	Sprite getSpriteFrameAtual();
	void andaDireita();
	void andaEsquerda();
	void andaCima();
	void andaBaixo();
	int getAtaque();
	int getVida(); //area total 120 110
	void recebeDano(int dano); //160 55
	int getXcolisao();
	int getYcolisao();
	bool getMorto();
	void ataca();
	bool getAtacou();
	void setAtacou(bool att);
	void setAcidou(bool acidou_);
	bool getAcidou() { return acidou; };
	float getX() { return x; };
	float getY() { return y; };
private:
	Clock frameClock;
	Texture txtIni;
	AnimatedSprite spIni;
	Animation animParado, animAndando, animAtacando, animTomaDano, animMorrer, animMorto, animEspecial, *animaAtual;
	float x, y, speed;
	int estadoAtual;
	int nAnimacaoAtual;
	int vida, ataque;
	bool morto, morrer;
	bool podeAtacar, atacando, atacou;
	Timer cooldownAtaque, tempoAtaque;
	int nHitsRecebidos, tipoCobra;
	float xInicial, yInicial;
	bool acidou, jaAcidou;
	Timer tempoAcidar;
};


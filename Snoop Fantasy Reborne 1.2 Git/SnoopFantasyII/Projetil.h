#pragma once
#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include "Timer.h"
#include "Collision.h"

using namespace std;
using namespace sf;

enum AnimacaoMagia
{
	Criacao, Efeito
};

class Projetil
{
public:
	Projetil();
	~Projetil();
	void inicializarTeste(int tipoMagia_, bool alvo_, int tipoAlvo_, float x_, float y_, int dano_, Texture txtzinha);
	void reinicializar(int tipoMagia_, bool alvo_, int tipoAlvo_, float x_, float y_, int dano_);
	void inicializar(int tipoMagia_, bool alvo_, int tipoAlvo_, float x_, float y_, int dano_);
	void inicializarInimigo(float x_, float y_, int dano_);
	void atualizar();
	void atualizarIni();
	AnimatedSprite desenhar();
	int getX();
	int getY();
	bool getDeleteMe();
	void setDeleteMeTrue();
	Sprite getSpriteFrameAtual();
	int getDano();

private:
	Clock frameClock;
	Texture txtProjetil;
	AnimatedSprite spProjetil;
	Animation animEfeito, *animaAtual, animCriacao;
	float x, y, xInicial, yInicial;
	int tipoMagia, tipoAlvo, nAnimacaoAtual, dano;
	bool alvo, deleteMe;
	float speed;
};


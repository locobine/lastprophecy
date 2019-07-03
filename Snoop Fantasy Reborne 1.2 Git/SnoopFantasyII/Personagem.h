#pragma once

#include <SFML\Graphics.hpp>
#include "AnimatedSprite.h"
#include <iostream>
#include "Timer.h"
#include "Projetil.h"
#include "Collision.h"

using namespace std;
using namespace sf;

struct Magia
{
	bool magiaInimigo, efeitoSecundario;
	string nomeMagia, magiaEfeito;
	float speedMagia;
	int tipoMagia, alvoMagia;
};

enum Animacao
{
	Parado, Andando, Atacando, TomaDano, Morrer, Morto, Especial, Especial2, Especial3
};

class Personagem
{
public:
	Personagem();
	~Personagem();

	Sprite getSpriteFrameAtual();
	virtual void inicializar(int x_, int y_);
	virtual void atualizar() {};
	AnimatedSprite desenhar();
	virtual void andaDireita();
	virtual void andaEsquerda();
	virtual void andaCima();
	virtual void andaBaixo();
	void setAnima(int qual);
	void ataca();
	bool getAtacando();
	void setCorrendo(bool estaCorrendo);
	int getXbotas();
	int getYbotas();
	int getVida();
	int getAtaque();
	float getTempoFrames();
	void recebeDano(int dano); // 75 45
	int getXatacando();
	int getYatacando();
	int getXmeio(); // 50 94
	int getYmeio(); // 30 50
	int getAnimacaoAtual();
	bool getMorto();
	virtual void especial();
	virtual bool getEspecializando();
	virtual void desEspecial();
	int getTipoPersonagem();
	int movePara(int x_, int y_);
	float getXReal();
	float getYReal();
	void paraAndar();
	bool getAndando();
	virtual bool getCastou();
	void setCastou(bool castou_);
	int getAtacouTipo();
	void setAtacouTipo(int atacouTipo_);
	Magia getMagia();
	void empurraEsquerda();
	string getNome() { return nome; };
	int getVidaMax() { return vidaMaxima; };
	int getDefesa() { return defesa; };
	int getMana() { return mana; };
	int getManaMax() { return manaMaxima; };
	int getLevel() { return level; };

	Personagem *proximo;
	Personagem *anterior;
protected:
	Clock frameClock;
	Timer tempoRegenMana;
	Texture txtChar;
	AnimatedSprite spChar;
	Animation animParado, animAndando, animAtacando, animTomaDano, animMorrer, animMorto, animEspecial, animEspecial2, animEspecial3, *animaAtual;
	float x, y;
	int nAnimacaoAtual;
	Timer tempoAtaque, tempoCooldownCacador;
	bool atacando, podeAndar, morrer, especializando, andando, morto, castou;
	float speedAtual, speedRecuo;
	int tipoPersonagem, atacouTipo;
	int ataque, vida, vidaMaxima, defesa, mana, manaMaxima, level;
	string nome;
	Magia magiazinha;
};

//110x85
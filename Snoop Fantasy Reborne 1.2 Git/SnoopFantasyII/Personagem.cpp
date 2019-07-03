#include "Personagem.h"


Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

Sprite Personagem::getSpriteFrameAtual()
{
	Sprite spriteFrameAtual;
	spriteFrameAtual.setTexture(txtChar);
	spriteFrameAtual.setTextureRect(animaAtual->getFrame(spChar.getCurrentFrame()));
	spriteFrameAtual.setPosition(x, y);
	return spriteFrameAtual;
}

void Personagem::inicializar(int x_, int y_)
{
	cout << "inicializou personagem" << endl;
	x = x_;
	y = y_;
	andando = false;
	morto = false;
	tipoPersonagem = 1;
}

AnimatedSprite Personagem::desenhar()
{
	return spChar;
}

void Personagem::andaDireita()
{
	if (podeAndar)
	{
		if (nAnimacaoAtual != Andando)
		{
			nAnimacaoAtual = Andando;
			animaAtual = &animAndando;
		}
		x += speedAtual;
		andando = true;
	}
}

void Personagem::andaEsquerda()
{
	if (podeAndar)
	{
		if (nAnimacaoAtual != Andando)
		{
			nAnimacaoAtual = Andando;
			animaAtual = &animAndando;
		}
		x -= speedAtual;
		andando = true;
	}
}

void Personagem::andaCima()
{
	if (podeAndar)
	{
		if (nAnimacaoAtual != Andando)
		{
			nAnimacaoAtual = Andando;
			animaAtual = &animAndando;
		}
		y -= speedAtual;
		andando = true;
	}
}

void Personagem::andaBaixo()
{
	if (podeAndar)
	{
		if (nAnimacaoAtual != Andando)
		{
			nAnimacaoAtual = Andando;
			animaAtual = &animAndando;
		}
		y += speedAtual;
		andando = true;
	}
}

void Personagem::setAnima(int qual)
{
	if (qual != nAnimacaoAtual)
	{
		switch (qual)
		{
		case 0:
			animaAtual = &animParado;
			nAnimacaoAtual = 0;
			spChar.setFrameTime(seconds(0.2));
			spChar.setLooped(true);
			break;
		case 1:
			animaAtual = &animAndando;
			nAnimacaoAtual = 1;
			spChar.setFrameTime(seconds(0.2));
			spChar.setLooped(true);
			break;
		case 2:
			animaAtual = &animAtacando;
			nAnimacaoAtual = 2;
			break;
		default:
			animaAtual = &animParado;
			nAnimacaoAtual = 0;
			spChar.setFrameTime(seconds(0.2));
			spChar.setLooped(true);
			break;
		}
	}
}

void Personagem::ataca()
{
	if (!atacando && !morrer)
	{
		double segs = 0.2;
		if (nAnimacaoAtual != Atacando)
		{
			nAnimacaoAtual = Atacando;
			animaAtual = &animAtacando;
			spChar.setFrameTime(seconds(segs));
			spChar.setLooped(false);
			tempoAtaque.contaAte(segs * 2);
		}
		atacando = true;
		podeAndar = false;
	}
}

bool Personagem::getAtacando()
{
	return atacando;
}

bool Personagem::getCastou()
{
	return false;
}

void Personagem::setCastou(bool castou_)
{
	castou = castou_;
}

void Personagem::setCorrendo(bool estaCorrendo)
{
	if (estaCorrendo)
	{
		if (speedAtual != 0.6)
		{
			speedAtual = 0.6;
		}
	}
	else
	{
		if (speedAtual != 0.4)
		{
			speedAtual = 0.4;
		}
	}
	/*if (estaCorrendo)
	{
		if (speedAtual != 0.08)
		{
			speedAtual = 0.08;
		}
	}
	else
	{
		if (speedAtual != 0.05)
		{
			speedAtual = 0.05;
		}
	}*/
}

int Personagem::getXbotas()
{
	return x;
}

int Personagem::getYbotas()
{
	return y + 66;
}

int Personagem::getVida()
{
	return vida;
}

int Personagem::getAtaque()
{
	return ataque;
}

float Personagem::getTempoFrames()
{
	return spChar.getFrameTime().asSeconds();
}

void Personagem::recebeDano(int dano)
{
	if (nAnimacaoAtual != TomaDano && !morto)
	{
		nAnimacaoAtual = TomaDano;
		animaAtual = &animTomaDano;
		spChar.setLooped(false);
		podeAndar = false;
		vida -= dano;
		
		cout << "player foi machucado" << endl;
	}
	if (vida <= 0)
	{
		morrer = true;
	}
}

int Personagem::getXatacando()
{
	return x + 80;
}

int Personagem::getYatacando()
{
	return y + 45;
}

int Personagem::getXmeio()
{
	return x + 30;
}

int Personagem::getYmeio()
{
	return y + 50;
}

int Personagem::getAnimacaoAtual()
{
	return nAnimacaoAtual;
}

bool Personagem::getMorto()
{
	return morto;
}

void Personagem::especial()
{
	
}

bool Personagem::getEspecializando()
{
	return especializando;
}

void Personagem::desEspecial()
{
	especializando = false;
	podeAndar = true;
	setAnima(Parado);
}

int Personagem::getTipoPersonagem()
{
	return tipoPersonagem;
}

int Personagem::movePara(int x_, int y_)
{
	int xAlvo, yAlvo, xAtual, yAtual;
	xAlvo = x_ - 50;
	yAlvo = y_;
	xAtual = x;
	yAtual = y;
	int andou = 0;
	//speedAtual = 0.04;
	//speedAtual = 0.3;
	if (xAtual > xAlvo)
	{
		andaEsquerda();
		andou++;
	}
	else if (xAtual < xAlvo)
	{
		andaDireita();
		andou++;
	}
	if (yAtual < yAlvo)
	{
		andaBaixo();
		andou++;
	}
	else if (yAtual > yAlvo)
	{
		andaCima();
		andou++;
	}
	if (andou == 0)
	{
		setAnima(Parado);
	}
	return andou;
}

float Personagem::getXReal()
{
	return x;
}

float Personagem::getYReal()
{
	return y;
}

void Personagem::paraAndar()
{
	andando = false;
}

bool Personagem::getAndando()
{
	return andando;
}

Magia Personagem::getMagia()
{
	return magiazinha;
}

int Personagem::getAtacouTipo()
{
	return atacouTipo;
}

void Personagem::setAtacouTipo(int atacouTipo_)
{
	atacouTipo = atacouTipo_;
}

void Personagem::empurraEsquerda()
{
	x -= speedAtual / 2.0;
	podeAndar = false;
}
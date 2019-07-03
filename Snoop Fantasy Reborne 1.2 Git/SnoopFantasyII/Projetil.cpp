#include "Projetil.h"



Projetil::Projetil()
{
}


Projetil::~Projetil()
{
}

void Projetil::inicializarTeste(int tipoMagia_, bool alvo_, int tipoAlvo_, float x_, float y_, int dano_, Texture txtzinha)
{
	x = x_;
	y = y_;
	xInicial = x;
	yInicial = y;
	tipoMagia = tipoMagia_;
	alvo = alvo_;
	tipoAlvo = tipoAlvo_;
	dano = dano_;
	deleteMe = false;
	txtProjetil = txtzinha;
	animEfeito.setSpriteSheet(txtProjetil);

	animEfeito.addFrame(IntRect(648, 23, 18, 5));
	animEfeito.addFrame(IntRect(744, 23, 18, 5));

	spProjetil.setPosition(x, y);
	spProjetil.setFrameTime(seconds(0.15));
	spProjetil.setLooped(true);

	animaAtual = &animEfeito;
	nAnimacaoAtual = Efeito;

	speed = 1.2;
}

void Projetil::reinicializar(int tipoMagia_, bool alvo_, int tipoAlvo_, float x_, float y_, int dano_)
{
	x = x_;
	y = y_;
	xInicial = x;
	yInicial = y;
	tipoMagia = tipoMagia_;
	alvo = alvo_;
	tipoAlvo = tipoAlvo_;
	dano = dano_;


	switch (tipoMagia)
	{
	case 0:
		spProjetil.setPosition(x, y);
		spProjetil.setFrameTime(seconds(0.15));
		spProjetil.setLooped(true);

		animaAtual = &animEfeito;
		nAnimacaoAtual = Efeito;

		speed = 1.2;
		break;
	case 1:
		spProjetil.setPosition(x, y);
		spProjetil.setFrameTime(seconds(0.15));
		spProjetil.setLooped(false);
		nAnimacaoAtual = Efeito;

		animaAtual = &animEfeito;

		speed = 0.7;
		break;
	}
}

//TIPOS MAGIA 0 = flecha 1 = bola de fogo 2 = heal em area

void Projetil::inicializar(int tipoMagia_, bool alvo_, int tipoAlvo_, float x_, float y_, int dano_)
{
	x = x_;
	y = y_;
	xInicial = x;
	yInicial = y;
	tipoMagia = tipoMagia_;
	alvo = alvo_;
	tipoAlvo = tipoAlvo_;
	dano = dano_;
	switch (tipoMagia)
	{
	case 0:
		/*if (!txtProjetil.loadFromFile("bin/cacador.png"))
		{
			cout << "Nao rolou cacador." << endl;
			system("pause"); return;
		}*/
		Collision::CreateTextureAndBitmask(txtProjetil, "bin/cacador.png");

		animEfeito.setSpriteSheet(txtProjetil);

		animEfeito.addFrame(IntRect(648, 23, 18, 5));
		animEfeito.addFrame(IntRect(744, 23, 18, 5));

		spProjetil.setPosition(x, y);
		spProjetil.setFrameTime(seconds(0.15));
		spProjetil.setLooped(true);

		animaAtual = &animEfeito;
		nAnimacaoAtual = Efeito;

		speed = 1.2;
		//speed = 0.3;

		break;
	case 1:
		/*if (!txtProjetil.loadFromFile("bin/musico.png"))
		{
			cout << "Nao rolou musico." << endl;
			system("pause"); return;
		}*/
		Collision::CreateTextureAndBitmask(txtProjetil, "bin/musico.png");

		animEfeito.setSpriteSheet(txtProjetil);
		animCriacao.setSpriteSheet(txtProjetil);

		animCriacao.addFrame(IntRect(547, 21, 29, 17));
		animCriacao.addFrame(IntRect(643, 21, 29, 17));
		animCriacao.addFrame(IntRect(739, 21, 29, 17));

		animEfeito.addFrame(IntRect(643, 117, 29, 17));
		animEfeito.addFrame(IntRect(739, 117, 29, 17));

		spProjetil.setPosition(x, y);
		spProjetil.setFrameTime(seconds(0.15));
		spProjetil.setLooped(false);
		nAnimacaoAtual = Criacao;

		animaAtual = &animCriacao;

		speed = 0.7;
		//speed = 0.15;

		break;
	case 2:
		/*if (!txtProjetil.loadFromFile("bin/barbeiro.png"))
		{
			cout << "Nao rolou barbeiro." << endl;
			system("pause"); return;
		}*/
		Collision::CreateTextureAndBitmask(txtProjetil, "bin/barbeiro.png");

		animEfeito.setSpriteSheet(txtProjetil);

		animEfeito.addFrame(IntRect(384, 0, 96, 96));
		animEfeito.addFrame(IntRect(480, 0, 96, 96));
		animEfeito.addFrame(IntRect(576, 0, 96, 96));
		animEfeito.addFrame(IntRect(672, 0, 96, 96));
		animEfeito.addFrame(IntRect(768, 0, 96, 96));
		break;
	}
	deleteMe = false;
}

void Projetil::inicializarInimigo(float x_, float y_, int dano_)
{
	x = x_;
	y = y_;
	xInicial = x;
	yInicial = y;
	dano = dano_;
	speed = 0.4;

	Collision::CreateTextureAndBitmask(txtProjetil, "bin/acido.png");

	animEfeito.setSpriteSheet(txtProjetil);

	animEfeito.addFrame(IntRect(0, 0, 219, 110));
	animEfeito.addFrame(IntRect(219, 0, 219, 110));

	spProjetil.setPosition(x, y);
	spProjetil.setFrameTime(seconds(0.15));
	spProjetil.setLooped(true);
	nAnimacaoAtual = Efeito;

	animaAtual = &animEfeito;
}

void Projetil::atualizar()
{
	Time frameTime = frameClock.restart();

	switch (tipoMagia)
	{
	case 0:
		x += speed;
		if (x > (xInicial + 600))
		{
			deleteMe = true;
		}
		break;
	case 1:
		x += speed;
		
		if (!spProjetil.isPlaying() && nAnimacaoAtual == Criacao) // ta bugado n sei pq
		{
			nAnimacaoAtual = Efeito;
			animaAtual = &animEfeito;
		}
		if (x > (xInicial + 600))
		{
			deleteMe = true;
		}
		break;

	case 2:

		break;
	}

	spProjetil.setPosition(x, y);

	spProjetil.play(*animaAtual);

	spProjetil.update(frameTime);
}

void Projetil::atualizarIni()
{
	Time frameTime = frameClock.restart();

	x -= speed;
	if (x < (xInicial - 1000))
	{
		deleteMe = true;
	}

	spProjetil.setPosition(x, y);

	spProjetil.play(*animaAtual);

	spProjetil.update(frameTime);
}

AnimatedSprite Projetil::desenhar()
{
	return spProjetil;
}

int Projetil::getX()
{
	return x;
}

int Projetil::getY()
{
	return y;
}

bool Projetil::getDeleteMe()
{
	return deleteMe;
}

void Projetil::setDeleteMeTrue()
{
	deleteMe = true;
}

Sprite Projetil::getSpriteFrameAtual()
{
	Sprite spriteFrameAtual;
	spriteFrameAtual.setTexture(txtProjetil);
	spriteFrameAtual.setTextureRect(animaAtual->getFrame(spProjetil.getCurrentFrame()));
	spriteFrameAtual.setPosition(x, y);
	return spriteFrameAtual;
}

int Projetil::getDano()
{
	return dano;
}
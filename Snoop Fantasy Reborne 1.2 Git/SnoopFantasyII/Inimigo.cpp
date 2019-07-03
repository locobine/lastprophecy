#include "Inimigo.h"



Inimigo::Inimigo()
{
}


Inimigo::~Inimigo()
{
}

void Inimigo::inicializar(int tipo, float x_, float y_)
{
	x = x_;
	y = y_;
	switch (tipo)
	{
	case Cobra1:
		/*if (!txtIni.loadFromFile("bin/snake1.png"))
		{
			cout << "Nao rolou cobra1." << endl;
			system("pause"); return;
		}*/
		Collision::CreateTextureAndBitmask(txtIni, "bin/snake1.png");

		animParado.setSpriteSheet(txtIni);
		animAndando.setSpriteSheet(txtIni);
		animAtacando.setSpriteSheet(txtIni);
		animTomaDano.setSpriteSheet(txtIni);
		animMorrer.setSpriteSheet(txtIni);
		animMorto.setSpriteSheet(txtIni);
		animEspecial.setSpriteSheet(txtIni);

		//animParado
		animParado.addFrame(IntRect(0, 0, 219, 110));
		animParado.addFrame(IntRect(219, 0, 219, 110));
		animParado.addFrame(IntRect(438, 0, 219, 110));
		animParado.addFrame(IntRect(657, 0, 219, 110));

		//animAndando
		animAndando.addFrame(IntRect(0, 110, 219, 110));
		animAndando.addFrame(IntRect(219, 110, 219, 110));
		animAndando.addFrame(IntRect(438, 110, 219, 110));
		animAndando.addFrame(IntRect(657, 110, 219, 110));

		//animAtacando
		animAtacando.addFrame(IntRect(0, 220, 219, 110));
		animAtacando.addFrame(IntRect(219, 220, 219, 110));
		animAtacando.addFrame(IntRect(438, 220, 219, 110));
		animAtacando.addFrame(IntRect(657, 220, 219, 110));
		animAtacando.addFrame(IntRect(876, 220, 219, 110));
		animAtacando.addFrame(IntRect(1095, 220, 219, 110));

		//animTomaDano
		animTomaDano.addFrame(IntRect(0, 330, 219, 110));
		animTomaDano.addFrame(IntRect(219, 330, 219, 110));
		animTomaDano.addFrame(IntRect(438, 330, 219, 110));
		animTomaDano.addFrame(IntRect(657, 330, 219, 110));
		animTomaDano.addFrame(IntRect(876, 330, 219, 110));
		animTomaDano.addFrame(IntRect(1095, 330, 219, 110));

		//animMorrer
		animMorrer.addFrame(IntRect(0, 440, 219, 110));
		animMorrer.addFrame(IntRect(219, 440, 219, 110));
		animMorrer.addFrame(IntRect(438, 440, 219, 110));
		animMorrer.addFrame(IntRect(657, 440, 219, 110));
		animMorrer.addFrame(IntRect(876, 440, 219, 110));
		animMorrer.addFrame(IntRect(1095, 440, 219, 110));
		animMorrer.addFrame(IntRect(1314, 440, 219, 110));

		//animMorto
		animMorto.addFrame(IntRect(1314, 330, 219, 110));

		//animEspecial
		animEspecial.addFrame(IntRect(219, 220, 219, 110));
		animEspecial.addFrame(IntRect(876, 220, 219, 110));
		animEspecial.addFrame(IntRect(1095, 220, 219, 110));

		//x = 800;
		//y = 200;

		spIni.setPosition(x, y);
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);

		animaAtual = &animParado;
		nAnimacaoAtual = 0;
		vida = 100;
		ataque = 10;
		tipoCobra = 1;
		break;
	case Cobra2:
		/*if (!txtIni.loadFromFile("bin/snake2.png"))
		{
			cout << "Nao rolou cobra2." << endl;
			system("pause"); return;
		}*/
		Collision::CreateTextureAndBitmask(txtIni, "bin/snake2.png");

		animParado.setSpriteSheet(txtIni);
		animAndando.setSpriteSheet(txtIni);
		animAtacando.setSpriteSheet(txtIni);
		animTomaDano.setSpriteSheet(txtIni);
		animMorrer.setSpriteSheet(txtIni);
		animMorto.setSpriteSheet(txtIni);
		animEspecial.setSpriteSheet(txtIni);

		//animParado
		animParado.addFrame(IntRect(0, 0, 219, 110));
		animParado.addFrame(IntRect(219, 0, 219, 110));
		animParado.addFrame(IntRect(438, 0, 219, 110));
		animParado.addFrame(IntRect(657, 0, 219, 110));

		//animAndando
		animAndando.addFrame(IntRect(0, 110, 219, 110));
		animAndando.addFrame(IntRect(219, 110, 219, 110));
		animAndando.addFrame(IntRect(438, 110, 219, 110));
		animAndando.addFrame(IntRect(657, 110, 219, 110));

		//animAtacando
		animAtacando.addFrame(IntRect(0, 220, 219, 110));
		animAtacando.addFrame(IntRect(219, 220, 219, 110));
		animAtacando.addFrame(IntRect(438, 220, 219, 110));
		animAtacando.addFrame(IntRect(657, 220, 219, 110));
		animAtacando.addFrame(IntRect(876, 220, 219, 110));
		animAtacando.addFrame(IntRect(1095, 220, 219, 110));

		//animTomaDano
		animTomaDano.addFrame(IntRect(0, 330, 219, 110));
		animTomaDano.addFrame(IntRect(219, 330, 219, 110));
		animTomaDano.addFrame(IntRect(438, 330, 219, 110));
		animTomaDano.addFrame(IntRect(657, 330, 219, 110));
		animTomaDano.addFrame(IntRect(876, 330, 219, 110));
		animTomaDano.addFrame(IntRect(1095, 330, 219, 110));

		//animMorrer
		animMorrer.addFrame(IntRect(0, 440, 219, 110));
		animMorrer.addFrame(IntRect(219, 440, 219, 110));
		animMorrer.addFrame(IntRect(438, 440, 219, 110));
		animMorrer.addFrame(IntRect(657, 440, 219, 110));
		animMorrer.addFrame(IntRect(876, 440, 219, 110));
		animMorrer.addFrame(IntRect(1095, 440, 219, 110));
		animMorrer.addFrame(IntRect(1314, 440, 219, 110));

		//animMorto
		animMorto.addFrame(IntRect(1314, 330, 219, 110));

		//animEspecial
		animEspecial.addFrame(IntRect(219, 220, 219, 110));
		animEspecial.addFrame(IntRect(876, 220, 219, 110));
		animEspecial.addFrame(IntRect(1095, 220, 219, 110));

		//x = 800;
		//y = 400;

		spIni.setPosition(x, y);
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);

		animaAtual = &animParado;
		nAnimacaoAtual = 0;
		vida = 150;
		ataque = 15;
		tipoCobra = 2;

		break;
	case Cobra3:
		/*if (!txtIni.loadFromFile("bin/snake3.png"))
		{
			cout << "Nao rolou cobra3." << endl;
			system("pause"); return;
		}*/
		Collision::CreateTextureAndBitmask(txtIni, "bin/snake3.png");

		animParado.setSpriteSheet(txtIni);
		animAndando.setSpriteSheet(txtIni);
		animAtacando.setSpriteSheet(txtIni);
		animTomaDano.setSpriteSheet(txtIni);
		animMorrer.setSpriteSheet(txtIni);
		animMorto.setSpriteSheet(txtIni);
		animEspecial.setSpriteSheet(txtIni);

		//animParado
		animParado.addFrame(IntRect(0, 0, 219, 110));
		animParado.addFrame(IntRect(219, 0, 219, 110));
		animParado.addFrame(IntRect(438, 0, 219, 110));
		animParado.addFrame(IntRect(657, 0, 219, 110));

		//animAndando
		animAndando.addFrame(IntRect(0, 110, 219, 110));
		animAndando.addFrame(IntRect(219, 110, 219, 110));
		animAndando.addFrame(IntRect(438, 110, 219, 110));
		animAndando.addFrame(IntRect(657, 110, 219, 110));

		//animAtacando
		animAtacando.addFrame(IntRect(0, 220, 219, 110));
		animAtacando.addFrame(IntRect(219, 220, 219, 110));
		animAtacando.addFrame(IntRect(438, 220, 219, 110));
		animAtacando.addFrame(IntRect(657, 220, 219, 110));
		animAtacando.addFrame(IntRect(876, 220, 219, 110));
		animAtacando.addFrame(IntRect(1095, 220, 219, 110));

		//animTomaDano
		animTomaDano.addFrame(IntRect(0, 330, 219, 110));
		animTomaDano.addFrame(IntRect(219, 330, 219, 110));
		animTomaDano.addFrame(IntRect(438, 330, 219, 110));
		animTomaDano.addFrame(IntRect(657, 330, 219, 110));
		animTomaDano.addFrame(IntRect(876, 330, 219, 110));
		animTomaDano.addFrame(IntRect(1095, 330, 219, 110));

		//animMorrer
		animMorrer.addFrame(IntRect(0, 440, 219, 110));
		animMorrer.addFrame(IntRect(219, 440, 219, 110));
		animMorrer.addFrame(IntRect(438, 440, 219, 110));
		animMorrer.addFrame(IntRect(657, 440, 219, 110));
		animMorrer.addFrame(IntRect(876, 440, 219, 110));
		animMorrer.addFrame(IntRect(1095, 440, 219, 110));
		animMorrer.addFrame(IntRect(1314, 440, 219, 110));

		//animMorto
		animMorto.addFrame(IntRect(1314, 330, 219, 110));

		//animEspecial
		animEspecial.addFrame(IntRect(219, 220, 219, 110));
		animEspecial.addFrame(IntRect(876, 220, 219, 110));
		animEspecial.addFrame(IntRect(1095, 220, 219, 110));

		//x = 1000;
		//y = 300;

		spIni.setPosition(x, y);
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(true);

		animaAtual = &animParado;
		nAnimacaoAtual = 0;
		vida = 200;
		ataque = 25;
		tipoCobra = 3;
		break;
	}
	morrer = false;
	morto = false;
	podeAtacar = false;
	atacando = false;
	speed = 1.0;
	nHitsRecebidos = 0;
	estadoAtual = Stopped;
	xInicial = x;
	yInicial = y;
	acidou = false;
	tempoAcidar.contaAte(4.0);
	jaAcidou = false;
}

void Inimigo::atualizar()
{
	Time frameTime = frameClock.restart();
	if (!morrer)
	{
		if (estadoAtual == Roaming)
		{
			int difY, difX;
			difY = y - yInicial;
			if (difY < 0)
			{
				difY *= -1;
			}
			difX = x - xInicial;
			if (difX < 0)
			{
				difX *= -1;
			}
			int actionAtual = rand() % 4;
			switch (actionAtual)
			{
			case 0:
				if (difX < 6)
				{
					andaEsquerda();
				}
				break;
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			}
		}
		else if (estadoAtual == Stopped)
		{
			if (nAnimacaoAtual != TomaDano2)
			{
				if (nAnimacaoAtual != Parado2)
				{
					animaAtual = &animParado;
					nAnimacaoAtual = Parado2;
					spIni.setFrameTime(seconds(0.2));
					spIni.setLooped(true);
				}
				if (nHitsRecebidos >= 3)
				{
					podeAtacar = true;
					estadoAtual = Reacting;
					nHitsRecebidos = 0;
				}
				if (tempoAcidar.checaConta() && tipoCobra == 1)
				{
					if (nAnimacaoAtual != Especializando2)
					{
						estadoAtual = Aciding;
					}
				}
			}
		}
		else if (estadoAtual == Aciding)
		{
			if (nAnimacaoAtual != Especializando2)
			{
				animaAtual = &animEspecial;
				nAnimacaoAtual = Especializando2;
				spIni.setFrameTime(seconds(0.6));
				spIni.setLooped(false);
			}
		}
		else if (estadoAtual == Reacting)
		{
			if (podeAtacar && !atacando)
			{
				ataca();
			}
		}
		if (atacando && !spIni.isPlaying())
		{
			cout << "entrou em atacando pelo menos?" << endl;
			animaAtual = &animParado;
			nAnimacaoAtual = Parado2;
			spIni.setFrameTime(seconds(0.2));
			spIni.setLooped(true);
			atacando = false;
			estadoAtual = Stopped;
			podeAtacar = false;
			//atacou = true;
		}
		if (estadoAtual == Aciding)
		{
			if (spIni.getCurrentFrame() == 1 && !jaAcidou)
			{
				acidou = true;
				jaAcidou = true;
			}
			
			if (!spIni.isPlaying())
			{
				estadoAtual = Stopped;
				jaAcidou = false;
			}
		}
		if (nAnimacaoAtual == TomaDano2 && !spIni.isPlaying())
		{
			animaAtual = &animParado;
			spIni.setFrameTime(seconds(0.2));
			spIni.setLooped(true);
			nAnimacaoAtual = Parado2;
		}
		if (tempoAtaque.checaConta())
		{
			atacou = true;
		}
	}
	if (morrer && !morto)
	{
		nAnimacaoAtual = Morrer2;
		animaAtual = &animMorrer;
		spIni.setFrameTime(seconds(0.2));
		spIni.setLooped(false);
		if (!spIni.isPlaying())
		{
			morto = true;
		}
	}
	else if (morrer && morto)
	{
		if (nAnimacaoAtual != Morto2)
		{
			animaAtual = &animMorto;
			spIni.setFrameTime(seconds(0.2));
			spIni.setLooped(true);
		}
	}
	
	

	spIni.setPosition(x, y);

	spIni.play(*animaAtual);

	spIni.update(frameTime);
}

AnimatedSprite Inimigo::desenhar()
{
	return spIni;
}

Sprite Inimigo::getSpriteFrameAtual()
{
	Sprite spriteFrameAtual;
	spriteFrameAtual.setTexture(txtIni);
	spriteFrameAtual.setTextureRect(animaAtual->getFrame(spIni.getCurrentFrame()));
	spriteFrameAtual.setPosition(x, y);
	return spriteFrameAtual;
}

int Inimigo::getVida()
{
	return vida;
}

int Inimigo::getAtaque()
{
	return ataque;
}

void Inimigo::recebeDano(int dano)
{
	if (nAnimacaoAtual != TomaDano2)
	{
		vida -= dano;
		//podeAtacar = true;
		float segs = 0.15;
		spIni.setFrameTime(seconds(segs));
		spIni.setLooped(false);
		animaAtual = &animTomaDano;
		nAnimacaoAtual = TomaDano2;
		nHitsRecebidos++;
	}
	if (vida <= 0)
	{
		morrer = true;
	}
	cout << "Cobra grita" << endl;
}

int Inimigo::getXcolisao()
{
	return x + 160;
}

int Inimigo::getYcolisao()
{
	return y + 55;
}

bool Inimigo::getMorto()
{
	return morto;
}

void Inimigo::ataca()
{
	if (!atacando && podeAtacar)
	{
		cout << "entrou aqui dentro do naoatacando ee podeatacar" << endl;
		float segs = 0.2;
		if (nAnimacaoAtual != Atacando2)
		{
			spIni.setFrameTime(seconds(segs));
			spIni.setLooped(false);
			animaAtual = &animAtacando;
			nAnimacaoAtual = Atacando2;
		}
		atacando = true;
		podeAtacar = false;
		nAnimacaoAtual = 2;
		tempoAtaque.contaAte(segs * 3);
	}
}

bool Inimigo::getAtacou()
{
	return atacou;
}

void Inimigo::setAtacou(bool att)
{
	atacou = att;
}

void Inimigo::setAcidou(bool acidou_)
{
	acidou = acidou_;
	jaAcidou = true;
	int tempoRandom = (rand() % 3) + 3.0;
	tempoAcidar.contaAte(tempoRandom);
}

void Inimigo::andaBaixo()
{
	if (nAnimacaoAtual != Andando2)
	{
		nAnimacaoAtual = Andando2;
		animaAtual = &animAndando;
		spIni.setLooped(true);
		spIni.setFrameTime(seconds(0.2));
	}
	y += speed;
}

void Inimigo::andaCima()
{
	if (nAnimacaoAtual != Andando2)
	{
		nAnimacaoAtual = Andando2;
		animaAtual = &animAndando;
		spIni.setLooped(true);
		spIni.setFrameTime(seconds(0.2));
	}
	y += speed;
}

void Inimigo::andaEsquerda()
{
	if (nAnimacaoAtual != Andando2)
	{
		nAnimacaoAtual = Andando2;
		animaAtual = &animAndando;
		spIni.setLooped(true);
		spIni.setFrameTime(seconds(0.2));
	}
	y += speed;
}

void Inimigo::andaDireita()
{
	if (nAnimacaoAtual != Andando2)
	{
		nAnimacaoAtual = Andando2;
		animaAtual = &animAndando;
		spIni.setLooped(true);
		spIni.setFrameTime(seconds(0.2));
	}
	y += speed;
}
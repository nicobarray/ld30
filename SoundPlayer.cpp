#include "SoundPlayer.h"

SoundPlayer::~SoundPlayer(void)
{
}

void SoundPlayer::play(int sound)
{
	sf::Sound* s = new sf::Sound();
	s->setBuffer(Ressource::getInstance().buffer_get(sound));
	s->play();

	sounds.push_back(s);
}

void SoundPlayer::update()
{
	for (auto it = sounds.begin(); it < sounds.end(); it++)
	{
		if ((*it)->getStatus() != sf::Sound::Playing)
			sounds.erase(it, it);
	}
}
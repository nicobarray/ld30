#include "SoundPlayer.h"

SoundPlayer::~SoundPlayer(void)
{
}

void SoundPlayer::play(int sound)
{
	sf::Sound s;
	s.setBuffer(Ressource::getInstance().buffer_get(sound));
	s.play();
}
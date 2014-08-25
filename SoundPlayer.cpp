#include "SoundPlayer.h"

SoundPlayer::~SoundPlayer(void)
{
	musics.clear();
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

void SoundPlayer::play_music(bool real)
{
	musics.at(!real)->setPlayingOffset(musics.at(real)->getPlayingOffset());
	musics.at(real)->setLoop(true);
	musics.at(!real)->stop();
	musics.at(real)->play();
}

void SoundPlayer::load_music(std::string path)
{
	sf::Music* music = new sf::Music();

	if (!music->openFromFile(path))
	{
		std::cout << "Open music form file error : " << path << std::endl;
	}

	musics.push_back(music);
}

void SoundPlayer::stop_music()
{
	for(sf::Music* m : musics)
	{
		if (m->getStatus() == sf::Music::Playing)
			m->stop();
	}
}

void SoundPlayer::stop_music(int index)
{
	musics.at(index)->stop();
}
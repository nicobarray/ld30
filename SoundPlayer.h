#pragma once

#include <vector>

#include "Ressource.h"

class SoundPlayer
{
public:
	static SoundPlayer& getInstance()
	{
		static SoundPlayer instance;
		return instance;
	}

	~SoundPlayer();
	void play(int sound);
	void play_music(bool real);
	void stop_music();
	void stop_music(int index);
	void load_music(std::string path);
	void update();

private:
	SoundPlayer()
		: sounds()
		, musics()
	{
	}

	SoundPlayer(SoundPlayer const&);
	void operator=(SoundPlayer const&);
private:
	std::vector<sf::Sound*> sounds;
	std::vector<sf::Music*> musics;
};


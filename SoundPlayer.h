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
	void update();

private:
	SoundPlayer()
		: sounds()
	{
	}

	SoundPlayer(SoundPlayer const&);
	void operator=(SoundPlayer const&);
private:
	std::vector<sf::Sound*> sounds;
};


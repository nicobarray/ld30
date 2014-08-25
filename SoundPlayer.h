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

private:
	SoundPlayer()
	{
	}

	SoundPlayer(SoundPlayer const&);
	void operator=(SoundPlayer const&);
private:
};


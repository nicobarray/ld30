#pragma once

#include<string>
#include<vector>
#include<iostream>

#include <SFML/Graphics.hpp>

enum tex_id
{
	TILESET1 = 0,
	DROPHEALTH,
	IMP
};

class Ressource
{
public:
	static Ressource& getInstance()
	{
		static Ressource instance;
		return instance;
	}

	~Ressource();
	int load_image(std::string path);
	sf::Texture& texture_get(int index);

private:
	Ressource()
		: textures()
	{
		
	}

	Ressource(Ressource const&);
	void operator=(Ressource const&);

private:
	std::vector<sf::Texture> textures;
};


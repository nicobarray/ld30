#include "Ressource.h"

int Ressource::load_image(std::string path)
{
	// load sample.png into image
	sf::Texture texture;

	if(!texture.loadFromFile(path))
	{
		std::cout << "Loading texture error : " << path << std::endl;
		return -1;
	}

	textures.push_back(texture);

	return textures.size() - 1;
}

int Ressource::load_wav(std::string path)
{
	sf::SoundBuffer* buffer = new sf::SoundBuffer();

	if (!buffer->loadFromFile(path))
	{
		std::cout << "Loading wav error : " << path << std::endl;
		return -1;
	}

	buffers.push_back(buffer);

	return buffers.size() - 1;
}

Ressource::~Ressource(void)
{
	buffers.clear();
	textures.clear();
}

sf::Texture& Ressource::texture_get(int index)
{
	return textures.at(index);
}

const sf::SoundBuffer& Ressource::buffer_get(int index)
{
	return *buffers.at(index);
}
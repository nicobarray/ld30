#include "Ressource.h"

int Ressource::load_image(std::string path)
{
	// load sample.png into image
	sf::Texture texture;
	
	if(!texture.loadFromFile(path)) {
		std::cerr << "Loading texture error : " << path << std::endl;
	}

	textures.push_back(texture);

	return textures.size() - 1;
}

Ressource::~Ressource(void)
{
}

sf::Texture& Ressource::texture_get(int index)
{
	return textures.at(index);
}

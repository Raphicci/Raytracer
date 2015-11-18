
namespace	Displayer
{
	Frame::Frame() 
	{

	}

	Frame::Frame(sf::Uint8 *pixels, float *dist)
	{
		sf::Texture	texture;

		texture.update(pixels);
		this->image = texture.copyToImage();
		this->setDist(dist);
	}

	void	Frame::setDist(float *dist) 
	{
		this->dist = dist;
	}

	void	Frame::setMotionBlur(Frame const& nextFrame) // ou une list de frame si on fait le blur sur plusieurs images (d'ailleurs plus le nombre de FPS est important plus le nombre d'image dont il faut faire la moyenne est important)
	{
		unsigned int	x;
		unsigned int	y;
		sf::Vector2u size = this->image.getSize();
		sf::Color		previousColor;
		sf::Color		nextColor;

		x = 0;
		while (x < size.x)  
		{
			while (y < size.y)  
			{
				previousColor = this->image.getPixel(x, y);
				nextColor = nextFrame.image.getPixel(x, y);
				this->motionBlurImage.setPixel(x, y, Tools::Color::MixSfColor(previousColor, nextColor)); // l'image est déjà allouée dans le constructeur ?
				y++;
			}
			x++;
		}
	}

	Frame::~Frame()
	{

	}
};

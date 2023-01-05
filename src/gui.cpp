#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>

#include "gui.h"

GUI::GUI()
{
  
}

GUI::~GUI()
{
  _alive = false;
  //  _thread.join();
}

void GUI::start()
{
  //  _thread = std::thread(&GUI::_start, this);
  _start();
}

void GUI::_start()
{
  _window.create(sf::VideoMode(2000, 2000), "My window");
  _alive = true;
  while (_alive)
    {
      sf::Event event;
      while (_window.pollEvent(event))
	{
	  // "close requested" event: we close the window
	  if (event.type == sf::Event::Closed)
	    {
	      _window.close();
	      _alive = false;
	      break;
	    }
	  _window.clear();
	  _window.draw(_sprite);
	  _window.display();
	}
    }
}

void GUI::setImage(torch::Tensor image)
{
  unsigned int height = image.sizes()[1];
  unsigned int width = image.sizes()[2];

  // Add alpha channel if missing
  if (image.sizes()[0] == 3)
    {
      torch::Tensor alpha = torch::ones({1, height, width});
      image = torch::cat({image, alpha}, 0);
    }
  
  torch::Tensor intImage = (image * 255).to(torch::kUInt8);
  intImage = intImage.index({torch::indexing::Slice(0, 4)}).transpose(0, 1).transpose(1, 2);

  _imageData = intImage.clone().contiguous();  
  sf::Uint8 *data = _imageData.data_ptr<sf::Uint8>();
  _image.create(width, height, data);
  _texture.loadFromImage(_image);
  _sprite.setTexture(_texture);
}

int main(int ac, char **av)
{
  if (ac != 2)
    {
      std::cout << "Usage " << av[0] << " IMG" << std::endl;
      return 0;
    }
  
  GUI g;

  torch::Tensor t = loadImage(av[1]);
  
  g.setImage(t);
  g.start();
  
  return 0;
}

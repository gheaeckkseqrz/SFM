#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "images.h"

class GUI
{
 public:
  GUI();
  ~GUI();

  void start();
  void setImage(torch::Tensor image);

private:
  void _start();

private:
  bool _alive;
  std::thread            _thread;
  sf::RenderWindow       _window;
  sf::Image              _image;
  sf::Texture            _texture;
  sf::Sprite             _sprite;
  torch::Tensor          _imageData;
};

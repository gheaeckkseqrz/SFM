#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "images.h"


/*
  Loads image and return it as a tensor of shape [CxHxW]
  with channel order RGB in range [0, 1]
*/
torch::Tensor loadImage(std::string const &path, unsigned int size)
{
  int x, y, n;
  unsigned char *data = stbi_load(path.c_str(), &x, &y, &n, 0);

  if (!data)
    throw std::runtime_error("Couln't load " + path);

  torch::Deleter deleter = [](void *p) { stbi_image_free(p); };
  torch::TensorOptions options = torch::TensorOptions().dtype(torch::kUInt8);
  torch::Tensor t = torch::from_blob(data, {y, x, n}, deleter, options);
  t = t.transpose(0, 2).transpose(1, 2);
  return t.to(torch::kFloat32) / 255;
}

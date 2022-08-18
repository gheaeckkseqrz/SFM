#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "images.h"

TEST_CASE( "Load Red", "[Images]" )
{
  torch::Tensor red = loadImage("./data/red.png");

  std::cout << red << std::endl;

  REQUIRE( red.sizes() == std::vector<int64_t>{3, 5, 5} );
  for (unsigned int y(0) ; y < 5 ; ++y)
    for (unsigned int x(0) ; x < 5 ; ++x)
      {
	REQUIRE( red[0][y][x].item().to<float>() == 1.0f );
	REQUIRE( red[1][y][x].item().to<float>() == 0.0f );
	REQUIRE( red[2][y][x].item().to<float>() == 0.0f );
      }
}

TEST_CASE( "Load Green", "[Images]" )
{
  torch::Tensor green = loadImage("./data/green.png");
  REQUIRE( green.sizes() == std::vector<int64_t>{3, 5, 5} );
  for (unsigned int y(0) ; y < 5 ; ++y)
    for (unsigned int x(0) ; x < 5 ; ++x)
      {
	REQUIRE( green[0][y][x].item().to<float>() == 0.0f );
	REQUIRE( green[1][y][x].item().to<float>() == 1.0f );
	REQUIRE( green[2][y][x].item().to<float>() == 0.0f );
      }
}

TEST_CASE( "Load Blue", "[Images]" )
{
  torch::Tensor blue = loadImage("./data/blue.png");
  REQUIRE( blue.sizes() == std::vector<int64_t>{3, 5, 5} );
  for (unsigned int y(0) ; y < 5 ; ++y)
    for (unsigned int x(0) ; x < 5 ; ++x)
      {
	REQUIRE( blue[0][y][x].item().to<float>() == 0.0f );
	REQUIRE( blue[1][y][x].item().to<float>() == 0.0f );
	REQUIRE( blue[2][y][x].item().to<float>() == 1.0f );
      }
}

TEST_CASE( "Load Banana", "[Images]" )
{
  torch::Tensor blue = loadImage("./data/banana.png");
  REQUIRE( blue.sizes() == std::vector<int64_t>{4, 16, 16} );

  // Top left corner
  REQUIRE( blue[0][0][0].item().to<float>() == 0.0f );
  REQUIRE( blue[1][0][0].item().to<float>() == 0.0f );
  REQUIRE( blue[2][0][0].item().to<float>() == 0.0f );
  REQUIRE( blue[3][0][0].item().to<float>() == 0.0f );

  // A white pixel at 3, 3 : 247,254,255
  REQUIRE( blue[0][3][3].item().to<float>() == 247.0f / 255.0f );
  REQUIRE( blue[1][3][3].item().to<float>() == 254.0f / 255.0f );
  REQUIRE( blue[2][3][3].item().to<float>() == 255.0f / 255.0f );
  REQUIRE( blue[3][3][3].item().to<float>() == 1.0f );

  // A black pixel at 3, 4 : 35,30,43
  REQUIRE( blue[0][4][3].item().to<float>() == 35.0f / 255.0f );
  REQUIRE( blue[1][4][3].item().to<float>() == 30.0f / 255.0f );
  REQUIRE( blue[2][4][3].item().to<float>() == 43.0f / 255.0f );
  REQUIRE( blue[3][4][3].item().to<float>() == 1.0f );

  // A yellow pixel at 9, 11 : 226,180,54
  REQUIRE( blue[0][11][9].item().to<float>() == 226.0f / 255.0f );
  REQUIRE( blue[1][11][9].item().to<float>() == 180.0f / 255.0f );
  REQUIRE( blue[2][11][9].item().to<float>() == 54.0f / 255.0f );
  REQUIRE( blue[3][11][9].item().to<float>() == 1.0f );  
}

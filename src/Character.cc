#include "Character.hh"
#include "Engine/InputSystem.hh"


sf::CircleShape* circle{new sf::CircleShape()};

Character::Character(){}

Character::Character(const char* textureUrl, sf::Vector2f position, float scale, float width, 
float height, int col, int row, float moveSpeed, sf::RenderWindow*& window)
{
  this->position = position;
  this->scale = scale;
  this->width = width;
  this->height = height;
  this->width = width;
  this->window = window;
  this->moveSpeed = moveSpeed;
  //this->textureUrl = textureUrl;
  //std::cout << this->textureUrl << std::endl;
  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(col * width, row * height, width, height));
  sprite->setPosition(position);
  sprite->setScale(sf::Vector2f(scale, scale));
  sprite->setColor(sf::Color::White);
  sprite->setOrigin(sprite->getLocalBounds().width / 2.f, sprite->getLocalBounds().height / 2.f);

  circle->setRadius(2.f);
  circle->setFillColor(sf::Color::Green);
  circle->setOutlineColor(sf::Color::Green);
}

Character::~Character()
{
}

void Character::Draw()
{
  window->draw(*sprite);
  circle->setPosition(sprite->getPosition());
  window->draw(*circle);
}

void Character::Movement(float& deltaTime)
{
  sprite->move(InputSystem::GetAxis() * deltaTime * moveSpeed);
  FlipSprite();
}

void Character::FlipSprite()
{
  sprite->setScale(InputSystem::GetAxis().x < 0.f ? -scale : 
  InputSystem::GetAxis().x > 0.f ? scale :
  sprite->getScale().x, sprite->getScale().y);
}
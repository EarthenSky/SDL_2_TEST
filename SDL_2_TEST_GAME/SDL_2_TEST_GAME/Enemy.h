#ifndef ENEMY
#define ENEMY

#include <SDL.h>
#include <string>
#include <cmath>
#include "Point.h"
#include "EnemyManager.h"

//TODO: add player attacks to checkInput().

//SDL_Texture *loadTexture(SDL_Renderer *renderer, std::string path);

//extern SDL_Event gInputHandler;

class EnemyManager;

class Enemy {
public:
	Enemy(SDL_Texture *texture, Point position, Point texSize, double rotation, int listIndex, EnemyManager* enemyPtr);

	EnemyManager* m_enemyPtr;

	int m_listIndex;

	Point m_position;  //position
	Point m_velocity;  //velocity
	double m_rotation = 0;

	int m_radius;

	Point m_texSize;  //width / height of the object
	SDL_Texture *m_texture = NULL;

	//for physics things.  //TODO: framerate independence.
	void update();
	void collision(Point collsionOffset);

	void destroyEnemy();  //This function destroys this object and removes it from the list.

	void render(SDL_Renderer *renderer);
	//void checkInput();  //this is a reference

	~Enemy();
};

#endif
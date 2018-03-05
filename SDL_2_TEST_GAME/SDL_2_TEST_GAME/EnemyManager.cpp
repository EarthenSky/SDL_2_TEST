#include "EnemyManager.h"

void EnemyManager::init(SDL_Renderer *renderer)
{
	// Initialize the enemy texture
	m_enemyTexture = loadTexture(renderer, "Images/aiTex.bmp");
}

void EnemyManager::spawnEnemy(Point pos, Point texSize, double rotation)
{
	// Loads the enemy texture
	//SDL_Texture *texture = loadTexture(renderer, "Images/aiTex.bmp");

	// The list id of the enemy, used for deleting the object.
	//int listIndex = m_enemyList.size();
	
	printf("ADD\n");

	// Adds a new smart pointer to an enemy to the list.  Doesn't need to be deallocated.
	m_enemyList.push_back(new Enemy(m_enemyTexture, pos, texSize, rotation, &m_killList));
}

void EnemyManager::update()
{
	// Iterates over all child list objects and calls their render function.
	for (Enemy* enemyObj : m_enemyList) {
		enemyObj->update();
	}

	// Destroys all objects that need to be killed
	for (Enemy* enemyPtr : m_killList) {
		delete enemyPtr;  // Give the memory back before the item is removed from list.
		printf("REMOVE\n");
		m_enemyList.remove(enemyPtr);
	}

	if (m_killList.size() > 0) {
		printf("%d before\n", m_killList.size());
		printf("CLEAR\n");
		m_killList.clear();
		printf("%d after\n", m_killList.size());
	}

}

void EnemyManager::render(SDL_Renderer *renderer)
{
	// Iterates over all child list objects and calls their render function.
	for (Enemy* enemyObj : m_enemyList) {
		enemyObj->render(renderer);
	}
}

EnemyManager::~EnemyManager()
{
	// Delete all enemy classes in the deconstructor to avoid memory leaks
	//for (Enemy* enemyObj : m_enemyList) {
		//delete enemyObj;
	//}

	// Delete Enemy Texture
	SDL_DestroyTexture(m_enemyTexture);
	m_enemyTexture = NULL;

	printf("DESTROYED");
}
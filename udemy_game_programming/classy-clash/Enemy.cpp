#include "Enemy.h"
#include "../raylib-master/src/raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
	worldPos = pos;
	idle = idle_texture;
	run = run_texture;	
	width = texture.width / maxFrames;
	height = texture.height;
	speed = 3.5f;
}

void Enemy::tick(float deltaTime) {
	if(!getAlive()) return;

	// get toTarget
	velocity = Vector2Subtract(target->getScreenPos(), getScreenPos());
	if(Vector2Length(velocity) < radius) velocity = {0.f, 0.f};
	BaseCharacter::tick(deltaTime);

	if(CheckCollisionRecs(target->getCollisionRec(), getCollisionRec())) {
		target->takeDamage(damagePerSec * deltaTime);
	}
}

Vector2 Enemy::getScreenPos() {
	return Vector2Subtract(worldPos, target->getWorldPos());
}
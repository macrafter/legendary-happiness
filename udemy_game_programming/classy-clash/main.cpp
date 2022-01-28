#include "../raylib-master/src/raylib.h"
#include "../raylib-master/src/raymath.h"
#include "Character.h" 
#include "Enemy.h"
#include "Prop.h"
#include <string>
// g++ main.cpp BaseCharacter.cpp Character.cpp Prop.cpp Enemy.cpp -L../raylib-master/src -lraylib

int main() {
	const int windowWidth = 384, windowHeight = 384;
	InitWindow(384, 384, "oof");

	Texture2D map = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
	Vector2 mapPos{0.0, 0.0};
	const float mapScale{4.0f};

	Character knight{windowWidth, windowHeight};

	Prop props[2] {
		Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
		Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}
	};

	Enemy goblin{
		Vector2{800.f, 300.f}, 
		LoadTexture("characters/goblin_idle_spritesheet.png"),
		LoadTexture("characters/goblin_run_spritesheet.png")
	};

	Enemy slime{
		Vector2{500.f, 700.f}, 
		LoadTexture("characters/slime_idle_spritesheet.png"),
		LoadTexture("characters/slime_run_spritesheet.png")
	};

	Enemy* enemies[] {
		&goblin,
		&slime
	};

	for(auto enemy : enemies) {
		enemy->setTarget(&knight);
	}

	SetTargetFPS(60);
	while(!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

		//draws map
		DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
			
		for(auto prop : props) {
			prop.Render(knight.getWorldPos());
		}

		if(!knight.getAlive()) {
		// character is not alive
			DrawText("Game Over!", 55.f, 45.f, 40, RED);
			EndDrawing();
			continue;
		}else {
		//character is alive
			std::string knightsHealth = "Health: ";
			knightsHealth.append(std::to_string(knight.getHealth()), 0, 5);
			DrawText(knightsHealth.c_str(), 55.f, 45.f, 40, RED);
		}
		knight.tick(GetFrameTime());

		//check map bounds
		if (knight.getWorldPos().x < 0.f or
			knight.getWorldPos().y < 0.f or
			knight.getWorldPos().x + windowWidth > map.width * 4.0 or
			knight.getWorldPos().y + windowHeight > map.height * 4.0) {

			knight.undoMovement();
		}

		//check prop collisions
		for(auto prop : props) {
			if (CheckCollisionRecs(prop.getCollisionRec(knight.getWorldPos()), knight.getCollisionRec())) {
				knight.undoMovement();
			}
		}

		for(auto enemy : enemies) {
			enemy->tick(GetFrameTime());
		}

		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			for(auto enemy : enemies) {
				if(CheckCollisionRecs(enemy->getCollisionRec(), knight.getWeaponCollisionRec())){
					enemy->setAlive(false);
				}
			}
		}

		EndDrawing();	
	}
    
	//UnloadTexture(map);
	//UnloadTexture(knight);
	CloseWindow();
}
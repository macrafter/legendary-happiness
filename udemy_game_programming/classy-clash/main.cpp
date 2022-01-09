#include <iostream>
#include "../raylib-master/src/raylib.h"
#include "../raylib-master/src/raymath.h"
#include "Character.h" 
using namespace std;
// g++ main.cpp -L../raylib-master/src -lraylib

int main() {
	const int windowWidth = 384, windowHeight = 384;
	InitWindow(384, 384, "oof");

	Texture2D map = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
	Vector2 mapPos{0.0, 0.0};
	const float mapScale{4.0f};

	Character knight;
	knight.setScreenPos(windowWidth, windowHeight);

	SetTargetFPS(60);
	while(!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(WHITE);

		mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

		//draws map
		DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
		knight.tick(GetFrameTime());

		//check map bounds
		if (knight.getWorldPos().x < 0.f or
			knight.getWorldPos().y < 0.f or
			knight.getWorldPos().x + windowWidth > map.width * 4.0 or
			knight.getWorldPos().y + windowHeight > map.height * 4.0) {

			knight.undoMovement();
		}

		EndDrawing();	
	}
    
	//UnloadTexture(map);
	//UnloadTexture(knight);
	CloseWindow();
}
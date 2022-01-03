#include <iostream>
#include "../raylib-master/src/raylib.h"
#include "../raylib-master/src/raymath.h"
// g++ main.cpp -L../raylib-master/src -lraylib

int main() {
	const int windowWidth = 384, windowHeight = 384;
	InitWindow(384, 384, "oof");

	Texture2D map = LoadTexture("./nature_tileset/OpenWorldMap24x24.png");
	Vector2 mapPos{0.0, 0.0};
	float speed = 4.0;
	float rightLeft;

	Texture2D knight = LoadTexture("characters/knight_idle_spritesheet.png");
	Vector2 knightPos{
		windowWidth/2.0f - 4.0f * (0.5f * (float)knight.width/6.0f),
		windowHeight/2.0f - 4.0f * (0.5f * (float)knight.height)
	};
	
	SetTargetFPS(60);
	while(!WindowShouldClose()) {
		
		BeginDrawing();
		ClearBackground(WHITE);

		Vector2 direction{0.0, 0.0};

		if(IsKeyDown(KEY_A)) direction.x -= 1.0;
		if(IsKeyDown(KEY_D)) direction.x += 1.0;
		if(IsKeyDown(KEY_W)) direction.y -= 1.0;
		if(IsKeyDown(KEY_S)) direction.y += 1.0;
		
		if(Vector2Length(direction) != 0.0) {
			//set mapPos = mapPos - direction
		
			mapPos = Vector2Subtract(mapPos, Vector2Scale(Vector2Normalize(direction), speed));
			direction.x < 0.f ? rightLeft = -1.0f: rightLeft = 1.0f;
		}

		//draws map
		DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
		
		//draws knight
		Rectangle source{0.f, 0.f, rightLeft * (float)knight.width/6.f, (float)knight.height};
		Rectangle dest{knightPos.x, knightPos.y, 4.0f * knight.width/6.0f, 4.0f * (float)knight.height};
		DrawTexturePro(knight, source, dest, Vector2{}, 0.f, WHITE);

		EndDrawing();	
	}

	UnloadTexture(map);
	CloseWindow();
}
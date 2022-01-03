#include "../raylib-master/src/raylib.h"
// g++ dapper-dasher.cpp -L../raylib-master/src -lraylib & ./a.out

struct AnimData 
{
	Rectangle rec;
	Vector2 pos;
	int frame;
	float updateTime;
	float runningTime;
};

bool isOnGround(AnimData data, int windowheight) {
	return data.pos.y >= windowheight - data.rec.height;
}

AnimData updateAnimData(AnimData data, float deltaTime, int maxFrame) {

	//update running time
	data.runningTime += deltaTime;
	if (data.runningTime >= data.updateTime) {
		data.runningTime = 0.0;

		//update animation frame
		data.rec.x = data.frame * data.rec.width;
		data.frame++;

		if(data.frame > maxFrame) {
			data.frame = 0;
		}
	}

	return data;
}

int main() {

	//window
	int windowDimensions[2] = {512, 380};
	InitWindow(windowDimensions[0], windowDimensions[1], "oof");	

	//nebula
	Texture2D nebula = LoadTexture("./textures/12_nebula_spritesheet.png");

	const int sizeOfNebulae = 50;
	AnimData nebulae[sizeOfNebulae];

	for(int i = 0;i < sizeOfNebulae;i++) {
		nebulae[i].rec.x = 0.0;
		nebulae[i].rec.y = 0.0;
		
		nebulae[i].rec.width = nebula.width/8;
		nebulae[i].rec.height = nebula.height/8;
		
		nebulae[i].pos.y = windowDimensions[1] - nebula.height/8; 
		nebulae[i].pos.x = windowDimensions[0] + i * 300;

		nebulae[i].frame = 0;
		nebulae[i].runningTime = 0.0;
		nebulae[i].updateTime = 0.0;
	}	

	float finishLine{nebulae[sizeOfNebulae - 1].pos.x};

	//nebula x velocity
	int nebVel{-200};

	//scarfy
	Texture2D scarfy = LoadTexture("./textures/scarfy.png");
	AnimData scarfyData;
	
	scarfyData.rec.width = scarfy.width/6;
	scarfyData.rec.height = scarfy.height;
	
	scarfyData.rec.x = 0;
	scarfyData.rec.y = 0;
	
	scarfyData.pos.x = windowDimensions[0]/2 - scarfyData.rec.width/2;
	scarfyData.pos.y = windowDimensions[1] - scarfyData.rec.height;
	
	scarfyData.frame = 0;
	scarfyData.updateTime = 1.0/12.0;
	scarfyData.runningTime = 0.0;

	//velocity and gravity
	int jumpVel = -600;
	int velocity = 0;
	const int gravity = 1000;

	//load background textures
	Texture2D background = LoadTexture("./textures/far-buildings.png");
	float bgX = 0;
	Texture2D midground = LoadTexture("./textures/back-buildings.png");
	float mgX = 0;
	Texture2D foreground = LoadTexture("./textures/foreground.png");
	float fgX = 0;

	bool isInAir = true;

	bool collision = false;
	
	SetTargetFPS(60);
	while(!WindowShouldClose()){

		//delta time
		const float dt = GetFrameTime();

		BeginDrawing();
		ClearBackground(WHITE);

		//scroll backgrounds
		bgX -= 20 * dt;
		if(bgX <= -background.width * 2) {
			bgX = 0.0;
		}
		
		mgX -= 40 * dt;
		if(mgX <= -midground.width * 2) {
			mgX = 0.0;
		}
		
		fgX -= 80 * dt;
		if(fgX <= -foreground.width * 2) {
			fgX = 0.0;
		}

		//draw the backgrounds
		Vector2 bg1Pos{bgX, 0.0}, bg2Pos{bgX + background.width * 2, 0.0};
		DrawTextureEx(background, bg1Pos, 0.0, 2.0, WHITE);
		DrawTextureEx(background, bg2Pos, 0.0, 2.0, WHITE);

		Vector2 mg1Pos{mgX, 0.0}, mg2Pos{mgX + midground.width * 2, 0.0};
		DrawTextureEx(midground, mg1Pos, 0.0, 2.0, WHITE);
		DrawTextureEx(midground, mg2Pos, 0.0, 2.0, WHITE);

		Vector2 fg1Pos{fgX, 0.0}, fg2Pos{fgX + foreground.width * 2, 0.0};
		DrawTextureEx(foreground, fg1Pos, 0.0, 2.0, WHITE);
		DrawTextureEx(foreground, fg2Pos, 0.0, 2.0, WHITE);

		//checks if it is in air
		if(isOnGround(scarfyData, windowDimensions[1])) {
			velocity = 0;
			isInAir = false;
		}else {
			velocity += gravity * dt;
			isInAir = true;
		}
		
		//jump check
		if(IsKeyDown(KEY_SPACE) and !isInAir){
			velocity += jumpVel;
		}

		for(int i = 0; i < sizeOfNebulae; i++) {
			//updates the position of each texture
			nebulae[i].pos.x += nebVel * dt;
		}

		//update finish line
		finishLine += nebVel * dt;

		//update scarfy position
		scarfyData.pos.y += velocity * dt;

		//update scarfy's animation frame
		if(!isInAir){
			scarfyData = updateAnimData(scarfyData, dt, 5);
		}

		//update nebulae animation frame
		for(int i = 0;i < sizeOfNebulae;i++) {
			nebulae[i] = updateAnimData(nebulae[i], dt, 7);
		}


		for(AnimData nebula : nebulae) {
			
			float pad = 50;
			Rectangle nebRec{
				nebula.pos.x + pad,
				nebula.pos.y + pad,
				nebula.rec.width - 2*pad,
				nebula.rec.height - 2*pad
			};

			Rectangle scarfyRec{
				scarfyData.pos.x,
				scarfyData.pos.y,
				scarfyData.rec.width,
				scarfyData.rec.height
			};

			if(CheckCollisionRecs(nebRec, scarfyRec)) {
				collision = true;
			}
		}

		if(collision) {
			//lose the game
			DrawText("You Lose!", windowDimensions[0]/4, windowDimensions[1]/2, 40, RED);
		}else if(scarfyData.pos.x >= finishLine){
			DrawText("You win!", windowDimensions[0]/4, windowDimensions[1]/2, 40, RED);
		}else{	
			// draws nebulae
			for(int i = 0;i < sizeOfNebulae;i++) {
				DrawTextureRec(nebula, nebulae[i].rec, nebulae[i].pos, WHITE); 
			}

			//draws scarfy
			DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
		}
		EndDrawing();
	}
	//unload textures
	UnloadTexture(scarfy);
	UnloadTexture(nebula);
	UnloadTexture(background);
	UnloadTexture(midground);
	UnloadTexture(foreground);
	CloseWindow();
}
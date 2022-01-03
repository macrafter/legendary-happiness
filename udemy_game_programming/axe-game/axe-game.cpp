#include "raylib-master/src/raylib.h"

int main() {
	int window_x = 1500, window_y = 725;
	int circle_x = 725, circle_y = 375, circle_radius=25;
	int axe_x = 300, axe_y = 500, axe_width = 50, axe_length = 50;
	int direction = 10;
	
	//circle edges
	int l_circle_x = circle_x - circle_radius;
	int r_circle_x = circle_x + circle_radius;
	int u_circle_y = circle_y - circle_radius;
	int b_circle_y = circle_y + circle_radius; 

	//axe edges
	int l_axe_x = axe_x;
	int r_axe_x = axe_x + axe_length;
	int u_axe_y = axe_y;
	int b_axe_y = axe_y + axe_length;

	bool collision_with_axe = false;

	InitWindow(window_x,window_y,"oof");

	while(!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(WHITE);

		if(b_axe_y >= u_circle_y and u_axe_y <= b_circle_y and l_axe_x <= r_circle_x and r_axe_x >= l_circle_x) {
			collision_with_axe = true;
		}

		if(collision_with_axe) {
			DrawText("Game Over!", 630, window_y/2-20, 50, RED); 
		}else{

			//updates circle edges
			l_circle_x = circle_x - circle_radius;
			r_circle_x = circle_x + circle_radius;
			u_circle_y = circle_y - circle_radius;
			b_circle_y = circle_y + circle_radius; 
			
			//updates axe edges
			l_axe_x = axe_x;
			r_axe_x = axe_x + axe_length;
			u_axe_y = axe_y;
			b_axe_y = axe_y + axe_length;
			
			//draws stuff
			DrawCircle(circle_x,circle_y,circle_radius,GREEN);
			DrawRectangle(axe_x, axe_y, axe_width, axe_length, RED);

			//changes axe's direction
			axe_y += direction;
			if(axe_y > window_y or axe_y < 0){
				direction = -direction;
			} 	

			//circle movement
			if(IsKeyDown(KEY_D) and circle_x<window_x-circle_radius) {
				circle_x+=10;
			} else if(IsKeyDown(KEY_A) and circle_x>circle_radius){
				circle_x-=10;
			} else if(IsKeyDown(KEY_S) and circle_y<window_y-circle_radius) {
				circle_y+=10;
			} else if(IsKeyDown(KEY_W) and circle_y>circle_radius) {
				circle_y-=10;
			}
		}
		
		EndDrawing();
	}	
}
#include <raylib.h>
#include <stdio.h>

// NOTE: would it be better to use Vector2 instead of making a struct?
//        ... maybe this is too OOP minded?
struct Player {
  int posX;
  int posY;
  int score;
  int speed;
  float ftime;
};

int main(void) {
  const int baseFPS = 60;
  const int screenW = 800;
  const int screenH = 600;
  const int playerSpeed = 10;

  const int paddleWidth = 15;
  const int paddleHeight = 70;

  InitWindow(screenW, screenH, "tokipongo");
  SetTargetFPS(baseFPS);
  SetExitKey(KEY_NULL);

  struct Player player1;
  player1.posX = 15;
  player1.posY = 15;
  player1.speed = 0;
  player1.score = 0;
  player1.ftime = 0;

  struct Player player2;
  player2.posX = screenW - paddleWidth - 15;
  player2.posY = 15;
  player2.speed = 0;
  player2.score = 0;
  player2.ftime = 0;

  while (!WindowShouldClose()) {
    // UPDATE
    // ------------------------------------------------------------------------
    // - Player 1 Movement
    if (IsKeyDown(KEY_F)) {
      player1.ftime += GetFrameTime();
      player1.speed = playerSpeed;
      player1.posY += player1.speed;
    }
    if (IsKeyDown(KEY_R)) {
      player1.ftime += GetFrameTime();
      player1.speed = playerSpeed;
      player1.posY -= player1.speed;
    }
    if (IsKeyReleased(KEY_F)) {
      printf("P1: %f\n", player1.ftime);
      player1.ftime = 0;
    }
    if (IsKeyReleased(KEY_R)) {
      printf("P1: %f\n", player1.ftime);
      player1.ftime = 0;
    }

    // - Player 2 Movement
    if (IsKeyDown(KEY_J)) {
      player2.ftime += GetFrameTime();
      player2.speed = playerSpeed;
      player2.posY += player2.speed;
    }
    if (IsKeyDown(KEY_U)) {
      player2.ftime += GetFrameTime();
      player2.speed = playerSpeed;
      player2.posY -= player2.speed;
    }
    if (IsKeyReleased(KEY_J)) {
      printf("P2: %f\n", player2.ftime);
      player2.ftime = 0;
    }
    if (IsKeyReleased(KEY_U)) {
      printf("P2: %f\n", player2.ftime);
      player2.ftime = 0;
    }
    // ------------------------------------------------------------------------

    // DRAW
    // ------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(player1.posX, player1.posY, paddleWidth, paddleHeight, RED);
    DrawRectangle(player2.posX, player2.posY, paddleWidth, paddleHeight, BLUE);

    DrawText(TextFormat("P1: %02i", player1.score), 40, 10, 20, RED);
    DrawText(TextFormat("P2: %02i", player2.score), 700, 10, 20, BLUE);

    EndDrawing();
    // ------------------------------------------------------------------------
  }
  CloseWindow();

  return 0;
}

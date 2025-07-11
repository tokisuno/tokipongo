#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

// NOTE: would it be better to use Vector2 instead of making a struct?
//        ... maybe this is too OOP minded?
struct Player {
  int score;
  float posX;
  float posY;
  float speed;
};

struct Ball {
  float posX;
  float posY;
  int radius;
  bool right;
};

float logToBase(float a, float b) { return log2(a) / log2(b); }

int main(void) {
  const int baseFPS = 60;
  const int screenW = 800;
  const int screenH = 600;
  const int playerSpeed = 15;

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

  struct Player player2;
  player2.posX = screenW - paddleWidth - 15;
  player2.posY = 15;
  player2.speed = 0;
  player2.score = 0;

  struct Ball ball;
  ball.posX = 400;
  ball.posY = 45;
  ball.radius = 10;
  ball.right = true;

  while (!WindowShouldClose()) {
    // UPDATE
    // ------------------------------------------------------------------------
    // - Player 1 Movement
    if (IsKeyDown(KEY_F)) {
      player1.speed = playerSpeed;
      player1.posY += player1.speed;
    }
    if (IsKeyReleased(KEY_F)) {
      while (player1.speed > 1) {
        player1.speed--;
        player1.posY += logToBase(player1.speed, 15);
      }
    }

    if (IsKeyDown(KEY_R)) {
      player1.speed = playerSpeed;
      player1.posY -= player1.speed;
    }
    if (IsKeyReleased(KEY_R)) {
      while (player1.speed > 1) {
        player1.speed--;
        player1.posY -= logToBase(player1.speed, 15);
      }
    }

    // - Player 2 Movement
    if (IsKeyDown(KEY_J)) {
      player2.speed = playerSpeed;
      player2.posY += player2.speed;
    }
    if (IsKeyReleased(KEY_J)) {
      while (player2.speed > 1) {
        player2.speed--;
        player2.posY += logToBase(player2.speed, 15);
      }
    }
    if (IsKeyDown(KEY_U)) {
      player2.speed = playerSpeed;
      player2.posY -= player2.speed;
    }
    if (IsKeyReleased(KEY_U)) {
      while (player2.speed > 1) {
        player2.speed--;
        player2.posY -= logToBase(player2.speed, 15);
      }
    }

    // - Ball movement
    if (ball.right == true) {
      ball.posX += 1;
      ball.posY += 1;
    } else {
      ball.posX -= 1;
      ball.posY -= 1;
    }

    // - Debugging
    if (IsKeyDown(KEY_T)) {
      player1.posY = 15;
    }
    if (IsKeyDown(KEY_Y)) {
      player2.posY = 15;
    }
    if (IsKeyDown(KEY_B)) {
      ball.posX = 400;
      ball.posY = 45;
    }

    // ------------------------------------------------------------------------

    // DRAW
    // ------------------------------------------------------------------------
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(player1.posX, player1.posY, paddleWidth, paddleHeight, RED);
    DrawRectangle(player2.posX, player2.posY, paddleWidth, paddleHeight, BLUE);

    DrawCircle(ball.posX, ball.posY, ball.radius, RED);

    DrawText(TextFormat("P1: %02i", player1.score), 40, 10, 20, RED);
    DrawText(TextFormat("P2: %02i", player2.score), 700, 10, 20, BLUE);

    DrawRectangleLines(1, 0, screenW - 1, screenH - 1, RED);

    EndDrawing();
    // ------------------------------------------------------------------------
  }
  CloseWindow();

  return 0;
}

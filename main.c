#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool gameIsRunning = false;
bool playerTurn = false; // false = Player 1; true = Player 2
bool validInput = false;
char tile[9] = {'.','.','.','.','.','.','.','.','.'};
int chosenTile;

int game1v1();
int gameCPU();
int checkTile();

int main()
{
  char start;

  //system("cls");
  puts("Welcome to Tic Tac Toe!");
  puts("Please choose the game mode:");
  puts("");
  puts("A - Local Multiplayer (2 Players)");
  puts("B - Against CPU (1 Player)");
  puts("Z - Exit");
  puts("");
  start = getchar();
  puts("");

  switch(start)
  {
    case 'A':
      game1v1();
      break;
    case 'B':
      gameCPU();
      break;
    case 'Z':
      return 0;
      break;
    default:
      puts("Invalid input!");
      puts("");
      main();
      break;
  }

  return 0;
}

int game1v1()
{
  puts("To place your mark, type a number from 1 to 9.");
  puts("1 refers to the upper-left tiles and 9 to the lower-right one.");
  puts("Tiles with dots are empty.");
  puts("Player X will go first and will then take turns with Player O.");
  puts("");

  gameIsRunning = true;

  if(gameIsRunning)
  {
    puts("");
    printf("%c", tile[0]);
    printf("\t%c", tile[1]);
    printf("\t%c\n", tile[2]);
    printf("%c", tile[3]);
    printf("\t%c", tile[4]);
    printf("\t%c\n", tile[5]);
    printf("%c", tile[6]);
    printf("\t%c", tile[7]);
    printf("\t%c\n\n", tile[8]);

    if(!playerTurn) { printf("Current Turn: X\n\n"); }
    else { printf("Current Turn: O\n\n"); }

    while(validInput == false)
    {
      checkTile();
    }
    printf("True");
  }
}

int gameCPU()
{
  printf("B");
  //WIP
}

int checkTile()
{
  chosenTile = 0;
  do
  {
    printf("Please choose the tile you wish to take:\n\n");
    scanf("%d", &chosenTile);
  } while(chosenTile > 9 || 1 > chosenTile);

  int a = (chosenTile - 1);

  printf("%c", tile[a]);
  printf("%d", chosenTile);
  if(tile[a] == '.') { validInput = true; }
  else { validInput = false; }
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "snake.h"

int width = 20;
int height = 20;

int x, y;
typedef struct {
    int x;
    int y;
} food;
food f;

int tailX[100], tailY[100];
int nTail = 0;
char tabla[20][20] = {{0}};
int score;
int gameOver = 0;
char direction='R', nextDirection='R';
int x, y;
void setup(){

    gameOver = 0;

    x = width / 2;
    y = height / 2;
    f.x = rand() % (width-2)+1;
    f.y = rand() % (height-2)+1;
    score = 0;
    //direction = 'R';
}
void draw(){
    system("cls");
    for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        tabla[i][j] = ' ';  // reset
    }
}
    for(int i=0;i<nTail;i++){
    tabla[tailY[i]][tailX[i]] = 'o';
}
    for(int i=0;i<width;i++){
        tabla[0][i] = '#';
        //printf("#");
    }
    for(int i=0;i<height-1;i++){
        tabla[i+1][0] = '#';
        //printf("#");
        for(int j=1;j<width-1;j++){
                tabla[i+1][j] = ' ';
            }
        tabla[i+1][width-1] = '#';
        //printf("#\n");
    }
    for(int i=0;i<width;i++){
        tabla[height-1][i] = '#';
        //printf("#");
    }
    if( f.x != 0 && f.y != 0 && f.x != width-1 && f.y != height-1){
        tabla[f.y][f.x] = 'F';
    }
if(x>0 && x<width-1 && y>0 && y<height-1)
    tabla[y][x] = 'O';
for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
        printf("%c",tabla[i][j]);
        fflush(stdout);
    }
    printf("\n");
}
printf("Score: %d\n", score);
printf("Use W/A/S/D to move the snake\n");
fflush(stdout);
}
void input() {
    if(_kbhit()){
        char c = _getch();
        switch(c){
            case 'w': if(direction != 'D') direction = 'U'; break;
            case 's': if(direction != 'U') direction = 'D'; break;
            case 'a': if(direction != 'R') direction = 'L'; break;
            case 'd': if(direction != 'L') direction = 'R'; break;
        }
    }
}
void logic() {
    // Actualizează direcția din buffer

    // Salvează poziția capului înainte de mutare
    int prevX = x;
    int prevY = y;
    int prev2X, prev2Y;

    // Mută capul
    switch(direction){
        case 'U': y--; break;
        case 'D': y++; break;
        case 'L': x--; break;
        case 'R': x++; break;
    }

    // Actualizează coada
    if(nTail > 0){
        prev2X = tailX[0];
        prev2Y = tailY[0];
        tailX[0] = prevX;
        tailY[0] = prevY;

        for(int i = 1; i < nTail; i++){
            int tempX = tailX[i];
            int tempY = tailY[i];
            tailX[i] = prev2X;
            tailY[i] = prev2Y;
            prev2X = tempX;
            prev2Y = tempY;
        }
    }

    // Verifică coliziunea cu pereții
    if(x == 0 || x == width-1 || y == 0 || y == height-1){
        gameOver = 1;
    }

    // Verifică coliziunea cu coada
    for(int i = 0; i < nTail; i++){
        if(tailX[i] == x && tailY[i] == y){
            gameOver = 1;
        }
    }

    // Verifică dacă mănâncă mâncarea
    if(f.x == x && f.y == y){
        score++;

        // Inițializează noul segment la ultima poziție a cozii
        if(nTail > 0){
            tailX[nTail] = tailX[nTail-1];
            tailY[nTail] = tailY[nTail-1];
        } else {
            tailX[nTail] = prevX;
            tailY[nTail] = prevY;
        }

        nTail++;

        // Plasează mâncarea la altă poziție
        f.x = rand() % (width-2) + 1;
        f.y = rand() % (height-2) + 1;
    }
}
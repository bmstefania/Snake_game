#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // pentru Sleep()
#include "snake.h"

int main() {

    setup();  // inițializează jocul
    while(!gameOver) {  // cât jocul nu s-a terminat

        draw();   // afișează tabla, șarpele și mâncarea
        input();  // citește tastele apăsate
        logic();  // actualizează poziția șarpelui, creștere, coliziuni

        Sleep(5000);  // întârziere ca să nu fie prea rapid
    }

    printf("\nGame Over! Scor: %d\n", score);

    return 0;
}
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define Xt 25
#define Yt 80
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define SPACEBAR 32
#define ENTER 13

void gotoxy(int x, int y)
{
    COORD destCoord;
    destCoord.X = x;
    destCoord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), destCoord);
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void showCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 20;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

int main(void)
{
    char s[Xt][Yt] = {0};
    char n[Xt][Yt] = {0};
    int c = 0;
    int i, j, k;

    char x = 0, y = 0;
    char d = 0, e = 0;

begin:
    x = 0;
    y = 0;
    for (i = 0; i < Xt; i++) {
        for (j = 0; j < Yt; j++) {
            printf("%c", s[i][j]);
        }
    }
    gotoxy(0,0);
    showCursor();
    while (d != ENTER) {
        d = _getch();
        switch(d) {
        case UP:
            x -= 1;
            if (x < 0) { x = Xt-1; }
            break;
        case DOWN:
            x += 1;
            if (x >= Xt) { x = 0; }
            break;
        case LEFT:
            y -= 1;
            if (y < 0) { y = Yt-1; }
            break;
        case RIGHT:
            y += 1;
            if (y >= Yt) { y = 0; }
            break;
        case SPACEBAR:
            s[x][y] = s[x][y]? 0 : '#';
            putch(s[x][y]);
            break;
        case ESC:
            return 0;
        }
        gotoxy(y, x);
    }
    gotoxy(0,0);
    hideCursor();
    d = 0;
    while (d != ESC) {
        for (i = 0; i < Xt; i++) {
            for (j = 0; j < Yt; j++) {
                c = 0;
                // verify each of the corners first
                if (i == 0 && j == 0) {
                    if (s[Xt-1][Yt-1]) { c++; } if (s[i][Yt-1]) { c++; } if (s[i+1][Yt-1]) { c++; }
                    if (s[Xt-1][j])    { c++; }                          if (s[i+1][j])    { c++; }
                    if (s[Xt-1][j+1])  { c++; } if (s[i][j+1]) { c++; }  if (s[i+1][j+1])  { c++; }
                }
                else if (i == 0 && j == Yt-1) {
                    if (s[Xt-1][j-1]) { c++; } if (s[i][j-1]) { c++; } if (s[i+1][j-1]) { c++; }
                    if (s[Xt-1][j])   { c++; }                         if (s[i+1][j])   { c++; }
                    if (s[Xt-1][0])   { c++; } if (s[i][0])   { c++; } if (s[i+1][0])   { c++; }
                }
                else if (i == Xt-1 && j == 0) {
                    if (s[i-1][Yt-1]) { c++; } if (s[i][Yt-1]) { c++; } if (s[0][Yt-1]) { c++; }
                    if (s[i-1][j])    { c++; }                          if (s[0][j])    { c++; }
                    if (s[i-1][j+1])  { c++; } if (s[i][j+1]) { c++; }  if (s[0][j+1])  { c++; }
                }
                else if (i == Xt-1 && j == Yt-1) {
                    if (s[i-1][j-1]) { c++; } if (s[i][j-1]) { c++; } if (s[0][j-1]) { c++; }
                    if (s[i-1][j])   { c++; }                         if (s[0][j])   { c++; }
                    if (s[i-1][0])   { c++; } if (s[i][0])   { c++; } if (s[0][0])   { c++; }
                } // verify the edges
                else if (i == 0) {
                    if (s[Xt-1][j-1]) { c++; } if (s[i][j-1]) { c++; } if (s[i+1][j-1]) { c++; }
                    if (s[Xt-1][j])   { c++; }                         if (s[i+1][j])   { c++; }
                    if (s[Xt-1][j+1]) { c++; } if (s[i][j+1]) { c++; } if (s[i+1][j+1]) { c++; }
                }
                else if (i == Xt-1) {
                    if (s[i-1][j-1]) { c++; } if (s[i][j-1]) { c++; } if (s[0][j-1]) { c++; }
                    if (s[i-1][j])   { c++; }                         if (s[0][j])   { c++; }
                    if (s[i-1][j+1]) { c++; } if (s[i][j+1]) { c++; } if (s[0][j+1]) { c++; }
                }
                else if (j == 0) {
                    if (s[i-1][Yt-1]) { c++; } if (s[i][Yt-1]) { c++; } if (s[i+1][Yt-1]) { c++; }
                    if (s[i-1][j])    { c++; }                          if (s[i+1][j])    { c++; }
                    if (s[i-1][j+1])  { c++; } if (s[i][j+1]) { c++; }  if (s[i+1][j+1])  { c++; }
                }
                else if (j == Yt-1) {
                    if (s[i-1][j-1]) { c++; } if (s[i][j-1]) { c++; } if (s[i+1][j-1]) { c++; }
                    if (s[i-1][j])   { c++; }                         if (s[i+1][j]) { c++; }
                    if (s[i-1][0])   { c++; } if (s[i][0])   { c++; } if (s[i+1][0]) { c++; }
                } // verify the rest
                else { 
                    if (s[i-1][j-1]) { c++; } if (s[i][j-1]) { c++; } if (s[i+1][j-1]) { c++; }
                    if (s[i-1][j])   { c++; }                         if (s[i+1][j])   { c++; }
                    if (s[i-1][j+1]) { c++; } if (s[i][j+1]) { c++; } if (s[i+1][j+1]) { c++; }
                }

                if (s[i][j]) {
                    if (c < 2) { n[i][j] = 0; }
                    else if (c > 3) { n[i][j] = 0; }
                    else { n[i][j] = s[i][j]; }
                }
                else if (s[i][j] == 0) {
                    if (c == 3) { n[i][j] = '#'; }
                    else { n[i][j] = s[i][j]; }
                }
            }
        }
        for (i = 0; i < Xt; i++) {
            for (j = 0; j < Yt; j++) {
                s[i][j] = n[i][j];
            }
        }
        for (i = 0; i < Xt; i++) {
            for (j = 0; j < Yt; j++) {
                putch(s[i][j]);
            }
        }
        gotoxy(0,0);
        if(kbhit()) {
            d = _getch();
            if(d == 'r' || d == 'R') { goto begin; }
        }
        Sleep(10);
    }
    return 0;
}
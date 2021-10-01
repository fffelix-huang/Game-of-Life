#include <bits/stdc++.h>
#include <tchar.h>

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

using namespace std;

const int d8i[] = {-1, -1, -1, 0, 0, 1, 1, 1}, d8j[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int height = 50, width = 160;

void Game_of_life() {
    char buffer[height][width + 1];
    bool board[height][width], new_board[height][width];
    for(int i = 0; i < height; ++i)
        for(int j = 0; j < width; ++j)
            board[i][j] = rand() & 1;
    while(true) {
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                int neighbors = 0;
                for(int dir = 0; dir < 8; ++dir) {
                    int di = i + d8i[dir], dj = j + d8j[dir];
                    if(di >= 0 && di < height && dj >= 0 && dj < width && board[di][dj])
                        ++neighbors;
                }
                if(board[i][j])
                    new_board[i][j] = neighbors == 2 || neighbors == 3;
                else
                    new_board[i][j] = neighbors == 3;
            }
        }
        for(int i = 0; i < height; ++i) {
            for(int j = 0; j < width; ++j) {
                buffer[i][j] = board[i][j] ? '.' : ' ';
                board[i][j] = new_board[i][j];
            }
            buffer[i][width] = '\0';
        }
        printf("\x1b[H");
        for(int i = 0; i < height; ++i)
            puts(buffer[i]);
        _sleep(10);
    }
}

int main() {
    srand(time(NULL));
    system("cls");
    Game_of_life();
    
    return 0;
}
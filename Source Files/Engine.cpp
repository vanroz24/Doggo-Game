#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include "../Header Files/Engine.h"
#include "../Header Files/Controls.h"

void draw(char Field[X][Y], int score, unsigned long step_counter, char player, char item) {
    std::cout << "SCORE: " << score << "\tSteps: " << step_counter << "\n";
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            std::cout << Field[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Press <Q> to exit.\n";
    std::cout << "\nUse arrow keys to move the Doggo\n";
    std::cout << "\n'" << player << "' is the Doggo (a player)\n";
    std::cout << "'" << item << "' is the bone (an item to pick up)\n";
}

char* placeItem(char Field[X][Y], char player, char item, int X, int Y) {
    int x = rand() % (X - 2) + 1;
    int y = rand() % (Y - 2) + 1;
    if (Field[x][y] == player)   placeItem(Field, player, item, X, Y);
    else {
        Field[x][y] = item;
        return &Field[x][y];
    }
}

void game(char Field[X][Y], char player, char* player_pos, char item, int& score) {
    auto start_time = std::chrono::steady_clock::now();
    char* item_pos = placeItem(Field, player, item, X, Y);
    unsigned long step_counter = 0;
    char* last_pos = player_pos;
    draw(Field, score, step_counter, player, item);
    while (1) {
        char move = getKey();
        if (move == 'q' || move == 'Q') break;
        switch (move) {
        case KEY_UP:
            last_pos = player_pos;
            if (*(player_pos - Y) == '#') {
                player_pos = player_pos + (Y * 8);
                *last_pos = '_';
                *player_pos = player;
            }
            else {
                player_pos = player_pos - Y;
                *last_pos = '_';
                *player_pos = player;
            }
            step_counter++;
            break;
        case KEY_DOWN:
            last_pos = player_pos;
            if (*(player_pos + Y) == '#') {
                player_pos = player_pos - (Y * 8);
                *last_pos = '_';
                *player_pos = player;
            }
            else {
                player_pos = player_pos + Y;
                *last_pos = '_';
                *player_pos = player;
            }
            step_counter++;
            break;
        case KEY_LEFT:
            last_pos = player_pos;
            if (*(player_pos - 1) == '#') {
                player_pos = player_pos + 8;
                *last_pos = '_';
                *player_pos = player;
            }
            else {
                player_pos = player_pos - 1;
                *last_pos = '_';
                *player_pos = player;
            }
            step_counter++;
            break;
        case KEY_RIGHT:
            last_pos = player_pos;
            if (*(player_pos + 1) == '#') {
                player_pos = player_pos - 8;
                *last_pos = '_';
                *player_pos = player;
            }
            else {
                player_pos = player_pos + 1;
                *last_pos = '_';
                *player_pos = player;
            }
            step_counter++;
            break;
        default:
            continue;
        }
        if (player_pos == item_pos) {
            score++;
            item_pos = placeItem(Field, player, item, X, Y);
        }
        system("cls");
        draw(Field, score, step_counter, player, item);
    }
    auto current_time = std::chrono::steady_clock::now();
    system("cls");
    std::cout <<
        "==================" <<
        "\nFINAL SCORE: " << score <<
        "\nSTEPS:       " << step_counter <<
        "\nSTEPS/SCORE: " << std::setprecision(3) << (double)step_counter / (double)score <<
        "\nTIME:        " <<
        std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() <<
        "\n==================\n";
    system("pause");
}
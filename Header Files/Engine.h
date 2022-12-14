#pragma once

const size_t X = 11, Y = 11;


// Drawing everything in the terminal each move
void draw(char Field[X][Y], int score, unsigned long step_counter);

// Places an item at a random location
char* placeItem(char Field[X][Y], char player, char item, int X, int Y);

// Main game logic
void game(char Field[X][Y], char player, char* player_pos, char item, int& score);
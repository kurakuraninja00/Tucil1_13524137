#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <chrono>
#include <thread>

struct coordinates{
    int x;
    int y;
};

extern std::map<char, std::vector<coordinates>> colors_coordinate;
extern std::map<char, coordinates> queens_position;
extern std::vector<std::string> board;

void ShiftQueens(std::map<char, coordinates>& queens_position);
void printBoard(const std::map<char, coordinates>& queens_pos);
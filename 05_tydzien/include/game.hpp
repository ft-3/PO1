#pragma once
#include <string>
#include "board.hpp"

class Game {
private:
    std::string _name;

public:
    void new_player(std::string);
    virtual void new_board(const Board&);
    virtual void print_board();
    virtual bool operator()(int, int);
};

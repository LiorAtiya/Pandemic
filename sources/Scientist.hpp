#pragma once
#include "Player.hpp"

namespace pandemic {
    class Scientist: public Player{
        int number_card_2_cure;

        public:
            Scientist(Board& b, City c, int n):Player(b,c), number_card_2_cure(n){}
            Player& discover_cure(Color c);
            string role();
    };
}
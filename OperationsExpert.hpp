#pragma once
#include "Player.hpp"

namespace pandemic {
    class OperationsExpert: public Player{
        private: 

        public:
            OperationsExpert(Board& b,City c):Player(b,c){}

            Player& build(){
                get_board().get_details_of_cities()[this->get_current_place()].research_stations = true;
                return *this;
            }
            string role(){ return "OperationsExpert"; }
    };
}
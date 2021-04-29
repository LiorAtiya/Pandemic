#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class OperationsExpert: public Player{
        private: 
            Board board;
            City city;

        public:
            OperationsExpert(Board b,City c){}
            // void build(){}
    };
}
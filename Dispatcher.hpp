#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class Dispatcher: public Player{
        
        public:
            Dispatcher(Board b, City c){}
            Player fly_direct(City c){return *this; }
    };
}
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class Scientist: public Player{
        
        public:
            Scientist(Board b, City c, int n){}
            void discover_cure(Color c){}
    };
}
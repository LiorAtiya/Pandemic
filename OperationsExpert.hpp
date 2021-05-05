#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"

namespace pandemic {
    class OperationsExpert: public Player{
        private: 

        public:
            OperationsExpert(Board& b,City c){
                set_board(b);
                set_current_place(c);
            }
            Player& build(){
                get_board().get_details_of_cities()[this->get_current_place()].research_stations = true;
                return *this;
            }
            string role(){ return "OperationsExpert"; }
    };
}
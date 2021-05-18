#include "Dispatcher.hpp"

namespace pandemic {

    Player& Dispatcher::fly_direct(City c){ 
        //If found in a research station you can fly direct without throwing a card.
        if(get_board().get_details_of_cities()[get_current_place()].research_stations && this->get_current_place() != c){
            set_current_place(c);
        }else{
            Player::fly_direct(c);
        }
        return *this; 
    }
    
    string Dispatcher::role(){ return "Dispatcher"; }
}
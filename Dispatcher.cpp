#include "Dispatcher.hpp"

namespace pandemic {

    Player& Dispatcher::fly_direct(City c){ 
        
        if(get_board().get_details_of_cities()[get_current_place()].research_stations){
            set_current_place(c);
        }else{
            Player::fly_direct(c);
        }
        return *this; 
    }
    
    string Dispatcher::role(){ return "Dispatcher"; }
}
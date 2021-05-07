#include "Medic.hpp"


namespace pandemic {

    Player& Medic::drive(City c){
        Player::drive(c);
        if(get_board().get_cure_was_found()[get_board().get_details_of_cities()[c].color]){
            get_board()[c] = 0;
        }

        return *this;
    }
    
    Player& Medic::fly_direct(City c){
        Player::fly_direct(c);

        if(get_board().get_cure_was_found()[get_board().get_details_of_cities()[c].color]){
            get_board()[c] = 0;
        }

        return *this;
    }

    Player& Medic::fly_charter(City c){
        Player::fly_charter(c);

        if(get_board().get_cure_was_found()[get_board().get_details_of_cities()[c].color]){
            get_board()[c] = 0;
        }

        return *this;
    }
    Player& Medic::fly_shuttle(City c){
        Player::fly_shuttle(c);

        if(get_board().get_cure_was_found()[get_board().get_details_of_cities()[c].color]){
            get_board()[c] = 0;
        }

        return *this;
    }

    Player& Medic::treat(City c){ 
    
        if(get_current_place() == c){
            //If there is a disease in the current city
            if(get_board().get_details_of_cities()[c].disease_level > 0){
                    get_board()[c] = 0;
            }else{
                string exp = "There is no air pollution in " + get_board().get_City_2_string()[c];
                throw invalid_argument(exp);
            }
        }else{
            throw invalid_argument("You are not in the city of input!");
        }

        return *this; 
    }

    string Medic::role(){ return "Medic"; }

}
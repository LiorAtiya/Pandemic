#include "FieldDoctor.hpp"

namespace pandemic {

    Player& FieldDoctor::treat(City c){
        //If the input city is a neighbor of the current city where the player is located.
        if(get_board().get_details_of_cities()[get_current_place()].neighbors.count(c) || get_current_place() == c){
            //If there is a disease in the neighbor city
            if(get_board().get_details_of_cities()[c].disease_level > 0){
                //If there was a "discover_cure" in the neighbor city
                if(get_board().get_cure_was_found()[get_board().get_details_of_cities()[c].color]){
                    get_board()[c] = 0;
                }else{
                    get_board()[c]--;
                }
            }else{
                throw invalid_argument("There is no air pollution in the current city!");
            }
        }else{
            throw invalid_argument("You are not neighbor city of input!");
        }

        return *this; 
    }

    string FieldDoctor::role(){ return "FieldDoctor"; }

}
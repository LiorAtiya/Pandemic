#include "Virologist.hpp"

namespace pandemic {

    Player& Virologist::treat(City c){

        //If a player has a city card "c".
        if(get_my_cards()[get_board().get_details_of_cities()[c].color].count(c)){
            //If there is a disease in the neighbor city
            if(get_board().get_details_of_cities()[c].disease_level > 0){
                //If there was a "discover_cure" in the neighbor city
                if(get_board().get_cure_was_found()[get_board().get_details_of_cities()[c].color]){
                    get_board()[c] = 0;
                }else{
                    get_board()[c]--;
                }
                get_my_cards()[get_board().get_details_of_cities()[c].color].erase(c);
            }else{
                throw invalid_argument("There is no air pollution in the current city!");
            }
        }else{
            throw invalid_argument("You do not have a City of Input card!");
        }

        return *this; 
    }

    string Virologist::role(){ return "Virologist"; }
}
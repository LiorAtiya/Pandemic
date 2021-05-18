#include "Virologist.hpp"

namespace pandemic {

    //Can perform a "treat" operation, 
    //not only in the city it is in, but in any city in the world 
    // - by throwing a card of that city.
    Player& Virologist::treat(City c){
        //Not the same card
        if(get_current_place() != c){
            //If a player has a city card "c".
            if(get_my_cards()[get_board().get_details_of_cities()[c].color].contains(c)){
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
                    string exp = "There is no air pollution in " + get_board().get_City_2_string()[c];
                    throw invalid_argument(exp);
                }
            }else{
                string exp = "You do not have the card of " + get_board().get_City_2_string()[c]; 
                throw invalid_argument(exp);
            }
        }else{
            Player::treat(c);
        }

        return *this; 
    }

    string Virologist::role(){ return "Virologist"; }
}
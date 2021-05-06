#include "Medic.hpp"


namespace pandemic {



    Player& Medic::treat(City c){ 
    
        // if(this->current_place == c){
        //     //If there is a disease in the current city
        //     if(board_game.get_details_of_cities()[this->current_place].disease_level > 0){
        //         //If there was a "discover_cure" in the current city
        //         if(board_game.get_cure_was_found()[board_game.get_details_of_cities()[c].color]){
        //             board_game[this->current_place] = 0;
        //         }else{
        //             board_game[this->current_place]--;
        //         }
        //     }else{
        //         throw invalid_argument("There is no air pollution in the current city!");
        //     }
        // }else{
        //     throw invalid_argument("You are not in the city of input!");
        // }

        return *this; 
    }

    string Medic::role(){ return "Medic"; }

}
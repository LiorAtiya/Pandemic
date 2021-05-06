#include "Scientist.hpp"

namespace pandemic {

    Player& Scientist::discover_cure(Color c){ 
        //If there is a research station in the city where the player is located
        if(get_board().get_details_of_cities()[get_current_place()].research_stations){
            //If there are 5 cards of the same color
            if(get_my_cards()[c].size() >= number_card_2_cure){
                //If no cure for the disease has yet been discovered
                if(!get_board().get_cure_was_found()[c]){
                    
                    //Remove 5 cards from my_cards
                    int count_delete = 0;
                    for (auto it = get_my_cards()[c].cbegin(), next_it = it; it != get_my_cards()[c].cend(); it = next_it){
                        ++next_it;
                        if (count_delete != 5){
                            get_my_cards()[c].erase(it);
                            count_delete++;
                        }else{
                            break;
                        }
                    }
                    get_board().get_cure_was_found()[c] = true;

                }else{
                    throw invalid_argument("A cure for the disease has already been discovered!");
                }
            }else{
                throw invalid_argument("You do not have 5 cards of the same color!");
            }
        }else{
            throw invalid_argument("There is no research station in the current city!");
        }   
        return *this; 
    }

    string Scientist::role(){ return "Scientist"; }
}
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
                    const int max_delete = 5;
                    for (auto it = get_my_cards()[c].cbegin(), next_it = it; it != get_my_cards()[c].cend(); it = next_it){
                        ++next_it;
                        if (count_delete != max_delete){
                            get_my_cards()[c].erase(it);
                            count_delete++;
                        }else{
                            break;
                        }
                    }
                    get_board().get_cure_was_found()[c] = true;
                }
            }else{
                string exp = "You only have "+to_string(get_my_cards()[c].size())+" "+ get_board().get_Color_2_string()[c] +" cards remaining";
                throw invalid_argument(exp);
            }
        }else{
            string exp = "There is no research station in " + get_board().get_City_2_string()[get_current_place()];
            throw invalid_argument(exp);
        }   
        return *this; 
    }

    string Scientist::role(){ return "Scientist"; }
}
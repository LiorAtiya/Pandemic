#include "GeneSplicer.hpp"

namespace pandemic {

    Player& GeneSplicer::discover_cure(Color c){
        //If there is a research station in the city where the player is located
        if(get_board().get_details_of_cities()[get_current_place()].research_stations){
            //If there are 5 cards of the same color
            const int min_card = 5;
            if(get_my_cards()[Color::Black].size() + get_my_cards()[Color::Red].size() + 
            get_my_cards()[Color::Yellow].size() + get_my_cards()[Color::Blue].size() >= min_card){
                // //If no cure for the disease has yet been discovered
                // if(!get_board().get_cure_was_found()[c]){
                    
                    //Remove 5 cards from my_cards
                    int count_delete = 0;
                    for(auto &pair : get_my_cards()){
                        for (auto it = get_my_cards()[pair.first].cbegin(), next_it = it; it != get_my_cards()[pair.first].cend(); it = next_it){
                            ++next_it;
                            if (count_delete != min_card){
                                get_my_cards()[pair.first].erase(it);
                                count_delete++;
                            }else{
                                get_board().get_cure_was_found()[c] = true;
                                return *this;
                            }
                        }
                    }

                // }else{
                //     throw invalid_argument("A cure for the disease has already been discovered!");
                // }
            }else{
                throw invalid_argument("You do not have any 5 cards!");
            }
        }else{
            throw invalid_argument("There is no research station in the current city!");
        }   
        return *this;
    }

    string GeneSplicer::role(){ return "GeneSplicer"; }
}
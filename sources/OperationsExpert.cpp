#include "OperationsExpert.hpp"

namespace pandemic {

    Player& OperationsExpert::build(){
        get_board().get_details_of_cities()[get_current_place()].research_stations = true;
        return *this;
    }
    string OperationsExpert::role(){ return "OperationsExpert"; }

}
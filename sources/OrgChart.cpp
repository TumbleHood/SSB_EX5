#include "OrgChart.hpp"

using namespace ariel;

OrgChart::OrgChart(){}

OrgChart& OrgChart::add_root(const string& person){
    return *this;
}

OrgChart& OrgChart::add_sub(const string& person, const string& subordinate){
    return *this;
}

OrgChart* OrgChart::begin(){
    return this;
}

OrgChart* OrgChart::end(){
    return this;
}

OrgChart* OrgChart::begin_level_order(){
    return this;
}

OrgChart* OrgChart::end_level_order(){
    return this;
}

OrgChart* OrgChart::begin_reverse_order(){
    return this;
}

OrgChart* OrgChart::end_reverse_order(){
    return this;
}

OrgChart* OrgChart::begin_preorder(){
    return this;
}

OrgChart* OrgChart::end_preorder(){
    return this;
}

int OrgChart::size(){
    return 0;
}

ostream& ariel::operator<<(ostream& os, const OrgChart& organization){
    return os;
}
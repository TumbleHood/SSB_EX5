#include <string>
#include <iostream>

using namespace std;

namespace ariel{
    class OrgChart{
        public:
            OrgChart();
            OrgChart& add_root(const string& object);
            OrgChart& add_sub(const string& object, const string& subordinate_object);
            OrgChart* begin_level_order();
            OrgChart* end_level_order();
            OrgChart* begin_reverse_order();
            OrgChart* reverse_order();
            OrgChart* begin_preorder();
            OrgChart* end_preorder();
            OrgChart* begin();
            OrgChart* end();
            int size();

            friend ostream& operator<<(ostream&, const OrgChart&);
    };
};
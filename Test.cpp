#include "sources/OrgChart.hpp"
#include "doctest.h"
#include <vector>

using namespace ariel;

TEST_CASE("Traversals"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("root"));
    CHECK_NOTHROW(organization.add_sub("root", "child1"));
    CHECK_NOTHROW(organization.add_sub("root", "child2"));
    CHECK_NOTHROW(organization.add_sub("child1", "grand1"));
    CHECK_NOTHROW(organization.add_sub("child1", "grand2"));
    CHECK_NOTHROW(organization.add_sub("child2", "grand3"));
    CHECK_NOTHROW(organization.add_sub("child2", "grand4"));

    OrgChart dummy;
    CHECK_NOTHROW(dummy.add_root("0"));
    CHECK_NOTHROW(dummy.add_sub("0", "1"));
    CHECK_NOTHROW(dummy.add_sub("1", "2"));
    CHECK_NOTHROW(dummy.add_sub("2", "3"));
    CHECK_NOTHROW(dummy.add_sub("3", "4"));
    CHECK_NOTHROW(dummy.add_sub("4", "5"));
    CHECK_NOTHROW(dummy.add_sub("5", "6"));
    CHECK_NOTHROW(dummy.add_sub("6", "7"));
    CHECK_NOTHROW(dummy.add_sub("7", "8"));
    CHECK_NOTHROW(dummy.add_sub("8", "9"));

    vector<string> level_order =    {"root", "child1", "child2", "grand1", "grand2", "grand3", "grand4"};
    vector<string> reverse_order =  {"grand1", "grand2", "grand3", "grand4", "child1", "child2", "root"};
    vector<string> preorder =       {"root", "child1", "grand1", "grand2", "child2", "grand3", "grand4"};

    vector<string> level_order_dummy =    {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector<string> reverse_order_dummy =  {"9", "8", "7", "6", "5", "4", "3", "2", "1", "0"};
    vector<string> preorder_dummy =       {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    SUBCASE("Level Order Traversal"){
        unsigned long i = 0;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
            CHECK_EQ(level_order.at(i++), *it);
        }

        i = 0;
        for (auto it = dummy.begin_level_order(); it != dummy.end_level_order(); ++it){
            CHECK_EQ(level_order_dummy.at(i++), *it);
        }
    }

    SUBCASE("Reverse Level Order Traversal"){
        unsigned long i = 0;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){
            CHECK_EQ(reverse_order.at(i++), *it);
        }

        i = 0;
        for (auto it = dummy.begin_reverse_order(); it != dummy.reverse_order(); ++it){
            CHECK_EQ(level_order_dummy.at(i++), *it);
        }
    }

    SUBCASE("Preorder Traversal"){
        unsigned long i = 0;
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it){
            CHECK_EQ(preorder.at(i++), *it);
        }

        i = 0;
        for (auto it = dummy.begin_preorder(); it != dummy.end_preorder(); ++it){
            CHECK_EQ(level_order_dummy.at(i++), *it);
        }
    }
}

TEST_CASE("Input Check"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("root"));
    CHECK_NOTHROW(organization.add_sub("root", "child1"));
    CHECK_NOTHROW(organization.add_sub("root", "child2"));
    CHECK_NOTHROW(organization.add_sub("child1", "grand1"));
    CHECK_NOTHROW(organization.add_sub("child1", "grand2"));
    CHECK_NOTHROW(organization.add_sub("child2", "grand3"));
    CHECK_NOTHROW(organization.add_sub("child2", "grand4"));

    CHECK_THROWS(organization.add_sub("nonexisting", "test")); //adding sub to nonexisting node

    CHECK_NOTHROW(organization.add_root("new_root"));
    CHECK_THROWS(organization.add_sub("root", "test")); //"root" does not exist anymore

    CHECK_NOTHROW(organization.add_sub("new_root", "new_root")); //legal
}
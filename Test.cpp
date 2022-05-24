#include "OrgChart.hpp"
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

    vector<OrgChart*> pointers;

    for (auto it = organization.begin(); it != organization.end(); ++it){
        pointers.push_back((OrgChart*)it);
    }

    SUBCASE("Level Order Traversal"){
        unsigned long i = 0;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
            CHECK_EQ(pointers.at(i++), it);
        }
    }

    SUBCASE("Reverse Level Order Traversal"){
        auto it = organization.begin_reverse_order();
        CHECK_EQ(it++, pointers.at(3));
        CHECK_EQ(it++, pointers.at(4));
        CHECK_EQ(it++, pointers.at(5));
        CHECK_EQ(it++, pointers.at(6));
        CHECK_EQ(it++, pointers.at(1));
        CHECK_EQ(it++, pointers.at(2));
        CHECK_EQ(it++, pointers.at(0));
        CHECK_EQ(it, organization.reverse_order());
    }

    SUBCASE("Preorder Traversal"){
        auto it = organization.begin_preorder();
        CHECK_EQ(it++, pointers.at(0));
        CHECK_EQ(it++, pointers.at(1));
        CHECK_EQ(it++, pointers.at(3));
        CHECK_EQ(it++, pointers.at(4));
        CHECK_EQ(it++, pointers.at(2));
        CHECK_EQ(it++, pointers.at(5));
        CHECK_EQ(it++, pointers.at(6));
        CHECK_EQ(it, organization.end_preorder());
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

    vector<OrgChart*> pointers;

    for (auto it = organization.begin(); it != organization.end(); ++it){
        pointers.push_back((OrgChart*)it);
    }

    CHECK_NOTHROW(organization.add_root("grandfather"));

    unsigned long i = 1;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        CHECK_EQ(pointers.at(i++), it);
    }

    CHECK_THROWS(organization.add_sub("nonexisting", "test"));
}
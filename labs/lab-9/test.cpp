#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bst.h"
#include <iostream>

TEST_CASE("Constructor") {
    BSTree t;
}

TEST_CASE("Destructor") {
    BSTree *t = new BSTree;
    delete t;
}

TEST_CASE("Insert") {
    SUBCASE("Increasing") {
        BSTree t;
        for (int i = 0; i < 100; ++i) {
            CHECK(t.height() == i-1);
            t.insert(i);
        }
        std::cout << t.height() << std::endl;
        REQUIRE(t.height() == 99);
    }
    SUBCASE("Decreasing") {
        BSTree t;
        for (int i=100; i>0; --i) {
            CHECK(t.height() == 100-i-1);
            t.insert(i);
        }
        REQUIRE(t.height() == 99);
    }
    SUBCASE("Perfect") {
        BSTree t;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);
        REQUIRE(t.height() == 2);
    }
}

TEST_CASE("Search") {
    BSTree t;
    REQUIRE_FALSE(t.search(0));

    t.insert(0);
    REQUIRE(t.search(0));
    REQUIRE_FALSE(t.search(1));
}

TEST_CASE("Postorder") {
    SUBCASE("Empty Tree") {
        BSTree t;
        std::ostringstream oss;
        t.postorder(oss);
        REQUIRE(oss.str() == "\n");
    }
    SUBCASE("Imbalanced") {
        BSTree t;
        std::ostringstream oss;
        t.insert(1);
        t.insert(2);
        t.postorder(oss);
        REQUIRE(oss.str() == "2, 1, \n");
    }
    SUBCASE("Balanced") {
        BSTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.postorder(oss);
        REQUIRE(oss.str() == "2, 4, 3, 6, 8, 7, 5, \n");
    }
}

TEST_CASE("Inorder") {
    SUBCASE("Empty Tree") {
        BSTree t;
        std::ostringstream oss;
        t.inorder(oss);
        REQUIRE(oss.str() == "\n");
    }
    SUBCASE("Imbalanced") {
        BSTree t;
        std::ostringstream oss;
        t.insert(1);
        t.insert(2);
        t.inorder(oss);
        REQUIRE(oss.str() == "1, 2, \n");
    }
    SUBCASE("Balanced") {
        BSTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.inorder(oss);
        REQUIRE(oss.str() == "2, 3, 4, 5, 6, 7, 8, \n");
    }
}

TEST_CASE("Preorder") {
    SUBCASE("Empty Tree") {
        BSTree t;
        std::ostringstream oss;
        t.preorder(oss);
        REQUIRE(oss.str() == "\n");
    }
    SUBCASE("Imbalanced") {
        BSTree t;
        std::ostringstream oss;
        t.insert(1);
        t.insert(2);
        t.preorder(oss);
        REQUIRE(oss.str() == "1, 2, \n");
    }
    SUBCASE("Balanced") {
        BSTree t;
        std::ostringstream oss;
        t.insert(5);
        t.insert(3);
        t.insert(7);
        t.insert(2);
        t.insert(4);
        t.insert(6);
        t.insert(8);

        t.preorder(oss);
        REQUIRE(oss.str() == "5, 3, 2, 4, 7, 6, 8, \n");
    }
}

TEST_CASE("Height") {
   BSTree t;
   REQUIRE(t.height() == -1);
   t.insert(1);
   REQUIRE(t.height() == 0);
   t.insert(2);
   REQUIRE(t.height() == 1);
}

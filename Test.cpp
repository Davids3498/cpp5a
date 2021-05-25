#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("exeptions")
{
    BinaryTree<int> tree;
    //no root
    CHECK_THROWS(tree.add_left(1, 2));
    CHECK_THROWS(tree.add_right(1, 2));
    tree.add_root(2);
    //root exist but no were to put nodes
    CHECK_THROWS(tree.add_left(1, 2));
    CHECK_THROWS(tree.add_right(1, 2));
}
TEST_CASE("adding sons shouldn't throw exeprions")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_left(1, 2));
    CHECK_NOTHROW(tree.add_right(1, 3));
    CHECK_NOTHROW(tree.add_left(2, 4));
    CHECK_NOTHROW(tree.add_right(2, 5));
    CHECK_NOTHROW(tree.add_left(3, 6));
    CHECK_NOTHROW(tree.add_right(3, 7));
}
TEST_CASE("Preorder iterator")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_left(1, 2));
    CHECK_NOTHROW(tree.add_right(1, 3));
    CHECK_NOTHROW(tree.add_left(2, 4));
    CHECK_NOTHROW(tree.add_right(2, 5));
    CHECK_NOTHROW(tree.add_left(3, 6));
    CHECK_NOTHROW(tree.add_right(3, 7));
    int arr[7] = {1, 2, 4, 5, 3, 6, 7};
    int i = 0;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        CHECK((*it) == arr[i]);
        i++;
    }
}
TEST_CASE("Inorder iterator")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_left(1, 2));
    CHECK_NOTHROW(tree.add_right(1, 3));
    CHECK_NOTHROW(tree.add_left(2, 4));
    CHECK_NOTHROW(tree.add_right(2, 5));
    CHECK_NOTHROW(tree.add_left(3, 6));
    CHECK_NOTHROW(tree.add_right(3, 7));
    int arr[7] = {4, 2, 5, 1, 6, 3, 7};
    int i = 0;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        CHECK((*it) == arr[i]);
        i++;
    }
}
TEST_CASE("Postorder iterator")
{
    BinaryTree<int> tree;
    CHECK_NOTHROW(tree.add_root(1));
    CHECK_NOTHROW(tree.add_left(1, 2));
    CHECK_NOTHROW(tree.add_right(1, 3));
    CHECK_NOTHROW(tree.add_left(2, 4));
    CHECK_NOTHROW(tree.add_right(2, 5));
    CHECK_NOTHROW(tree.add_left(3, 6));
    CHECK_NOTHROW(tree.add_right(3, 7));
    int arr[7] = {4, 5, 2, 6, 7, 3, 1};
    int i = 0;
    for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
    {
        CHECK((*it) == arr[i]);
        i++;
    }
}
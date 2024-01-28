#include <gtest/gtest.h>
#include <fstream>
#include <iostream>

import AVL;
import Interface;
import SetInterface;

TEST(Exceptions, Insert){
    AVLTree<int> tree;
    for(int i = 0; i < 10; ++i)
        tree.insert(i);

    int n = 0;
    for(int i = 0; i < 10; ++i)
        try{
            tree.insert(i);
        }
        catch(const std::string &str){
            EXPECT_EQ(str, "Value " + std::to_string(i) + " is already exist.\n");
            ++n;
        }
    EXPECT_EQ(n, 10);
}

TEST(Exceptions, MinStat){
    AVLTree<int> tree;
    for(int i = 0; i < 10; ++i)
        tree.insert(i);

    int n = 0;
    try{
        tree.minStat(1);
    }
    catch(const std::string &str){
        ++n;
    }

    try{
        tree.minStat(10);
    }
    catch(const std::string &str){
        ++n;
    }

    try{
        tree.minStat(11);
    }
    catch(const std::string &str){
        EXPECT_EQ(str, "Value 11 is greater than count 10\n");
        ++n;
    }

    try{
        tree.minStat(115);
    }
    catch(const std::string &str){
        EXPECT_EQ(str, "Value 115 is greater than count 10\n");
        ++n;
    }

    EXPECT_EQ(n, 2);
}

TEST(Itterator, Dereferenceability){
    AVLTree<int> tree;
    tree.insert(8);
    AVLTree<int>::itterator it = tree.begin();
    EXPECT_EQ(*it, 8);
}

TEST(Itterator, Increment){
    AVLTree<int> tree;
    for(int i = 1; i < 16; ++i)
        tree.insert(i);
    
    int n = 1;
    for(auto it = tree.begin(), end = tree.end(); it != end; ++it, ++n){
        EXPECT_EQ(*it, n);
    }
    EXPECT_EQ(n, 16);
}

TEST(Itterator, Decrement){
    AVLTree<int> tree;
    for(int i = 1; i < 16; ++i)
        tree.insert(i);

    int n = 15;
    auto it = tree.end();
    --it;
    for(auto begin = tree.begin(); it != begin; --it, --n){
        EXPECT_EQ(*it, n);
    }
    EXPECT_EQ(*it, 1);
    EXPECT_EQ(n, 1);
}


TEST(TestFile, example){
    std::ifstream fs1("tests/example");
    std::ifstream fs2("tests/example");

    std::stringstream tree_out;
    std::stringstream tree_err;
    std::stringstream set_out;
    std::stringstream set_err;

    Interface<int> tree;
    SetInterface set;

    tree.GetCommands(fs1);
    tree.RunCommands(tree_out, tree_err);
    set.GetCommands(fs2);
    set.RunCommands(set_out, set_err);

    EXPECT_EQ(tree_out.str(), set_out.str());
    EXPECT_EQ(tree_err.str(), set_err.str());
    std::cout << tree_out.str() << tree_err.str();
}

TEST(TestFile, test1_1){
    std::ifstream fs1("tests/test1_1");
    std::ifstream fs2("tests/test1_1");

    std::stringstream tree_out;
    std::stringstream tree_err;
    std::stringstream set_out;
    std::stringstream set_err;

    Interface<int> tree;
    SetInterface set;

    tree.GetCommands(fs1);
    tree.RunCommands(tree_out, tree_err);
    set.GetCommands(fs2);
    set.RunCommands(set_out, set_err);

    EXPECT_EQ(tree_out.str(), set_out.str());
    EXPECT_EQ(tree_err.str(), set_err.str());
    std::cout << tree_out.str() << tree_err.str();
}

TEST(TestFile, test1_2){
    std::ifstream fs1("tests/test1_2");
    std::ifstream fs2("tests/test1_2");

    std::stringstream tree_out;
    std::stringstream tree_err;
    std::stringstream set_out;
    std::stringstream set_err;

    Interface<int> tree;
    SetInterface set;

    tree.GetCommands(fs1);
    tree.RunCommands(tree_out, tree_err);
    set.GetCommands(fs2);
    set.RunCommands(set_out, set_err);

    EXPECT_EQ(tree_out.str(), set_out.str());
    EXPECT_EQ(tree_err.str(), set_err.str());
    std::cout << tree_out.str() << tree_err.str();
}

TEST(TestFile, test1_3){
    std::ifstream fs1("tests/test1_3");
    std::ifstream fs2("tests/test1_3");

    std::stringstream tree_out;
    std::stringstream tree_err;
    std::stringstream set_out;
    std::stringstream set_err;

    Interface<int> tree;
    SetInterface set;

    tree.GetCommands(fs1);
    tree.RunCommands(tree_out, tree_err);
    set.GetCommands(fs2);
    set.RunCommands(set_out, set_err);

    EXPECT_EQ(tree_out.str(), set_out.str());
    EXPECT_EQ(tree_err.str(), set_err.str());
    std::cout << tree_out.str() << tree_err.str();
}

TEST(TestFile, test2_1){
    std::ifstream fs1("tests/test2_1");
    std::ifstream fs2("tests/test2_1");

    std::stringstream tree_out;
    std::stringstream tree_err;
    std::stringstream set_out;
    std::stringstream set_err;

    Interface<int> tree;
    SetInterface set;

    tree.GetCommands(fs1);
    tree.RunCommands(tree_out, tree_err);
    set.GetCommands(fs2);
    set.RunCommands(set_out, set_err);

    EXPECT_EQ(tree_out.str(), set_out.str());
    EXPECT_EQ(tree_err.str(), set_err.str());
    std::cout << tree_out.str() << tree_err.str();
}

TEST(TestFile, test2_2){
    std::ifstream fs1("tests/test2_2");
    std::ifstream fs2("tests/test2_2");

    std::stringstream tree_out;
    std::stringstream tree_err;
    std::stringstream set_out;
    std::stringstream set_err;

    Interface<int> tree;
    SetInterface set;

    tree.GetCommands(fs1);
    tree.RunCommands(tree_out, tree_err);
    set.GetCommands(fs2);
    set.RunCommands(set_out, set_err);

    EXPECT_EQ(tree_out.str(), set_out.str());
    EXPECT_EQ(tree_err.str(), set_err.str());
    std::cout << tree_out.str() << tree_err.str();
}
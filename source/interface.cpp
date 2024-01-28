module;

import AVL;

#include <string>
#include <queue>
#include <iostream>

export module Interface;

export template <typename T>
class Interface{
public:
    void GetCommands(std::istream& istream = std::cin){
        char key;
        int val;
        while(istream >> key){
            istream >> val;
            commands.push({key, val});
        }
    }
    void RunCommands(std::ostream& ostream = std::cout, std::ostream& errstream = std::cerr){
        while(!commands.empty()){
            char key = commands.front().first;
            int  val = commands.front().second;
            if(key == 'k'){
                try{
                    tree.insert(val);
                }
                catch(const std::string &str){
                    errstream << str;
                    errstream << "Command k " + std::to_string(val) + " was ignored\n";
                }
            }
            else if(key == 'm'){
                try{
                    const T& answer = tree.minStat(val);
                    ostream << answer << ' ';
                }
                catch(const std::string &str){
                    errstream << str;
                    errstream << "Command m " + std::to_string(val) + " was ignored\n";
                }
            }
            else if(key == 'n'){
                ostream << tree.countLess(val) << ' ';
            }
            else{
                errstream << "Unknown command " << key << " was ignored\n";
            }

            commands.pop();
        }
        ostream << '\n';
    }
private:
    std::queue<std::pair<char, int>> commands;
    AVLTree<T> tree;
};

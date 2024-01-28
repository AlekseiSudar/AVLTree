module;

#include <queue>
#include <set>
#include <algorithm>
#include <iostream>

export module SetInterface;

export class SetInterface{
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
                if(data.count(val)){
                    errstream << std::string("Value " + std::to_string(val) + " is already exist.\n");;
                    errstream << "Command k " + std::to_string(val) + " was ignored\n";
                }
                else{
                    data.insert(val);
                }
            }
            else if(key == 'm'){
                if(val < 1){
                    errstream << std::string("Value " + std::to_string(val) + " is less than 1\n");
                    errstream << "Command m " + std::to_string(val) + " was ignored\n";
                }
                else if (data.size() < val){
                    errstream << std::string("Value " + std::to_string(val) + " is greater than count " + std::to_string(data.size()) + "\n");
                    errstream << "Command m " + std::to_string(val) + " was ignored\n";
                }
                else{
                    auto it = data.begin();
                    std::advance(it, val-1);
                    ostream << *it << ' ';
                }
            }
            else if(key == 'n'){
                auto it = lower_bound(data.begin(), data.end(), val);
                int res = 0;
                while(it != data.begin()){
                    res++;
                    it--;
                }
                ostream << res << ' ';
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
    std::set<int> data;
};

#include<iostream>
// using namespace std;
#include <vector>
#include <stack>
using std::cout;
using std::endl;
using std::vector;
using std::stack;

void display_array(vector<int> stack){
    int n = stack.size();
    for (int i = 0; i < n; ++i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

void display_stacks(vector<vector<int>> stacks) {
    for(int i = 0; i < 3; ++i) {
        cout << (char) ('A' + i) << " : ";
        display_array(stacks[i]);
    }
    cout << endl;
}

void make_legal_move(vector<vector<int>> &stacks, int index1, int index2) {
    // if((stacks[index1].size()) && (stacks[index2].size())) {
    //     if (stacks[index1].back() < stacks[index2].back()) {
    //         stacks[index2].push_back(stacks[index1].back());
    //         stacks[index1].pop_back();
    //     } else {
    //         stacks[index1].push_back(stacks[index2].back());
    //         stacks[index2].pop_back();
    //     }
    //     display_stacks(stacks);
    // } else {
    //     if(stacks[index1].size()) {
    //         stacks[index2].push_back(stacks[index1].back());
    //         stacks[index1].pop_back();
    //         display_stacks(stacks);
    //     } else if (stacks[index2].size()) {
    //         stacks[index1].push_back(stacks[index2].back());
    //         stacks[index2].pop_back();
    //         display_stacks(stacks);
    //     }
    // }

    if((stacks[index1].size()) && (! stacks[index2].size())) {
        stacks[index2].push_back(stacks[index1].back());
        stacks[index1].pop_back();
        display_stacks(stacks);
    } else if ((stacks[index2].size()) && (!stacks[index1].size())) {
        stacks[index1].push_back(stacks[index2].back());
        stacks[index2].pop_back();
        display_stacks(stacks);
    } else if((stacks[index1].size()) && (stacks[index2].size())) {
        if (stacks[index1].back() < stacks[index2].back()) {
            stacks[index2].push_back(stacks[index1].back());
            stacks[index1].pop_back();
        } else {
            stacks[index1].push_back(stacks[index2].back());
            stacks[index2].pop_back();
        }
        display_stacks(stacks);
    }
}

void tower_of_hanoi_solve(vector<vector<int>> & stacks){
    cout << "initially\n";
    display_stacks(stacks);
    int n = stacks[0].size();
    while(stacks[2].size() < n) {
        make_legal_move(stacks, 0, 1);
        make_legal_move(stacks, 0, 2);
        make_legal_move(stacks, 1, 2);
    }
}

void recursive_tower_of_hanoi(vector<vector<int>> &stacks, int source, int spare, int destination, int n){
    if (n == 1) {
        // cout << stacks[source].back() << endl;
        stacks[destination].push_back(stacks[source].back());
        stacks[source].pop_back();
        cout << "move " << (char) ('A' + source) << " to " << (char) ('A' + destination) << endl;
    } else {
        recursive_tower_of_hanoi(stacks, source, destination, spare, n - 1);
        recursive_tower_of_hanoi(stacks, source, spare, destination, 1);
        recursive_tower_of_hanoi(stacks, spare, source, destination, n - 1);
    }
}

int main() {

    vector<vector<int>> stacks;
    for(int i = 0; i < 3; ++i) {
        vector<int> stack;
        stacks.push_back(stack);
    }

    int n = 3;
    for (int i = n; i > 0; --i) {
        stacks[0].push_back(i);
    }

    display_stacks(stacks);

    tower_of_hanoi_solve(stacks);
    // recursive_tower_of_hanoi(stacks, 0, 1, 2, n);

    display_stacks(stacks);


    return 0 ;
}

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "priority_queue.hpp"
using namespace std;

int main()
{

    srand(time(NULL));

    vector<int> v;
    
    for (int i = 0; i < 10; i++) {
        int rnum = rand() % 50 + 1;
        v.push_back(rnum);
    }

    pohan::priority_queue<int> pqi;
    
    for (int num : v) {
        pqi.push(num);

    }

    for (int num : v) {
        pqi.showPQ();

        //cout << pqi.top();
        pqi.pop();
    }
        

    //cout << pqi.top();
    
    //int a = 5;
    //pqi.push(a);
}


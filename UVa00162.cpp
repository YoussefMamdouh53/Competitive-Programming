#include <bits/stdc++.h>

using namespace std;

#define DEALER 0
#define PLAYER 1
#define GND 3

// one card for a Jack, two for a Queen, three for a King and four for an Ace

deque<string> deck[3];
int FLAG = 0;

void add_cards(deque<string> *s){
    while (!deck[2].empty()){
        (*s).push_back(deck[2].front());
        deck[2].pop_front();
    }
}

int main() {
    string in;
    while (cin >> in, in!="#"){
        deck[0].push_back(in);
        de
    while (!deck[0].empty() && !deck[1].empty()){
        deck[2].push_back(deck[FLAG].front());
        deck[FLAG].pop_front();
        FLAG = FLAG = 0 ? 1 : 0;
        if (deck[2].back()[1] == 'J'){
            int c = 1;
            bool yes = false;
            while (!deck[FLAG].empty() && c--){
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();
                if (deck[2].back()[1] == 'J') {yes=true; break;}
            }
            if (!yes && !deck[FLAG].empty()){
                add_cards(&deck[!FLAG]);
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();
            }
        }
        else if (deck[2].back()[1] == 'Q'){
            int c = 2;
            bool yes = false;
            while (!deck[FLAG].empty() && c--){
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();
                if (deck[2].back()[1] == 'Q') {yes=true; break;}
            }
            if (!yes && !deck[FLAG].empty()){
                add_cards(&deck[!FLAG]);
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();
            }
        }
        else if (deck[2].back()[1] == 'K'){
            int c = 3;
            bool yes = false;
            while (!deck[FLAG].empty() && c--){
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();
                if (deck[2].back()[1] == 'K') {yes=true; break;}
            }
            if (!yes && !deck[FLAG].empty()){
                add_cards(&deck[!FLAG]);
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();            
            }
        }
        else if (deck[2].back()[1] == 'A'){
            int c = 4;
            bool yes = false;
            while (!deck[FLAG].empty() && c--){
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();
                if (deck[2].back()[1] == 'A') {yes=true; break;}
            }
            if (!yes && !deck[FLAG].empty()){
                add_cards(&deck[!FLAG]);
                deck[2].push_back(deck[FLAG].front());
                deck[FLAG].pop_front();         
           }
        }
    }
    if (!deck[0].empty())
        cout << "1 " << deck[0].size() << endl;
    else
        cout << "2 " << deck[1].size() << endl;
    }
    
    return 0;
}
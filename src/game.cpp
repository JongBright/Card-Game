#include "game.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::string;

using namespace std;



enum cardLabel {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum cardType {SPADE, CLUB, HEART, DIAMOND};

struct Card{
    cardLabel card_label;
    cardType card_type;
    int card_value;
    int num_card_label = 13;
    int num_card_type = 4;

};

struct Deck{
    vector<Card> cards;
};

vector<Card> computer_cards;
vector<Card> player_cards;

void initialize_main_deck(Deck&);
void showDeck(Deck&);
void deal(Deck&, vector<Card>&);
void showHand(vector<Card>&);
void results(vector<Card>&, vector<Card>&);


game::game()
{

}

//the game
game::play()
{
    Deck main_deck;
    initialize_main_deck(main_deck);
    //showDeck(main_deck);
    deal(main_deck, player_cards);
    showHand(player_cards);

    string qst;
    string yes("Yes");
    string no("No");
    cout << " " << endl;
    cout << "Are you satisfied with the hand obtained for you. If you are, type 'Yes' or else type 'No': ";
    cin >> qst;
    if (qst == yes){
        deal(main_deck, computer_cards);
        cout << " " << endl;
        cout << " Human player's cards " << endl;
        showHand(player_cards);
        cout << " " << endl;

        cout << " Computer player's cards " << endl;
        showHand(computer_cards);
        cout << " " << endl;

    }else if(qst == no){
        player_cards.erase(player_cards.begin() + 0);
        player_cards.erase(player_cards.begin() + 1);
        player_cards.erase(player_cards.begin() + 2);
        player_cards.erase(player_cards.begin() + 3);
        player_cards.erase(player_cards.begin() + 4);

        deal(main_deck, player_cards);
        showHand(player_cards);

        deal(main_deck, computer_cards);
        cout << " " << endl;
        cout << " Human player's cards " << endl;
        showHand(player_cards);
        cout << " " << endl;

        cout << " Computer player's cards " << endl;
        showHand(computer_cards);
        cout << " " << endl;
    }else{
        cout << "Invalid input " << endl;
    }


    cout << " " << endl;

    results(player_cards, computer_cards);


}


//initializing the 52 decks of card
void initialize_main_deck(Deck& x){
    Card card;
    for (int card_label = 0; card_label<card.num_card_label; card_label++){
        for (int card_type = 0; card_type<card.num_card_type; card_type++){
                card.card_label = cardLabel(card_label);
                card.card_type = cardType(card_type);

                if(card.card_label == 10){
                    card.card_value = 10;
                }else if(card.card_label == 11){
                    card.card_value = 10;
                }else if(card.card_label == 12){
                    card.card_value = 10;
                }else{
                    card.card_value = (int)(card.card_label+1);
                }
                x.cards.push_back(card);

        }
    }
}

//generating random cards from the deck of cards for the players
void deal(Deck& x, vector<Card>& player_hand){
    for (int card = 0; card<5; card++){
        srand(time(0));
        int rand_card = (int)((rand()%52));
        player_hand.push_back(x.cards[rand_card]);
        x.cards.erase(x.cards.begin()+ rand_card);
    }
}



//displaying each of the players 5 cards
void showHand(vector<Card>& hand){
    for(Card c: hand){
        if(c.card_label==0){
           std::cout << "Ace";
        }
        if(c.card_label==1){
           std::cout << "2";
        }
        if(c.card_label==2){
           std::cout << "3";
        }
        if(c.card_label==3){
           std::cout << "4";
        }
        if(c.card_label==4){
           std::cout << "5";
        }
        if(c.card_label==5){
           std::cout << "6";
        }if(c.card_label==6){
           std::cout << "7";
        }if(c.card_label==7){
           std::cout << "8";
        }if(c.card_label==8){
           std::cout << "9";
        }if(c.card_label==9){
           std::cout << "10";
        }
        if(c.card_label==10){
           std::cout << "Jack";
        }
        if(c.card_label==11){
           std::cout << "Queen";
        }
        if(c.card_label==12){
           std::cout << "King";
        }


        if(c.card_type==0){
           std::cout << " - Spade";
        }
        if(c.card_type==1){
           std::cout << " - Club";
        }
        if(c.card_type==2){
           std::cout << " - Heart";
        }
        if(c.card_type==3){
           std::cout << " - Diamond";
        }
        cout << " " << endl;

    }

}


//defining cards and their names
void showDeck(Deck& x){
    for(Card c: x.cards){
        if(c.card_label==0){
           std::cout << "Ace";
        }
        if(c.card_label==1){
           std::cout << "2";
        }
        if(c.card_label==2){
           std::cout << "3";
        }
        if(c.card_label==3){
           std::cout << "4";
        }
        if(c.card_label==4){
           std::cout << "5";
        }
        if(c.card_label==5){
           std::cout << "6";
        }if(c.card_label==6){
           std::cout << "7";
        }if(c.card_label==7){
           std::cout << "8";
        }if(c.card_label==8){
           std::cout << "9";
        }if(c.card_label==9){
           std::cout << "10";
        }
        if(c.card_label==10){
           std::cout << "Jack";
        }
        if(c.card_label==11){
           std::cout << "Queen";
        }
        if(c.card_label==12){
           std::cout << "King";
        }


        if(c.card_type==0){
           std::cout << " - Spade";
        }
        if(c.card_type==1){
           std::cout << " - Club";
        }
        if(c.card_type==2){
           std::cout << " - Heart";
        }
        if(c.card_type==3){
           std::cout << " - Diamond\n";
        }
        cout << " " << endl;

    }

}

//deciding the winner of the game by comparison of the human player's value and the computer player's value
void results(vector<Card>& x, vector<Card>& y){
    int player_score = 0;
    int computer_score = 0;

    for(int i = 0; i<x.size(); i++){
        player_score += x[i].card_value;
    }
    for(int i = 0; i<y.size(); i++){
        computer_score += y[i].card_value;
    }
    cout << "Human player's value: " << player_score << "        " << "Computer player's value: " << computer_score  << endl;
    cout << " " << endl;

    if (player_score>computer_score){
        cout << " Human player is the winner of this round" << endl;
    }else if(computer_score>player_score){
        cout << " Computer player is the winner of this round " << endl;
    }else{
        cout << " Draw " << endl;
    }

    cout << " " << endl;

    cout << "GAME OVER" << endl;


}

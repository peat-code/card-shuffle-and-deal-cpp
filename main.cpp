#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

class Card
{
public:
    int face, suit;
    const char *suits[4] = {"Clubs", "Hearts", "Diamonds", "Spades"};
    const char *faces[13] = {"Ace", "Duece", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    Card(int f, int s)
    {
        face = f;
        suit = s;
    }
    void toString()
    {
        cout << "The card is " << faces[face ] << " of " << suits[suit ] << endl;
    }
};

class DeckOfCards
{
public:
    DeckOfCards()
    {
        int faces_count = 13;
        int suits_count = 4;
        for (int i = 0; i < suits_count; i++)
            for (int j = 0; j < faces_count; j++)
            {
                Card c(j, i);
                this->deck.push_back(c);
            }
        
        this->cCard = 0;
    }
    vector <Card> deck;
    int cCard;
    void shuffle()
    {
        std::random_device random_device;
        std::mt19937 random_generator(random_device());
        std::uniform_int_distribution<int> distribution2(0, 51);

        for (int i = 0; i < this->deck.size(); i++)
        {
            int rand_i = distribution2(random_generator);
            rand_i = rand_i %(this->deck.size());
            Card temp = this->deck[i];
            this->deck[i] = this->deck[rand_i];
            this->deck[rand_i] = temp;
        }
        this->cCard = 0;
    }

    Card dealCard(){
        if(this->moreCards()){
            Card temp =  this->deck[this->cCard];
            this->cCard++;
            return temp;
    }   else return Card(1,1); 
    }
    bool moreCards(){
        if(this->cCard < this->deck.size())
            return true;
        else return false;
    }


};

int main(){
    int count;
    DeckOfCards d;
    d.shuffle();
    //cout << d.moreCards();
    for (auto i = d.deck.begin(); i != d.deck.end(); ++i){
         cout << (*i).face << ","<<(*i).suit <<endl;
         count++;
    }
    //cout << count <<endl;
    //d.deck.back().toString();
    // d.dealCard().toString();
    return 0;
}

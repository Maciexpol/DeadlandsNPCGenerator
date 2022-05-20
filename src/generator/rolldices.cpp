#include "rolldices.h"
#include "dice.h"
#include "card.h"
#include <QVector>

using namespace RollDices;


QVector<Card> Private::translateNumbers(QVector<qint16> numbers){
    QVector<Card> output{};
    // add translated number for card into output
    for(auto number : numbers){
        output.push_back(Card(number));
    }

    return output;
}

QVector<Card> Private::rollCards(){
    // TODO:
    //  Check if it returns exactly 12 cards

    // generate "deck" - numbers
    QVector<qint16> numbers = generateBasicDeck();

    // shuffle the deck
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(numbers), std::end(numbers), rng);

    // translate numbers and make real deck
    QVector<Card> deck = translateNumbers(numbers);

    // create output container
    QVector<Card> cards(12);

    // choose first 12 cards
    std::copy(deck.begin(), deck.begin() + 12, cards);

    return cards;
}

void Private::sortCards(QVector<Card> & deck){
     std::sort(deck.begin(), deck.end());
}

QVector<Card> Private::selectCards(QVector<Card> deck){
     // TODO:
     //  Problem - at the beggining - unskipable 2's,
     //            need to take cards from the end
     //  -- Check if it works --
     QVector<Card> finalCards;

     sortCards(finalCards);

     // adding 2's
     qint16 i = 0;
     while(deck[i].getFace() == FACES::two){
         finalCards.push_back(deck[i]);
         i++;
     }

     // adding rest the best dices
     i = deck.size() - 1;
     while(finalCards.size() < 10){
         finalCards.push_back(deck[i]);
         i--;
     }

     return finalCards;
}

QVector<Dice> generateDices(){
    QVector<Card> cards = Private::rollCards();
    cards = Private::selectCards(cards);
    return translateCards(cards);
}

QVector<Dice> translateCards(QVector<Card> deck){
    QVector<Dice> dices{};

    // translating cards to dices
    for(auto card : deck){
        dices.push_back(Dice(card));
    }

    return dices;
}

QVector<qint16> generateBasicDeck(){
    QVector<qint16> numbers{};
    // add 54 numbers into "deck"
    for(qint16 i = 0; i < 54; i++){
        numbers.push_back(i);
    }

    return numbers;
}

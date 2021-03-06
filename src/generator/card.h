#ifndef CARD_H
#define CARD_H

enum FACES{
    two = 2,
    three = 3,
    four = 4,
    five = 5,
    six = 6,
    seven = 7,
    eight = 8,
    nine = 9,
    ten = 10,
    jack = 11,
    queen = 12,
    king = 13,
    ace = 14
};

// Every color has 13 cards
// We can split 54 cards using floor to suits
enum SUITS{
    clubs = 0,
    diamonds = 1,
    hearts = 2,
    spades = 3,
    joker = 4
};

class Card
{
private:
    FACES face;
    SUITS suit;

    int const convertFace(int number)
        {return (number % 13) + 2;}

    int const convertSuits(int const number)
        {return (int) number / 13;}

public:
    Card(int number);

    bool operator == (Card a)
        {return face == a.getFace() and suit == a.getSuit();}

    bool operator < (Card a)
        {return face < a.getFace() and suit <= a.getSuit();}

    bool operator > (Card a)
        {return face > a.getFace() and suit >= a.getSuit();}

    bool operator <= (Card a)
        {return face <= a.getFace() and suit <= a.getSuit();}

    bool operator >= (Card a)
        {return face >= a.getFace() and suit >= a.getSuit();}

    void setFace(int number)
        {face = FACES(convertFace(number));}

    void setSuit(int number)
        {suit = SUITS(convertSuits(number));}

    FACES getFace() const
        {return face;}

    SUITS getSuit() const
        {return suit;}

};

#endif // CARD_H

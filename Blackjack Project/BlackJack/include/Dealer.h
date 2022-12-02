#ifndef DEALER_H
#define DEALER_H

#include "Human.h"

class Dealer: public Human{

    public:
        std::vector <char> printFirstCard();
};

#endif
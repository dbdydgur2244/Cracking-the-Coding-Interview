#include <cstdio>
#include <vector>
#include <random>
#include <algorithm>
#include <string>

class Card{
protected:
    const int Spade = 0, Heart = 1, Diamond = 2, Club = 3, Joker = 4;
    const int Ace = 1, King = 11, Queen = 12, Jack = 13; 
    int usedCard;
    std::vector<std::vector<bool>> cardInfo;    
    enum class cardType{
        Spade, Heart, Diamond, Club, Joker
    };

public:
    Card() : cardInfo(5, std::vector<bool>()){
        init(); 
    }

    ~Card(){
        cardInfo.clear();
        usedCard = 0;
    }

    virtual void init(void){
        usedCard = 0;
        cardInfo[Spade].resize(15);
        cardInfo[Heart].resize(15);
        cardInfo[Diamond].resize(15);
        cardInfo[Club].resize(15);
        cardInfo[Joker].resize(2);
    }
};

class Blackjack : public Card{
private:
    int personNum;
    std::vector<bool>Isstop;
    std::vector<std::vector<int>>personCard;
    std::vector<int>cardIdx;
public:
    Blackjack(int _person) : personNum(_person), Isstop(_person, false),
                                personCard(_person, std::vector<int>(0))
    {
        init();
    }

    ~Blackjack(){
        personNum = 0;
    }

    void mixCard(void){
        std::random_device rn;
        std::mt19937_64 rnd( rn() );
        std::uniform_int_distribution<int> range(0, 51);
        int rand_num;

        for (int i = 0; i < 52; ++i)
            cardIdx[i] = i;

        for (int i = 0; i < 52; ++i){
            rand_num = range(rnd);
            std::swap(cardIdx[i], cardIdx[rand_num]);
        }
    }

    cardType getCardType(int cardNum){
        switch(cardNum / 13){
            case 0:
                return cardType::Spade;
                break;
            case 1:
                return cardType::Heart;
                break;
            case 2:
                return cardType::Diamond;
                break;
            case 3:
                return cardType::Club;
                break;
            default:
                return cardType::Joker;
                break;
        }
   }

    std::string GetCardInfo(int cardNum){
        std::string cardName = "";
        cardType type = getCardType(cardNum);
        switch(type){
            case cardType::Spade:
                cardName = "Spade ";
                break;
            case cardType::Heart:
                cardName = "Heart ";
                break;
            case cardType::Diamond:
                cardName = "Diamond ";
                break;
            case cardType::Club:
                cardName = "Club ";
                break;
            default:
                break;
        }
       
        switch(cardNum % 13){
            case 0:
                cardName += "Ace";
                break;
            case 10:
                cardName += "King";
                break;
            case 11:
                cardName += "Queen";
                break;
            case 12:
                cardName += "Jack";
                break;
            default:
                cardName += ('1' + cardNum % 13);
                break;
        }

        return cardName;
    }

    void init(void){
        usedCard = 0;
        cardInfo[Spade].resize(15);
        cardInfo[Heart].resize(15);
        cardInfo[Diamond].resize(15);
        cardInfo[Club].resize(15);
        cardInfo[Joker].clear();
        
        cardIdx.resize(52);
        mixCard();
    }

    void Playturn(){
        int flag;
        for (int i = 0; i < personNum; ++i){
            if (Isstop[i])
                continue;
            printf("Go(0) or Stop(1) ? : ");
            scanf("%d", &flag);
            Isstop[i] = flag;
            personCard[i].push_back(cardIdx.back());
            cardIdx.pop_back();
        }
    }
};

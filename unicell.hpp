#ifndef __UNICELL_H_
#define __UNICELL_H_
#include <iostream>
#include <vector>
using namespace std;

class unicell
{
private:
    int avg_lifespan;
    int age;
    int foodQty;
    int excreteQty;
    int metabolism;
    int waterConc;
    int waterConcMax;
    int MembHandlingLimit;
    bool alive;

public:
    int getAvg_lifespan()
    {
        return this->avg_lifespan;
    }
    int getAge()
    {
        return this->age;
    }
    int getFoodqty()
    {
        return this->foodQty;
    }
    int getExcreteqty()
    {
        return this->excreteQty;
    }
    int getMetabolism()
    {
        return this->metabolism;
    }
    int getWaterConc()
    {
        return this->waterConc;
    }
    int getWaterConcMax()
    {
        return this->waterConcMax;
    }
    int getMembHandlingLimit()
    {
        return this->MembHandlingLimit;
    }
    bool isAlive()
    {
        return this->alive;
    }
    void unicell_init(int avg_lifespan, int age, int foodQty, int excreteQty, int metabolism, int waterConc, int waterConcMax, int MembHandlingLimit)
    {
        this->avg_lifespan = avg_lifespan;
        this->age = age;
        this->foodQty = foodQty;
        this->excreteQty = excreteQty;
        this->metabolism = metabolism;
        this->alive = true;
        this->waterConc = waterConc;
        this->waterConcMax = waterConcMax;
        this->MembHandlingLimit = MembHandlingLimit;
    }
    void update_age()
    {
        this->age += (this->avg_lifespan) / 100;
    }
    void update_age(int newAge)
    {
        this->age += newAge;
    }
    void engulf(int foodAmt)
    {
        this->foodQty += foodAmt;
    }
    void digest(int intake, int digAmt, int metaInc)
    {
        this->foodQty -= intake;
        this->excreteQty += digAmt;
        this->metabolism += metaInc;
    }
    void excrete(int excreteAmt)
    {
        this->excreteQty -= excreteAmt;
    }
    void osmosis(int extWaterConc)
    {
        if(extWaterConc < waterConcMax){
            this->waterConc = extWaterConc;
        }
        else{
            if(extWaterConc - waterConcMax <= MembHandlingLimit){
                this->waterConc = waterConcMax;
            }
            else{
                alive = false;
            }
        }
    }
};

#endif
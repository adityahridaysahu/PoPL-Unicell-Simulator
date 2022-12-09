#include <iostream>
#include <vector>
#include "unicell.hpp"
using namespace std;

class unicell_sexual : public unicell
{
private:
    bool f_status;
    unicell_sexual *parent;
    unicell_sexual *child;

public:
    bool getF_status()
    {
        return this->f_status;
    }
    unicell_sexual *getParent()
    {
        return this->parent;
    }
    unicell_sexual *getChild()
    {
        return this->child;
    }
    void unicell_sexual_init(int avg_lifespan, int age, int foodQty, int excreteQty, int metabolism, bool f_status, int waterConc, int waterConcMax, int MembHandlingLimit, unicell_sexual *parent, unicell_sexual *child)
    {
        this->unicell_init(avg_lifespan, age, foodQty, excreteQty, metabolism, waterConc, waterConcMax, MembHandlingLimit);
        this->f_status = f_status;
        this->parent = parent;
        this->child = child;
    }
    int conjugate(unicell_sexual *partner)
    {
        if (this->f_status == partner->f_status)
        {
            return -1;
        }
        else if (this->f_status)
        {
            this->child = partner;
            partner->parent = this;
            return 1;
        }
        else
        {
            this->parent = partner;
            partner->child = this;
            return 1;
        }
    }
    void printAll(){
        cout << "Average Lifespan: " << this->getAvg_lifespan() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "Food Quantity: " << this->getFoodqty() << endl;
        cout << "Excrete Quantity: " << this->getExcreteqty() << endl;
        cout << "Metabolism: " << this->getMetabolism() << endl;
        cout << "Fertility Status: " << this->getF_status() << endl;
        cout << "Current Water Concentration: " << this->getWaterConc() << endl;
        cout << "Maximum Water Concentration: " << this->getWaterConcMax() << endl;
        cout << "Maximum Membrane Handling Limit: " << this->getMembHandlingLimit() << endl;
        cout << endl;
    }
};
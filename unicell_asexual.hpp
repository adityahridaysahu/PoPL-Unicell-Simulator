#include <iostream>
#include <vector>
#include <math.h>
#include "unicell.hpp"
using namespace std;

class unicell_asexual : public unicell
{
public:
    void unicell_asexual_init(int avg_lifespan, int age, int foodQty, int excreteQty, int metabolism, int waterConc, int waterConcMax, int MembHandlingLimit)
    {
        this->unicell_init(avg_lifespan, age, foodQty, excreteQty, metabolism, waterConc, waterConcMax, MembHandlingLimit);
    }
    void fission(vector<unicell_asexual *> *children, vector<int> metabolism, int n_ary)
    {
        for (int i = 0; i < n_ary; i++)
        {
            unicell_asexual *temp = new unicell_asexual;
            temp->unicell_asexual_init(this->getAvg_lifespan(), 0, (this->getFoodqty()) / n_ary, (this->getExcreteqty()) / n_ary, metabolism[i], this->getWaterConc(), this->getWaterConcMax(), floor((this->getMembHandlingLimit())/ (cbrt(n_ary)*cbrt(n_ary))));
            children->push_back(temp);
        }
    }
    void printAll(){
        cout << "Average Lifespan: " << this->getAvg_lifespan() << endl;
        cout << "Age: " << this->getAge() << endl;
        cout << "Food Quantity: " << this->getFoodqty() << endl;
        cout << "Excrete Quantity: " << this->getExcreteqty() << endl;
        cout << "Metabolism: " << this->getMetabolism() << endl;
        cout << "Current Water Concentration: " << this->getWaterConc() << endl;
        cout << "Maximum Water Concentration: " << this->getWaterConcMax() << endl;
        cout << "Maximum Membrane Handling Limit: " << this->getMembHandlingLimit() << endl;
        cout << endl;
    }
};
#include <iostream>
#include <vector>
#include "unicell_sexual.hpp"
#include "unicell_asexual.hpp"
using namespace std;

int main()
{
    // Engulf, Digest, Excrete, Age Update method demonstration
    cout << "Engulf, Digest, Excrete, Age Update method demonstration" << endl;
    unicell_sexual *cell1 = new unicell_sexual;
    cell1->unicell_sexual_init(100, 0, 100, 0, 1, true, 100, 150, 20, NULL, NULL);
    cell1->printAll();
    cell1->engulf(100);
    cell1->printAll();
    cell1->digest(50, 40, 1);
    cell1->printAll();
    cell1->excrete(30);
    cell1->printAll();
    cell1->update_age();
    cell1->printAll();
    cell1->update_age(5);
    cell1->printAll();

    //Demonstration of Conjugation
    cout << "Demonstration of Conjugation"  << endl;
    unicell_sexual *cell2 = new unicell_sexual;
    cell2->unicell_sexual_init(100, 0, 100, 0, 1, false, 90, 150, 25, NULL, NULL);
    cell2->printAll();
    cell1->conjugate(cell2);
    cout << "Cell 1's child: " << endl;
    cell1->getChild()->printAll();
    cout << "This is nothing but cell 2's features." << endl;
    cell2->printAll();
    cout << "Cell 2's parent: " << endl;
    cell2->getParent()->printAll();
    cout << "This is nothing but cell 1's features." << endl;
    cell1->printAll();
    cout << "Thus, conjugation works and the parent child relation is established." << endl;

    //Demonstration of Fission
    cout << "Demonstration of Fission" << endl;
    unicell_asexual *cell3 = new unicell_asexual;
    cell3->unicell_asexual_init(100, 0, 100, 16, 1, 100, 150, 30);
    cell3->printAll();
    vector <unicell_asexual *> children;
    int n_ary = 4;
    vector<int> metabolism;
    metabolism.push_back(1);
    metabolism.push_back(2);
    metabolism.push_back(2);
    metabolism.push_back(1);
    cell3->fission(&children, metabolism, n_ary);
    delete cell3;
    for (int i = 0; i < n_ary; i++)
    {
        cout << "Child " << i + 1 << endl;
        children[i]->printAll();
    }

    //Demonstration of Osmosis
    cout << "Demonstration of Osmosis" << endl;
    unicell_asexual *cell4 = new unicell_asexual;
    cell4->unicell_asexual_init(100, 0, 100, 16, 1, 100, 150, 30);
    cell4->printAll();
    cell4->osmosis(140);
    cell4->printAll();
    cell4->osmosis(160);
    cell4->printAll();
    cell4->osmosis(190);
    cell4->printAll();
    if (cell4->isAlive())
    {
        cout << "Cell is alive" << endl;
    }
    else{
        cout << "Cell is dead" << endl;
        delete cell4;
    }
    return 0;
}
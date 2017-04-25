#include "vectorspace.h"
#include "cexception.h"
#include <iostream>
#include <string>
#include "cmathvector.h"
using namespace std;

int main()
{

    try {

        myVector::CMathVector<int> vect(5);// = myVector::CMathVector<int>(5);
        string t = "hey";

        myVector::CMathVector<int> vect2 = { 0, 2, 3, 4, 5 };
        cout << vect2 << endl;


    //    vect.CMathVector(5);
        vect[0] = 1;
        vect[1] = 2;
        vect[2] = 3;
        vect[3] = 4;
        vect[4] = 5;
        cout << vect.GetAbsoluteValue() << "\n";
        cout << vect2.GetAbsoluteValue() << "\n";
        if(vect2 == vect) {
            cout << "er! ";
        }
        if(vect2 < vect) {
            cout << "< ";
        }
        if(vect2 <= vect) {
            cout << "<= ";
        }

        vect2 = vect;
        cout << vect2;

        try{
            throw CMemoryError(t);

        }
        catch(CBaseException ex)
        {
            cout << ex.what();
        }

            cout << "\n";

        myVector::CConstVectorIterator<int> it = vect.begin();
        cout << " ok\n";
        cout << *it << " ";
        it++;
        cout << *it << " ";
       // cout << *it2 << " ";
       // it2 = ++it;
       // cout << *it2 << endl;

        cout << vect;

        vect = -vect;
        cout << vect;
        vect = -vect;
        cout << -vect;
        cout << +vect;
       // vect += vect;


        cout << vect + vect;

        cout << vect.GetAbsoluteValue() << " ";

        cout << vect.GetElement(3);

        vect += vect;

        cout << vect;

        for(it = vect.begin(); it != vect.end(); it++) {
            cout << *it << " ";
        }
    }
    catch (CBaseException ex) {
        cout << ex.what();
    }


    return 0;
}

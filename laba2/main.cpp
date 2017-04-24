#include "vectorspace.h"
#include "cexception.h"
#include <iostream>
#include <string>
#include "cmathvector.h"
using namespace std;

int main()
{
    myVector::CMathVector<int> vect(5);// = myVector::CMathVector<int>(5);
    string t = "hey";

//    vect.CMathVector(5);
    vect[0] = 1;
    vect[1] = 2;
    vect[2] = 3;
    vect[3] = 4;
    vect[4] = 5;
    try{
        throw CMemoryError(t);

    }
    catch(CBaseException ex)
    {
        cout << ex.what();
    }

        cout << "ok\n";

    myVector::CVectorIterator<int> it(vect.begin());
    cout << "ok\n";
    cout << *it << " ";
    it++;
   // CVectorIterator<int> it2 = it++;
    cout << *it << " ";
   // cout << *it2 << " ";
   // it2 = ++it;
   // cout << *it2 << endl;

    cout << vect;

    //vect = -vect;
    cout << -vect;
   // vect += vect;


    cout << vect + vect;

    cout << vect.GetAbsoluteValue();

    cout << vect.GetElement(3);

    vect += vect;

    cout << vect;



    return 0;
}

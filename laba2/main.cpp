#include "cmathvector.h"
#include "cvectoriterator.h"

using namespace std;
int main(int argc, char *argv[])
{
    CMathVector<int> vect(5);
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

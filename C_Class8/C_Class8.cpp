#include <iostream>
#include <math.h>
#include "Class.h"
using namespace std;


int main()
{
    Date date(18, 6, 2006);

    cout << date;
    cout << "\n";

    ++date;
    date += 70;
    date -= 100;
    --date;

    cout << date;
    cout << "\n";

    date(22, 3, 1960);
    cout << date;
    cout << "\n";
}

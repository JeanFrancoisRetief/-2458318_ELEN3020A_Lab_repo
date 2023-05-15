// Jean-Francois Retief (2458318)
// test.cpp file for testing code
// No formal framework used, just "Without a framework" part of an answer on stackoverflow
// Reference: https://stackoverflow.com/questions/52273110/how-do-i-write-a-unit-test-in-c

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// JF - Functions to test (copied from main fincat.cpp, without comments)
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
int dollars2rands(int x)
{
    return (x * 20);
}

double calcRatioPM(double revenue, double expenses)
{
    return ((revenue - expenses) / revenue);
}

double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ((revenue - expenses) / assets);
}

double calcRatioDE(double assets, double liabilities)
{
    return (liabilities / assets);
}

string categorisePM(double ratio)
{
    string cat;
    if (ratio < 0.08)
        cat = 'unhealty';
    else if (0.08 <= ratio < 0.15)
        cat = 'average';
    else
        cat = 'healthy';
    return (cat);
}

string categoriseRoA(double ratio)
{
    string cat;
    if (ratio < 0.08)
        cat = 'unhealthy';
    else if (0.08 <= ratio < 0.15)
        cat = 'average';
    else
        cat = 'healthy';
    return (cat);
}

string categoriseDE(double ratio)
{
    string cat;
    if (ratio < 1)
        cat = 'healthy';
    else if (1 <= ratio < 2)
        cat = 'average';
    else
        cat = 'unhealthy';
    return (cat);
}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------

// JF - Testing functions
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
void test_dollars2rands(int x)
{
    if (dollars2rands(x) == (x * 20))
    {
        cout << "Function: dollars2rands was succesfull." << endl;
    }
    else
    {
        cout << "Function: dollars2rands has failed." << endl;
    }
}

void test_calcRatioPM(double revenue, double expenses)
{
    if (calcRatioPM(revenue, expenses) == ((revenue - expenses) / revenue))
    {
        cout << "Function: calcRatioPM was succesfull." << endl;
    }
    else
    {
        cout << "Function: calcRatioPM has failed." << endl;
    }
}

void test_calcRatioRoA(double revenue, double expenses, double assets)
{
    if (calcRatioRoA(revenue, expenses, assets) == ((revenue - expenses) / assets))
    {
        cout << "Function: calcRatioRoA was succesfull." << endl;
    }
    else
    {
        cout << "Function: calcRatioRoA has failed." << endl;
    }
}

void test_calcRatioDE(double assets, double liabilities)
{
    if (calcRatioDE(assets, liabilities) == (liabilities / assets))
    {
        cout << "Function:  was succesfull." << endl;
    }
    else
    {
        cout << "Function:  has failed." << endl;
    }
}

void test_categorisePM()
{
    if ()
    {
        cout << "Function:  was succesfull." << endl;
    }
    else
    {
        cout << "Function:  has failed." << endl;
    }
}

void test_categoriseRoA()
{
    if ()
    {
        cout << "Function:  was succesfull." << endl;
    }
    else
    {
        cout << "Function:  has failed." << endl;
    }
}
void test_categoriseDE()
{
    if ()
    {
        cout << "Function:  was succesfull." << endl;
    }
    else
    {
        cout << "Function:  has failed." << endl;
    }
}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------

int main(void)
{
    // Call tests
    test_dollars2rands();
    test_calcRatioPM();
    test_calcRatioRoA();
    test_calcRatioDE();
    test_categorisePM();
    test_categoriseRoA();
    test_categoriseDE();
}
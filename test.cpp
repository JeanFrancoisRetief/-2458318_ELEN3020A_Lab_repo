// Jean-Francois Retief (2458318)
// test.cpp file for testing code

// No formal framework used, just "Without a framework" part of an answer on stackoverflow
// Instead of #DEFINE 'ing the check functions, I rather put the checks (if statements as well as try-catch statements)
// into the actual test functions.
// Reference: https://stackoverflow.com/questions/52273110/how-do-i-write-a-unit-test-in-c

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Functions to test (copied from main fincat.cpp, without comments)
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
        cat = 'unhealthy';
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

// Testing functions
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
void test_dollars2rands(string xInt) // function parameters string instead of int (for input data-type validation)
{
    try
    {
        int x = stoi(xInt); // TRY to see if parameter is correct datatype
        if (dollars2rands(x) == (x * 20))
        {
            cout << "Function: dollars2rands was succesfull." << endl;
        }
        else
        {
            cout << "Function: dollars2rands has failed." << endl;
        }
    }
    catch (...)
    {
        cout << "Function: dollars2rands has failed -> integer not entered" << endl;
    }
}

void test_calcRatioPM(string revenue, string expenses) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(revenue);  // TRY to see if parameter is correct datatype
        double e = stod(expenses); // TRY to see if parameter is correct datatype
        if (calcRatioPM(r, e) == ((r - e) / r))
        {
            cout << "Function: calcRatioPM was succesfull." << endl;
        }
        else
        {
            cout << "Function: calcRatioPM has failed." << endl;
        }
    }
    catch (...)
    {
        cout << "Function: calcRatioPM has failed -> doubles not entered" << endl;
    }
}

void test_calcRatioRoA(string revenue, string expenses, string assets) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(revenue);  // TRY to see if parameter is correct datatype
        double e = stod(expenses); // TRY to see if parameter is correct datatype
        double a = stod(assets);   // TRY to see if parameter is correct datatype
        if (calcRatioRoA(r, e, a) == ((r - e) / a))
        {
            cout << "Function: calcRatioRoA was succesfull." << endl;
        }
        else
        {
            cout << "Function: calcRatioRoA has failed." << endl;
        }
    }
    catch (...)
    {
    }
}

void test_calcRatioDE(string assets, string liabilities) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double a = stod(assets);      // TRY to see if parameter is correct datatype
        double l = stod(liabilities); // TRY to see if parameter is correct datatype
        if (calcRatioDE(a, l) == (l / a))
        {
            cout << "Function: calcRatioDE was succesfull." << endl;
        }
        else
        {
            cout << "Function: calcRatioDE has failed." << endl;
        }
    }
    catch (...)
    {
        cout << "Function: calcRatioDE has failed -> doubles not entered" << endl;
    }
}

void test_categorisePM(string ratio) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(ratio); // TRY to see if parameter is correct datatype
        if ((r < 0.08) && categorisePM(r) == "unhealthy")
        {
            cout << "Function: categorisePM  was succesfull for unhealthy test case." << endl;
        }
        else if ((0.08 <= r < 0.15) && categorisePM(r) == "average")
        {
            cout << "Function: categorisePM  was succesfull for average test case." << endl;
        }
        else if ((r >= 0.15) && categorisePM(r) == "healthy")
        {
            cout << "Function: categorisePM  was succesfull for healthy test case." << endl;
        }
        else
        {
            cout << "Function: categorisePM has failed." << endl;
        }
    }
    catch (...)
    {
        cout << "Function: categorisePM has failed -> a double was not entered" << endl;
    }
}

void test_categoriseRoA(string ratio) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(ratio); // TRY to see if parameter is correct datatype
        if ((r < 0.08) && categoriseRoA(r) == "unhealthy")
        {
            cout << "Function: categoriseRoA  was succesfull for unhealty test case." << endl;
        }
        else if ((0.08 <= r < 0.15) && categoriseRoA(r) == "average")
        {
            cout << "Function: categoriseRoA  was succesfull for average test case." << endl;
        }
        else if ((r >= 0.15) && categoriseRoA(r) == "healthy")
        {
            cout << "Function: categoriseRoA  was succesfull for healty test case." << endl;
        }
        else
        {
            cout << "Function: categoriseRoA has failed." << endl;
        }
    }
    catch (...)
    {
        cout << "Function: categoriseRoA has failed -> a double was not entered" << endl;
    }
}
void test_categoriseDE(string ratio) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(ratio); // TRY to see if parameter is correct datatype
        if ((r < 1) && categoriseDE(r) == "healthy")
        {
            cout << "Function: categoriseDE  was succesfull for unhealty test case." << endl;
        }
        else if ((1 <= r < 2) && categoriseDE(r) == "average")
        {
            cout << "Function: categoriseDE  was succesfull for average test case." << endl;
        }
        else if ((r >= 2) && categoriseDE(r) == "unhealthy")
        {
            cout << "Function: categoriseDE  was succesfull for healty test case." << endl;
        }
        else
        {
            cout << "Function: categoriseDE has failed." << endl;
        }
    }
    catch (...)
    {
        cout << "Function: categoriseDE has failed -> a double was not entered" << endl;
    }
}
//}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------

int main(void)
{
    // Call tests

    // testing dollars2rands()
    test_dollars2rands("50000");          // correct int testcase
    test_dollars2rands("60.03");          // incorrect float testcase -catch
    test_dollars2rands("Fifty Thousand"); // incorrect string testcase -catch

    // testing calcRatioPM()
    test_calcRatioPM("50000", "10000");      // correct double testcase
    test_calcRatioPM("1000000", "10000");    // correct double testcase
    test_calcRatioPM("500.55", "100.12");    // correct double testcase
    test_calcRatioPM("Revenue", "Expenses"); // incorrect string testcase -catch
    test_calcRatioPM("50000", "Expenses");   // incorrect string testcase -catch
    test_calcRatioPM("Revenue", "10000");    // incorrect string testcase -catch

    // testing calcRatioRoA()
    test_calcRatioRoA("50000", "10000", "5000");        // correct double testcase
    test_calcRatioRoA("1000000", "10000", "60000");     // correct double testcase
    test_calcRatioRoA("500.55", "100.12", "50.25");     // correct double testcase
    test_calcRatioRoA("Revenue", "Expenses", "Assets"); // incorrect string testcase -catch
    test_calcRatioRoA("50000", "Expenses", "Assets");   // incorrect string testcase -catch
    test_calcRatioRoA("Revenue", "10000", "Assets");    // incorrect string testcase -catch
    test_calcRatioRoA("Revenue", "Expenses", "5000");   // incorrect string testcase -catch

    // testing calcRatioDE()
    test_calcRatioDE("5000", "3000");          // correct double testcase
    test_calcRatioDE("60000", "44000");        // correct double testcase
    test_calcRatioDE("50.25", "39.99");        // correct double testcase
    test_calcRatioDE("Assets", "Liabilities"); // incorrect string testcase -catch
    test_calcRatioDE("5000", "Liabilities");   // incorrect string testcase -catch
    test_calcRatioDE("Assets", "3000");        // incorrect string testcase -catch

    // testing categorisePM()
    test_categorisePM("0.05");  // correct double testcase - unhealthy
    test_categorisePM("0.10");  // correct double testcase - average
    test_categorisePM("0.20");  // correct double testcase - healthy
    test_categorisePM("Ratio"); // incorrect string testcase -catch

    // testing categoriseRoA()
    test_categoriseRoA("0.05");  // correct double testcase - unhealthy
    test_categoriseRoA("0.10");  // correct double testcase - average
    test_categoriseRoA("0.20");  // correct double testcase - healthy
    test_categoriseRoA("Ratio"); // incorrect string testcase -catch

    // testing categoriseDE()
    test_categoriseDE("0.5");   // correct double testcase - healthy
    test_categoriseDE("1.5");   // correct double testcase - average
    test_categoriseDE("2.5");   // correct double testcase - unhealthy
    test_categoriseDE("Ratio"); // incorrect string testcase -catch
}
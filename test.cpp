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

// Note: this fucntion is being tested with inputted testcases, not ifstream and ofstream
// all file-code has been commented out in this version and replaced by return-string functionality
string process_data(string company_id, int revenue_USD, double expenses, double assets, double liabilities, double revenue_ZAR,
                    double ratio_PM, double ratio_RoA, double ratio_DE)
{

    // ifstream f_in;
    // ofstream f_out;
    // string data;
    // string company_id;
    // int revenue_USD;
    // double expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    string cat, cat2, cat3;

    string output;

    // f_in.open(input_file, ios::in);
    // f_out.open(output_file, ofstream::out);

    // while (!f_in.eof())
    //{
    // f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities;
    revenue_ZAR = double(dollars2rands(revenue_USD));
    ratio_PM = calcRatioPM(revenue_ZAR, expenses);
    cat = categorisePM(ratio_PM);
    ratio_RoA = calcRatioRoA(revenue_ZAR, expenses, assets);
    cat2 = categoriseRoA(ratio_RoA);
    ratio_DE = calcRatioDE(assets, liabilities);
    cat3 = categoriseDE(ratio_DE);

    // f_out << company_id << " " << ratio_PM << " " << cat << " " << ratio_RoA << " " << cat3 << " " << ratio_DE << " " << cat2 << endl;
    output = company_id + " " + to_string(ratio_PM) + " " + cat + " " + to_string(ratio_RoA) + " " + cat3 + " " +
             to_string(ratio_DE) + " " + cat2;
    return (output);
    //}

    // f_in.close();
    //.close();
}
//----------------------------------------------------------------------------//----------------------------------------------------------------------------

// Testing functions
//----------------------------------------------------------------------------//----------------------------------------------------------------------------
void test_dollars2rands(string xInt) // function parameters string instead of int (for input data-type validation)
{
    try
    {
        int x = stoi(xInt);               // TRY to see if parameter is correct datatype
        if (dollars2rands(x) == (x * 20)) // check if function returns correct output
        {
            cout << "Function: dollars2rands was succesfull." << endl; // debug log
        }
        else
        {
            cout << "Function: dollars2rands has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: dollars2rands has failed -> integer not entered" << endl; // debug log
    }
}

void test_calcRatioPM(string revenue, string expenses) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(revenue);               // TRY to see if parameter is correct datatype
        double e = stod(expenses);              // TRY to see if parameter is correct datatype
        if (calcRatioPM(r, e) == ((r - e) / r)) // check if function returns correct output
        {
            cout << "Function: calcRatioPM was succesfull." << endl; // debug log
        }
        else
        {
            cout << "Function: calcRatioPM has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: calcRatioPM has failed -> doubles not entered" << endl; // debug log
    }
}

void test_calcRatioRoA(string revenue, string expenses, string assets) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(revenue);                   // TRY to see if parameter is correct datatype
        double e = stod(expenses);                  // TRY to see if parameter is correct datatype
        double a = stod(assets);                    // TRY to see if parameter is correct datatype
        if (calcRatioRoA(r, e, a) == ((r - e) / a)) // check if function returns correct output
        {
            cout << "Function: calcRatioRoA was succesfull." << endl; // debug log
        }
        else
        {
            cout << "Function: calcRatioRoA has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: calcRatioRoA has failed -> doubles not entered" << endl; // debug log
    }
}

void test_calcRatioDE(string assets, string liabilities) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double a = stod(assets);          // TRY to see if parameter is correct datatype
        double l = stod(liabilities);     // TRY to see if parameter is correct datatype
        if (calcRatioDE(a, l) == (l / a)) // check if function returns correct output
        {
            cout << "Function: calcRatioDE was succesfull." << endl; // debug log
        }
        else
        {
            cout << "Function: calcRatioDE has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: calcRatioDE has failed -> doubles not entered" << endl; // debug log
    }
}

void test_categorisePM(string ratio) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(ratio);                             // TRY to see if parameter is correct datatype
        if ((r < 0.08) && (categorisePM(r) == "unhealthy")) // check if function returns correct output
        {
            cout << "Function: categorisePM  was succesfull for unhealthy test case." << endl; // debug log
        }
        else if ((0.08 <= r < 0.15) && (categorisePM(r) == "average")) // check if function returns correct output
        {
            cout << "Function: categorisePM  was succesfull for average test case." << endl; // debug log
        }
        else if ((r >= 0.15) && (categorisePM(r) == "healthy")) // check if function returns correct output
        {
            cout << "Function: categorisePM  was succesfull for healthy test case." << endl; // debug log
        }
        else
        {
            cout << "Function: categorisePM has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: categorisePM has failed -> a double was not entered" << endl; // debug log
    }
}

void test_categoriseRoA(string ratio) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(ratio);                              // TRY to see if parameter is correct datatype
        if ((r < 0.08) && (categoriseRoA(r) == "unhealthy")) // check if function returns correct output
        {
            cout << "Function: categoriseRoA  was succesfull for unhealty test case." << endl; // debug log
        }
        else if ((0.08 <= r < 0.15) && (categoriseRoA(r) == "average")) // check if function returns correct output
        {
            cout << "Function: categoriseRoA  was succesfull for average test case." << endl; // debug log
        }
        else if ((r >= 0.15) && (categoriseRoA(r) == "healthy")) // check if function returns correct output
        {
            cout << "Function: categoriseRoA  was succesfull for healty test case." << endl; // debug log
        }
        else
        {
            cout << "Function: categoriseRoA has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: categoriseRoA has failed -> a double was not entered" << endl; // debug log
    }
}
void test_categoriseDE(string ratio) // function parameters string instead of double (for input data-type validation)
{
    try
    {
        double r = stod(ratio);                        // TRY to see if parameter is correct datatype
        if ((r < 1) && (categoriseDE(r) == "healthy")) // check if function returns correct output
        {
            cout << "Function: categoriseDE  was succesfull for unhealty test case." << endl; // debug log
        }
        else if ((1 <= r < 2) && (categoriseDE(r) == "average")) // check if function returns correct output
        {
            cout << "Function: categoriseDE  was succesfull for average test case." << endl; // debug log
        }
        else if ((r >= 2) && (categoriseDE(r) == "unhealthy")) // check if function returns correct output
        {
            cout << "Function: categoriseDE  was succesfull for healty test case." << endl; // debug log
        }
        else
        {
            cout << "Function: categoriseDE has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: categoriseDE has failed -> a double was not entered" << endl; // debug log
    }
}

// Correct data types for parameters: string , int , double , double , double , double , double , double , double - respectively
void test_process_data(string company_id, string revenue_USD, string expenses, string assets, string liabilities, string revenue_ZAR,
                       string ratio_PM, string ratio_RoA, string ratio_DE)
{
    try
    {
        // TRY to see if parameters is correct datatype
        string c_id = company_id;
        int USDrev = stoi(revenue_USD);
        double e = stod(expenses);
        double a = stod(assets);
        double l = stod(liabilities);
        double ZARrev = stod(revenue_ZAR);
        double r_PM = stod(ratio_PM);
        double r_RoA = stod(ratio_RoA);
        double r_DE = stod(ratio_DE);

        // Create tesing variable
        string testString = c_id + " " + to_string(r_PM) + " " + categorisePM(r_PM) + " " + to_string(r_RoA) + " " + categorisePM(r_RoA) + " " +
                            to_string(r_DE) + " " + categorisePM(r_DE);
        // test
        if (process_data(c_id, USDrev, e, a, l, ZARrev, r_PM, r_RoA, r_DE) == testString)
        {
            cout << "Function: process_data  was succesfull for this test case." << endl; // debug log
        }
        else
        {
            cout << "Function: process_data has failed." << endl; // debug log
        }
    }
    catch (...)
    {
        cout << "Function: process_data has failed -> incorrect data type was entered" << endl; // debug log
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

    // testing test_process_data()

    // correct string, int and double testcase
    test_process_data("company5", "10000", "50000", "30000", "20000", "200000", "0.10", "0.10", "1.5");
    // incorrect string testcase -catch
    test_process_data("company_id", "revenue_USD", "expenses", "assets", "liabilities", "revenue_ZAR", "ratio_PM", "ratio_RoA", "ratio_DE");
}
// Jean-Francois Retief (2458318)
// main fincat.cpp file

// JA - it is good practice to insert comment about intended use, context, contributors, etc

// JF - included libraries
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// JF - exchange dollars for rands (for yearly dollar revenue - rest already in rand)
int dollars2rands(int x)
{
    return (x * 20); // JF - assuming the exchange rate is $1 = R20
}

// JF - Calculate Profit margin ratio = (revenue - expenses) / revenue
double calcRatioPM(double revenue, double expenses)
{
    return ((revenue - expenses) / revenue);
}

// JF - Calculate Return on Assets ratio = (revenue - expenses) / assets
double calcRatioRoA(double revenue, double expenses, double assets)
{
    return ((revenue - expenses) / assets);
}

// JF - Calculate Debt-to-Equity ratio = liabilities/assets
double calcRatioDE(double assets, double liabilities)
{
    return (liabilities / assets);
}

// JF - ***********Note on changes: "char cat" has been changed to "string cat" throughout the code***********

// JF -categorize the financial ratios according to these rules for the Profit margin ratio and the Return on Assets ratio:
// Less than 0.08: unhealty
// Not less than 0.08 but less than 0.15: average
// 0.15 or over: healthy

// JF - categorise Profit margin ratio
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

// JF - categorise Return on Assets ratio
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

// JF - categorize the Debt-to-Equity ratio as follows:
// Less than 1: healty
// Not less than 1 but less than 2: average
// 2 or over: unhealthy

// JF - categorise Debt-to-Equity ratio
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

// JF - Prossess the data (Profit margin ratio, Return on Assets ratio, Debt-to-Equity ratio as well as their categories)
// Note: corrected USD vs ZAR variable swaps
// Note: corrected revenue_ZAR = dollars2rands(double(revenue_USD));
// Note: made revenue_USD an integer, since the dollars2rands function takes in integers
// Note: added more [<< " " <<]'s to the  f_out << ... line for properly spaced output, like the readme example

void process_data(char *input_file, char *output_file)
{
    // JF - variables
    ifstream f_in;
    ofstream f_out;
    string data;
    string company_id;
    int revenue_USD;
    double expenses, assets, liabilities, revenue_ZAR, ratio_PM, ratio_RoA, ratio_DE;
    string cat, cat2, cat3; // JF -string, not char

    // open files
    f_in.open(input_file, ios::in);
    f_out.open(output_file, ofstream::out);

    // use files
    while (!f_in.eof()) // JF - loop until entire input file is read
    {
        f_in >> company_id >> revenue_USD >> expenses >> assets >> liabilities; // JF - input from f_in
        revenue_ZAR = double(dollars2rands(revenue_USD));                       // JF - convert $___ revenue to R____
        ratio_PM = calcRatioPM(revenue_ZAR, expenses);                          // JF - get Profit margin ratio
        cat = categorisePM(ratio_PM);                                           // JF - categorise Profit margin ratio
        ratio_RoA = calcRatioRoA(revenue_ZAR, expenses, assets);                // JF - get Return on Assets ratio //;
        cat2 = categoriseRoA(ratio_RoA);                                        // JF - categorise Return on Assets ratio
        ratio_DE = calcRatioDE(assets, liabilities);                            // JF - get Debt-to-Equity ratio
        cat3 = categoriseDE(ratio_DE);                                          // JF - categorise Debt-to-Equity ratio //;

        // JF - OUTPUT to f_out, the ratios and categories
        f_out << company_id << " " << ratio_PM << " " << cat << " " << ratio_RoA << " " << cat3 << " " << ratio_DE << " " << cat2 << endl;
    }

    // close files
    f_in.close();
    f_out.close();
}

int main(int argc, char *argv[])
{
    // JA - Need to check that 3 arguments were supplied upon execution
    process_data(argv[1], argv[2]);
}

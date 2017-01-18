#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    // constants
    const double Q_Joists = 25;
    const double Q_TwoSix = 100;
    const double Q_TwoFour = 25;
    const double Q_FourFour = 20;
    const double Q_FourEight = 100;

    // variables
    string LumberyardName;
    double Joists;
    double TwoSix;
    double TwoFour;
    double FourFour;
    double FourEight;
    char Answer;


    cout << "-------------- Welcome to program Budget Plan Instructions --------------" << endl;
    cout << "              The program will calculate cost by 2 decimals." << endl;

   do {

            // get input
            cout << "Please enter name of lumberyard: ";
            cin >> LumberyardName;

            cout << "Please enter unit cost of each material." << endl;
            cout << "Joists : ";
            cin >> Joists;
            cout << "2x6 : ";
            cin >> TwoSix;
            cout << "2x4 : ";
            cin >> TwoFour;
            cout << "4x4 : ";
            cin >> FourFour;
            cout << "4x8 sheet plywood : ";
            cin >> FourEight;


            // Display result
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Budget Plan Instructions for lumberyard : " << LumberyardName << endl;
            cout << "Description        Unit Cost           Quantity Needed            Cost" << endl;
            cout << "Joists"            << setw (18) << fixed << setprecision (2) << Joists    << setw (22) << Q_Joists    << setw (24) << Joists*Q_Joists << endl;
            cout << "2x6"               << setw (21) << fixed << setprecision (2) << TwoSix    << setw (22) << Q_TwoSix    << setw (24) << TwoSix*Q_TwoSix << endl;
            cout << "2x4"               << setw (21) << fixed << setprecision (2) << TwoFour   << setw (22) << Q_TwoFour   << setw (24) << TwoFour*Q_TwoFour << endl;
            cout << "4x4"               << setw (21) << fixed << setprecision (2) << FourFour  << setw (22) << Q_FourFour  << setw (24) << FourFour*Q_FourFour << endl;
            cout << "4x8 sheet plywood" << setw (7) << fixed << setprecision (2) << FourEight << setw (22) << Q_FourEight << setw (24) << FourEight*Q_FourEight << endl;
            cout << "Total cost:" << fixed << setprecision (2) << (Joists*Q_Joists) + (TwoSix*Q_TwoSix) + (TwoFour*Q_TwoFour) + (FourFour*Q_FourFour) + (FourEight*Q_FourEight) << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            cout << "Do you want to calculate more lumberyard?" << endl;
            cout << "If yes, please type Y" << endl;
            cout << "If no, please type any key" << endl;
            cin >> Answer;

    }while((Answer=='y')||(Answer=='Y'));



        cout << "------------------------ Thank you. Hope to see you again. -----------------------" << endl;



}

#include <iostream>

using namespace std;

int main()
{
    // constants
    const double PayRate = 16.78;
    const double SocialSecurityTaxRate = 0.06;
    const double FederalIncomeTaxRate = 0.14;
    const double StateIncomeTaxRate = 0.05;
    const int UnionDues = 10;

    // variables
    int Hours;
    int Dependents;
    double GrossPay;
    double SocialSecurityTax;
    double FederalIncomeTax;
    double StateIncomeTax;
    int ExtraHealthInsurance;
    double NetPay;

    // input
    cout << "Please enter the number of hours worked in a week." << endl;
    cin >> Hours;
    cout << "Please enter the number of dependents." << endl;
    cin >> Dependents;

    // calculate for gross pay
    if(Hours > 40){
        GrossPay =  (40 * PayRate) + ( (Hours - 40)*PayRate*1.5 );
    }else{
        GrossPay = Hours * PayRate;
    }

    // calculate for each withholding amount
    SocialSecurityTax = GrossPay * SocialSecurityTaxRate;
    FederalIncomeTax = GrossPay * FederalIncomeTaxRate;
    StateIncomeTax = GrossPay * StateIncomeTaxRate;

    // Calculate for dependents
    if(Dependents >= 3)
    {
        ExtraHealthInsurance = 35;
    }

    // Calculate for the net take-home pay for the week
    NetPay = GrossPay - SocialSecurityTax - FederalIncomeTax - StateIncomeTax - UnionDues - ExtraHealthInsurance;

    // Output
    cout << endl;
    cout << "----------------Employee Pay Instructions----------------" << endl;
    cout << "The number of hours worked in a week     = " << Hours << endl;
    cout << "The number of dependents                 = " << Dependents << endl;
    cout << "The worker's gross pay                   = " << GrossPay << endl;
    cout << "Each withholding amount." << endl;
    cout << "  ->Social Security Tax                  = " << SocialSecurityTax << endl;
    cout << "  ->Federal Income Tax                   = " << FederalIncomeTax << endl;
    cout << "  ->State Income Tax                     = " << StateIncomeTax << endl;
    cout << "  ->Union Dues                           = " << UnionDues << endl;
    cout << "  ->The extra cost of health insurance   = " << ExtraHealthInsurance << endl;
    cout << "The net take-home pay for the week       = " << NetPay << endl;
    cout << "---------------------------------------------------------" << endl;

    return 0;
}

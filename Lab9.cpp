#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



class CalculatePayment
{
protected:
    double basesalary;
    double bonus;
public:
   double Salaries(double wages);
   double Hours(double wages, int hours);
   double Commission(double wages, int sales);
};

double CalculatePayment::Salaries(double wages)
{
       basesalary = wages * 40;
       bonus = (basesalary * 10 ) / 100;
       return double (basesalary + bonus);
}

double CalculatePayment::Hours(double wages, int hours)
{
       if (hours > 40)
         return double ( ((hours - 40) * (wages * 2)) + (40 * wages));
       else
        return double (hours * wages);
}

double CalculatePayment::Commission(double wages, int sales)
{
       return double (( (sales * 10) /100 ) + wages);
}


int main()
{
    string firstname[5];
    string lastname[5];
    string status[5];
    int hours[5];
    int sales[5];
    double wages[5];
    double pay[5];
    char answer;

      for (int i = 0; i < 5; i++)
          {
            cout << "-------------" << i+1 << "-------------" << endl;
            cout << "Enter first name: ";
            cin >> firstname[i];
            cout << "Enter last name: ";
            cin >> lastname[i];
            cout << "Enter status: ";
            cin >> status[i];
            cout << "Enter hours: ";
            cin >> hours[i];
            cout << "Enter sales: ";
            cin >> sales[i];
            cout << "Enter wages: ";
            cin >> wages[i];
          }

      for (int i = 0; i < 5; i++)
          {

             CalculatePayment Payment;

             if (status[i].substr(0,1) == "S")
                 {
                      pay[i] = Payment.Salaries(wages[i]);
                 }
             else if (status[i].substr(0,1) == "H")
                 {
                      pay[i] = Payment.Hours(wages[i], hours[i]);

                 }
             else if (status[i].substr(0,1) == "C")
                 {
                      pay[i] = Payment.Commission(wages[i], sales[i]);
                 }


                  if (i == 0)
                  {
                      // print title
                  cout<< "------------------------------- Employee Report Instructions -------------------------------" << endl;
                  cout<< "Name" << setw(18.5) << "Status" << setw(18.8) << "Hours" << setw(19) << "Sales" << setw(19.5) << "Wages" << setw(19.9) << "Pays" << endl;
                  }

                  cout<< firstname[i] << " " << lastname[i] << setw(15) << status[i] << setw(16) << hours[i] << setw(17) << "$" << sales[i] << setw(18) << fixed << setprecision (2) << "$"<< wages[i] << setw(19) << fixed << setprecision (2) << "$" << pay[i] << endl;


          }
}

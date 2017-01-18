#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


    static double InputMoney;
    static int NoPotato = 2;
    static int NoCookies = 3;
    static int NoCandies = 3;
    static int Choice;
    static double PricePotato = 1.25;
    static const double PriceCookies = 0.85;
    static const double PriceCandies = 0.95;
    static int SelectSoldOut;



void ShowItem()
{
            // Show items of vending machine
                cout << "It is a pleasure to serve you." << endl;
                cout << "1. Patato chips  Price $" << PricePotato  << "  avaliable " << NoPotato  << " packs" << endl;
                cout << "2. Cookies       Price $" << PriceCookies << "  avaliable " << NoCookies << " packs" << endl;
                cout << "3. Candies       Price $" << PriceCandies << "  avaliable " << NoCandies << " packs" << endl << endl;
}

void Welcome()
{

        int NoQuarter;
        int NoDime;
        int NoNickel;
            // Show items of vending machine

                cout << "\n-------------- Welcome to Snack Factory --------------" << endl;

                ShowItem();

            // Enter the money

                cout << "Please prepare your coins." << endl;
                cout << "Enter number of quarters : ";
                cin  >> NoQuarter;
                cout << "Enter number of dimes : ";
                cin  >> NoDime;
                cout << "Enter number nickels : ";
                cin  >> NoNickel;
                InputMoney = InputMoney + (NoQuarter*.25) + (NoDime*.10) + (NoNickel*.05);
                cout << "=>>> Your have inserted $" << InputMoney << endl << endl;
}

int ChoiceResult(double Price, double Stock)
{
    // Enough money to buy Potato chips

         if(InputMoney >= Price)
          {
               if (Stock > 0)
                  {
                        InputMoney = InputMoney - Price;
                        NoPotato = Stock - 1;
                        SelectSoldOut = 0;
                        cout << "=>>> Please take your a(food)" << endl << endl;


                   }else
                   {
                        cout << "Sold out. Please make another choice." << endl << endl;
                        SelectSoldOut = 1;
                   }

            }

             else
            {
                cout << "=>>> Your money is not enough to buy potato chips." << endl << endl;
                SelectSoldOut = 0;
             }

             return SelectSoldOut;
}

int Purchase()
{
                  // Show items list
                  ShowItem();


                cout << "Please enter number of snack that you would like to buy : ";
                cin  >> Choice;

                    if (Choice == 1)
                    {
                        return ChoiceResult(PricePotato, NoPotato);

                    }

                    else if(Choice == 2)
                    {
                        return ChoiceResult(PriceCookies, NoCookies);

                    }

                    else if(Choice == 3)
                    {

                        return ChoiceResult(PriceCandies, NoCandies);

                    }else
                    {
                         cout << "Your choice does not exist. Please make another choice." << endl << endl;
                         SelectSoldOut = 0;

                    }

                    return (SelectSoldOut);

}

void ShowBalance()
{
     int BalanceQ;
     int BalanceD;
     double BalanceN;

                if ( InputMoney > 0 )
                 {
                     BalanceQ = InputMoney / 0.25;
                     InputMoney = InputMoney - (BalanceQ * 0.25);
                     BalanceD = InputMoney / 0.10;
                     InputMoney = InputMoney - (BalanceD * 0.10);
                     BalanceN = InputMoney / 0.05;

                     cout << "=>>> Please take your balance." << endl;
                     cout <<  setw (6) << BalanceQ << "  Quarter" << endl;
                     cout <<  setw (6) << BalanceD << "  Dime" << endl;
                     cout <<  setw (6) << BalanceN << "  Nickel" << endl << endl;

                 }else{
                        cout << "=>>> Your balance is 0." << endl << endl;
                 }
}



int main()
{
     char Answer;


do{

      // Show what we have and ask user to insert money
      Welcome();


            do{

                // Show what we have and ask user to insert money
                Purchase();

                }
            while( SelectSoldOut == 1 );

                // Show balance to user
                ShowBalance();

                //
                cout << "=>>> Do you want to buy more snack?" << endl;
                cout << "If yes, please type Y." << endl;
                cout << "If no, please type any key." << endl;
                cin  >> Answer;


} while((Answer=='y')||(Answer=='Y'));

        cout << "---Thank you for your purchase. See you again soon.---" << endl;

    return 0;

}




#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <iterator>


using namespace std;


int main()
{
        int num_rows;
        int num_cols = 3;
        int count_column;
        vector<vector<string> > table;
        string input;
        string dataIntoArray;
        double cost;
        double totalCost;

        cout << "How many record's number of your call history? ";
        cin >> num_rows;
        cin.ignore();

        table.resize(num_rows);
        for (int i = 0; i < num_rows; i++)
        {
            table[i].resize(num_cols);

        }



        cout << "Please prov/usride the call history detail." << endl;


            for (int i = 0; i < num_rows; i++)
            {
                //std::getline (std::cin,input);
                cout << i+1 << " record history detail: ";
                //cin.ignore( 256, '\n') ;
                getline(cin , input) ;
                std::string str = input;
                std::istringstream buf(str);
                std::istream_iterator<std::string> beg(buf), end;

                std::vector<std::string> tokens(beg, end); // done!

                // spilt each value into array
                count_column = 0;
                for(auto& s: tokens)
                {
                    //std::cout << '"' << s << '"' << '\n';
                    //table[num_rows][column_count] = s;

                    dataIntoArray = s;
                    table[i][count_column] = dataIntoArray;
                    count_column++;
                }

                int hour;
                int startHour;
                int endHour;
                int startMin;
                double costBeforeMidnight;
                double costAfterMidnight;
                double costBeforeEight;
                double costAfterEight;
                double costAfterEightteen;
                double costBeforeEightteen;



                 startHour = std::stoi(table[i][1].substr(0,2));
                 endHour= startHour + ((std::stoi(table[i][2])/60));


                 endHour= startHour + ((std::stoi(table[i][2])/60));
                // calculate for the cost of each record
                if (table[i][0].substr(0,2) == "Fr")
                {
                       startHour = std::stoi(table[i][1].substr(0,2));
                       endHour= startHour + ((std::stoi(table[i][2])/60));
                       if (endHour >= 24)
                       {
                          startMin = std::stoi(table[i][1].substr(3,2));
                          costBeforeMidnight = ((((24 - (startHour + 1))*60) + ( 60 - startMin) )* 25) /100;
                          costAfterMidnight = (((std::stoi(table[i][2]) - ((24 - (startHour + 1))*60) + ( 60 - startMin) )) * 15)/100;
                          table[i][3] = costBeforeMidnight + costAfterMidnight;
                       }

                      else
                      {
                             if ((startHour >= 8) || (endHour <= 18))
                                {
                                    table[i][3] = to_string(( (std::stod(table[i][2]) )* 40)/100);
                                }

                           else {
                                     table[i][3] = to_string(((std::stod(table[i][2])) * 25) /100);
                                }

                      }


                }



                else if (table[i][0] == "Su")
                {
                       startHour = std::stoi(table[i][1].substr(0,2));
                       if ( (std::stoi(table[i][1].substr(3,2))) + std::stoi(table[i][2]) > 60 )
                         {
                               endHour= (startHour + ((std::stoi(table[i][2])/60)) ) + 1;
                         }else
                         {
                               endHour= startHour + ((std::stoi(table[i][2])/60));
                         }

                       if (endHour >= 24)
                       {

                              startMin = std::stoi(table[i][1].substr(3,2));
                              costBeforeMidnight = ((((24 - (startHour + 1))*60) + ( 60 - startMin) )* 15) ;
                              costAfterMidnight = ( (( ((24 - (startHour + 1))*60) + ( std::stod(table[i][2]) - ( 60 - startMin) ) ))  * 25);
                               //cout << costAfterMidnight << endl;
                              table[i][3] = to_string(( costBeforeMidnight + costAfterMidnight ) / 100);
                       }

                      else
                        {
                              if ((startHour >= 8) and (endHour <= 18))
                               {
                                   table[i][3] = to_string((std::stod(table[i][2]) * 40)/100);
                               }


                               else
                               {
                                    table[i][3] = to_string((std::stod(table[i][2]) * 25)/100);
                               }


                        }


                }


                else if ((table[i][0] == "Mo")||(table[i][0] == "Tu")||(table[i][0] == "We")||(table[i][0] == "Th"))
                {

                      if ( (std::stoi(table[i][1].substr(3,2))) + std::stoi(table[i][2]) > 60 )
                     {
                           endHour= (startHour + ((std::stod(table[i][2])/60)) ) + 1;
                     }else
                     {
                           endHour= startHour + ((std::stod(table[i][2])/60));
                     }


                     if ((startHour >= 8) and (endHour < 18))
                    {



                           //float cost = ((std::stof(table[i][2]) * 40)/100);

                           //cout << "monday = " << cost<< endl;

                           table[i][3] = to_string((std::stod(table[i][2]) * 40)/100);


                    }

                    else
                    {


                        if (startHour < 8)
                        {

                          endHour= startHour + ((std::stoi(table[i][2])/60));
                          startMin = std::stoi(table[i][1].substr(3,2));
                          costBeforeEight = ((((8 - (startHour + 1) )*60) + ( 60 - startMin) )* 25) ;
                          costAfterEight = (((((8 - (startHour + 1))*60) + ( 60 - startMin) )) * 40);
                          table[i][3] = to_string( (costBeforeEight + costAfterEight ) / 100 );

                        }
                        else if (endHour >= 18)
                        {
                          //endHour= startHour + ((std::stoi(table[i][2])/60));
                          startMin = std::stoi(table[i][1].substr(3,2));
                          costBeforeEightteen = (((((startHour + 1) - 18)*60) + ( 60 - startMin) )* 40);
                          costAfterEightteen = ((((((startHour + 1) - 18)*60) + ( std::stod(table[i][2])  -  ( 60 - startMin) ) )) * 25);
                          table[i][3] = to_string( ( costBeforeEightteen + costAfterEightteen) / 100 );




                        }






                    }
                }

                else if  (table[i][0] == "Sa")
                {
                      table[i][3] = to_string((std::stod(table[i][2]) * 15)/100);
                }

               totalCost = totalCost + (std::stod(table[i][3].substr(0,5)));


            }



              for (int i = 0; i < num_rows; i++)
          {
                  if (i == 0)
                  {
                      // print title
                      cout<< "Day" << setw(10) << "Time" << setw(16) << "Duration" << setw(23) << "Cost" << endl;
                  }

                cout<< table[i][0] << setw(12) << table[i][1] << setw(13) << table[i][2] << setw(21) <<"$ " << table[i][3].substr(0,5) << endl;

                 if (i == (num_rows -1) )
                  {
                      cout<< setw(14) << "Total" << setw(21) << "$ " << totalCost << endl;
                  }
            }



    return 0;

}

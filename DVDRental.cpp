//: DVDRental.cpp

/*
Title: DVDRental.cpp
Description: Program that creates a DVD class with functions to help display a DVD catalougue text file, make rental selections, output the total cost, and display the new DVD cataloge after purchase.
Date: January 14, 2021
Author: Pawan Iyer
Version: 1.0
Copyright: 2021 Pawan Iyer
*/

/*
Program Purpose:
Write a program to manage DVD rental in a video rental store. Create
an abstract data type that represents a DVD in this store. Consider all
the data and operations that may be necessary for the DVD type to
work well within a rental management system. Include a print()
member function that displays all the information about the DVD. Test
your data type by creating an array of ten DVD instances and filling
them using information read from a test input file that you create.
Display the DVD information.
*/

#include <iostream>
#include <fstream>
using namespace std;

class DVD
{
    string dvd_name;
    string genre;
    int price_per_day;
    bool stock;
    
public:
    DVD()   //Constructor
    {
        dvd_name = "";
        genre = "";
        price_per_day = 0;
        stock = false;
    }

    void setInfo(string d, string g, int p, bool inventory)    //Function to set values of DVD name, genre, price per day, and whether DVD is in stock or not.
    {
        dvd_name = d;
        genre = g;
        price_per_day = p;
        stock = inventory;
    }

    void print()    //Function to print
    {
        cout << "DVD Title: " << dvd_name << "\tGenre: " << genre << "\tPrice/Day: $" << price_per_day << "\tIn Stock? (1:Yes / 0:No): " << stock << endl;
    }

    int rental(int num_days)  //Function to rent DVD's and specify how many days you want to rent each DVD.
    {
        if(dvd_name.empty() == true)
        {
            return 0;
        }
        stock = false;
        return num_days*price_per_day;
    }
};

int main(); //Initializer

int main()
{
    int price_per_day;
    int total_cost = 0;
    string dvd_name;
    string genre;
    
    DVD arr[10];    //Instance of array

    ifstream in("TMA2Question1.txt"); //Opens the inputted text file, and starts reading

    for(int i = 0; i < 10; ++i) //Loops thorough array to read the text file of DVD's
    {
        in >> dvd_name >> genre >> price_per_day;   //Reading the file
        arr[i].setInfo(dvd_name,genre,price_per_day,true);  //Set the information at given index on array
    }

    std::cout << "DVD Rental Catalog (Before Purchase):" << std::endl;  //Statement to indicate DVD Catalog is being printed (before purchases are made)

    for(int j = 0; j < 10; ++j) //Loops through array to print DVD's before any rentals are made.
    {
        arr[j].print();
    }

    total_cost = total_cost + arr[9].rental(4);   //Use the lines beside to rent DVD's. Using the statement "total_cost = total_cost + arr[x].rental(y);" where x is index of the array (which DVD), and y is the # of days you want to rent the DVD.
    total_cost = total_cost + arr[4].rental(8);   //Each line, rents a DVD, and also adds the cost of renting to the total_cost variable.
    total_cost = total_cost + arr[6].rental(3);   //Few example lines have been used to the left.
    total_cost = total_cost + arr[3].rental(5);
    total_cost = total_cost + arr[1].rental(2);

    std::cout<< "\n" <<"Total Cost of Purchase (After Rent Commands): $"<<total_cost<<"\n\n";    //Statement to show the total cost of rented DVDs.

    std::cout << "DVD Rental Catalog (After Purchase):" << std::endl;   //Statement to indicate DVD Catalog is being printed (after purchases are made)

    for(int k = 0; k < 10; ++k) //Loops thorough array to print DVD's after rentals have been made. This shows which DVD's are left in stock.
    {
        arr[k].print(); 
    } 
    return 0;
}

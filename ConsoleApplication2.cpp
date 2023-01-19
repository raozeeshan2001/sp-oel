#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include<direct.h>
#include <iostream>
#include <ctime>
#include "OEL.h"
#include <fstream>
#include <string.h>
#include <string>

using namespace std;
void copy(string path) {

    string myText;


    ifstream MyReadFile(path + "/file1.txt");
    ofstream MyFile("C:/Users/lenovo/OneDrive/Desktop/OEL/secondFile.txt");

    while (getline(MyReadFile, myText)) {
        MyFile << myText, ios::app;
    }

    MyReadFile.close();
}

void del(string path) {
    ofstream fout;
    ifstream fin;
    fin.open(path + "/file1.txt");
    fout.open(path + "/file1.txt");
    if (fin.is_open())
        fout << "";

    fin.close();
    fout.close();
}

void task1(string user) {

    string filepath = "C:/Users/lenovo/OneDrive/Desktop/OEL/" + user;
    if (_mkdir(filepath.data()) == -1)
        cout << "Error Occured";
    else
        cout << "Directory Created";
    ofstream MyFile(filepath + "/file1.txt");
    string enrollment;
    cout << "\nInput Your Enrollment Number: ";
    cin >> enrollment;
    MyFile << user << "     " << enrollment;
    MyFile.close();


    copy(filepath);     //Copy Content in The Second File
    del(filepath);      //Delete Content of The Second File


}

int main()
{
    string username;

    try
    {
        cout << "Input Your Name: ";
        cin >> username;

        task1(username);
    }
    catch (const char* msg)
    {
        cout << "Error Occured!!!!" << msg;
    }
}





//Task:2
#include <string>
#include <iostream>
using namespace std;

int main()
{
    try
    {
        string input;

        cout << "Would you like to input? (y/n): ";
        cin >> input;
        if (input != "y")
        {
            throw string("exception ! error");
        }
    }
    catch (string e)
    {
        cout << e << endl;
    }
}





//Task 3
#include <iostream>
#include "Header.h"
#include <string.h>
#include <stdio.h>

int main()
{
    double num;
    std::cout << "Input The Price to Calculate the Tax: ";
    std::cin >> num;
    double ans = calculate(num);
    if (ans == 0)
    {
        std::cout << "\nAmount Less Than 300";
    }
    std::cout << "\nAmount after Task Deductionans: " << ans;
}
Library Code :
#pragma once
double calculate(double price) {
    double Tax = 145.00;
    double TransactionFee = 100;
    if (price > 300)
    {
        return (price - Tax - TransactionFee);
    }
    else {
        return 0;
    }

}






// Task 4
#include <string>
#include <iostream>
#include <thread>

using namespace std;

void calculator() {
    system("calc");
}
void chrome() {
    system("start chrome");
}
int main()
{

    std::thread worker1(calculator);
    std::thread worker2(chrome);


    thread::id t1_id = worker1.get_id();
    thread::id t2_id = worker2.get_id();

    cout << "\nID associated with thread1= "
        << t1_id << endl;
    cout << "\nID associated with thread2= "
        << t2_id << endl;

    worker1.join();
    worker2.join();

}

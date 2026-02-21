#include <iostream>
#include <fstream>
#include <string>
#include "PacketManager.h"
using namespace std;

int main()
{
    string filename;
    ifstream fin;

    do
    {
        cout << "Enter the name of the input file: ";
        cin >> filename;

        fin.open(filename);

        if (!fin)
        {
            cout << "ERROR: The file " << filename << "does not exist!!" << endl;
            cout << "Re-enter the input file name: ";
        }
    } while (!fin);

    PacketManager p1(fin);
    fin.close();

    cout << endl;
    cout << "Packets originally read from the file are:" << endl;
    p1.displayPackets();

    p1.extractMessage();

    p1.displayMessage();

    cout << endl;
    return 0;
}
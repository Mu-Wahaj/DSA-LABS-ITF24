#include "PacketManager.h"
#include <cstring>

PacketManager::PacketManager(ifstream &fin)
{
    fin >> numPackets;
    fin.ignore();

    packets = new Packet[numPackets];

    for (int i = 0; i < numPackets; i++)
    {
        fin >> packets[i].position;
        fin.ignore();
        fin.getline(packets[i].body, PACKET_SIZE + 1);
    }

    message = NULL;
    msgLength = 0;
}

PacketManager::~PacketManager()
{
    if (packets != NULL)
    {
        delete[] packets;
    }
    if (message != NULL)
    {
        delete[] message;
    }
}

void PacketManager::displayPackets() const
{
    for (int i = 0; i < numPackets; i++)
    {
        cout << packets[i].position << " " << packets[i].body << endl;
    }
}

void PacketManager::sortPacketsBubbleSort()
{
    for (int i = 0; i < numPackets - 1; i++)
    {
        for (int j = 0; j < numPackets - i - 1; j++)
        {
            if (packets[j].position > packets[j + 1].position)
            {
                Packet temp = packets[j];
                packets[j] = packets[j + 1];
                packets[j + 1] = temp;
            }
        }
    }
}

void PacketManager::sortPacketsSelectionSort()
{
    for (int i = 0; i < numPackets - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < numPackets; j++)
        {
            if (packets[j].position < packets[minIndex].position)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Packet temp = packets[i];
            packets[i] = packets[minIndex];
            packets[minIndex] = temp;
        }
    }
}

void PacketManager::extractMessage()
{
    char choice;
    cout << "Which sorting algorithm do you want to use?" << endl;
    cout << "Enter 'B' or 'b' for Bubble sort" << endl;
    cout << "Enter 'S' or 's' for Selection sort" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 'B' || choice == 'b')
    {
        sortPacketsBubbleSort();
    }
    else if (choice == 'S' || choice == 's')
    {
        sortPacketsSelectionSort();
    }
    else
    {
        cout << "Invalid choice! Using Bubble sort by default." << endl;
        sortPacketsBubbleSort();
    }

    int lastPacketLength = strlen(packets[numPackets - 1].body);
    msgLength = (numPackets - 1) * PACKET_SIZE + lastPacketLength;
    message = new char[msgLength + 1];

    int index = 0;
    for (int i = 0; i < numPackets; i++)
    {
        for (int j = 0; packets[i].body[j] != '\0'; j++)
        {
            message[index++] = packets[i].body[j];
        }
    }
    message[index] = '\0';

    cout << "The order of packets after extracting the message:" << endl;
    displayPackets();
}

void PacketManager::displayMessage() const
{
    if (message != NULL)
    {
        cout << "The extracted message is:" << endl;
        cout << message << endl;
    }
    else
    {
        cout << "Error: Message has not been extracted yet!" << endl;
    }
}
#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <iostream>
#include <fstream>
using namespace std;

const int PACKET_SIZE = 5;

struct Packet {
    int position;
    char body[PACKET_SIZE + 1];
};

class PacketManager {
private:
    Packet* packets;
    int numPackets;
    char* message;
    int msgLength;
    
    void sortPacketsBubbleSort();
    void sortPacketsSelectionSort();
    
public:
    PacketManager(ifstream& fin);
    ~PacketManager();
    void displayPackets() const;
    void extractMessage();
    void displayMessage() const;
};

#endif
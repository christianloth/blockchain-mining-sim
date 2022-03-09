/* CELEBU10

   This example reads an unsigned int and formats it to decimal,
   octal, hexadecimal constants converted to a character string.

*/

#define _OPEN_SYS_ITOA_EXT
#include <string>
#include <iostream>
#include <sstream>
#include "sha256.h"


using namespace std;


std::string int2string(int number) {
    std::stringstream ss;//create a stringstream
    ss << number;//add number to the stream
    return ss.str();//return a string with the contents of the stream
}

int main() {

    int nonce = 0;
    string word = "Transaction ID";
    string hash = "";

    cout << "Enter a difficulty: ";
    int difficulty;
    cin >> difficulty;
    cout << endl;

    stringstream ss;
    for (int i = 0; i < difficulty; i++) {
        ss << "0";
    }

    auto startTime = std::chrono::system_clock::now(); // Start time

    while(hash.substr(0, difficulty) != ss.str()) { // while the hash doesnt start with proper amount of zeros
        nonce++;
        hash = sha256(word + int2string(nonce));
    }
    auto endTime = std::chrono::system_clock::now(); //End time
    std::chrono::duration<double> totalTime = endTime - startTime; //Calculate time took with difference
    double msTime = totalTime.count() * 1000; //Convert to milliseconds

    cout << "Nonce: " << nonce << endl;
    cout << "Hash: " << hash << endl;
    cout << "Time: " << msTime << " ms" << endl;
    return 0;
}


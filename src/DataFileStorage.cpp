#include "DataFileStorage.h"
#include "Action.h"
#include <sys/stat.h>
/**
 *  \file    DataFileStorage.cpp
 *  \author  RTT
 *  \date    7/03/2017
 *  \version 1.0
 *
 *  \brief Contains all the functions used to store the game and actions of the players.
 *
 */
DataFileStorage::DataFileStorage() {
}

DataFileStorage::~DataFileStorage() {
}


// \brief Create a new file to store games
void DataFileStorage::newDataFile() {
    ofstream dataFileOut;
    dataFileOut.open("DataFromPlays.csv");
    dataFileOut.close();
}

/* \brief Create a new file to store games and give it a specified name
* \param name Name of the file
*/
void DataFileStorage::newDataFile(string name) {
    ofstream dataFileOut;
    dataFileOut.open(name);
    dataFileOut.close();
}

// \brief Open a file storing games
void DataFileStorage::openDataFile() {
    ofstream dataFileOut;
    dataFileOut.open("test.txt");
    dataFileOut << "test du 1";
    dataFileOut.close();
}

/* \brief Open a file storing games with the name in parameter
* \param Name of the file
*/
void DataFileStorage::openDataFile(string name) {
    ifstream dataFileIn;
    dataFileIn.open(name);
    dataFileIn.close();
}


void DataFileStorage::saveDataFile(){}

// \brief Check if a file exists
bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

/* \brief Save a game and it's informations
* \param movesTree The move tree of a game
* \param playerR First player (name) -> important for when it's an AI
* \param playerL Second player of the game (name) -> important for when it's an AI
*/
void DataFileStorage::saveDataFile(vector<char> movesTree , string playerR ,string playerL) {
    ifstream dataFileIn;
    ofstream dataFileOut;
    cout << "debug - test de l'appel de fonction" << endl;

    //Creating a new file
    if(!fileExists("DataFromPlays.csv")){        dataFileOut.open("DataFromPlays.csv", fstream::out);
        dataFileOut << "Creation succesful !" << endl;
    }

    else{
    dataFileOut.open("DataFromPlays.csv", fstream::in |  fstream::out | fstream::app);
        if (dataFileOut.is_open()){
        cout << "File has been opened properly";

        //Write the name of the two players
        dataFileOut << playerR+"; ";
        dataFileOut << playerL+"; ";

        //Browse the tree and display the values for each turn played
        for (vector<char>::const_iterator i = movesTree.begin(); i != movesTree.end(); ++i) {

            dataFileOut << *i << ", ";

            //These 2 lines below are now deprecated, used to transform from one value to x,y coordinates
            /*
            *char x = ceil(*i / hexBoard.getLength()), y = *i % hexBoard.getLength();
            *dataFileOut << x+y+0 << "; ";
            */
        }

        dataFileOut << "\n";
        }
        else {
            cout << "Failed to open the file :(" << endl;
        }
    }
    dataFileOut.close();
}


// \brief Verify if the game is loaded or not
bool DataFileStorage::loadGame() {
    return true;
}

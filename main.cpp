#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;


void readData(vector<int> &data)
{
    ifstream inputFile;
    inputFile.open("data.txt");
    int numberRead;

    while(!inputFile.eof())
    {
        inputFile>>numberRead;
        data.push_back(numberRead);
    }

    inputFile.close();
    cout<<"data reading from file finished\n";
}


int writeData(vector<int> &data)
{
    ofstream outputFile;
    outputFile.open("sortedData.txt");

    for(int i=0; i<data.size(); i++)
    {
        outputFile<<data[i]<<endl;
    }

    outputFile.close();
    cout<<"writing data to file finished\n";
}


void sortData(vector<int> &data)
{
    bool sorted;
    int temp;
    int index1, index2;
    int dataSize = data.size();

    do
    {
        //assume that data is sorted
        sorted = true;

        //check if data is sorted or not
        for(int i=0; i<dataSize-1; i++)
        {
            if(data[i] > data[i+1]) sorted = false;
        }

        //if data is sorted - break bogo sorting
        if(sorted) break;

        //if data is not sorted - bogo!
        for(int i=0; i<dataSize; i++)
        {
            index1 = rand()%dataSize;
            index2 = rand()%dataSize;

            temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }
    }
    while(!sorted);
    cout<<"Sorintg finished\n";
}


int main()
{
    vector<int> data;
    srand(time(NULL));

    readData(data);
    sortData(data);
    writeData(data);

    cout<<"Bogo sort finished.\n";
    system("PAUSE");
    return 0;
}

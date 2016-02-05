#include "TrainingData.h"
#include "Net.h"
#include <iostream>
#include <cassert>

using namespace ANN;

void showVectorVals(const string& label, const vector<double>& v)
{
    cout << label << " ";

    for (const auto& elem : v) 
    {
        cout << elem << " ";
    }

    cout << endl;
}

int main()
{
    TrainingData trainData("trainingData.txt");

    // e.g., { 3, 2, 1 }
    vector<int> topology;
    topology = trainData.getTopology();

    Net myNet(topology);

    vector<double> inputVals; 
    vector<double> targetVals;
    vector<double> resultVals;
    int            trainingPass = 0;

    while (!trainData.isEof()) 
    {
        ++trainingPass;
        cout << endl << "Pass:    " << trainingPass << endl;

        // Get new input data and feed it forward:
        if (trainData.getNextInputs(inputVals) != topology[0]) 
        {
            break;
        }
        showVectorVals("Inputs: ", inputVals);
        myNet.feedForward(inputVals);

        // Collect the net's actual output results:
        resultVals = myNet.getResults();
        showVectorVals("Outputs:", resultVals);

        // Train the net what the outputs should have been:
        trainData.getTargetOutputs(targetVals);
        showVectorVals("Targets:", targetVals);
        assert(targetVals.size() == topology.back());

        myNet.backProp(targetVals);

        // Report how well the training is working, average over recent samples:
        cout << "-----------------------------------" << endl;
        cout << "Net recent average error: " << myNet.getRecentAverageError() << endl;
        cout << "-----------------------------------" << endl;
    }

    cout << endl << "Done" << endl;
}

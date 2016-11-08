#ifndef NEURON_H
#define NEURON_H

#include <vector>

namespace ANN
{
	struct Connection
	{
		double weight = rand() / double(RAND_MAX);
		double deltaWeight;
	};

	class Neuron;
	typedef std::vector<Neuron> Layer;

	class Neuron
	{
	public:
		Neuron(int numOutputs, int myIdxL);
		void   activate(const Layer& prevLayer);
		void   calcOutputGradients(const double target);
		void   calcHiddenGradients(const Layer& nextLayer);
		void   updateInputWeights(Layer& prevLayer);

        void   setOutput(double val) { output_ = val;  }
        double output() const        { return output_; }

	private:
		static double activationFunction(double x);           // for forward  propagation
		static double activationFunctionDerivative(double x); // for backward propagation

		       double sumDOW(const Layer& nextLayer) const;

        static double           rate;     // [0.0, 1.0] overall net learning rate
        static double           momentum; // [0.0, n] multiplier of last weight change (momentum)
               double           output_;
		       double           gradient_;
        const  int              idxL_;
        std::vector<Connection> axon_;
	};
}

#endif // NEURON_H

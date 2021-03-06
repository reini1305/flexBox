#ifndef flexL2dualizedOperator_H
#define flexL2dualizedOperator_H

#include "flexTermDual.h"
#include "flexBasicDualizedOperator.h"

template < typename T >
class flexL2dualizedOperator : public flexBasicDualizedOperator<T>
{
	public:
		flexL2dualizedOperator(T _alpha, int numberPrimals, flexVector<flexMatrix<T> > _operatorList) : flexBasicDualizedOperator<T>(_alpha, numberPrimals, _operatorList){};

		void applyProx(flexBoxData<T> &data, flexVector<T> sigma, flexVector<int> dualNumbers, flexVector<int> primalNumbers)
		{
			for (int i = 0; i < dualNumbers.size(); ++i)
			{
				T factor = this->alpha / (this->alpha + sigma[dualNumbers[i]]);

				// should be data.y[dualNumbers[i]] = data.yTilde[dualNumbers[i]] * factor;
				data.y[dualNumbers[i]] = data.yTilde[dualNumbers[i]];
				data.y[dualNumbers[i]] *= factor;
			}
		
		};
};

#endif
#include "Epsilon.h"

namespace appcore {
    namespace Epsilon
    {
        double compute()
        {
            double e = 0.5;
            while (1.0 + e > 1.0) {
                e *= 0.5;
            }
            return e;
        }
    }
}
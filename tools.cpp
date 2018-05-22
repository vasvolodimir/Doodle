#include "tools.h"

double Tools::distance(double x1, double y1, double x2, double y2)
{
    double statment = (x2 - x1) * (x2 - x1) + (y2 - y1) + (y2 - y1);
    return pow(statment, 0.5);
}

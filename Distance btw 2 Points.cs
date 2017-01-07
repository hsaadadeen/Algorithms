using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Distance_Bet_Two_Points
{
    class Distance
    {
        public double PointsDistance(double x1, double y1, double x2, double y2)
        {
            double distance;

            distance = Math.Sqrt (Math.Pow((x1 - x2), 2) + Math.Pow((y1 - y2), 2));

            return distance;
        } // end method PointsDistance
    } // end class Distance
}

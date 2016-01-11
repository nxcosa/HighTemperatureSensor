#include "HighTemp.h"
HighTemp::HighTemp()
{
	vref = 5.000;
}

HighTemp::HighTemp(float v)
{
	vref = v;
}

HighTemp::~HighTemp()
{
	
}
int HighTemp::getTemp(int PIN)
{
    int i = analogRead(PIN);
    float voltage = 0,res = 0;
    voltage = i * vref / 1023;
    // res =  (1800 * voltage + 235.9 * 18) / (2.359 * 18 - voltage);
	res =  (1800 * voltage + 220.9 * 18) / (2.209 * 18 - voltage);
    int front = 0, end = 0, mid = 0;
    front = 0;
    end = 399;
    mid = (front + end) / 2;

    while (front < end && pgm_read_float(&PT100Tab[mid]) != res)
        {
            if (pgm_read_float(&PT100Tab[mid]) < res)
                if (pgm_read_float(&PT100Tab[mid + 1]) < res)
                    front = mid + 1;
                else
                    {
                        mid = comp(res, mid);
                        return mid;
                    }
            if (pgm_read_float(&PT100Tab[mid]) > res)
                if (pgm_read_float(&PT100Tab[mid - 1]) > res)
                    end = mid - 1;
                else
                    {
                        mid = comp(res, mid - 1);
                        return mid;
                    }
            mid = front + (end - front) / 2;
        }
    return mid;
}
int HighTemp::comp(float pt, int i)
{
    if ((pt - pgm_read_float(&PT100Tab[i])) > (pgm_read_float(&PT100Tab[i + 1]) - pgm_read_float(&PT100Tab[i])) / 2 )
        return i + 1;
    else
        return i;
}

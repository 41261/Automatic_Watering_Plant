/* 
    AUTOMATIC WATERING PLANT

    Kelompok 2:
    - Audrey Asokawati (1801165)
    - Muhammad Argi Nafisa (1800066)
*/

#include <stdio.h>

void main() {

    printf("Automatic Watering Plant\n");
    printf("v1.0\n\n");
    float inpud; // Sensor dari moisture sensor (%)
    float numerator, denominator;
    float moist[5] = {30, 40, 50, 60, 70}; // Kelembapan
    float flush[5] = {10, 8, 4, 6, 2}; // Banyaknya penyiraman air
    float degree[5] = {0.00, 0.00, 0.00, 0.00, 0.00};
    float res; // hasil output

    printf("Soil moisture: ");
    scanf("%f", &inpud);
    
    // ------------------------------------ Derajat keanggotaan 1
    if(inpud <= moist[0]) {
        degree[0] = 1;
    }
    if(inpud > moist[0] && inpud < moist[1]) {

        numerator = moist[1] - inpud;
        denominator = moist[1] - moist[0];
        degree[0] = numerator / denominator;
    }

    // ------------------------------------ Derajat keanggotaan 2
    if(inpud > moist[0] && inpud <= moist[1]) {

        numerator = inpud - moist[0];
        denominator = moist[1] - moist[0];
        degree[1] = numerator / denominator;
    }
    if(inpud > moist[1] && inpud < moist[2]) {

        numerator = moist[2] - inpud;
        denominator = moist[2] - moist[1];
        degree[1] = numerator / denominator;
    }

    // ------------------------------------ Derajat keanggotaan 3
    if(inpud > moist[1] && inpud <= moist[2]) {

        numerator = inpud - moist[1];
        denominator = moist[2] - moist[1];
        degree[2] = numerator / denominator;
    }
    if(inpud > moist[2] && inpud < moist[3]) {

        numerator = moist[3] - inpud;
        denominator = moist[3] - moist[2];
        degree[2] = numerator / denominator;
    }

    // ------------------------------------ Derajat keanggotaan 4
    if(inpud > moist[2] && inpud <= moist[3]) {

        numerator = inpud - moist[2];
        denominator = moist[3] - moist[2];
        degree[3] = numerator / denominator;
    }
    if(inpud > moist[3] && inpud < moist[4]) {

        numerator = moist[4] - inpud;
        denominator = moist[4] - moist[3];
        degree[3] = numerator / denominator;
    }

    // ------------------------------------ Derajat keanggotaan 5
    if(inpud >= moist[4]) {

        degree[4] = 1;
    }
    if(inpud > moist[3] && inpud < moist[4]) {

        numerator = moist[4] + inpud;
        denominator = moist[4] - moist[3];
        degree[4] = numerator / denominator;
    }


    // ------------------------------------ Defuzzification Process
    int stat = 0, count = 0, stop = 0;
    int num1 = 0, num2 = 0, stop2 = 0;

    for(int i = 0; i < 5; i++) {

        if(stop == 0 && degree[i] == 1) {

            count = i;
            stop = 1;
            stat = 1;
        }
        else if(stop != 1 && degree[i] > 0) {

            if(stop2 != 0) {
                num2 = i;
                stop = 1;
            }
            else{
                num1 = i;
                stop2 = 1;
            }
        }
    }

    // ------------------------------------ Average Weight Process
    if(stat != 0) {

        printf("Flushing water: %0.f Cc\n", flush[count]);
    }
    else {

        float numerator1 = degree[num1] * flush[num1];
        float numerator2 = degree[num2] * flush[num2];
        numerator = numerator1 + numerator2;
        denominator = degree[num1] + degree[num2];
        res = numerator /denominator;

        printf("Flushing water: %0.f Cc\n", res);
    }
}

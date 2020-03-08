#include <math.h>
#include "pav_analysis.h"
#define Abs(x) (x>0 ? x:-x);

float compute_power( const float *x , unsigned int N){
    float power=0;
    for (int i=0;i<N;i++){
        power= power + (x[i]*x[i]);
    }
    power= 10*log10(power/N);
    return power;
}
float compute_am( const float *x, unsigned int N){
    float am=0;
    for (int i=0;i<N;i++){
        am=am + Abs(x[i]);
    }
    am=am/N;
    return am;
}
float compute_zcr(const float *x, unsigned int N, float fm){
    float zcr=0;
    for (int i=0;i<N;i++){
        if(x[i]<0 && x[i+1]>0 || x[i]>0 && x[i+1]<0){
            zcr=zcr+1;
        }
    }
    zcr= zcr*fm/(2*(N-1));
    return zcr;
}
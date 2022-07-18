#include "templatedesign.h"



float templateDesign :: random(){
    return zeroToOne();
}

void Slc :: Rule() {
    float compare = random();
    if (compare <= Back3){
        // Do something
    }
    if (compare <= Back2){
        // Do something
    }
    if (compare <= Back1){
        // Do something
    }
    if (compare <= Forward1){
        // Do something
    }
    if (compare <= Forward2){
        // Do something
    }
    if (compare <= Forward3){
        // Do something
    }
    if (compare <= GoToDC){
        // Do something
    }
    // return for OSAP
}


void Nhall :: Rule() {
    float compare = random();
    if (compare <= neg200){
        // Do something
    }
    if (compare <= neg100){
        // Do something
    }
    if (compare <= neg50){
        // Do something
    }
    if (compare <= pos25){
        // Do something
    }
    if (compare <= pos50){
        // Do something
    }
    if (compare <= pos100){
        // Do something
    }
    // return for pos200
}



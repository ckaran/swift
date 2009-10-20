/*
 *  bin64.cpp
 *  p2tp
 *
 *  Created by Victor Grishchenko on 10/10/09.
 *  Copyright 2009 Delft University of Technology. All rights reserved.
 *
 */
#include "bin64.h"

const uint64_t bin64_t::NONE = 0xffffffffffffffffULL;
const uint64_t bin64_t::ALL = 0x7fffffffffffffffULL;
const uint32_t bin64_t::NONE32 = 0xffffffffU;
const uint32_t bin64_t::ALL32 = 0x7fffffffU;

uint32_t bin64_t::to32() const {
    if (v<0xffffffff && v!=0x7fffffff)
        return (uint32_t)v;
    if (v==ALL)
        return ALL32;
    return NONE32;
}

bin64_t bin64_t::next_dfsio (uint8_t floor) {
    /*while (ret.is_right())
        ret = ret.parent();
    ret = ret.sibling();
    while (ret.layer()>floor)
        ret = ret.left();*/
    if (is_right()) {
        return parent();
    } else {
        bin64_t ret = sibling();
        while (ret.layer()>floor)
            ret = ret.left();
        return ret;
    }
}

int bin64_t::peaks (uint64_t length, bin64_t* peaks) {
    int pp=0;
    uint8_t layer = 0;
    while (length) {
        if (length&1) 
            peaks[pp++] = bin64_t(layer,length^1);
        length>>=1;
        layer++;
    }
    for(int i=0; i<(pp>>1); i++) {
        uint64_t memo = peaks[pp-1-i];
        peaks[pp-1-i] = peaks[i];
        peaks[i] = memo;
    }
    peaks[pp] = NONE;
    return pp;
}

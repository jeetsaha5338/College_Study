////////////////////////////////////////////////////////////////////////////////
//   ____  ____   
//  /   /\/   /  
// /___/  \  /   
// \   \   \/  
//  \   \        Copyright (c) 2003-2004 Xilinx, Inc.
//  /   /        All Right Reserved. 
// /---/   /\     
// \   \  /  \  
//  \___\/\___\
////////////////////////////////////////////////////////////////////////////////

#ifndef H_Work_nand_2_and_behavioral_H
#define H_Work_nand_2_and_behavioral_H
#ifdef __MINGW32__
#include "xsimMinGW.h"
#else
#include "xsim.h"
#endif


class Work_nand_2_and_behavioral: public HSim__s6 {
public:

    HSim__s1 SE[3];

    HSim__s1 SA[1];
  char t0;
    Work_nand_2_and_behavioral(const char * name);
    ~Work_nand_2_and_behavioral();
    void constructObject();
    void constructPorts();
    void reset();
    void architectureInstantiate(HSimConfigDecl* cfg);
    virtual void vhdlArchImplement();
};



HSim__s6 *createWork_nand_2_and_behavioral(const char *name);

#endif
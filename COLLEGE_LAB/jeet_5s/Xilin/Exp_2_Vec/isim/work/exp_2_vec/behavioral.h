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

#ifndef H_Work_exp_2_vec_behavioral_H
#define H_Work_exp_2_vec_behavioral_H
#ifdef __MINGW32__
#include "xsimMinGW.h"
#else
#include "xsim.h"
#endif


class Work_exp_2_vec_behavioral: public HSim__s6 {
public:

    HSim__s1 SE[2];

  char t0;
  char t1;
  char t2;
  char t3;
  char t4;
  char t5;
  char t6;
  char t7;
  char t8;
  char t9;
  char t10;
  char t11;
  char t12;
    Work_exp_2_vec_behavioral(const char * name);
    ~Work_exp_2_vec_behavioral();
    void constructObject();
    void constructPorts();
    void reset();
    void architectureInstantiate(HSimConfigDecl* cfg);
    virtual void vhdlArchImplement();
};



HSim__s6 *createWork_exp_2_vec_behavioral(const char *name);

#endif

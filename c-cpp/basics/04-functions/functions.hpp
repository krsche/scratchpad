#pragma once
/*
  #ifndef _H_FUNCTIONS_
  #define _H_FUNCTIONS_
  
  The include guards above (commented out) and at the far bottom, work totally fine but 
  '#pragma once', although not standard, is widely supported for C & C++ and has some benefits, 
  including:
  - less code
  - avoidance of name clashes
  - improvement of compilation speed (sometimes)
  downsides of '#pragma once' are:
  - not supported everywhere
  - underlying implementation is tricky and not always reliable
*/

int add(int a, int b);

// #endif
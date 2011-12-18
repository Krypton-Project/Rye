/*

  Name: Edward Chernysh
  Copyright: Copyright (C) GNU GPL 3
  Author: Edward Chernysh
  Date: 13-12-11 18:14
  Description: Header File
               
*/



/* These files cannot be modified! They are what runs the code! */

#ifndef rye_statements_header_H
#define rye_statements_header_H

#define null (0)

        struct statements {
               const char *output;  
               const char *input;
               const char *_if;
               const char *elseif;
               const char *_else;
               const char *_do;
               const char *_while;
               const char *var;
        };       
        
        
        struct _operators {
               const char *add;
               const char *sub;
               const char *multiply;
               const char *divide;
               const char *equals;     
        };
        
        /* Keywords */
        
        struct numbers {
               const char *point;
               const char *num;
               const char *sector;
               const char *alloc;
               const char *val;
               const char *_int;
        };      
        
        struct string {
               const char *string;
               const char *var;
               unsigned const char *cchar;
               const char *txt;
               char *str;
               signed char *bit;          /* I know... I was out of names -_- */
        };
        
        struct variables {
          /* Integers */     
          int point;     
          int num;
          int sector;
          int alloc;
          int val;
          int _int;
          
          /* Strings (const char*) */
          char *string;
          char *var;
          char *cchar;
          const char *txt;
          char *str;
          signed char *bit; 
        };

#endif

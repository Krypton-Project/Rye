/*

  Name: Edward Chernysh
  Copyright: Copyright (C) GNU GPL 3
  Author: Edward Chernysh
  Date: 13-12-11 18:14
  Description: Header File
               
*/

/**
*   Copyright (C) 2011 Edward Chernysh

    This file is part of Rye.

    Rye is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Rye is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Rye.  If not, see <http://www.gnu.org/licenses/>.
    
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "include/statements.h"

int i = 0;
int n;
long elapsed_seconds;
char line[80];

void init();
int run(char *process);
FILE *file;

int main(int argc, char *argv[]) {  
    int c;    
    char** pArg;   
    if (argc < 2) {             
             printf("/**\n*\n* The Rye scripting language:\n");
             printf("* Copyright (C) 2011 Edward Chernysh\n");
             printf("* Released under the GNU General Public License v3\n");
             printf("*\n**/\n\n"); 
             printf("-h\tHelp\n");            
             system("pause");   
               
    } else {
    while (--argc > 0 && (*++argv)[0] == '-') 
          c = *++argv[0];
          struct statements statement = {
       "out",
       "in",
       "if",
       "elseif",
       "else",
       "do:",
       "while",
       "var"
       };
       
       struct _operators _operator = { "+", "-", "x", "/", "="};
       
       struct numbers number = { "point", "num", "sector", "alloc", "val", "int" };    /* Pointer structure */
       
       struct string str = {
               "string",
               "var",
               "cchar",
               "txt",
               "str",
               "bit",          /* I know... I was out of names -_- */
        };
        
       /* Huge initialization */

#ifdef INITIALIZED
 /* Skip */
#else
struct variables variable =  {
          /* Integers */     
          null,     
          null,
          null,
          null,
          null,
          null,          
          /* Strings (const char*) */
          null,
          null,
          null,
          null,
          null,
          null, 
        };
#endif 
        
       switch (c) {           
       
       case 'r':            
	        if (!strcmp(argv[0], statement.output)) {     /* String Output */                              
               if ((!strcmp(argv[1], "<<")) || (!strcmp(argv[1], "?")) ||
               (!strcmp(argv[1], "!")) || (!strcmp(argv[1], "<-")))  {
               for (i = 2; i < argc; i++)
                  printf("%s ", argv[i]);
               }
            } else if (!strcmp(argv[0], statement.input)) {  /* Character input */
                   if(!strcmp(argv[1], ">>")) {
                   char _hold;
                      _hold = getchar();              
                   }       
            } else if (!strcmp(argv[1], _operator.add)) {    /* Addition */
                   int szi;
                   szi = atoi(argv[0]) + atoi(argv[2]);
            } else if (!strcmp(argv[1], _operator.sub)) {
                   printf("%d\n",
                                 atoi(argv[0]) - atoi(argv[2]));
            } else if (!strcmp(argv[1], _operator.multiply))
            { /* Multiply */
              int product;
              product = atoi(argv[0]) * atoi(argv[2]);             
              printf("%d\n", product);              
            } 
            else if (!strcmp(argv[1], _operator.divide)) {   /* Divide */
                 float quotient;
                 quotient = atoi(argv[0]) / atoi(argv[2]);
                 printf("%4.2f\n", quotient);
            } else if ((!strcmp(argv[0], statement._if))) {    /* Manages if statement */
                   if (!strcmp(argv[2], statement._do)) {
                     int i;
                     for (i = 3; i < argc; ++i) {
                         if (!strcmp(argv[i], "start"))
                         system("rye.exe");
                         else system(argv[i]);    
                     }
                   }
            } else if ((!strcmp(argv[0], statement._if)) &&    /* Elseif */
                      (!strcmp(argv[4], statement.elseif))) {
                int i;               
                if (argc > 7) {
                   for (i = 4; i < argc; i+=4) {
                       /* */                      
                   }
                }                        
            } else if (!strcmp(argv[0], number.point)) {    /* Point */
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.point = atoi(argv[2]);                                       
                   }
                   
            } else if (!strcmp(argv[0], number.num)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.num = atoi(argv[2]);                                       
                   }
            } else if (!strcmp(argv[0], number.sector)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.sector = atoi(argv[2]);                                       
                   }
            } else if (!strcmp(argv[0], number.alloc)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.alloc = atoi(argv[2]);                                       
                   }
            } else if (!strcmp(argv[0], number.val)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.val = atoi(argv[2]);                                       
                   }
            } else if (!strcmp(argv[0], number._int)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable._int = atoi(argv[2]);                                       
                   }
            } else if (!strcmp(argv[0], str.string)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.string = (argv[2]);  
                                                               
                   }
            } else if (!strcmp(argv[0], str.var)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.var = (argv[2]);  
                                                               
                   }
            } else if (!strcmp(argv[0], str.cchar)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.cchar = (argv[2]);  
                                                               
                   }
            } else if (!strcmp(argv[0], str.txt)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.txt = (argv[2]);  
                                                               
                   }
            } else if (!strcmp(argv[0], str.str)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.str = (argv[2]);  
                                                               
                   }
            } else if (!strcmp(argv[0], str.bit)) {
                   if (!strcmp(argv[1], _operator.equals)) {
                             variable.bit = (argv[2]);  
                                                               
                   }
            } else {
                    printf("segmentation fault\n");
            }
                        
         
           break;       
           
           case 'h':            
             printf("./args---------------------------------------------\n");
             printf("\n-r [statement] <operators> [string]\n");
             system("pause");
             break;
           case 'f':
                /* Execute lines from file */
file = fopen ( argv[0], "r" );
   if ( file != NULL ) {
      char line [128]; /* or other suitable maximum line size */
 
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      { 
            system (line);
      }
      fclose ( file );
   }
   else
   {
      perror ( argv[0] ); /* why didn't the file open? */
   }
 
           break;
         default: 
                  printf("Argument does not exist\n");
         break;
             
    }
}
    return 0;
}

int run(char *process) {
    return 0;
}


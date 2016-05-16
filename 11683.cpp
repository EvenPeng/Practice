#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
   int block_height, block_width;

   while (scanf("%d %d", &block_height, &block_width)) {
       if (block_height == 0 && block_width == 0) {
           break;
       }

       int i = 0;
       int result = 0;
       int curr_height = block_height;
       for (i = 0; i < block_width; i++) {
         int top;
         scanf("%d", &top);

         if (curr_height > top) {
            result += (curr_height - top);
         }
         curr_height = top;
       }
       printf("%d\n", result);
    }
   return 0;
}
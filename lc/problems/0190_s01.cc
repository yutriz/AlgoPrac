#include "heads.h"
#include <unitypes.h>

uint32_t reverseBits(uint32_t n) {
    /*
     * binary      1  0011  0101  0100
     * echo "ibase=2;1001101010100" | bc -> 4948(10)    
     *
     * to hex  (0001)(0011)(0101)(0100)
     *            1     3     5     4
     *          echo "ibase=16;1355"|bc
     */

    /* reverse every 4 bits */

    /* every 2 bits 0101 1010 */
    n = ((n&0x55555555)<<1 | (n&0xaaaaaaaa)>>1);
    /* every 4 bits 0011 1100 */
    n = ((n&0x33333333)<<2 | (n&0xcccccccc)>>2);
    /* every 8 bits 00001111 11110000 */
    n = ((n&0x0f0f0f0f)<<4 | (n&0xf0f0f0f0)>>4);
    /* every 16 bits 0000000011111111 1111111100000000 */
    n = ((n&0x00ff00ff)<<8 | (n&0xff00ff00)>>8);

    /* auto discard */
    n = (n<<16 | n>>16);

    return n;

}

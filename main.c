#include "bsp/board.h"
#include "tusb.h"

int main(void)
{
    board_init();
    tusb_init();

    while (1)
    {
        tud_task();

        // ide jöhet majd a te egérmozgás kódod
        // jelenleg csak egy statikus HID egér eszköz
    }

    return 0;
}

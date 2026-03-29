#include "tusb.h"

tusb_hid_report_desc_t const desc_hid_report[] =
{
    TUD_HID_MOUSE_DESCRIPTOR( HID_REPORT_ID(0) )
};

int main(void)
{
    board_init();
    tusb_init();

    while (1)
    {
        tud_task();
        if (tud_hid_ready())
        {
            // idle egér (0 mozgás)
            tud_hid_mouse_report(0, 0, 0, 0, 0);
            delay_ms(10);
        }
    }
}


#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#define CFG_TUSB_MCU OPT_MCU_RP2040
#define CFG_TUSB_OS  OPT_OS_NONE

#define CFG_TUD_ENDPOINT0_SIZE    64

#define CFG_TUD_HID               1
#define CFG_TUD_HID_EP_BUFSIZE    16

#endif

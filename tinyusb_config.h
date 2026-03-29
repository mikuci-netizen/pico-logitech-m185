#ifndef TINYUSB_CONFIG_H_
#define TINYUSB_CONFIG_H_

#define CFG_TUSB_OS               OPT_OS_NONE
#define CFG_TUSB_RHPORT0_MODE     (OPT_MODE_DEVICE)
#define CFG_TUSB_RHPORT0_SPEED    OPT_MODE_FULL_SPEED

#define USBD_VENDOR_ID           0x046D
#define USBD_PRODUCT_ID          0x4054
#define USBD_DEVICE_VER          0x0100

#define USBD_MANUFACTURER_STR    "Logitech"
#define USBD_PRODUCT_STR         "Wireless Mouse M185"
#define USBD_SERIAL_STR          "0001"

#define CFG_TUD_ENDPOINT0_SIZE   64
#define CFG_TUD_HID              1
#define CFG_TUD_HID_BUFSIZE      8

#endif

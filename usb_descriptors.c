#include "tusb.h"
#include <string.h>

#define USB_VID   0x046D   // Logitech
#define USB_PID   0x4054   // Logitech M185

// Device descriptor
tusb_desc_device_t const desc_device =
{
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0200,

    .bDeviceClass       = 0x00,
    .bDeviceSubClass    = 0x00,
    .bDeviceProtocol    = 0x00,

    .bMaxPacketSize0    = 64,

    .idVendor           = USB_VID,
    .idProduct          = USB_PID,
    .bcdDevice          = 0x0100,

    .iManufacturer      = 1,
    .iProduct           = 2,
    .iSerialNumber      = 3,

    .bNumConfigurations = 1
};

uint8_t const * tud_descriptor_device_cb(void)
{
    return (uint8_t const *) &desc_device;
}

// HID report descriptor (mouse)
uint8_t const desc_hid_report[] =
{
    TUD_HID_REPORT_DESC_MOUSE()
};

uint8_t const * tud_hid_descriptor_report_cb(uint8_t instance)
{
    return desc_hid_report;
}

// String descriptors
char const* string_desc_arr[] =
{
    (const char[]) { 0x09, 0x04 }, // English (US)
    "Logitech",
    "Wireless Mouse M185",
    "A00001"
};

static uint16_t _desc_str[32];

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    uint8_t chr_count;

    if ( index == 0 )
    {
        memcpy(&_desc_str[1], string_desc_arr[0], 2);
        chr_count = 1;
    }
    else
    {
        const char* str = string_desc_arr[index];
        chr_count = strlen(str);

        for(uint8_t i=0; i<chr_count; i++)
        {
            _desc_str[1+i] = str[i];
        }
    }

    _desc_str[0] = (TUSB_DESC_STRING << 8 ) | (2*chr_count + 2);

    return _desc_str;
}

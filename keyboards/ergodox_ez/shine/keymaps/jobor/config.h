/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define USB_SUSPEND_WAKEUP_DELAY 0
#define FIRMWARE_VERSION u8"schnusel"
#define LAYER_STATE_8BIT

#undef LED_BRIGHTNESS_DEFAULT
#define LED_BRIGHTNESS_DEFAULT (LED_BRIGHTNESS_LO)

#define TAPPING_TERM 175

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0


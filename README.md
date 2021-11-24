QWERTY US Intl ergodox_ez keymaps and some additional keys/features

You need to get qmk_firmware [official link](https://docs.qmk.fm/#/?id=how-to-get-it)

Then copy * to the QMK_FIRMWARE_ROOT_DIRECTORY.

Don't forget to run : `make git-submodule` in order to be sure you get avery submodule...

## Important

- `qmk_firmware/keyboards/ergodox_ez/config.h` should be edited to comment `UNICODE_KEY_LNX UC_LNX`

## 2021-Update

Since qmk release (i don't know when a nice way to create, build and flash the keyboard), i juste refresh all my keymaps.c.

To compile and flash:

- `qmk clean && qmk compile`
- `qmk flash`

QWERTY US Intl ergodox_ez keymaps.

You need to get qmk_firmware [official link](https://docs.qmk.fm/#/?id=how-to-get-it)

Then copy * to the QMK_FIRMWARE_ROOT_DIRECTORY.

Don't forget to run : `make git-submodule` in order to be sure you get avery submodule...

## Important

- `qmk_firmware/keyboards/ergodox_ez/config.h` should be edited to comment `UNICODE_KEY_LNX UC_LNX`



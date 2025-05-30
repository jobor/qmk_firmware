# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(THIS_DIR)/oryx_source/rules.mk

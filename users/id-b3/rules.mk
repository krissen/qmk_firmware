SRC += id-b3.c

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled/oled_stuff.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
    SRC += encoder_stuff.c
endif

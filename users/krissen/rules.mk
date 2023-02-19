WPM_ENABLE = no # Enable words per minute counting
MOUSEKEY_ENABLE = yes

SRC += krissen.c

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled_stuff.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_stuff.c
endif

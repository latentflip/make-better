#STYLUS_FILES = $(call find_recursive,*.styl)
find_recursive = $(shell find $1 -not \( -path ./node_modules -prune \) -type f -name "$2")

STYLUS_DIR ?= .
JADE_DIR ?= .
JS_DIR ?= .

STYLUS_FILES ?= $(call find_recursive,$(STYLUS_DIR),*.styl)
JADE_FILES ?= $(call find_recursive,$(JADE_DIR),*.jade)
JS_FILES ?= $(call find_recursive,$(JS_DIR),*.js)

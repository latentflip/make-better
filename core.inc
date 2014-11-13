# Set the shell to bash, enables path modification to work
SHELL := /bin/bash

# Project local bin node_modules bin directory, for npm installed command line tools
BIN_DIR := node_modules/.bin

# Add project's bindir, and this repo's bindir (for cssmin/uglify)
PATH := $(BIN_DIR):node_modules/make-better/node_modules/.bin:$(PATH)

# Finds files recursively within a directory, by filetype
# e.g. STYLUS_FILES = $(call find_recursive,public/styl,*.styl)
find_recursive = $(shell find $1 -not \( -path ./node_modules -prune \) -type f -name "$2")

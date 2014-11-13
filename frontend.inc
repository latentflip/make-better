# creates minify_js and minify_css recipes, use them like this
#   in production they will minify, in dev they'll just copy, for speed.
#
# path/to/output.min.css: path/to/input.min.css
#   $(minify_css)
#
# path/to/output.min.js: path/to/input.min.js
#   $(minify_js)

ifeq ($(NODE_ENV),production)
    minify_js = uglifyjs $< > $@
    minify_css = cssmin $< > $@
else
    minify_js = cp $< $@
    minify_css = cp $< $@
endif


# Overwrite these in your templates, to improve the performance of *_FILES
STYLUS_DIR ?= .
JADE_DIR ?= .
JS_DIR ?= .

# Lists all stylus/jade/js files in your project, useful for targets
STYLUS_FILES ?= $(call find_recursive,$(STYLUS_DIR),*.styl)
JADE_FILES ?= $(call find_recursive,$(JADE_DIR),*.jade)
JS_FILES ?= $(call find_recursive,$(JS_DIR),*.js)

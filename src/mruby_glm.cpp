#include <mruby.h>
#include <stdio.h>
#include "glm/glm.hpp"
#include "vec3.h"

extern "C"
void mrb_mruby_glm_gem_init(mrb_state* mrb) {
	mruby_glm::init_vec3(mrb);
}

extern "C"
void mrb_mruby_glm_gem_final(mrb_state* mrb) {
  // finalizer
}

#ifndef MRUBY_VECTOR_VEC3_H
#define MRUBY_VECTOR_VEC3_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>

#include <glm/glm.hpp>

namespace mruby_glm
{
	struct vec3
	{
		glm::vec3* vector;
		glm::vec3 value;

	public:
		vec3()
			:vector(nullptr), value(0.0f)
		{
		}

		vec3(glm::vec3* vec)
			:vector(vec)
		{
		}

		vec3(glm::vec3 vec)
			:value(vec), vector(&value)
		{
		}
	};

	void vec3_free(mrb_state *mrb, void *p);

	void init_vec3(mrb_state* mrb);
	mrb_value vec3_wrap(mrb_state *mrb, struct RClass *tc, struct vec3 *tm);
	vec3* vec3_get_ptr(mrb_state* mrb, mrb_value value);

	mrb_value vec3_get_x(mrb_state* mrb, mrb_value self);
	mrb_value vec3_set_x(mrb_state* mrb, mrb_value self);

	mrb_value vec3_get_y(mrb_state* mrb, mrb_value self);
	mrb_value vec3_set_y(mrb_state* mrb, mrb_value self);

	mrb_value vec3_get_z(mrb_state* mrb, mrb_value self);
	mrb_value vec3_set_z(mrb_state* mrb, mrb_value self);
}

#endif
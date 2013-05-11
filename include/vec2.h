#ifndef MRUBY_VECTOR_VEC2_H
#define MRUBY_VECTOR_VEC2_H

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>

#include <glm/glm.hpp>

namespace mruby_glm
{

	struct vec2
	{
		glm::vec2* vector;
		glm::vec2 value;

	public:
		vec2()
			:vector(nullptr), value(0.0f)
		{
		}

		vec2(glm::vec2* vec)
			:vector(vec)
		{
		}

		vec2(glm::vec2 vec)
			:value(vec), vector(&value)
		{
		}
	};

	void vec2_free(mrb_state *mrb, void *p);

	void init_vec2(mrb_state* mrb);
	mrb_value vec2_wrap(mrb_state *mrb, struct RClass *tc, struct vec2 *tm);
	vec2* vec2_get_ptr(mrb_state* mrb, mrb_value value);

	mrb_value vec2_get_x(mrb_state* mrb, mrb_value self);
	mrb_value vec2_set_x(mrb_state* mrb, mrb_value self);

	mrb_value vec2_get_y(mrb_state* mrb, mrb_value self);
	mrb_value vec2_set_y(mrb_state* mrb, mrb_value self);

}

#endif
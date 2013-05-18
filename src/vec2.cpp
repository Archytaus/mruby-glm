#include "vec2.h"

#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>

#include <glm/glm.hpp>
#include <glm/core/func_geometric.hpp>

namespace mruby_glm
{

	struct mrb_data_type vec2_type = { "Vec2", vec2_free };

	void vec2_free(mrb_state *mrb, void *ptr)
	{
		mrb_free(mrb, ptr);
	}

	mrb_value vec2_wrap(mrb_state *mrb, struct RClass *tc, struct vec2 *tm)
	{
		return mrb_obj_value(Data_Wrap_Struct(mrb, tc, &vec2_type, tm));
	}

	vec2* vec2_get_ptr(mrb_state* mrb, mrb_value value)
	{
		return (vec2*)mrb_data_get_ptr(mrb, value, &vec2_type);
	}

	mrb_value vec2_get_x(mrb_state* mrb, mrb_value self)
	{
		struct vec2 *vec = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		return mrb_float_value(vec->vector->x);
	}

	mrb_value vec2_set_x(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		mrb_get_args(mrb, "f", &new_value);

		struct vec2 *vec = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);
		vec->vector->x = mrb_float(new_value);

		return new_value;
	}

	mrb_value vec2_get_y(mrb_state* mrb, mrb_value self)
	{
		struct vec2 *vec = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		return mrb_float_value(vec->vector->y);
	}

	mrb_value vec2_set_y(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		mrb_get_args(mrb, "f", &new_value);

		struct vec2 *vec = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);
		vec->vector->y = mrb_float(new_value);

		return new_value;
	}

	mrb_value vec2_equals(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		return mrb_bool_value(
			selfValue->vector->x == arg->vector->x &&
			selfValue->vector->y == arg->vector->y);
	}

	mrb_value vec2_plus(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
			glm::vec2(selfValue->vector->x + arg->vector->x,
			selfValue->vector->y + arg->vector->y)));
	}

	mrb_value vec2_plus_inplace(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		selfValue->vector->x += arg->vector->x;
		selfValue->vector->y += arg->vector->y;
		return self;
	}

	mrb_value vec2_subtract(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
			glm::vec2(
			selfValue->vector->x - arg->vector->x,
			selfValue->vector->y - arg->vector->y)));
	}

	mrb_value vec2_subtract_inplace(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		selfValue->vector->x -= arg->vector->x;
		selfValue->vector->y -= arg->vector->y;
		return self;
	}

	mrb_value vec2_usubtract(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!selfValue) return mrb_nil_value();

		return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
			glm::vec2(
			0 - selfValue->vector->x,
			0 - selfValue->vector->y)));
	}

	mrb_value vec2_usubtract_inplace(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!selfValue) return mrb_nil_value();

		selfValue->vector->x = 0 - selfValue->vector->x;
		selfValue->vector->y = 0 - selfValue->vector->y;
		return self;
	}

	mrb_value vec2_times(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		mrb_value new_value;
		mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);

		if (arg)
		{
			return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
				glm::vec2(selfValue->vector->x * arg->vector->x,
				selfValue->vector->y * arg->vector->y)));
		}

		mrb_float modifier;
		mrb_get_args(mrb, "f", &modifier);
		if(modifier)
		{
			return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
				glm::vec2(selfValue->vector->x * modifier,
				selfValue->vector->y * modifier)));
		}

		return mrb_nil_value();
	}

	mrb_value vec2_times_inplace(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		mrb_value new_value;
		mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);

		if (arg)
		{
			selfValue->vector->x *= arg->vector->x;
			selfValue->vector->y *= arg->vector->y;
			return self;
		}

		mrb_float modifier;
		mrb_get_args(mrb, "f", &modifier);
		if(modifier)
		{
			selfValue->vector->x *= modifier;
			selfValue->vector->y *= modifier;
			return self;
		}

		return mrb_nil_value();
	}

	mrb_value vec2_divide(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		mrb_value new_value;
		mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);

		if (arg)
		{
			return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
				glm::vec2(selfValue->vector->x / arg->vector->x,
				selfValue->vector->y / arg->vector->y)));
		}

		mrb_float modifier;
		mrb_get_args(mrb, "f", &modifier);
		if(modifier)
		{
			return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), new vec2(
				glm::vec2(selfValue->vector->x / modifier,
				selfValue->vector->y / modifier)));
		}

		return mrb_nil_value();
	}

	mrb_value vec2_divide_inplace(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		mrb_value new_value;
		mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);

		if (arg)
		{
			selfValue->vector->x /= arg->vector->x;
			selfValue->vector->y /= arg->vector->y;
			return self;
		}

		mrb_float modifier;
		mrb_get_args(mrb, "f", &modifier);
		if(modifier)
		{
			selfValue->vector->x /= modifier;
			selfValue->vector->y /= modifier;
			return self;
		}

		return mrb_nil_value();
	}

	mrb_value vec2_initialize(mrb_state *mrb, mrb_value self)
	{
		mrb_float x, y;
		int n;
		struct vec2 *tm;

		tm = (struct vec2*)DATA_PTR(self);
		if (tm) {
			vec2_free(mrb, tm);
		}
		DATA_TYPE(self) = &vec2_type;
		DATA_PTR(self) = NULL;

		n = mrb_get_args(mrb, "|f|f", &x, &y); // 1 or 2 float arguments
		tm = (struct vec2 *)mrb_malloc(mrb, sizeof(struct vec2));

		if (n == 0)
		{
			tm->value = glm::vec2();
		}
		if (n == 1)
		{
			tm->value = glm::vec2(x);
		}
		else if (n == 2)
		{
			tm->value = glm::vec2(x, y);
		}

		tm->vector = &tm->value;
		DATA_PTR(self) = tm;
		return self;
	}

	mrb_value vec2_normalize(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);
		vec2* result = new vec2(glm::normalize(*selfValue->vector));

		return vec2_wrap(mrb, mrb_class_get(mrb, "Vec2"), result);
	}

	mrb_value vec2_normalize_inplace(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);
		*selfValue->vector = glm::normalize(*selfValue->vector);

		return self;
	}

	mrb_value vec2_length(mrb_state* mrb, mrb_value self)
	{
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		return mrb_float_value(glm::length(*selfValue->vector));
	}

	mrb_value vec2_distance(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		return mrb_float_value(glm::distance(*selfValue->vector, *arg->vector));
	}

	mrb_value vec2_dot(mrb_state* mrb, mrb_value self)
	{
		mrb_value new_value;
		int args = mrb_get_args(mrb, "o", &new_value);
		vec2* arg =(struct vec2*)mrb_data_get_ptr(mrb, new_value, &vec2_type);
		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);

		if (!arg) return mrb_nil_value();

		return mrb_float_value(glm::dot(*selfValue->vector, *arg->vector));
	}

	mrb_value vec2_inspect(mrb_state* mrb, mrb_value self)
	{
		char buf[256];
		int len;

		vec2* selfValue = (struct vec2*)mrb_data_get_ptr(mrb, self, &vec2_type);
		if (!selfValue) return mrb_nil_value();

		len = snprintf(buf, sizeof(buf), "[%.4f,%.4f]",
			selfValue->vector->x, selfValue->vector->y);
		return mrb_str_new(mrb, buf, len);
	}

	void init_vec2(mrb_state* mrb)
	{
		auto vector2Class = mrb_define_class(mrb, "Vec2", mrb->object_class);
		MRB_SET_INSTANCE_TT(vector2Class, MRB_TT_DATA);

		mrb_define_method(mrb, vector2Class, "x", vec2_get_x, ARGS_NONE());
		mrb_define_method(mrb, vector2Class, "x=", vec2_set_x, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "y", vec2_get_y, ARGS_NONE());
		mrb_define_method(mrb, vector2Class, "y=", vec2_set_y, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "+", vec2_plus, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "add", vec2_plus, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "add!", vec2_plus_inplace, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "-", vec2_subtract, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "subtract", vec2_subtract, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "subtract!", vec2_subtract_inplace, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "-@", vec2_usubtract, ARGS_NONE());
		mrb_define_method(mrb, vector2Class, "negate", vec2_usubtract, ARGS_NONE());
		mrb_define_method(mrb, vector2Class, "negate!", vec2_usubtract_inplace, ARGS_NONE());

		mrb_define_method(mrb, vector2Class, "*", vec2_times, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "multiply", vec2_times, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "multiply!", vec2_times_inplace, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "/", vec2_divide, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "divide", vec2_divide, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "divide!", vec2_divide_inplace, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "normalize", vec2_normalize, ARGS_NONE());
		mrb_define_method(mrb, vector2Class, "normalize!", vec2_normalize_inplace, ARGS_NONE());

		mrb_define_method(mrb, vector2Class, "length", vec2_length, ARGS_NONE());

		mrb_define_method(mrb, vector2Class, "dot", vec2_dot, ARGS_REQ(1));
		mrb_define_method(mrb, vector2Class, "distance_to", vec2_distance, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "==", vec2_equals, ARGS_REQ(1));

		mrb_define_method(mrb, vector2Class, "initialize", vec2_initialize, ARGS_ANY());

		mrb_define_method(mrb, vector2Class, "to_s", vec2_inspect, ARGS_NONE());
		mrb_define_method(mrb, vector2Class, "inspect", vec2_inspect, ARGS_NONE());
	}

}
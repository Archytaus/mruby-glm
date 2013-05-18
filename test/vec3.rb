assert 'default constructor' do
	Vec3.new(1) != nil
end

assert 'constructor setting empty value' do
	value = Vec3.new
	value.x == 0 && value.y == 0 && value.z == 0
end

assert 'constructor setting single value' do
	value = Vec3.new(1)
	value.x == 1 && value.y == 1 && value.z == 1
end

assert 'constructor setting values' do
	value = Vec3.new(1, 2, 3)
	value.x == 1 && value.y == 2 && value.z == 3
end

assert 'get x property' do
	vec = Vec3.new(5)
	vec.x == 5
end

assert 'set x property' do
	vec = Vec3.new(5)
	vec.x = 2
	vec.x == 2
end

assert 'get y property' do
	vec = Vec3.new(5)
	vec.y == 5
end

assert 'set y property' do
	vec = Vec3.new(5)
	vec.y = 2
	vec.y == 2
end

assert 'get z property' do
	vec = Vec3.new(5)
	vec.z == 5
end

assert 'set z property' do
	vec = Vec3.new(5)
	vec.z = 2
	vec.z == 2
end

assert 'add' do
	value = Vec3.new(0, 1, 0) + Vec3.new(1, 0, 0) + Vec3.new(0, 0, 1)
	value.x == 1 && value.y == 1 && value.z == 1
end

assert 'add!' do
	value = Vec3.new(0, 1, 0)
	value.add! Vec3.new(1, 0, 0)
	value.add! Vec3.new(0, 0, 1)
	value.x == 1 && value.y == 1 && value.z == 1
end

assert 'multiply' do
	value = Vec3.new(1) * Vec3.new(3)
	value.x == 3 && value.y == 3 && value.z == 3
end

assert 'multiply!' do
	value = Vec3.new(1)
	value.multiply! Vec3.new(3)
	value.x == 3 && value.y == 3 && value.z == 3
end

assert 'float multiply' do
	value = Vec3.new(1) * 3
	value.x == 3 && value.y == 3 && value.z == 3
end

assert 'float multiply!' do
	value = Vec3.new(1)
	value.multiply! 3

	value.x == 3 && value.y == 3 && value.z == 3
end

assert 'multiplication is not destructive' do
	original = Vec3.new(1)
	value = original * Vec3.new(3, 3, 3)
	original.x == 1 && original.y == 1 && original.z == 1
end

assert 'subtract' do
	value = Vec3.new(3) - Vec3.new(2)
	value.x == 1 && value.y == 1 && value.z == 1
end

assert 'subtract!' do
	value = Vec3.new(3)
	value.subtract! Vec3.new(2)
	value.x == 1 && value.y == 1 && value.z == 1
end

assert 'negate' do
	value = -Vec3.new(3)
	value.x == -3 && value.y == -3 && value.z == -3
end

assert 'negate!' do
	value = Vec3.new(3)
	value.negate!
	value.x == -3 && value.y == -3 && value.z == -3
end

assert 'divide' do
	value = Vec3.new(4) / Vec3.new(2)
	value.x == 2 && value.y == 2 && value.z == 2
end

assert 'divide!' do
	value = Vec3.new(4)
	value.divide! Vec3.new(2)
	value.x == 2 && value.y == 2 && value.z == 2
end

assert 'float divide' do
	value = Vec3.new(4) / 2
	value.x == 2 && value.y == 2 && value.z == 2
end

assert 'float divide!' do
	value = Vec3.new(4)
	value.divide! 2
	value.x == 2 && value.y == 2 && value.z == 2
end

assert 'equality' do
	Vec3.new(1, 2, 3) == Vec3.new(1, 2, 3)
end

assert 'inequality' do
	Vec3.new(1, 2, 4) != Vec3.new(1, 2, 3)
end

assert 'normalize' do
	value = Vec3.new(0, 5, 0).normalize
	value.x == 0 && value.y == 1 && value.z == 0
end

assert 'normalize!' do
	value = Vec3.new(0, 5, 0)
	value.normalize!
	value.x == 0 && value.y == 1 && value.z == 0
end

assert 'length' do
	value = Vec3.new(0, 3, 0).length
	value == 3
end

assert 'distance' do
	value = Vec3.new(3).distance_to(Vec3.new(3, 3, 6))
	value == 3
end

assert 'dot' do
	value = Vec3.new(3).dot(Vec3.new(3, 4, 3))
	value == 30
end

assert 'memory allocation' do
	after_obj_count = {}
	before_obj_count = {}
	other_value = Vec3.new(3)
	ObjectSpace.count_objects(before_obj_count)

	value = Vec3.new(3)

	ObjectSpace.count_objects(after_obj_count)
	assert_equal(before_obj_count[:MRB_TT_DATA] + 1, after_obj_count[:MRB_TT_DATA])

	ObjectSpace.count_objects(before_obj_count)

	value.multiply! other_value

	ObjectSpace.count_objects(after_obj_count)
	assert_equal(before_obj_count[:MRB_TT_DATA], after_obj_count[:MRB_TT_DATA])
end
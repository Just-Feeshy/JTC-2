local jtc_math = {}
local vector2 = {}

local function assert_number(value, label)
    assert(type(value) == "number", label .. " must be a number")
end

local function assert_matrix(matrix, label)
    assert(type(matrix) == "table", label .. " must be a matrix table")
    assert_number(matrix.m11, label .. ".m11")
    assert_number(matrix.m12, label .. ".m12")
    assert_number(matrix.m21, label .. ".m21")
    assert_number(matrix.m22, label .. ".m22")
end

local function assert_vector(vec, label)
    assert(type(vec) == "table", label .. " must be a vector table")
    assert_number(vec.x, label .. ".x")
    assert_number(vec.y, label .. ".y")
end

function jtc_math.new(m11, m12, m21, m22)
    assert_number(m11, "m11")
    assert_number(m12, "m12")
    assert_number(m21, "m21")
    assert_number(m22, "m22")

    return {
        m11 = m11,
        m12 = m12,
        m21 = m21,
        m22 = m22
    }
end

function jtc_math.zero()
    return jtc_math.new(0, 0, 0, 0)
end

function jtc_math.identity()
    return jtc_math.new(1, 0, 0, 1)
end

function jtc_math.clone(matrix)
    assert_matrix(matrix, "matrix")
    return jtc_math.new(matrix.m11, matrix.m12, matrix.m21, matrix.m22)
end

function jtc_math.from_rows(row1_col1, row1_col2, row2_col1, row2_col2)
    return jtc_math.new(row1_col1, row1_col2, row2_col1, row2_col2)
end

function jtc_math.transpose(matrix)
    assert_matrix(matrix, "matrix")
    return jtc_math.new(matrix.m11, matrix.m21, matrix.m12, matrix.m22)
end

function jtc_math.determinant(matrix)
    assert_matrix(matrix, "matrix")
    return (matrix.m11 * matrix.m22) - (matrix.m12 * matrix.m21)
end

function jtc_math.add(left, right)
    assert_matrix(left, "left")
    assert_matrix(right, "right")

    return jtc_math.new(
        left.m11 + right.m11,
        left.m12 + right.m12,
        left.m21 + right.m21,
        left.m22 + right.m22
    )
end

function jtc_math.subtract(left, right)
    assert_matrix(left, "left")
    assert_matrix(right, "right")

    return jtc_math.new(
        left.m11 - right.m11,
        left.m12 - right.m12,
        left.m21 - right.m21,
        left.m22 - right.m22
    )
end

function jtc_math.multiply(left, right)
    assert_matrix(left, "left")
    assert_matrix(right, "right")

    return jtc_math.new(
        (left.m11 * right.m11) + (left.m12 * right.m21),
        (left.m11 * right.m12) + (left.m12 * right.m22),
        (left.m21 * right.m11) + (left.m22 * right.m21),
        (left.m21 * right.m12) + (left.m22 * right.m22)
    )
end

function jtc_math.multiply_scalar(matrix, scalar)
    assert_matrix(matrix, "matrix")
    assert_number(scalar, "scalar")

    return jtc_math.new(
        matrix.m11 * scalar,
        matrix.m12 * scalar,
        matrix.m21 * scalar,
        matrix.m22 * scalar
    )
end

function jtc_math.multiply_vector(matrix, x, y)
    assert_matrix(matrix, "matrix")
    assert_number(x, "x")
    assert_number(y, "y")

    return {
        x = (matrix.m11 * x) + (matrix.m12 * y),
        y = (matrix.m21 * x) + (matrix.m22 * y)
    }
end

function jtc_math.inverse(matrix)
    assert_matrix(matrix, "matrix")

    local determinant = jtc_math.determinant(matrix)

    if determinant == 0 then
        return nil, "matrix is singular"
    end

    return jtc_math.new(
        matrix.m22 / determinant,
        -matrix.m12 / determinant,
        -matrix.m21 / determinant,
        matrix.m11 / determinant
    )
end

function jtc_math.rotation(radians)
    assert_number(radians, "radians")

    local cosine = math.cos(radians)
    local sine = math.sin(radians)

    return jtc_math.new(
        cosine, -sine,
        sine, cosine
    )
end

function jtc_math.scale(scale_x, scale_y)
    assert_number(scale_x, "scale_x")
    assert_number(scale_y, "scale_y")

    return jtc_math.new(
        scale_x, 0,
        0, scale_y
    )
end

function jtc_math.equals(left, right, epsilon)
    assert_matrix(left, "left")
    assert_matrix(right, "right")

    epsilon = epsilon or 0
    assert_number(epsilon, "epsilon")

    return math.abs(left.m11 - right.m11) <= epsilon
        and math.abs(left.m12 - right.m12) <= epsilon
        and math.abs(left.m21 - right.m21) <= epsilon
        and math.abs(left.m22 - right.m22) <= epsilon
end

function jtc_math.to_string(matrix)
    assert_matrix(matrix, "matrix")
    return string.format("[[%s, %s], [%s, %s]]", matrix.m11, matrix.m12, matrix.m21, matrix.m22)
end

function vector2.new(x, y)
    assert_number(x, "x")
    assert_number(y, "y")
    return {x = x, y = y}
end

function vector2.zero()
    return vector2.new(0, 0)
end

function vector2.one()
    return vector2.new(1, 1)
end

function vector2.clone(vec)
    assert_vector(vec, "vec")
    return vector2.new(vec.x, vec.y)
end

function vector2.add(left, right)
    assert_vector(left, "left")
    assert_vector(right, "right")
    return vector2.new(left.x + right.x, left.y + right.y)
end

function vector2.subtract(left, right)
    assert_vector(left, "left")
    assert_vector(right, "right")
    return vector2.new(left.x - right.x, left.y - right.y)
end

function vector2.multiply_scalar(vec, scalar)
    assert_vector(vec, "vec")
    assert_number(scalar, "scalar")
    return vector2.new(vec.x * scalar, vec.y * scalar)
end

function vector2.dot(left, right)
    assert_vector(left, "left")
    assert_vector(right, "right")
    return (left.x * right.x) + (left.y * right.y)
end

function vector2.length_squared(vec)
    assert_vector(vec, "vec")
    return vector2.dot(vec, vec)
end

function vector2.length(vec)
    return math.sqrt(vector2.length_squared(vec))
end

function vector2.normalize(vec)
    assert_vector(vec, "vec")

    local length = vector2.length(vec)
    if length == 0 then
        return vector2.zero()
    end

    return vector2.new(vec.x / length, vec.y / length)
end

function vector2.distance(left, right)
    return vector2.length(vector2.subtract(left, right))
end

function vector2.equals(left, right, epsilon)
    assert_vector(left, "left")
    assert_vector(right, "right")

    epsilon = epsilon or 0
    assert_number(epsilon, "epsilon")

    return math.abs(left.x - right.x) <= epsilon
        and math.abs(left.y - right.y) <= epsilon
end

function vector2.to_string(vec)
    assert_vector(vec, "vec")
    return string.format("(%s, %s)", vec.x, vec.y)
end

jtc_math.vector2 = vector2

return jtc_math

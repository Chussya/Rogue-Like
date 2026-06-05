#include "pch.h"

#include "Vector2D.h"

TEST(VectorTests, ZeroConstructor)
{
	CustomEngine::Vector2D<float> v;
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);
}

TEST(VectorTests, Constructor)
{
	CustomEngine::Vector2D<float> v(5.f, -3.f);
	EXPECT_EQ(v.x, 5.f);
	EXPECT_EQ(v.y, -3.f);
}

TEST(VectorTests, GetLength)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2(-4.f, 3.f);

	EXPECT_EQ(v1.getLength(), 5.f);
	EXPECT_EQ(v2.getLength(), 5.f);
}

TEST(VectorTests, DotProduct)
{
	CustomEngine::Vector2D<float> v1(1.f, -3.f);
	CustomEngine::Vector2D<float> v2(6.f, -2.f);

	EXPECT_EQ(v1.dotProduct(v2), 12.f);
}

TEST(VectorTests, Addition)
{
	CustomEngine::Vector2D<float> v1(1.f, -3.f);
	CustomEngine::Vector2D<float> v2(6.f, -2.f);
	CustomEngine::Vector2D<float> res = v1 + v2;

	EXPECT_EQ(res.x, 7.f);
	EXPECT_EQ(res.y, -5.f);
}

TEST(VectorTests, Subtraction)
{
	CustomEngine::Vector2D<float> v1(1.f, -3.f);
	CustomEngine::Vector2D<float> v2(6.f, -2.f);
	CustomEngine::Vector2D<float> res = v1 - v2;

	EXPECT_EQ(res.x, -5.f);
	EXPECT_EQ(res.y, -1.f);
}

TEST(VectorTests, Multiplication)
{
	CustomEngine::Vector2D<float> v1(1.f, -3.f);
	CustomEngine::Vector2D<float> v2(6.f, -2.f);
	CustomEngine::Vector2D<float> res = v1 * v2;

	EXPECT_EQ(res.x, 6.f);
	EXPECT_EQ(res.y, 6.f);
}

TEST(VectorTests, Separation)
{
	CustomEngine::Vector2D<float> v1(6.f, -3.f);
	CustomEngine::Vector2D<float> v2(6.f, 3.f);
	CustomEngine::Vector2D<float> res = v1 / v2;

	EXPECT_EQ(res.x, 1.f);
	EXPECT_EQ(res.y, -1.f);
}

TEST(VectorTests, Negative)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2 = -v1;

	EXPECT_EQ(v2.x, -4.f);
	EXPECT_EQ(v2.y, 3.f);
}

TEST(VectorTests, ScalarMultiply)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2 = v1 * -1.5f;

	EXPECT_EQ(v2.x, -6.f);
	EXPECT_EQ(v2.y, 4.5f);
}

TEST(VectorTests, MultiplyScalar)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2 = -1.5f * v1;

	EXPECT_EQ(v2.x, -6.f);
	EXPECT_EQ(v2.y, 4.5f);
}

TEST(VectorTests, Equality)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2(4.f, -3.f);
	CustomEngine::Vector2D<float> v3(-4.f, -3.f);

	EXPECT_TRUE(v1 == v2);
	EXPECT_TRUE(!(v1 == v3));
}

TEST(VectorTests, InEquality)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2(4.f, -3.f);
	CustomEngine::Vector2D<float> v3(-4.f, -3.f);

	EXPECT_TRUE(!(v1 != v2));
	EXPECT_TRUE(v1 != v3);
}

TEST(VectorTests, MoreThan)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2(5.f, -2.f);

	EXPECT_TRUE(v2 > v1);
}

TEST(VectorTests, LessThan)
{
	CustomEngine::Vector2D<float> v1(4.f, -3.f);
	CustomEngine::Vector2D<float> v2(5.f, -2.f);

	EXPECT_TRUE(v1 < v2);
}
#pragma once
#include <cmath>
using namespace std;

template<typename T>
class Vec2 {
public:

	T x, y;

	/// <summary>
	/// デフォルトコンストラクタ
	/// </summary>
	Vec2() = default;

	/// <summary>
	/// 代入コンストラクタ
	/// </summary>
	/// <param name="x">ｘの大きさ、座標</param>
	/// <param name="y">ｙの大きさ、座標</param>
	Vec2(T x, T y) :x(x), y(y) {}


	template<typename t>
	/// <summary>
	/// 代入コンストラクタ
	/// </summary>
	/// <param name="vec2">ほかのVec2(型はキャストされる)</param>
	Vec2(Vec2<t> vec2) : x(static_cast<T>( vec2.x)), y(static_cast<T>(vec2.y)) {}

	/// <summary>
	/// 三角形の斜辺の長さを返す
	/// </summary>
	double GetLength() const{
		return sqrt(x * x + y * y);
	}

	/// <summary>
	/// 三角形の斜辺の2乗を返す
	/// </summary>
	constexpr double GetLengthSquare() const{
		return x * x + y * y;
	}

	/// <summary>
	/// 三角形のラジアン角を返す
	/// </summary>
	double GetAngle() const{
		return std::atan(y / x);
	}

	template<typename t>
	/// <summary>
	/// 2点間のなす角のラジアン角を返す
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	double GetAngle(const Vec2<t>& other) const{
		return std::atan2((other.y - this->y), (other.x - this->x));
	}

	/// <summary>
	/// x､yの絶対値を返す
	/// </summary>
	T abs() const{
		return { std::abs(x), std::abs(y) };
	}

	/// <summary>
	/// 三角形の内積を返す
	/// </summary>
	/// <param name="other">ほかのVec2</param>
	constexpr double Dot(const Vec2& other) const{
		return x * other.x + y * other.y;
	}

	/// <summary>
	/// 2点間の距離を返す
	/// </summary>
	/// <param name="other">ほかのVec2</param>
	double Distance(const Vec2& other) const{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	/// <summary>
	/// 傾きを返す
	/// </summary>
	/// <returns>0と(x, y)の傾き</returns>
	double Slope() const{
		return (this.y) / (this.x);
	}

	/// <summary>
	/// 二点間の傾きを求める
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	double SlopeByOther(const Vec2& other) const{
		return (this.y - other.y) / (this.x - other.x);
	}

	/// <summary>
	/// 斜辺の長さとの比を返す
	/// </summary>
	/// <returns></returns>
	Vec2 Normalizes() const {
		return{ x / GetLength() , y / GetLength() };
	}

	/// <summary>
	/// 0ベクトルかを返す
	/// </summary>
	constexpr bool isZero() const {
		return x == 0.0 && y == 0.0;
	}


	constexpr Vec2 operator =(const Vec2& other) {
		x = other.x;
		y = other.y;
		return *this;
	}

	constexpr Vec2 operator +() const {
		return *this;
	}

	constexpr Vec2 operator -() const {
		return{ -x, -y };
	}

	constexpr Vec2 operator +(const Vec2& other) const {
		return{ x + other.x, y + other.y };
	}

	template<typename t>
	constexpr Vec2 operator +(const Vec2<t>& other) const {
		return{ x + static_cast<T>(other.x), y + static_cast<T>(other.y) };
	}

	template<typename t>
	constexpr Vec2 operator -(const Vec2<t>& other) const {
		return{ x - static_cast<T>(other.x), y - static_cast<T>(other.y) };
	}

	template<typename t>
	constexpr Vec2 operator *(const Vec2<t>& other) const {
		return{ x * static_cast<T>(other.x), y * static_cast<T>(other.y) };
	}

	template<typename t>
	constexpr Vec2 operator /(const Vec2<t>& other) const {
		return{ x / static_cast<T>(other.x), y / static_cast<T>(other.y) };
	}

	template<typename t>
	Vec2 operator %(const Vec2<t>& other) const {
		return{ fmod(x, other.x),fmod(y, other.y) };
	}

	template<typename t>
	constexpr Vec2 operator +(t s) const {
		return{ x + s, y + s };
	}

	template<typename t>
	constexpr Vec2 operator -(t s) const {
		return{ x - s, y - s };
	}

	template<typename t>
	constexpr Vec2 operator *(t s) const {
		return{ x * s, y * s };
	}

	template<typename t>
	constexpr Vec2 operator /(t s) const {
		return{ static_cast<T>(x / s), static_cast<T>(y / s) };
	}

	template<typename t>
	Vec2 operator %(t s) const {
		return{ fmod(x, s),fmod(y, s) };
	}

	constexpr bool operator ==(Vec2 other) const {
		return (x == other.x) && (y == other.y);
	}

	constexpr bool operator !=(Vec2 other) const {
		return (x != other.x) || (y != other.y);
	}

	Vec2& operator +=(const Vec2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vec2& operator -=(const Vec2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vec2& operator *=(const Vec2& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vec2& operator /=(const Vec2& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vec2& operator %=(const Vec2& other) {
		x = fmod(x, other.x);
		y = fmod(y, other.y);
		return *this;
	}

	template<typename t>
	Vec2& operator +=(const Vec2<t>& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	template<typename t>
	Vec2& operator -=(const Vec2<t>& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	template<typename t>
	Vec2& operator *=(const Vec2<t>& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	template<typename t>
	Vec2& operator /=(const Vec2<t>& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	template<typename t>
	Vec2& operator %=(const Vec2<t>& other) {
		x = fmod(x, other.x);
		y = fmod(y, other.y);
		return *this;
	}

	template<typename t>
	Vec2& operator +=(t s) {
		x += s;
		y += s;
		return *this;
	}

	template<typename t>
	Vec2& operator -=(t s) {
		x -= s;
		y -= s;
		return *this;
	}

	template<typename t>
	Vec2& operator *=(t s) {
		x *= s;
		y *= s;
		return *this;
	}

	template<typename t>
	Vec2& operator /=(t s) {
		x /= s;
		y /= s;
		return *this;
	}

	template<typename t>
	Vec2& operator %=(t s) {
		x = fmodf(x, s);
		y = fmodf(y, s);
		return *this;
	}

	Vec2& operator ++() {
		++x;
		++y;
		return *this;
	}

	Vec2& operator --() {
		--x;
		--y;
		return *this;
	}

	template<typename t>
	Vec2& operator ++(t) {
		x++;
		y++;
		return *this;
	}

	template<typename t>
	Vec2& operator --(t) {
		x--;
		y--;
		return *this;
	}

	operator Vec2<int16>() {
		return { static_cast<int16>(x), static_cast<int16> (y) };
	}

	operator Vec2<uint16>() {
		return { static_cast<uint16>(x), static_cast<uint16> (y) };
	}

	operator Vec2<int32>() {
		return { static_cast<int32>(x), static_cast<int32> (y) };
	}

	operator Vec2<uint32>() {
		return { static_cast<uint32>(x), static_cast<uint32> (y) };
	}

	operator Vec2<int64>() {
		return { static_cast<int64>(x), static_cast<int64> (y) };
	}

	operator Vec2<uint64>() {
		return { static_cast<uint64>(x), static_cast<uint64> (y) };
	}

	operator Vec2<char8>() {
		return { static_cast<char8>(x), static_cast<char8> (y) };
	}

	operator Vec2<char16>() {
		return { static_cast<char16>(x), static_cast<char16> (y) };
	}

	operator Vec2<uchar8>() {
		return { static_cast<uchar8>(x), static_cast<uchar8> (y) };
	}

	operator Vec2<float>() {
		return { static_cast<float> (x), static_cast<float> (y) };
	}

	operator Vec2<double>() {
		return { static_cast<double> (x), static_cast<double>(y) };
	}

	operator Vec2<ldouble>() {
		return { static_cast<ldouble> (x), static_cast<ldouble>(y) };
	}
}
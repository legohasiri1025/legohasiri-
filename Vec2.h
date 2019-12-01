#pragma once
#include <cmath>
using namespace std;

template<typename T>
class Vec2 {
public:

	T x, y;

	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	Vec2() = default;

	/// <summary>
	/// ����R���X�g���N�^
	/// </summary>
	/// <param name="x">���̑傫���A���W</param>
	/// <param name="y">���̑傫���A���W</param>
	Vec2(T x, T y) :x(x), y(y) {}


	template<typename t>
	/// <summary>
	/// ����R���X�g���N�^
	/// </summary>
	/// <param name="vec2">�ق���Vec2(�^�̓L���X�g�����)</param>
	Vec2(Vec2<t> vec2) : x(static_cast<T>( vec2.x)), y(static_cast<T>(vec2.y)) {}

	/// <summary>
	/// �O�p�`�̎Εӂ̒�����Ԃ�
	/// </summary>
	double GetLength() const{
		return sqrt(x * x + y * y);
	}

	/// <summary>
	/// �O�p�`�̎Εӂ�2���Ԃ�
	/// </summary>
	constexpr double GetLengthSquare() const{
		return x * x + y * y;
	}

	/// <summary>
	/// �O�p�`�̃��W�A���p��Ԃ�
	/// </summary>
	double GetAngle() const{
		return std::atan(y / x);
	}

	template<typename t>
	/// <summary>
	/// 2�_�Ԃ̂Ȃ��p�̃��W�A���p��Ԃ�
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	double GetAngle(const Vec2<t>& other) const{
		return std::atan2((other.y - this->y), (other.x - this->x));
	}

	/// <summary>
	/// x�y�̐�Βl��Ԃ�
	/// </summary>
	T abs() const{
		return { std::abs(x), std::abs(y) };
	}

	/// <summary>
	/// �O�p�`�̓��ς�Ԃ�
	/// </summary>
	/// <param name="other">�ق���Vec2</param>
	constexpr double Dot(const Vec2& other) const{
		return x * other.x + y * other.y;
	}

	/// <summary>
	/// 2�_�Ԃ̋�����Ԃ�
	/// </summary>
	/// <param name="other">�ق���Vec2</param>
	double Distance(const Vec2& other) const{
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	/// <summary>
	/// �X����Ԃ�
	/// </summary>
	/// <returns>0��(x, y)�̌X��</returns>
	double Slope() const{
		return (this.y) / (this.x);
	}

	/// <summary>
	/// ��_�Ԃ̌X�������߂�
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	double SlopeByOther(const Vec2& other) const{
		return (this.y - other.y) / (this.x - other.x);
	}

	/// <summary>
	/// �Εӂ̒����Ƃ̔��Ԃ�
	/// </summary>
	/// <returns></returns>
	Vec2 Normalizes() const {
		return{ x / GetLength() , y / GetLength() };
	}

	/// <summary>
	/// 0�x�N�g������Ԃ�
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
#pragma once
#include <DxLib.h>  // VECTOR型の宣言を使うために

struct Vector3
{
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}

    // VECTOR型から変換するコンストラクターを追加
    Vector3(const VECTOR& v) : x(v.x), y(v.y), z(v.z) {}
};
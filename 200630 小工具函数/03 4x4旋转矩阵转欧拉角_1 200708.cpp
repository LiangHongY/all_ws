#include <iostream>
#include <cmath>

#define M_PI 3.1415926

class Vec4 {
public:
    Vec4(float x, float y, float z, float w) :
        x(x), y(y), z(z), w(w) {}

    float dot(const Vec4& other) const {
        return x * other.x +
            y * other.y +
            z * other.z +
            w * other.w;
    };

    float x, y, z, w;
};

class Mat4x4 {
public:
    Mat4x4() {}

    Mat4x4(float v00, float v01, float v02, float v03,
        float v10, float v11, float v12, float v13,
        float v20, float v21, float v22, float v23,
        float v30, float v31, float v32, float v33) {
        values[0] = v00;
        values[1] = v01;
        values[2] = v02;
        values[3] = v03;
        values[4] = v10;
        values[5] = v11;
        values[6] = v12;
        values[7] = v13;
        values[8] = v20;
        values[9] = v21;
        values[10] = v22;
        values[11] = v23;
        values[12] = v30;
        values[13] = v31;
        values[14] = v32;
        values[15] = v33;

    }

    Vec4 row(const int row) const {
        return Vec4(
            values[row * 4],
            values[row * 4 + 1],
            values[row * 4 + 2],
            values[row * 4 + 3]
        );
    }

    Vec4 column(const int column) const {
        return Vec4(
            values[column],
            values[column + 4],
            values[column + 8],
            values[column + 12]
        );
    }

    Mat4x4 multiply(const Mat4x4& other) const {
        Mat4x4 result;
        for (int row = 0; row < 4; ++row) {
            for (int column = 0; column < 4; ++column) {
                result.values[row * 4 + column] = this->row(row).dot(other.column(column));
            }
        }
        return result;
    }

    void extractEulerAngleXYZ(float& rotXangle, float& rotYangle, float& rotZangle) const {
        rotXangle = atan2(-row(1).z, row(2).z);
        float cosYangle = sqrt(pow(row(0).x, 2) + pow(row(0).y, 2));
        rotYangle = atan2(row(0).z, cosYangle);
        float sinXangle = sin(rotXangle);
        float cosXangle = cos(rotXangle);
        rotZangle = atan2(cosXangle * row(1).x + sinXangle * row(2).x, cosXangle * row(1).y + sinXangle * row(2).y);
    }

    float values[16];
};

float toRadians(float degrees) {
    return degrees * (M_PI/180);
}

float toDegrees(float radians) {
    return radians*(180/M_PI);
}

int main() {
    float rotXangle = toRadians(10);
    float rotYangle = toRadians(30);
    float rotZangle = toRadians(60);

    Mat4x4 rotX(
        1, 0, 0, 0,
        0, cos(rotXangle), -sin(rotXangle), 0,
        0, sin(rotXangle), cos(rotXangle), 0,
        0, 0, 0, 1
    );
    Mat4x4 rotY(
        cos(rotYangle), 0, sin(rotYangle), 0,
        0, 1, 0, 0,
        -sin(rotYangle), 0, cos(rotYangle), 0,
        0, 0, 0, 1
    );
    Mat4x4 rotZ(
        cos(rotZangle), -sin(rotZangle), 0, 0,
        sin(rotZangle), cos(rotZangle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );

    Mat4x4 concatenatedRotationMatrix =
        rotX.multiply(rotY.multiply(rotZ));

    float extractedXangle = 0, extractedYangle = 0, extractedZangle = 0;
    concatenatedRotationMatrix.extractEulerAngleXYZ(
        extractedXangle, extractedYangle, extractedZangle
    );

    std::cout << toDegrees(extractedXangle) << ' ' <<
        toDegrees(extractedYangle) << ' ' <<
        toDegrees(extractedZangle) << std::endl;

    return 0;
}
//看不懂，貌似这是已知欧拉角求欧拉角，有点傻叉感觉200708
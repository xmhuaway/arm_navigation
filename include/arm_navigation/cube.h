
#ifndef CUBE_H
#define CUBU_H

#include <iostream>
#include <vector>
#include "tf/tf.h"

namespace cubes
{
    class Cube
    {
        // enum CubeColor
        // {
        //     White,
        //     Blue,
        //     Red,
        //     Green,
        // };

        public:
            int mId;
            int mWidth;
            int mLength;
            int mHeight;
            // CubeColor mColor;
            std::string mName;

            /**
             * @brief  This is the current transform of brick
             * 
             */
            tf::Transform mTran;

            /**
             * @brief  This is the target transform where the brick move to.
             * 
             */
            tf::Transform mTargetTran;
        public:

            Cube();
            Cube(tf::Transform pTran);
            Cube(int pWidth, int pLength, int pHeight);
            // Cube(int pWidth, int pLength, int pHeight, CubeColor cubeColor);
            Cube(int pWidth, int pLength, int pHeight, tf::Transform pTran);

            inline bool operator == (const Cube &other);
            inline Cube& operator = (const Cube &other);
    };
}

#endif